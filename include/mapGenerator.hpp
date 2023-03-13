/*
** EPITECH PROJECT, 2022
** map generator class header
** File description:
** mapGenerator
*/

#ifndef MAPGENERATOR_HPP_
#define MAPGENERATOR_HPP_

#include "core.hpp"
#include "map.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class MapGenerator {
    public:
        MapGenerator();
        ~MapGenerator() = default;
        int **GenerateMap();
        void InitMap();
        void PlacePlayer();
        void RemovePlayer();
        void AddWalls();
        void CleanMap();
        bool CheckPos();
        int GetWidth();
        int GetHeight();
        map GetMap();
    private:
        int **_map;
        int _height;
        int _width;
        int _centerX;
        int _centerY;
};

#endif /* !MAPGENERATOR_HPP_ */
