//
// Created by breizhhardware on 26/04/24.
//

#include "Game.h"
#include "Player.h"
#include <QGraphicsView>
#include <QDebug>

Game::Game(Menu* menu) : menu(menu)
{
    // Set the user gold and wave number to 0
    userGold = 0;
    waveNumber = 0;
    isWaveSpawning = false;

    // Set the FocusPolicy to StrongFocus to allow the QGraphicsView to receive key events
    this->setFocusPolicy(Qt::StrongFocus);

    // Create the Map object
    gameMap = new Map(this);

    // Create the player object
    player = new Player(150, 0, 10, 10, 1, ":/ressources/player.png", 0, 0, *gameMap, *this);

    // Create the text items for the health, gold and wave number
    healthDisplay = new QGraphicsTextItem();
    goldDisplay = new QGraphicsTextItem();
    waveDisplay = new QGraphicsTextItem();

    // Set the Z-value of the text items to 2 to draw them on top of the player
    healthDisplay->setZValue(2);
    goldDisplay->setZValue(2);
    waveDisplay->setZValue(2);

    // Set the default text color to red
    healthDisplay->setDefaultTextColor(Qt::red);
    goldDisplay->setDefaultTextColor(Qt::red);
    waveDisplay->setDefaultTextColor(Qt::red);

    // Add all the items to the scene
    gameMap->addItem(healthDisplay);
    gameMap->addItem(goldDisplay);
    gameMap->addItem(waveDisplay);
    gameMap->addItem(player->getGraphics());

    // Set the position of the text items
    healthDisplay->setPos(0, 0);
    goldDisplay->setPos(0, 20);
    waveDisplay->setPos(0, 40);

    // Set the scene of the QGraphicsView to the gameMap
    this->setScene(gameMap);

    player->updatePreviousHealth();

    this->gameOverSound.setSource(QUrl::fromLocalFile(":/ressources/GameOver.wav"));
    this->gameOverSound.setVolume(0.5f);
    this->deathSound.setSource(QUrl::fromLocalFile(":/ressources/explosion.wav"));
    this->deathSound.setVolume(0.5f);
    this->warpSound.setSource(QUrl::fromLocalFile(":/ressources/warp.wav"));
    this->warpSound.setVolume(0.5f);
}

void Game::start() {
    // Heal the player to full health (150)
    int preiousHealth = player->getHealth();
    player->heal(150 - preiousHealth);

    // Create the map
    gameMap->generateMap(25, 14, this);

    // Set the user gold
    userGold = 100;

    // Set the wave number
    waveNumber = 1;

    // Get the start tile of the map
    Tile* startTile = gameMap->getStartTile();

    // Get start tile coordinates
    x = startTile->gridX();
    y = startTile->gridY();

    // Set the player position to the end tile
    Tile* endTile = gameMap->getEndTile();

    int xEnd = endTile->gridX();
    int yEnd = endTile->gridY();
    player->setPosition(xEnd, yEnd);

    // Start the game timer
    gameTimer.start(1000);

    // Connect the game timer to the updateDisplay slot
    connect(&gameTimer, &QTimer::timeout, this, &Game::updateDisplay);

    // Set focus to the QGraphicsView
    this->setFocus();

    // Spawn the enemies
    spawnEnemies(waveNumber);

    // Start the enemy check timer
    connect(&enemyCheckTimer, &QTimer::timeout, this, &Game::checkEnemyNumber);
    enemyCheckTimer.start(1000);
}

void Game::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Left:
            player->setPosition(player->getX() - 1, player->getY());
            break;
        case Qt::Key_Right:
            player->setPosition(player->getX() + 1, player->getY());
            break;
        case Qt::Key_Up:
            player->setPosition(player->getX(), player->getY() - 1);
            break;
        case Qt::Key_Down:
            player->setPosition(player->getX(), player->getY() + 1);
            break;
        case Qt::Key_Plus:
            this->setTransform(this->transform().scale(1.1, 1.1));
            break;
        case Qt::Key_Minus:
            this->setTransform(this->transform().scale(0.9, 0.9));
            break;
        default:
            QGraphicsView::keyPressEvent(event);
    }
}

void Game::updateDisplay() const{
    if(this == nullptr || player == nullptr || healthDisplay == nullptr || goldDisplay == nullptr || waveDisplay == nullptr) {
        return;
    }
    healthDisplay->setPlainText("Health: " + QString::number(player->getHealth()));
    goldDisplay->setPlainText("Gold: " + QString::number(userGold));
    waveDisplay->setPlainText("Wave: " + QString::number(waveNumber));
}

void Game::spawnEnemies(int waveNumber) {
    isWaveSpawning = true;
    totalWeight = 0;
    targetWeight = waveNumber * 2;
    if(waveNumber == 1) {
        targetWeight = 1;
    }
    if(waveNumber == 2) {
        targetWeight = 3;
    }
    if(waveNumber == 3) {
        targetWeight = 5;
    }
    int enemyId = 0;

    // Get the start tile
    Tile* startTile = gameMap->getStartTile();

    auto* spawnTimer = new QTimer();
    connect(spawnTimer, &QTimer::timeout, [this, waveNumber, &enemyId, spawnTimer, startTile](){
        if(totalWeight < targetWeight){
            for (int i = Enemy::Idris; i >= Enemy::P52; i--) {
                Enemy::Type type = static_cast<Enemy::Type>(i);
                Enemy enemy(type, *gameMap, enemyId, *this);
                if (totalWeight + enemy.getWeight() <= targetWeight) {
                    totalWeight += enemy.getWeight();
                    Enemy* newEnemy = new Enemy(type, *gameMap, enemyId, *this);
                    // Set the enemy position to the start tile
                    newEnemy->setPosition(startTile->gridX(), startTile->gridY());
                    currentEnemies.push_back(newEnemy);
                    gameMap->addItem(currentEnemies.back()->getGraphics());
                    enemyId++;
                    break;
                }
            }
        } else {
            spawnTimer->stop();
            spawnTimer->deleteLater();
            isWaveSpawning = false;
        }
    });
    spawnTimer->start(1000);
}

void Game::checkEnemyNumber() {
    if (currentEnemies.empty() && !isWaveSpawning){
        waveNumber++;
        endRound();
        spawnEnemies(waveNumber);
    }
}

void Game::removeEnemy(Enemy* enemy) {
    if(this == nullptr) {
        if (enemy == nullptr) {
            return;
        }
        delete enemy;
        return;
    }
    if (enemy->getGraphics()->scene() == gameMap) {
        gameMap->removeItem(enemy->getGraphics());
    }
    auto it = std::find(currentEnemies.begin(), currentEnemies.end(), enemy);
    if (it != currentEnemies.end()) {
        currentEnemies.erase(it);
        delete enemy;
    }
}

void Game::gameOver() {
    gameTimer.stop();
    enemyCheckTimer.stop();

    // Remove all the enemies from the game
    while (!currentEnemies.empty()) {
        Enemy* enemy = currentEnemies.back();
        if (enemy->getGraphics()->scene() == gameMap) {
            gameMap->removeItem(enemy->getGraphics());
        }
        currentEnemies.pop_back();
        delete enemy; // Delete the enemy after it has been removed from currentEnemies
    }

    // Remove the player from the game
    if (player->getGraphics()->scene() == gameMap) {
        gameMap->removeItem(player->getGraphics());
    }
    delete player;

    // Open a connection to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("leaderboard.db");
    if(!db.open()) {
        qDebug() << "Error: connection with database failed";
    }

    // Check if the leaderboard table exists in the database
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS leaderboard (username TEXT, wave INTEGER)");
    if(!query.exec()) {
        qDebug() << "Error: table creation failed";
    }

    // Get the user's name
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString username = env.value("USER", "Unknown");

    // Create a new SQL query to insert the user's score into the database
    QSqlQuery queryInsert;
    queryInsert.prepare("INSERT INTO leaderboard (username, wave) VALUES (:username, :wave)");
    queryInsert.bindValue(":username", username);
    queryInsert.bindValue(":wave", waveNumber);

    // Execute the query
    if(!queryInsert.exec()) {
        qDebug() << "Error: query failed";
    }

    // Close the database connection
    db.close();

    // Reset game variables
    userGold = 0;
    waveNumber = 0;
    totalWeight = 0;
    targetWeight = 0;

    clearTowers();

    gameOverSound.play();

    auto* gameOver = new Gameover(this);
    connect(gameOver, &Gameover::restartGameSignal, this, &Game::start);
    gameOver->setFixedSize(200, 100);
    gameOver->show();
}

void Game::resetGame() {
    // Recreate the player
    player = new Player(100, 0, 10, 10, 1, ":/ressources/player.png", 0, 0, *gameMap, *this);
    gameMap->addItem(player->getGraphics());
}


void Game::placeTower(QMouseEvent* event) {
    // Check if the click is a left click
    if (event->button() != Qt::LeftButton) {
        return;
    }

    // Convert the mouse position to scene coordinates
    int gridX = event->pos().x() / 50;
    int gridY = event->pos().y() / 50;

    // Check if the Tile is a other tile
    if (gameMap->getTile(gridX, gridY)->getType() == Tile::Other) {
        placeTower(gridX, gridY, event);
    }
    else if(gameMap->getTile(gridX, gridY)->getType() == Tile::Tower) {
        for (auto* tower : towers) {
            if (tower->getGraphics()->pos() == QPointF(gridX * 50, gridY * 50)) {
                upgradeTower(tower, event);
            }
        }
    }
    for (auto& tileList : gameMap->getTiles()) {
        for (auto* tile : tileList) {
            if (tile->gridX() == gridX && tile->gridY() == gridY && tile->getType() == Tile::Other) {
                tile->setType(Tile::Tower);
            }
        }
    }
}

void Game::upgradeTower(Tower* tower, QMouseEvent* event) {
    // Create a menu to upgrade the tower
    QMenu upgradeMenu;
    // Check if the user has enough gold to upgrade the tower
    if(userGold < 25) {
        QAction* notEnoughGold = upgradeMenu.addAction("Not enough gold to upgrade");
        QAction* selectedAction = upgradeMenu.exec(event->globalPosition().toPoint());
    }
    else {
        if(tower->getDamageUpgrades() == 5 && tower->getFireRateUpgrades() == 5) {
            QAction* maxUpgrades = upgradeMenu.addAction("Tower is fully upgraded");
            QAction* selectedAction = upgradeMenu.exec(event->globalPosition().toPoint());
        }
        else if(tower->getDamageUpgrades() == 5){
            QAction* upgradeFireRate = upgradeMenu.addAction("Upgrade Fire Rate - 50 gold");
            QAction* selectedAction = upgradeMenu.exec(event->globalPosition().toPoint());
            if(selectedAction == upgradeFireRate) {
                userGold -= 50;
                tower->upgradeFireRate();
            }
        }
        else if(tower->getFireRateUpgrades() == 5){
            QAction* upgradeDamage = upgradeMenu.addAction("Upgrade Damage - 50 gold");
            QAction* selectedAction = upgradeMenu.exec(event->globalPosition().toPoint());
            if(selectedAction == upgradeDamage) {
                userGold -= 50;
                tower->upgradeDamage();
            }
        }
        else{
            QAction* upgradeDamage = upgradeMenu.addAction("Upgrade Damage - 25 gold");
            QAction* upgradeFireRate = upgradeMenu.addAction("Upgrade Fire Rate - 50 gold");

            // Display the menu and wait for the user to select an action
            QAction* selectedAction = upgradeMenu.exec(event->globalPosition().toPoint());

            // Perform the selected upgrade
            if (selectedAction == upgradeDamage && userGold >= 25) {
                userGold -= 25;
                tower->upgradeDamage();
            } else if (selectedAction == upgradeFireRate && userGold >= 50) {
                userGold -= 50;
                tower->upgradeFireRate();
            }
        }
    }
}

void Game::placeTower(int gridX, int gridY, QMouseEvent* event) {
    if (gridX < 0 || gridX >= gameMap->getWidth() || gridY < 0 || gridY >= gameMap->getHeight()) {
        return;
    }
    // Clear the previous actions
    towerMenu.clear();
    QAction* laserTower = nullptr;
    QAction* balisticTower = nullptr;
    QAction* distorsionTower = nullptr;

    if(userGold < 50) {
        QAction* notEnoughGold = towerMenu.addAction("Not enough gold to place a tower");
        QAction* selectedAction = towerMenu.exec(event->globalPosition().toPoint());
        return;
    }
    else if(userGold < 75){
        laserTower = towerMenu.addAction("Laser Tower - 50 gold");
        balisticTower = towerMenu.addAction("Balistic Tower - 100 gold Not enough gold");
        distorsionTower = towerMenu.addAction("Distorsion Tower - 75 gold Not enough gold");
    }
    else if(userGold < 100){
        laserTower = towerMenu.addAction("Laser Tower - 50 gold");
        balisticTower = towerMenu.addAction("Balistic Tower - 100 gold Not enough gold");
        distorsionTower = towerMenu.addAction("Distorsion Tower - 75 gold");
    }
    else {
        laserTower = towerMenu.addAction("Laser Tower - 50 gold");
        balisticTower = towerMenu.addAction("Balistic Tower - 100 gold");
        distorsionTower = towerMenu.addAction("Distorsion Tower - 75 gold");
    }

    // Display the menu and wait for the user to select an action
    if(event == nullptr || towerMenu.actions().isEmpty()) {
        return;
    }
    QPoint point = event->globalPosition().toPoint();

    // Check the validity of towerMenu
    if (towerMenu.isEmpty()) {
        qDebug() << "towerMenu is not valid";
    } else {
    }

    // Check the validity of each QAction
    foreach (QAction* action, towerMenu.actions()) {
        if (action == nullptr) {
                qDebug() << "A QAction in towerMenu is not valid";
            }
        }

    // Call exec()
    QAction* selectedAction = towerMenu.exec(point);

    // Check if selectedAction is nullptr before using it
    if (selectedAction == nullptr) {
        return;
    }

    // Create the selected tower and add it to the list of towers
    if (selectedAction == laserTower && userGold >= 50) {
        userGold -= 50;
        Tile* tile = gameMap->getTile(gridX, gridY);
        tile->setType(Tile::Tower);
        auto* tower = new LaserTower(QPointF(gridX, gridY), *this);
        towers.push_back(tower);
        gameMap->addItem(tower->getGraphics());
    } else if (selectedAction == balisticTower && userGold >= 100) {
        userGold -= 100;
        Tile* tile = gameMap->getTile(gridX, gridY);
        tile->setType(Tile::Tower);
        auto* tower = new BalisticTower(QPointF(gridX, gridY), *this);
        towers.push_back(tower);
        gameMap->addItem(tower->getGraphics());
    } else if (selectedAction == distorsionTower && userGold >= 75) {
        userGold -= 75;
        Tile* tile = gameMap->getTile(gridX, gridY);
        tile->setType(Tile::Tower);
        auto* tower = new DistorionTower(QPointF(gridX, gridY), *this);
        towers.push_back(tower);
        gameMap->addItem(tower->getGraphics());
    }
}

void Game::endRound() {
    if(player->getHealth() == player->getPreviousHealth()) {
        player->heal(5);
    }
    player->updatePreviousHealth();
}

void Game::clearTowers() {
    for (auto* tower : towers) {
        if (tower->getGraphics() != nullptr && tower->getGraphics()->scene() == gameMap) {
            gameMap->removeItem(tower->getGraphics());
        }
        // Remove the rangeIndicator from the scene
        if (tower->getRangeIndicator() != nullptr && tower->getRangeIndicator()->scene() == gameMap) {
            gameMap->removeItem(tower->getRangeIndicator());
        }
        delete tower;
    }
    // Clear the list of towers after deleting them
    towers.clear();
}

void Game::handleTileClick(int gridX, int gridY, QMouseEvent* event) {
    Tile* tile = gameMap->getTile(gridX, gridY);
    if(tile->getType() == Tile::Other) {
        placeTower(gridX, gridY, event);
    }
    else if(tile->getType() == Tile::Tower) {
        for (auto* tower : towers) {
            if (tower->getGraphics()->pos() == QPointF(gridX * 50, gridY * 50)) {
                upgradeTower(tower, event);
            }
        }
    }
}

void Game::wheelEvent(QWheelEvent* event) {
    // Check if the wheel event is a zoom in or zoom out
    if(event->angleDelta().y() > 0) {
        // Zoom in
        this->setTransform(this->transform().scale(1.1, 1.1));
    } else {
        // Zoom out
        this->setTransform(this->transform().scale(0.9, 0.9));
    }
}

void Game::playDeathSound() {
    deathSound.play();
}

void Game::playWarpSound() {
    warpSound.play();
}