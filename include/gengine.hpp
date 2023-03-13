/*
** EPITECH PROJECT, 2022
** game engine header
** File description:
** gengine
*/

#ifndef GENGINE_HPP_
#define GENGINE_HPP_

#include "core.hpp"
#include "bomb.hpp"
#include "powerUp.hpp"
#include "map.hpp"
#include "menus.hpp"
#include "player.hpp"
#include "mapGenerator.hpp"
#include "options.hpp"
#include "saveManager.hpp"
#include "graphLib.hpp"

#define POS1 pos(1, 1)
#define POS2 pos(_map.getSizeX() - 2, 1)
#define POS3 pos(1, _map.getSizeY() - 2)
#define POS4 pos(_map.getSizeX() - 2, _map.getSizeY() - 2)

class gengine {
    public:
        gengine();
        ~gengine() = default;
        void run();
        void initPlayers();
        int gameLoop();
        void updateBombs();
        void updateItems();
        void updatePlayers(size_t playerNbr);
    private:
        graphLib _graphLib;
        map _map;
        menus _menus;
        options _options;
        MapGenerator _mapGenerator;
        saveManager _saveManager;
        std::vector<player> _players;
        std::vector<bomb> _bombs;
        std::vector<pos> _explosions;
        std::vector<powerUp> _powerUps;
        void safeVectorCat(std::vector<pos> &dest, std::vector<pos> src);
        std::vector<renderables *> regroupRenderables();
        size_t countPlayerBombs(size_t playerNbr);
        double getPosDifference(double diff);
        void movePlayer(size_t playerNbr, dpos playerScreenPos, dpos direction);
        bool pauseMode;
};

class gengineError : public std::exception {
    public:
        gengineError(std::string const &msg, size_t line) : _msg(msg), _line(line) {}
        const char *what() const noexcept override {
            string str = "gengineError: " + _msg + " [line]: " + std::to_string(_line);
            return str.c_str();
        }
    private:
        std::string _msg;
        size_t _line;
};

#endif /* !GENGINE_HPP_ */
