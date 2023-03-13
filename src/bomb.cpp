/*
** EPITECH PROJECT, 2022
** bombs implementation
** File description:
** bomb
*/

#include "bomb.hpp"

bomb::bomb(pos position, size_t power, double time, size_t player)
{
    _pos = position;
    _power = power;
    _time = time;
    _ownerID = player;
    _clock.start();
}

renderType bomb::getRenderType()
{
    return renderType::BOMB;
}

int bomb::getRenderState()
{
    return static_cast<int>(_state);
}

itemType bomb::getItemType()
{
    return itemType::I_BOMB;
}

void bomb::setState(bombState state)
{
    _state = state;
}

pos bomb::getPos()
{
    return _pos;
}

size_t bomb::getPower()
{
    return _power;
}

size_t bomb::getOwnerID()
{
    return _ownerID;
}

bool bomb::hasExploded()
{
    if ((_clock.getElapsedTime() >= _time)) {
        return true;
    }
    return false;
}