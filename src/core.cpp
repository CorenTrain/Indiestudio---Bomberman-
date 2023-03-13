/*
** EPITECH PROJECT, 2022
** core functions
** File description:
** core
*/

#include "core.hpp"
#include "gengine.hpp"

int main(void)
{
    gengine engine;

    try {
        engine.run();
    } catch (std::exception &e) {
        return 84;
    }
    return 0;
}