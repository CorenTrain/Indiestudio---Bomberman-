/*
** EPITECH PROJECT, 2022
** B-YEP-400-REN-4-1-indiestudio-corentin.pilard
** File description:
** map_gen
*/


#include "mapGenerator.hpp"

//Constructor

MapGenerator::MapGenerator()
{
    this->_height = 19;
    this->_width = 17;

    this->_centerY = this->_height / 2;
    this->_centerX = this->_width / 2;
    this->GenerateMap();
}

//Map Builders

void MapGenerator::InitMap()
{
    this->_map = new int *[this->_height];

    for (int i = 0; i < this->_height; i++) {
        _map[i] = new int[this->_width];
        for (int j = 0; j < this->_width; j++)
            _map[i][j] = 5;
    }
    for (int i = 0; i < this->_height; i++) {
        _map[i][0] = 1;
        _map[i][this->_width - 1] = 1;
    }
    for (int i = 0; i < this->_width - 1; i++) {
        _map[0][i] = 1;
        _map[this->_height - 1][i] = 1;
    }
    _map[this->_centerY][this->_centerX] = 1;
}

bool MapGenerator::CheckPos()
{
    int randX, randY;
    bool check = false;

    randX = rand() % (this->_width - 3) + 2;
    randY = rand() % (this->_height - 3) + 2;
    if (randX % 2 == 1 || randY % 2 == 1)
        check = true;
    for (int i = -1; i < 2; i++) {
        if (check == true)
            return (CheckPos());
        for (int j = -1; j < 2; j++) {
            if (_map[randY + i][randX + j] == 1)
                check = true;
        }
    }
    if (check == false) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                _map[randY + j][randX + i] = 0;
            }
        }
        _map[randY][randX] = 1;
    }
    return (check);
}

void MapGenerator::PlacePlayer()
{
    _map[1][1] = 4;
    _map[this->_height - 2][this->_width - 2] = 4;
    _map[1][this->_width - 2] = 4;
    _map[this->_height - 2][1] = 4;
    // _map[this->_centerY][1] = 4;
    // _map[this->_centerY][this->_width - 2] = 4;
    // _map[1][this->_centerX] = 4;
    // _map[this->_height - 2][this->_centerX] = 4;
}

void MapGenerator::RemovePlayer()
{
    _map[1][1] = 0;
    _map[this->_height - 2][this->_width - 2] = 0;
    _map[1][this->_width - 2] = 0;
    _map[this->_height - 2][1] = 0;
    // _map[this->_centerY][1] = 0;
    // _map[this->_centerY][this->_width - 2] = 0;
    // _map[1][this->_centerX] = 0;
    // _map[this->_height - 2][this->_centerX] = 0;
}

void MapGenerator::AddWalls()
{
    for (int i = 0; i < this->_height; i++) {
        for (int j = 0; j < this->_width; j++) {
            if (_map[i][j] == 0) {
                if (_map[i - 1][j] != 4 && _map[i - 1][j] != 1)
                    _map[i - 1][j] = 2;
                if (_map[i + 1][j] != 4 && _map[i + 1][j] != 1)
                    _map[i + 1][j] = 2;
                if (_map[i][j - 1] != 4 && _map[i][j - 1] != 1)
                    _map[i][j - 1] = 2;
                if (_map[i][j + 1] != 4 && _map[i][j + 1] != 1)
                    _map[i][j + 1] = 2;
            }
        }
    }
}

void MapGenerator::CleanMap()
{
    for (size_t i = 0; i < this->_height; i++) {
        for (size_t j = 0; j < this->_width; j++) {
            if (this->_map[i][j] == 5)
                this->_map[i][j] = 0;
        }
    }
}

//MapGenarator core function

int **MapGenerator::GenerateMap()
{
    int op = 80;
    this->InitMap();

    srand(time(NULL));
    for (int i = 0; i < op; i++)
        this->CheckPos();
    this->PlacePlayer();
    this->AddWalls();
    this->RemovePlayer();
    this->CleanMap();
    return (this->_map);
}


//Getters


int MapGenerator::GetWidth()
{
    return (this->_width);
}

int MapGenerator::GetHeight()
{
    return (this->_height);
}

map MapGenerator::GetMap()
{   
    GenerateMap();
    map formatMap = map(this->_map, this->_width, this->_height);

    return formatMap;
}
