/*
** EPITECH PROJECT, 2022
** pos class header
** File description:
** pos
*/

#ifndef POS_HPP_
#define POS_HPP_

#include "core.hpp"

class dpos;

class pos {
    public:
        pos(int x, int y);
        pos();
        ~pos() = default;
        int getPosX();
        int getPosY();
        bool operator==(pos const &other);
        void operator+=(pos const &other);
        void operator=(dpos &other);
    private:
        int _posX;
        int _posY;
};

class dpos {
    public:
        dpos(double x, double y);
        dpos();
        ~dpos() = default;
        double getPosX();
        double getPosY();
        void ceilAll();
        bool operator==(dpos const &other);
        void operator+=(dpos const &other);
        bool operator>=(double const &other);
        void operator-=(double const &other);
    private:
        double _posX;
        double _posY;
};

#endif /* !POS_HPP_ */
