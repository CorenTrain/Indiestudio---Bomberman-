/*
** EPITECH PROJECT, 2022
** options class
** File description:
** options
*/

#ifndef OPTIONS_HPP_
    #define OPTIONS_HPP_
    #include "binds.hpp"
    #include "core.hpp"

class options {
    public:
        options();
        ~options() = default;
        void setMusicVolume(size_t volume);
        void setSoundVolume(size_t volume);
        void setFullscreen(bool fullscreen);
        void setFps(size_t fps);
        void setPlayerNbr(size_t playerNbr);
        void setBotNbr(size_t botNbr);
        void setBind(int player, action act, KeyboardKey key);
        size_t getMusicVolume();
        size_t getSoundVolume();
        size_t getFps();
        size_t getPlayerNbr();
        size_t getBotNbr();
        binds &getBinds(size_t player);
        bool getFullscreen();
    private:
        binds _bindsP1;
        binds _bindsP2;
        binds _bindsP3;
        binds _bindsP4;
        size_t _volMusic;
        size_t _volSound;
        size_t _fps;
        int player_nbr;
        int bot_nbr;
        bool _fullscreen;
};

#endif /* !OPTIONS_HPP_ */
