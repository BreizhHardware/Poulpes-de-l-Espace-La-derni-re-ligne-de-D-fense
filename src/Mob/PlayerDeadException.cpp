//
// Created by breizhhardware on 01/05/24.
//

#include "PlayerDeadException.h"

const char* PlayerDeadException::what() const noexcept {
    return "Player is dead";
}