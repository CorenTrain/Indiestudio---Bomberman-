/*
** EPITECH PROJECT, 2022
** binds class
** File description:
** binds
*/

#ifndef BINDS_HPP_
#define BINDS_HPP_

#include "core.hpp"

typedef enum action {
    A_UP,
    A_DOWN,
    A_LEFT,
    A_RIGHT,
    A_BOMB,
    A_PAUSE,
    A_NOOPE
} action;

class binds {
    public:
        binds();
        ~binds() = default;
        void setDefaultPlayerBinds(size_t player);
        KeyboardKey getActionBind(action act);
        string getActionBindStr(action act);
        void setActionBind(action act, KeyboardKey key);
        bool checkBind(binds &current, binds other[], KeyboardKey key);
    private:
        string keyToStr(KeyboardKey key);
        bool isKeyValid(KeyboardKey key);
        std::map<action, KeyboardKey> _binds;
        std::map<KeyboardKey, string> _keyStr;
};


#endif /* !BINDS_HPP_ */
