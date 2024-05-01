//
// Created by breizhhardware on 01/05/24.
//

#ifndef POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYERDEADEXCEPTION_H
#define POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYERDEADEXCEPTION_H
#include <exception>

class PlayerDeadException : public std::exception
{
public:
    const char* what() const noexcept override;

};


#endif //POULPES_DE_L_ESPACE_LA_DERNIERE_LIGNE_DE_DEFENSE_PLAYERDEADEXCEPTION_H
