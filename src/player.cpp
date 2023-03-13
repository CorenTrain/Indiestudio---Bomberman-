/*
** EPITECH PROJECT, 2022
** player implementation
** File description:
** player
*/

#include "player.hpp"

player::player(size_t id)
{
    _id = id;
    _life = 3;
    _score = 0;
    _speed = 1;
    _capacity = 1;
    _power = 1;
    _ghost = false;
    _state = playerState::LIVING;
}

renderType player::getRenderType()
{
    return renderType::PLAYER;
}

int player::getRenderState()
{
    return static_cast<int>(_state);
}

void player::setPos(pos position)
{
    _mapPos = position;
}

void player::setScreenPos(dpos position)
{
    _screenPos = position;
}

pos player::getPos()
{
    return _mapPos;
}

dpos player::getScreenPos()
{
    return _screenPos;
}

int player::getLife()
{
    return _life;
}

void player::setLife(int life)
{
    _life = life;
}

void player::setScore(int score)
{
    _score = score;
}

int player::getScore()
{
    return _score;
}

void player::setState(playerState state)
{
    _state = state;
}

playerState player::getState()
{
    return _state;
}

size_t player::getId()
{
    return _id;
}

size_t player::getSpeed()
{
    return _speed;
}

size_t player::getCapacity()
{
    return _capacity;
}

size_t player::getPower()
{
    return _power;
}

void player::setIndexSkin(int nb)
{
    indexSkin = nb;
}

int player::getIndexSkin() const
{
    return indexSkin;
}

void player::powerUp(powerUpType type)
{
    switch (type) {
        case powerUpType::P_SPEED:
            if (_speed < 8)
                _speed++;
            break;
        case powerUpType::P_CAPCITY:
            if (_capacity < 8)
                _capacity++;
            _capacity++;
            break;
        case powerUpType::P_POWER:
            if (_power < 8)
                _power++;
            _power++;
            break;
        case powerUpType::P_GHOST:
            _ghost = true;
            break;
        default:
            break;
    }
}