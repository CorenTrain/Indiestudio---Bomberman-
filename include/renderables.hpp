/*
** EPITECH PROJECT, 2022
** rendarables interface header
** File description:
** renderables
*/

#ifndef RENDERABLES_HPP_
#define RENDERABLES_HPP_

#include "core.hpp"
#include "pos.hpp"

enum renderType {
    PLAYER,
    ENNEMY,
    BOMB,
    WALL,
    CRATE,
    FLOOR,
    EXPLOSION,
    POWERUP
};

class renderables {
    public:
        ~renderables() = default;
        virtual renderType getRenderType() = 0;
        virtual int getRenderState() = 0;
        virtual pos getPos() = 0;
};

#endif /* !RENDERABLES_HPP_ */
