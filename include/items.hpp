/*
** EPITECH PROJECT, 2022
** items class header
** File description:
** items
*/

#ifndef ITEMS_HPP_
#define ITEMS_HPP_

#include "core.hpp"

enum itemType {
    I_POWERUP,
    I_BOMB
};

class items {
    public:
        ~items() = default;
        virtual itemType getItemType() = 0;
};

#endif /* !ITEMS_HPP_ */
