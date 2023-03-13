/*
** EPITECH PROJECT, 2022
** pos implementation
** File description:
** pos
*/

#include "pos.hpp"

pos::pos(int x, int y)
{
    _posX = x;
    _posY = y;
}

pos::pos()
{
    _posX = 0;
    _posY = 0;
}

int pos::getPosX()
{
    return _posX;
}

int pos::getPosY()
{
    return _posY;
}

bool pos::operator==(pos const &other)
{
    return (_posX == other._posX && _posY == other._posY);
}

void pos::operator+=(pos const &other)
{
    _posX += other._posX;
    _posY += other._posY;
}

void pos::operator=(dpos &other)
{
    _posX = static_cast<int>(other.getPosX());
    _posY = static_cast<int>(other.getPosY());
}

// Dpos

dpos::dpos()
{
    _posX = 0.0;
    _posY = 0.0;
}

dpos::dpos(double x, double y)
{
    _posX = x;
    _posY = y;
}

double dpos::getPosX()
{
    return _posX;
}

double dpos::getPosY()
{
    return _posY;
}

bool dpos::operator==(dpos const &other)
{
    return (_posX == other._posX && _posY == other._posY);
}

void dpos::operator+= (dpos const &other)
{
    _posX += other._posX;
    _posY += other._posY;
}

bool dpos::operator>=(double const &other)
{
    double posx = std::fabs(_posX);
    double posy = std::fabs(_posY);

    if (posx == 0.0) {
        return (posy >= other);
    }
    else {
        return (posx >= other);
    }
}

void dpos::operator-=(double const &other)
{
    if (_posX == 0)
        _posY -= other;
    else
        _posX -= other;
}

void dpos::ceilAll()
{
    _posX = std::ceil(_posX);
    _posY = std::ceil(_posY);
}