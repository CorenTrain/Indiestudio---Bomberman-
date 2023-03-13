/*
** EPITECH PROJECT, 2022
** map class header
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "core.hpp"
#include "bomb.hpp"

enum mapElement {
    M_EMPTY,
    M_UNBREAKABLE,
    M_WALL
};

class map {
    public:
        map(int **map, size_t sizeX, size_t sizeY);
        map();
        ~map() = default;
        int **getIntMap();
        size_t getSizeX();
        size_t getSizeY();
        mapElement getMapElement(pos position);
        void setIntMap(int **map);
        void setMapElement(pos position, mapElement element);
        std::vector<pos> explode(bomb boom);
    private:
        int **_map;
        size_t _sizeX;
        size_t _sizeY;
};

#endif /* !MAP_HPP_ */
