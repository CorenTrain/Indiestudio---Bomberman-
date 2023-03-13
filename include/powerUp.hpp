/*
** EPITECH PROJECT, 2022
** powerUps classes
** File description:
** powerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "core.hpp"
#include "items.hpp"
#include "renderables.hpp"

enum powerUpType {
    P_CAPCITY,
    P_SPEED,
    P_POWER,
    P_GHOST
};

class powerUp : public items, public renderables {
    public:
        powerUp(pos pos, powerUpType type);
        ~powerUp() = default;
        renderType getRenderType();
        itemType getItemType();
        int getRenderState();
        powerUpType getPowerUpType();
        pos getPos();
        bool operator==(powerUp const &other);
    private:
        pos _pos;
        itemType _type;
        powerUpType _powerUpType;
};

#endif /* !POWERUP_HPP_ */
