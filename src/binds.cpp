/*
** EPITECH PROJECT, 2022
** binds implementation
** File description:
** binds
*/

#include "binds.hpp"

binds::binds()
{
    _keyStr[KeyboardKey::KEY_A] = "A";
    _keyStr[KeyboardKey::KEY_B] = "B";
    _keyStr[KeyboardKey::KEY_C] = "C";
    _keyStr[KeyboardKey::KEY_D] = "D";
    _keyStr[KeyboardKey::KEY_E] = "E";
    _keyStr[KeyboardKey::KEY_F] = "F";
    _keyStr[KeyboardKey::KEY_G] = "G";
    _keyStr[KeyboardKey::KEY_H] = "H";
    _keyStr[KeyboardKey::KEY_I] = "I";
    _keyStr[KeyboardKey::KEY_J] = "J";
    _keyStr[KeyboardKey::KEY_K] = "K";
    _keyStr[KeyboardKey::KEY_L] = "L";
    _keyStr[KeyboardKey::KEY_M] = "M";
    _keyStr[KeyboardKey::KEY_N] = "N";
    _keyStr[KeyboardKey::KEY_O] = "O";
    _keyStr[KeyboardKey::KEY_P] = "P";
    _keyStr[KeyboardKey::KEY_Q] = "Q";
    _keyStr[KeyboardKey::KEY_R] = "R";
    _keyStr[KeyboardKey::KEY_S] = "S";
    _keyStr[KeyboardKey::KEY_T] = "T";
    _keyStr[KeyboardKey::KEY_U] = "U";
    _keyStr[KeyboardKey::KEY_V] = "V";
    _keyStr[KeyboardKey::KEY_W] = "W";
    _keyStr[KeyboardKey::KEY_X] = "X";
    _keyStr[KeyboardKey::KEY_Y] = "Y";
    _keyStr[KeyboardKey::KEY_Z] = "Z";
    _keyStr[KeyboardKey::KEY_KP_0] = "0";
    _keyStr[KeyboardKey::KEY_KP_1] = "1";
    _keyStr[KeyboardKey::KEY_KP_2] = "2";
    _keyStr[KeyboardKey::KEY_KP_3] = "3";
    _keyStr[KeyboardKey::KEY_KP_4] = "4";
    _keyStr[KeyboardKey::KEY_KP_5] = "5";
    _keyStr[KeyboardKey::KEY_KP_6] = "6";
    _keyStr[KeyboardKey::KEY_KP_7] = "7";
    _keyStr[KeyboardKey::KEY_KP_8] = "8";
    _keyStr[KeyboardKey::KEY_KP_9] = "9";
    _keyStr[KeyboardKey::KEY_UP] = "UP";
    _keyStr[KeyboardKey::KEY_DOWN] = "DOWN";
    _keyStr[KeyboardKey::KEY_LEFT] = "LEFT";
    _keyStr[KeyboardKey::KEY_RIGHT] = "RIGHT";
    _keyStr[KeyboardKey::KEY_SPACE] = "SPACE";
    _keyStr[KeyboardKey::KEY_BACKSPACE] = "BACKSPACE";
    _keyStr[KeyboardKey::KEY_ESCAPE] = "ESCAPE";
    _keyStr[KeyboardKey::KEY_TAB] = "TAB";
    _keyStr[KeyboardKey::KEY_LEFT_SHIFT] = "LSHIFT";
    _keyStr[KeyboardKey::KEY_RIGHT_SHIFT] = "RSHIFT";
    _keyStr[KeyboardKey::KEY_LEFT_CONTROL] = "LCONTROL";
    _keyStr[KeyboardKey::KEY_RIGHT_CONTROL] = "RCONTROL";
    _keyStr[KeyboardKey::KEY_LEFT_ALT] = "LALT";
    _keyStr[KeyboardKey::KEY_RIGHT_ALT] = "RALT";
    _keyStr[KeyboardKey::KEY_CAPS_LOCK] = "CAPS_LOCK";
    _keyStr[KeyboardKey::KEY_END] = "END";
    _keyStr[KeyboardKey::KEY_HOME] = "HOME";
    _keyStr[KeyboardKey::KEY_INSERT] = "INSERT";
    _keyStr[KeyboardKey::KEY_DELETE] = "DELETE";
    _keyStr[KeyboardKey::KEY_PAGE_UP] = "PAGE_UP";
    _keyStr[KeyboardKey::KEY_PAGE_DOWN] = "PAGE_DOWN";
    _keyStr[KeyboardKey::KEY_NULL] = "Err";
}

bool binds::isKeyValid(KeyboardKey key)
{
    if (_keyStr.find(key) == _keyStr.end())
        return false;
    return true;
}

string binds::keyToStr(KeyboardKey key)
{
    return _keyStr[key];
}

void binds::setDefaultPlayerBinds(size_t player)
{
    _binds[A_PAUSE] = KeyboardKey::KEY_ESCAPE;
    if (player == 1) {
        _binds[A_UP] = KeyboardKey::KEY_W;
        _binds[A_DOWN] = KeyboardKey::KEY_S;
        _binds[A_LEFT] = KeyboardKey::KEY_A;
        _binds[A_RIGHT] = KeyboardKey::KEY_D;
        _binds[A_BOMB] = KeyboardKey::KEY_SPACE;
    } else if (player == 2) {
        _binds[A_UP] = KeyboardKey::KEY_UP;
        _binds[A_DOWN] = KeyboardKey::KEY_DOWN;
        _binds[A_LEFT] = KeyboardKey::KEY_LEFT;
        _binds[A_RIGHT] = KeyboardKey::KEY_RIGHT;
        _binds[A_BOMB] = KeyboardKey::KEY_END;
    } else if (player == 3) {
        _binds[A_UP] = KeyboardKey::KEY_T;
        _binds[A_DOWN] = KeyboardKey::KEY_G;
        _binds[A_LEFT] = KeyboardKey::KEY_F;
        _binds[A_RIGHT] = KeyboardKey::KEY_H;
        _binds[A_BOMB] = KeyboardKey::KEY_B;
    } else if (player == 4) {
        _binds[A_UP] = KeyboardKey::KEY_O;
        _binds[A_DOWN] = KeyboardKey::KEY_L;
        _binds[A_LEFT] = KeyboardKey::KEY_K;
        _binds[A_RIGHT] = KeyboardKey::KEY_M;
        _binds[A_BOMB] = KeyboardKey::KEY_P;
    }
}

KeyboardKey binds::getActionBind(action act)
{
    return _binds[act];
}

string binds::getActionBindStr(action act)
{
    return keyToStr(_binds[act]);
}

void binds::setActionBind(action act, KeyboardKey key)
{
    if (isKeyValid(key))
        _binds[act] = key;
    else
        _binds[act] = KeyboardKey::KEY_NULL;
}

bool binds::checkBind(binds &current, binds other[], KeyboardKey key)
{
    for (size_t i = 0; i < 4; i++) {
        if (other[i].getActionBind(A_BOMB) == key) {
            // std::cout << "current: " << current.getActionBind(A_BOMB) << "\tother:  " << other[i].getActionBind(A_BOMB) << std::endl;
            // std::cout << "current: " << current.getActionBindStr(A_BOMB) << "\tother:  " << other[i].getActionBindStr(A_BOMB) << std::endl;
            // std::cout << key << std::endl;
            // std::cout << "1" << std::endl;
            return true;
        }
        if (other[i].getActionBind(A_DOWN) == key) {
            // std::cout << "current: " << current.getActionBind(A_DOWN) << "\tother:  " << other[i].getActionBind(A_DOWN) << std::endl;
            // std::cout << "current: " << current.getActionBindStr(A_DOWN) << "\tother:  " << other[i].getActionBindStr(A_DOWN) << std::endl;
            // std::cout << key << std::endl;
            // std::cout << "2" << std::endl;
            return true;
        }
        if (other[i].getActionBind(A_LEFT) == key) {
            // std::cout << "current: " << current.getActionBind(A_LEFT) << "\tother:  " << other[i].getActionBind(A_LEFT) << std::endl;
            // std::cout << "current: " << current.getActionBindStr(A_LEFT) << "\tother:  " << other[i].getActionBindStr(A_LEFT) << std::endl;
            // std::cout << key << std::endl;
            // std::cout << "3" << std::endl;
            return true;
        }
        if (other[i].getActionBind(A_RIGHT) == key) {
            // std::cout << "current: " << current.getActionBind(A_RIGHT) << "\tother:  " << other[i].getActionBind(A_RIGHT) << std::endl;
            // std::cout << "current: " << current.getActionBindStr(A_RIGHT) << "\tother:  " << other[i].getActionBindStr(A_RIGHT) << std::endl;
            // std::cout << key << std::endl;
            // std::cout << "4" << std::endl;
            return true;
        }
        if (other[i].getActionBind(A_UP) == key) {
            // std::cout << "current: " << current.getActionBind(A_UP) << "\tother:  " << other[i].getActionBind(A_UP) << std::endl;
            // std::cout << "current: " << current.getActionBindStr(A_UP) << "\tother:  " << other[i].getActionBindStr(A_UP) << std::endl;
            // std::cout << key << std::endl;
            // std::cout << "5" << std::endl;
            return true;
        }
    }
    return false;
}