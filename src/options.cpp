/*
** EPITECH PROJECT, 2022
** options implementation
** File description:
** options
*/

#include "options.hpp"

options::options()
{
    _fullscreen = true;
    _fps = 60;
    _volMusic = 100;
    _volSound = 100;
    player_nbr = 2;
    bot_nbr = 0;
    _bindsP1.setDefaultPlayerBinds(1);
    _bindsP2.setDefaultPlayerBinds(2);
    _bindsP3.setDefaultPlayerBinds(3);
    _bindsP4.setDefaultPlayerBinds(4);
}

// SETTERS

void options::setMusicVolume(size_t volume)
{
    _volMusic = volume;
}

void options::setSoundVolume(size_t volume)
{
    _volSound = volume;
}

void options::setFullscreen(bool fullscreen)
{
    _fullscreen = fullscreen;
}

void options::setFps(size_t fps)
{
    _fps = fps;
}

void options::setPlayerNbr(size_t playerNbr)
{
    player_nbr = playerNbr;
}

void options::setBotNbr(size_t botNbr)
{
    bot_nbr = botNbr;
}

// GETTERS

size_t options::getMusicVolume()
{
    return _volMusic;
}

size_t options::getSoundVolume()
{
    return _volSound;
}

bool options::getFullscreen()
{
    return _fullscreen;
}

size_t options::getFps()
{
    return _fps;
}

size_t options::getPlayerNbr()
{
    return player_nbr;
}

size_t options::getBotNbr()
{
    return bot_nbr;
}

void options::setBind(int player, action act, KeyboardKey key)
{
    if (player == 0)
        _bindsP1.setActionBind(act, key);
    else if (player == 1)
        _bindsP2.setActionBind(act, key);
    else if (player == 2)
        _bindsP3.setActionBind(act, key);
    else if (player == 3)
        _bindsP4.setActionBind(act, key);
}

binds &options::getBinds(size_t player)
{
    if (player == 0)
        return _bindsP1;
    else if (player == 1)
        return _bindsP2;
    else if (player == 2)
        return _bindsP3;
    else
        return _bindsP4;
}
