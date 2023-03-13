/*
** EPITECH PROJECT, 2022
** bomb class header
** File description:
** bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "core.hpp"
#include "items.hpp"
#include "renderables.hpp"
#include "timer.hpp"

enum class bombState {
    TIMING,
    EXPLODING,
    EXPLODED,
    SUPER
};

class bomb : public items, public renderables {
    public:
        bomb(pos position, size_t power, double time, size_t player);
        ~bomb() = default;
        renderType getRenderType();
        int getRenderState();
        itemType getItemType();
        void setState(bombState state);
        pos getPos();
        size_t getPower();
        size_t getOwnerID();
        bool hasExploded();
    private:
        pos _pos;
        size_t _power;
        double _time;
        size_t _ownerID;
        bombState _state;
        timer _clock;
};

#endif /* !BOMB_HPP_ */
