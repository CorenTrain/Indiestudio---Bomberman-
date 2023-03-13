/*
** EPITECH PROJECT, 2022
** player class header
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "core.hpp"
#include "renderables.hpp"
#include "pos.hpp"
#include "powerUp.hpp"

enum class playerState {
    LIVING,
    DEAD,
    WIN
};

class player : public renderables {
    public:
        player(size_t id);
        ~player() = default;
        renderType getRenderType();
        int getRenderState();
        pos getPos();
        dpos getScreenPos();
        int getLife();
        int getScore();
        playerState getState();
        size_t getId();
        size_t getSpeed();
        size_t getCapacity();
        size_t getPower();
        void setPos(pos position);
        void setScreenPos(dpos position);
        void setLife(int life);
        void setScore(int score);
        void setState(playerState state);
        void powerUp(powerUpType type);
        int getIndexSkin() const;
        void setIndexSkin(int nb);
    private:
        pos _mapPos;
        dpos _screenPos;
        int _life;
        int _score;
        size_t _id;
        size_t _speed;
        size_t _capacity;
        size_t _power;
        bool _ghost;
        int indexSkin = 0;
        playerState _state;
};

#endif /* !PLAYER_HPP_ */
