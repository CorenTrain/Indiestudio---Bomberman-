/*
** EPITECH PROJECT, 2022
** map implementation
** File description:
** map
*/

#include "map.hpp"

map::map(int **map, size_t sizeX, size_t sizeY)
{
    _map = map;
    _sizeX = sizeX;
    _sizeY = sizeY;
}

map::map()
{
    _map = nullptr;
    _sizeX = 0;
    _sizeY = 0;
}

int **map::getIntMap()
{
    return _map;
}

size_t map::getSizeX()
{
    return _sizeX;
}

size_t map::getSizeY()
{
    return _sizeY;
}

mapElement map::getMapElement(pos position)
{
    switch (_map[position.getPosY()][position.getPosX()])
    {
        case static_cast<int>(mapElement::M_EMPTY):
            return mapElement::M_EMPTY;
            break;
        case static_cast<int>(mapElement::M_UNBREAKABLE):
            return mapElement::M_UNBREAKABLE;
            break;
        case static_cast<int>(mapElement::M_WALL):
            return mapElement::M_WALL;
            break;
    }
}

void map::setIntMap(int **map)
{
    _map = map;
}

void map::setMapElement(pos position, mapElement element)
{
    _map[position.getPosY()][position.getPosX()] = static_cast<int>(element);
}

std::vector<pos> map::explode(bomb boom)
{
    pos bombPos = boom.getPos();
    pos currPos;
    size_t bombPower = boom.getPower();
    std::vector<pos> explosions;

    explosions.push_back(bombPos);
    for (size_t i = 1; i <= bombPower; i++) {
        currPos = pos(bombPos.getPosX() - i, bombPos.getPosY());
        if (getMapElement(currPos) == mapElement::M_UNBREAKABLE)
            break;
        explosions.push_back(currPos);
        if (getMapElement(currPos) == mapElement::M_WALL)
            setMapElement(currPos, mapElement::M_EMPTY);
    }
    for (size_t i = 1; i <= bombPower; i++) {
        currPos = pos(bombPos.getPosX() + i, bombPos.getPosY());
        if (getMapElement(currPos) == mapElement::M_UNBREAKABLE)
            break;
        explosions.push_back(currPos);
        if (getMapElement(currPos) == mapElement::M_WALL)
            setMapElement(currPos, mapElement::M_EMPTY);
    }
    for (size_t i = 1; i <= bombPower; i++) {
        currPos = pos(bombPos.getPosX(), bombPos.getPosY() - i);
        if (getMapElement(currPos) == mapElement::M_UNBREAKABLE)
            break;
        explosions.push_back(currPos);
        if (getMapElement(currPos) == mapElement::M_WALL)
            setMapElement(currPos, mapElement::M_EMPTY);
    }
    for (size_t i = 1; i <= bombPower; i++) {
        currPos = pos(bombPos.getPosX(), bombPos.getPosY() + i);
        if (getMapElement(currPos) == mapElement::M_UNBREAKABLE)
            break;
        explosions.push_back(currPos);
        if (getMapElement(currPos) == mapElement::M_WALL)
            setMapElement(currPos, mapElement::M_EMPTY);
    }
    return explosions;
}