/*
** EPITECH PROJECT, 2022
** menus class header
** File description:
** menus
*/

#ifndef MENUS_HPP_
    #define MENUS_HPP_

    #include "core.hpp"
    #include "options.hpp"
    #include "mapGenerator.hpp"
    #include "raylib.h"
    #include "graphLib.hpp"

typedef enum menu_ret {
    PLAY,
    OPTIONS,
    EXIT,
    RETURN,
    SKIN,
    RESTART,
    BACK,
    NOPE
} menu_ret;

class menus {
    public:
        Camera camera = {0};
        menus();
        ~menus() = default;
        menu_ret gameOverMenu(graphLib &graph, std::vector<player> _players, int player_id);
        void save_sprites_in_array(graphLib &graph);
        Texture2D *get_sprites();
        void setScreenWidth(graphLib &graph);
        void setScreenHeight(graphLib &graph);
        void unloadSprites();
        bool checkBool(bool changed[]);
        //Main Menu
        menu_ret displayMainMenu(graphLib &graph);
        //Options
        menu_ret displayOptions(options &options, graphLib &graph);
        void displayVolSound(graphLib &graphLib, options &options);
        void displayVolMusic(graphLib &graphLib, options &options);
        void displayPlayerOpt(graphLib &graph, options &options, bool lock);
        void displayBotOpt(graphLib &graph, options &opt, bool lock);
        void displayFullscreen(graphLib &graph, options &options);
        menu_ret displayReturnArrow(graphLib &graph);
        bool goToKeyBindings(graphLib &graph);
        void displayKeyBindingsp1(graphLib &graph, options &opt, binds players[]);
        void displayKeyBindingsp2(graphLib &graph, options &opt, binds players[]);
        void setBind(options &opt, bool changed[], graphLib &graph, binds &current, binds players[], action act, int nb, int pl_id);
        //Pause Menu using Options displaying
        menu_ret pauseMenu(options &options, graphLib &graph);
        menu_ret SkinSelection(graphLib &graph, options &opt, std::vector<player> &_player);
    private:
        Texture2D *_sprites;
        int screenWidth;
        int screenHeight;
};

#endif /* !MENUS_HPP_ */
