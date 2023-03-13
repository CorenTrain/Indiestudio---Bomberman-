/*
** EPITECH PROJECT, 2022
** powerups implementation
** File description:
** powerUp
*/

#include "powerUp.hpp"

powerUp::powerUp(pos pos, powerUpType type)
{
    _pos = pos;
    _powerUpType = type;
    _type = itemType::I_POWERUP;
}

itemType powerUp::getItemType()
{
    return _type;
}

int powerUp::getRenderState()
{
    return 0;
}

renderType powerUp::getRenderType()
{
    return renderType::POWERUP;
}

powerUpType powerUp::getPowerUpType()
{
    return _powerUpType;
}

pos powerUp::getPos()
{
    return _pos;
}

bool powerUp::operator==(powerUp const &other)
{
    if (_pos == other._pos && _powerUpType == other._powerUpType)
        return true;
    return false;
}