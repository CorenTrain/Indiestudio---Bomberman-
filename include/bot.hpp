/*
** EPITECH PROJECT, 2022
** bip boup
** File description:
** bot
*/

#ifndef BOT_HPP_
#define BOT_HPP_

#include "player.hpp"
#include "map.hpp"
#include "bomb.hpp"

class bot : public player {
    public:
        bot(size_t id);
        ~bot() = default;
        void action(map &map, std::vector<bomb> &bombs);
    private:
        pos _pos;
        int _life;
        int _score;
        size_t _speed;
        size_t _capacity;
        size_t _power;
        bool _ghost;
        playerState _state;
};

#endif /* !BOT_HPP_ */
