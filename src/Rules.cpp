//
// Created by breizhhardware on 26/04/24.
//

#include "Rules.h"
#include <QVBoxLayout>

Rules::Rules(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    rulesLabel = new QLabel("Rules:\n"
                            "1. Place towers on the map\n"
                            "2. Click on the start button\n"
                            "3. Watch the enemies go through the map\n"
                            "4. If an enemy reaches the end, you lose\n"
                            "5. If you kill all the enemies, you win\n"
                            "6. Have fun!", this);
    layout->addWidget(rulesLabel);
}