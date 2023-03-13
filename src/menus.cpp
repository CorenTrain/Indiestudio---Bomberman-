/*
** EPITECH PROJECT, 2022
** Menus.cpp
** File description:
** Menus functions file
*/

#include "menus.hpp"

//Constructor

menus::menus()
{
    this->_sprites = new Texture2D[11];
}

//Main Menu Handling

menu_ret menus::displayMainMenu(graphLib &graph)
{
    ClearBackground((Color){175, 175, 175, 255});
    static bool set = false;
    menu_ret ret = NOPE;

    if (set == false) {
        this->save_sprites_in_array(graph);
        graph.levitate_texture(_sprites[9], true,(float)graph.getScreenWidth()/2 - _sprites[9].width - _sprites[9].width/2 - _sprites[9].width/4, graph.getScreenHeight()/2 - (float)_sprites[9].height/2 - (float)_sprites[9].height/5);
        set = true;
    }
    this->setScreenHeight(graph);
    this->setScreenWidth(graph);
    graph.displayTexture2D(this->_sprites[0], {(float)screenWidth/2 + _sprites[0].width/2, screenHeight/2 - (float)_sprites[0].height - _sprites[0].height});
    if (graph.checkCollision((Rectangle){(float)screenWidth/2 + _sprites[0].width/2, (float)screenHeight/2 - _sprites[0].height - _sprites[0].height, (float)_sprites[0].width, (float)_sprites[0].height})) {
        graph.displayTexture2D(this->_sprites[1], {(float)screenWidth/2 + _sprites[1].width/2, screenHeight/2 - (float)_sprites[1].height - _sprites[1].height});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayTexture2D(_sprites[2], {(float)screenWidth/2 + _sprites[0].width/2, screenHeight/2 - (float)_sprites[0].height - _sprites[0].height});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
            ret = SKIN;
    }
    graph.displayTexture2D(this->_sprites[3], {(float)screenWidth/2 + _sprites[3].width/2, screenHeight/2 - (float)_sprites[3].height/2});
    if (graph.checkCollision((Rectangle){(float)screenWidth/2 + _sprites[3].width/2, (float)screenHeight/2 - _sprites[3].height/2, (float)_sprites[3].width, (float)_sprites[3].height})) {
        graph.displayTexture2D(this->_sprites[4], {(float)screenWidth/2 + _sprites[4].width/2, screenHeight/2 - (float)_sprites[4].height/2});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayTexture2D(this->_sprites[5], {(float)screenWidth/2 + _sprites[5].width/2, screenHeight/2 - (float)_sprites[5].height/2});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
            ret = OPTIONS;
    }
    graph.displayTexture2D(this->_sprites[6], {(float)screenWidth/2 + _sprites[6].width/2, screenHeight/2 + (float)_sprites[6].height});
    if (graph.checkCollision((Rectangle){(float)screenWidth/2 + _sprites[6].width/2, (float)screenHeight/2 + _sprites[6].height, (float)_sprites[6].width, (float)_sprites[6].height})) {
        graph.displayTexture2D(this->_sprites[7], {(float)screenWidth/2 + _sprites[7].width/2, screenHeight/2 + (float)_sprites[7].height});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayTexture2D(this->_sprites[8], {(float)screenWidth/2 + _sprites[6].width/2, (float)screenHeight/2 + _sprites[6].height});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            graph.displayTexture2D(this->_sprites[6], {(float)screenWidth/2 + _sprites[6].width/2, screenHeight/2 + (float)_sprites[6].height});
            ret = EXIT;
        }
    }
    graph.levitate_texture(_sprites[9], false,(float)graph.getScreenWidth()/2 - _sprites[9].width - _sprites[9].width/2 - _sprites[9].width/4, graph.getScreenHeight()/2 - (float)_sprites[9].height/2 - (float)_sprites[9].height/5);
    return (ret);
}

//Skin Option Menu Handling

menu_ret menus::SkinSelection(graphLib &graph, options &opt, std::vector<player> &_player)
{
    static std::vector<int> anim = {0, 0, 0, 0};
    static int anime = 0;

    graph.clearBack(LIGHTGRAY);
    graph.begin3D(camera);
        anime++;
        UpdateModelAnimation(graph.getPlayerModel()[0][2], graph.getPlayerAnimations()[2][0], anime);
        UpdateModelAnimation(graph.getPlayerModel()[1][2], graph.getPlayerAnimations()[2][0], anime);
    if (opt.getBotNbr() + opt.getPlayerNbr() >= 2) {
        graph.drawMyModel(graph.getPlayerModel()[0][2], (Vector3) {-1, 10, 20}, 2.0f, LIGHTGRAY, (Vector3) {DEG2RAD * 75, 0, 0});
        graph.drawMyModel(graph.getPlayerModel()[1][2], (Vector3) {6, 10, 20}, 2.0f, LIGHTGRAY, (Vector3) {DEG2RAD * 75, 0, 0});
    }
    if (opt.getBotNbr() + opt.getPlayerNbr() >= 3) {
        UpdateModelAnimation(graph.getPlayerModel()[2][2], graph.getPlayerAnimations()[2][0], anime);
        graph.drawMyModel(graph.getPlayerModel()[2][2], (Vector3) {13, 10, 20}, 2.0f, LIGHTGRAY, (Vector3) {DEG2RAD * 75, 0, 0});
    }
    if (opt.getBotNbr() + opt.getPlayerNbr() >= 4) {
        UpdateModelAnimation(graph.getPlayerModel()[3][2], graph.getPlayerAnimations()[2][0], anime);
        graph.drawMyModel(graph.getPlayerModel()[3][2], (Vector3) {20, 10, 20}, 2.0f, LIGHTGRAY, (Vector3) {DEG2RAD * 75, 0, 0});
    }
    if (anime >= graph.getPlayerAnimations()[2][0].frameCount)
        anime = 0;
    graph.end3D(camera);
    graph.displayText("Choose your skin !", graph.getScreenWidth()/2 - graph.myMeasureText("Choose your skin !", 100)/2, 50, 100, (Color){214, 97, 1, 255});

    // PLAYER 1-2
    if (opt.getBotNbr() + opt.getPlayerNbr() >= 2) {
        graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("<", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText("<", 80)*2, (float)graph.myMeasureText("<", 80)*3})) {
            graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                _player[0].setIndexSkin(graph.setSkinPlayer(_player[0].getIndexSkin() - 1, 0));
                //CHANGE
            }
        }
        graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText(">", 80)*4, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText(">", 80)*4, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText(">", 80)*2, (float)graph.myMeasureText(">", 80)*3})) {
            graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText(">", 80)*4, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText(">", 80)*4, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                _player[0].setIndexSkin(graph.setSkinPlayer(_player[0].getIndexSkin() + 1, 0));
                //CHANGE
            }
        }
        graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 - graph.myMeasureText("<", 80)/2, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 - graph.myMeasureText("<", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText("<", 80)*2, (float)graph.myMeasureText("<", 80)*3})) {
            graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 - graph.myMeasureText("<", 80)/2, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 - graph.myMeasureText("<", 80)/2, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                //CHANGE
                _player[1].setIndexSkin(graph.setSkinPlayer(_player[1].getIndexSkin() - 1, 1));
            }
        }
        graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)/2, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText(">", 80)*2, (float)graph.myMeasureText(">", 80)*3})) {
            graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)/2, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*14 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)/2, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                //CHANGE
                _player[1].setIndexSkin(graph.setSkinPlayer(_player[1].getIndexSkin() + 1, 1));
            }
        }
    }
    //PLAYER 3
    if (opt.getBotNbr() + opt.getPlayerNbr() >= 3) {
        graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 - graph.myMeasureText("<", 80), graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 - graph.myMeasureText("<", 80), (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText("<", 80)*2, (float)graph.myMeasureText("<", 80)*3})) {
            graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 - graph.myMeasureText("<", 80), graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 - graph.myMeasureText("<", 80), graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                //CHANGE
                _player[2].setIndexSkin(graph.setSkinPlayer(_player[2].getIndexSkin() - 1, 2));
            }
        }
        graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80), graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80), (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText(">", 80)*2, (float)graph.myMeasureText(">", 80)*3})) {
            graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80), graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*28 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80), graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                //CHANGE
                _player[2].setIndexSkin(graph.setSkinPlayer(_player[2].getIndexSkin() + 1, 2));
            }
        }
    }
    //PLAYER 4
    if (opt.getBotNbr() + opt.getPlayerNbr() >= 4) {
        graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 - graph.myMeasureText("<", 80)*1.5, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)(graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 - graph.myMeasureText("<", 80)*1.5), (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText("<", 80)*2, (float)graph.myMeasureText("<", 80)*3})) {
            graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 - graph.myMeasureText("<", 80)*1.5, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText("<", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 - graph.myMeasureText("<", 80)*1.5, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                //CHANGE
                _player[3].setIndexSkin(graph.setSkinPlayer(_player[3].getIndexSkin() - 1, 3));
            }
        }
        graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)*1.5, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, (Color){0, 35, 73, 255});
        if (graph.checkCollision((Rectangle){(float)(graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)*1.5), (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, (float)graph.myMeasureText(">", 80)*2, (float)graph.myMeasureText(">", 80)*3})) {
            graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)*1.5, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, YELLOW);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
                graph.displayText(">", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 + graph.myMeasureText("<", 80)*42 + graph.myMeasureText(">", 80)*4 - graph.myMeasureText(">", 80)*1.5, graph.getScreenHeight()/2 + graph.getScreenHeight()/4 - graph.getScreenHeight()/10, 80, ORANGE);
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                //CHANGE
                _player[3].setIndexSkin(graph.setSkinPlayer(_player[3].getIndexSkin() + 1, 3));
            }
        }
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/2, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18}, 8, (Color){0, 35, 73, 255});
    graph.displayText("Continue", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Continue", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/2, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18})) {
    graph.displayText("Continue", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Continue", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, RED);
    if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
        graph.displayText("Continue", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Continue", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, ORANGE);
    if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
        return (PLAY);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/2, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18}, 8, (Color){0, 35, 73, 255});
    graph.displayText("Go Back", (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.getScreenWidth()/8 - graph.myMeasureText("Continue", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/2, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18})) {
        graph.displayText("Go Back", (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.getScreenWidth()/8 - graph.myMeasureText("Continue", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, RED);
    if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
        graph.displayText("Go Back", (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.getScreenWidth()/8 - graph.myMeasureText("Continue", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, ORANGE);
    if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
        return (BACK);
    }
    return RETURN;
}

//Options Menu Handling

menu_ret menus::displayOptions(options &opt, graphLib &graph)
{
    char title[] = "Options";
    static bool first = true;
    menu_ret ret = NOPE;
    menu_ret intra_ret = NOPE;
    binds players[4] {opt.getBinds(0), opt.getBinds(1), opt.getBinds(2), opt.getBinds(3)};

    ClearBackground((Color){0, 35, 73});
    if (first) {
        graph.displayText(title, graph.getScreenWidth()/2 - graph.myMeasureText(title, 100)/2, 50, 100, (Color){214, 97, 1, 255});
        this->displayVolMusic(graph, opt);
        this->displayVolSound(graph, opt);
        this->displayPlayerOpt(graph, opt, false);
        this->displayBotOpt(graph, opt, false);
        this->displayFullscreen(graph, opt);
        ret = this->displayReturnArrow(graph);
        if (this->goToKeyBindings(graph))
            first = false;
    } else {
        intra_ret = this->displayReturnArrow(graph);
        this->displayKeyBindingsp1(graph, opt, players);
        this->displayKeyBindingsp2(graph, opt, players);
        if (intra_ret == RETURN)
            first = true;
    }
    return (ret);
}

void menus::displayVolSound(graphLib &graph, options &opt)
{
    char volSound[] = "Sound Volume";
    Vector2 mousePosition = {0};
    bool mousePressed1 = false;
    mousePosition = GetTouchPosition(0);
    static Rectangle bar1 = {
        (float)graph.getScreenWidth() - graph.getScreenWidth()/3 - (float)graph.getScreenWidth()/10,
        (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/4,
        (float)graph.getScreenWidth()/3,
        (float)graph.getScreenHeight()/10
    };
    static Rectangle slider1 = {
        bar1.x + bar1.width - (graph.getScreenWidth()/100) / 2,
        bar1.y,
        (float)graph.getScreenWidth()/100,
        (float)graph.getScreenHeight()/10
    };

    if (graph.checkCollision(bar1)) {
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1) {
        slider1.x = (int)mousePosition.x - slider1.width/2;
        if (slider1.x < bar1.x) slider1.x = bar1.x ;
        if (slider1.x > (bar1.x + bar1.width + 20)) slider1.x = bar1.x + bar1.width;
        mousePressed1 = true;
        } else {
            mousePressed1 = false;
        }
    }
    opt.setSoundVolume((((slider1.x + slider1.width) - bar1.x) * 100 / bar1.width) - 1);
    graph.drawRect(bar1, (Color){ 80, 80, 80, 100 });
    graph.drawRectEx(bar1, 5, (Color){ 80, 80, 80, 255 });
    graph.drawRect(slider1, (Color){ 80, 80, 80, 255 });
    if (!mousePressed1)
        graph.drawRectEx(slider1, 5, BLACK);
    else
        graph.drawRectEx(slider1, 5, LIGHTGRAY);
    graph.displayText(graph.myTextFormat("%d", opt.getSoundVolume()), bar1.x + bar1.width/2 - graph.myMeasureText(graph.myTextFormat("%d", opt.getSoundVolume()), 80)/2, bar1.y + bar1.height/8, 80, (Color){ 255, 255, 255, 255 });
    graph.displayText(volSound, bar1.x + bar1.width/2 - graph.myMeasureText(volSound, 80)/2, bar1.y - graph.getScreenHeight()/10, 80, (Color){ 250, 230, 0, 255 });
}

void menus::displayVolMusic(graphLib &graph, options &opt)
{
    char volMusic[] = "Music Volume";
    Vector2 mousePosition = {0};
    bool mousePressed1 = false;
    mousePosition = GetTouchPosition(0);
    static Rectangle bar1 = {
        (float)graph.getScreenWidth() - graph.getScreenWidth()/3 - (float)graph.getScreenWidth()/10,
        (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10,
        (float)graph.getScreenWidth()/3,
        (float)graph.getScreenHeight()/10
    };
    static Rectangle slider1 = {
        bar1.x + bar1.width - (graph.getScreenWidth()/100)/2,
        bar1.y,
        (float)graph.getScreenWidth()/100,
        (float)graph.getScreenHeight()/10
    };

    if (graph.checkCollision(bar1)) {
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1) {
        slider1.x = (int)mousePosition.x - slider1.width/2;
        if (slider1.x < bar1.x) slider1.x = bar1.x ;
        if (slider1.x > (bar1.x + bar1.width + 20)) slider1.x = bar1.x + bar1.width;
        mousePressed1 = true;
        } else {
            mousePressed1 = false;
        }
    }
    opt.setMusicVolume((((slider1.x + slider1.width) - bar1.x) * 100 / bar1.width) - 1);
    graph.drawRect(bar1, (Color){ 80, 80, 80, 100 });
    graph.drawRectEx(bar1, 5, (Color){ 80, 80, 80, 255 });
    graph.drawRect(slider1, (Color){ 80, 80, 80, 255 });
    if (!mousePressed1)
        graph.drawRectEx(slider1, 5, (Color){ 0, 0, 0, 255 });
    else
        graph.drawRectEx(slider1, 5, (Color){ 200, 200, 200, 255 });
    graph.displayText(graph.myTextFormat("%d", opt.getMusicVolume()), bar1.x + bar1.width/2 - graph.myMeasureText(graph.myTextFormat("%d", opt.getMusicVolume()), 80)/2, bar1.y + bar1.height/8, 80, (Color){ 255, 255, 255, 255 });
    graph.displayText(volMusic, bar1.x + bar1.width/2 - graph.myMeasureText(volMusic, 80)/2, bar1.y - graph.getScreenHeight()/10, 80, (Color){ 250, 230, 0, 255 });
}

void menus::displayBotOpt(graphLib &graph, options &opt, bool lock)
{
    char botOpt[] = "Bot Number";
    int botNb = opt.getBotNbr();

    graph.displayText(botOpt, graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(botOpt, 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    graph.displayText(graph.myTextFormat("%d", botNb), graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(graph.myTextFormat("%d", botNb), 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, (Color){255, 255, 255, 255});
    graph.displayText("-", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("2", 80) - graph.getScreenWidth()/10, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, (Color){255, 255, 255, 255});
    graph.displayText("+", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("2", 80) - graph.getScreenWidth()/10 + graph.getScreenWidth()/5, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, (Color){255, 255, 255, 255});
    if (!lock) {
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("-", 80) - graph.getScreenWidth()/10 - graph.getScreenWidth()/150, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.myMeasureText("-", 80)/2, (float)graph.myMeasureText("-", 100), (float)graph.myMeasureText("-", 100)})) {
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                botNb--;
            }
        } else if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("+", 80) - graph.getScreenWidth()/10 + graph.getScreenWidth()/5, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.myMeasureText("+", 80)/3, (float)graph.myMeasureText("+", 100), (float)graph.myMeasureText("+", 100)})) {
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                botNb++;
            }
        }
        if (botNb < 0)
            botNb = 0;
        if (botNb > 3)
            botNb = 3;
        if (botNb + opt.getPlayerNbr() > 4)
            botNb -= 1;
        if (botNb == 0 && opt.getPlayerNbr() < 2)
            opt.setPlayerNbr(2);
        opt.setBotNbr(botNb);
    }
}

void menus::displayPlayerOpt(graphLib &graph, options &opt, bool lock)
{
    char botOpt[] = "Player Number";
    int playerNb = opt.getPlayerNbr();

    graph.displayText(botOpt, graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(botOpt, 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    graph.displayText(graph.myTextFormat("%d", playerNb), graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(graph.myTextFormat("%d", playerNb), 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/4, 80, (Color){255, 255, 255, 255});
    graph.displayText("-", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("2", 80) - graph.getScreenWidth()/10, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/4, 80, (Color){255, 255, 255, 255});
    graph.displayText("+", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("2", 80) - graph.getScreenWidth()/10 + graph.getScreenWidth()/5, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/4, 80, (Color){255, 255, 255, 255});
    if (!lock) {
        if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("-", 80) - graph.getScreenWidth()/10 - graph.getScreenWidth()/150, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.myMeasureText("-", 80)/2 + graph.getScreenHeight()/4, (float)graph.myMeasureText("-", 100), (float)graph.myMeasureText("-", 100)})) {
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                playerNb--;
            }
        } else if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("+", 80) - graph.getScreenWidth()/10 + graph.getScreenWidth()/5, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.myMeasureText("+", 80)/3 + graph.getScreenHeight()/4, (float)graph.myMeasureText("+", 100), (float)graph.myMeasureText("+", 100)})) {
            if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
                playerNb++;
            }
        }
        if (playerNb < 1)
            playerNb = 1;
        if (playerNb > 4)
            playerNb = 4;
        if (playerNb + opt.getBotNbr() > 4)
            opt.setBotNbr(opt.getBotNbr() - 1);
        opt.setPlayerNbr(playerNb);
    }
}

void menus::displayFullscreen(graphLib &graph, options &opt)
{
    static bool toggle = false;
    static bool security = false;
    char fullscreenOpt[] = "Fullscreen";
    Rectangle rect = {
        (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/30)/2,
        (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/10,
        (float)graph.getScreenWidth()/30,
        (float)graph.getScreenWidth()/30
    };
    Rectangle rect2 = {
        (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/30)/2 - graph.getScreenWidth()/250/2,
        (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/10 - graph.getScreenWidth()/250/2,
        (float)graph.getScreenWidth()/30 + graph.getScreenWidth()/250,
        (float)graph.getScreenWidth()/30 + graph.getScreenWidth()/250
    };

    if (graph.checkCollision(rect)) {
        graph.drawRect(rect, (Color){ 250, 230, 0, 100 });
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
            opt.setFullscreen(!opt.getFullscreen());
    }

    graph.displayText(fullscreenOpt, graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(fullscreenOpt, 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    if (opt.getFullscreen()) {
        security = false;
        graph.drawRect(rect, YELLOW);
        if (toggle == false) {
            graph.myToggleFullscreen();
            toggle = true;
        }
    } else {
        if (security == false) {
            graph.myToggleFullscreen();
            security = true;
        }
        toggle = false;
    }
    graph.drawRectEx(rect2, 2, RED);
}

menu_ret menus::displayReturnArrow(graphLib &graph)
{
    Rectangle rect1 = {
        0,
        0,
        (float)this->_sprites[10].width,
        (float)this->_sprites[10].height
    };
    Rectangle rect2 = {
        (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.getScreenWidth()/5 - graph.getScreenWidth()/30,
        (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 - graph.getScreenHeight()/10,
        (float)graph.getScreenWidth()/15,
        (float)graph.getScreenWidth()/15
    };
    graph.drawTexturePro(this->_sprites[10], rect1, rect2, (Vector2){0, 0}, 270, WHITE);
    if (graph.checkCollision((Rectangle){rect2.x, rect2.y - graph.getScreenHeight()/8, rect2.width, rect2.height})) {
        graph.drawTexturePro(this->_sprites[10], rect1, rect2, (Vector2){0, 0}, 270, (Color){ 250, 230, 0, 255 });
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.drawTexturePro(this->_sprites[10], rect1, rect2, (Vector2){0, 0}, 270, WHITE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
            return RETURN;
    }
    return NOPE;
}

bool menus::goToKeyBindings(graphLib &graph)
{
    char str[] = "Display Key Bindings";
    bool ret = false;

    graph.displayText(str, (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(str, 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(str, 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4, (float)graph.myMeasureText(str, 80), (float)graph.getScreenHeight()/11})) {
        graph.displayText(str, (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(str, 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4, 80, (Color){214, 97, 1, 255});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(str, (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(str, 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/4 + graph.getScreenHeight()/4, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
            ret = true;
    }
    return (ret);
}

void menus::displayKeyBindingsp1(graphLib &graph, options &opt, binds players[])
{
    static bool changed[5] = {false, false, false, false, false};
    std::string str;
    char title[] = "Key Bindings";
    static int pl = 0; // 1 or 2

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/20*4/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, (float)graph.getScreenWidth()/20*4, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText("ESCAPE", (float)graph.getScreenWidth()/2 - graph.myMeasureText("ESCAPE", 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, (Color){250, 230, 0, 255});
    graph.displayText("Pause", (float)graph.getScreenWidth()/2 - graph.myMeasureText("Bomb", 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4 + graph.getScreenHeight()/20*2, 80, RED);

    graph.displayText(title, graph.getScreenWidth()/2 - graph.myMeasureText(title, 100)/2, graph.getScreenHeight()/21, 100, (Color){214, 97, 1, 255});
    if (pl == 0)
        graph.displayText("Player 1", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Player 1", 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    else if (pl == 2)
        graph.displayText("Player 3", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Player 3", 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});


    graph.displayText("X", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Player 3", 80)/2 - graph.myMeasureText("X", 80)/1.5 - graph.myMeasureText("X", 80), (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)(graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Player 3", 80)/2 - graph.myMeasureText("X", 80)/1.5 - graph.myMeasureText("X", 80)), (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4, (float)graph.myMeasureText("X", 80), (float)graph.getScreenHeight()/11})) {
        graph.displayText("X", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Player 3", 80)/2 - graph.myMeasureText("X", 80)/1.5 - graph.myMeasureText("X", 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){214, 97, 1, 255});
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText("X", graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Player 3", 80)/2 - graph.myMeasureText("X", 80)/1.5 - graph.myMeasureText("X", 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (pl == 0)
                pl = 2;
            else if (pl == 2)
                pl = 0;
        }
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, ORANGE);;
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[0] = true;
        }
    }
    if (changed[0]) {
        graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, RED);
        this->setBind(opt ,changed, graph, players[pl], players, A_UP, 0, pl);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[1] = true;
        }
    }
    if (changed[1]) {
        graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        this->setBind(opt, changed, graph, players[pl], players, A_DOWN, 1, pl);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[2] = true;
        }
    }
    if (changed[2]) {
        graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        this->setBind(opt, changed, graph, players[pl], players, A_RIGHT, 2, pl);;
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[3] = true;
        }
    }
    if (changed[3]) {
        graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        this->setBind(opt ,changed, graph, players[pl], players, A_LEFT, 3, pl);;
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[4] = true;
        }
    }
    graph.displayText("Bomb", (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText("Bomb", 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4 + graph.getScreenHeight()/20*2, 80, RED);
    if (changed[4]) {
        graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 - graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, RED);
        this->setBind(opt , changed, graph, players[pl], players, A_BOMB, 4, pl);;
    }
}

void menus::displayKeyBindingsp2(graphLib &graph, options &opt, binds players[])
{
    static bool changed[5] = {false, false, false, false, false};
    std::string str;
    static int pl = 1;

    if (pl == 1)
        graph.displayText("Player 2", graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText("Player 2", 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    else if (pl == 3)
        graph.displayText("Player 4", graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText("Player 4", 80)/2, graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    graph.displayText("X", graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.myMeasureText("Player 4", 80)/2 + + graph.myMeasureText("X", 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.myMeasureText("Player 4", 80)/2 + + graph.myMeasureText("X", 80), (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4, (float)graph.myMeasureText("X", 80), (float)graph.getScreenHeight()/20})) {
        graph.displayText("X", graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.myMeasureText("Player 4", 80)/2 + + graph.myMeasureText("X", 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText("X", graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.myMeasureText("Player 4", 80)/2 + + graph.myMeasureText("X", 80), graph.getScreenHeight()/2 - graph.getScreenHeight()/4, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (pl == 3)
                pl = 1;
            else if (pl == 1)
                pl = 3;
        }
    }
    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[0] = true;
        }
    }
    if (changed[0]) {
        graph.displayText(players[pl].getActionBindStr(A_UP).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_UP).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10, 80, RED);
        this->setBind(opt, changed, graph, players[pl], players, A_UP, 0, pl);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_DOWN).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_DOWN).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_DOWN).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[1] = true;
        }
    }
    if (changed[1]) {
        graph.displayText(players[pl].getActionBindStr(A_DOWN).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_DOWN).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        this->setBind(opt ,changed, graph, players[pl], players, A_DOWN, 1, pl);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[2] = true;
        }
    }
    if (changed[2]) {
        graph.displayText(players[pl].getActionBindStr(A_RIGHT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 + (float)graph.getScreenWidth()/20*3 + graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_RIGHT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        this->setBind(opt ,changed, graph, players[pl], players, A_RIGHT, 2, pl);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[3] = true;
        }
    }
    if (changed[3]) {
        graph.displayText(players[pl].getActionBindStr(A_LEFT).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20 - (float)graph.getScreenWidth()/20*3 - graph.getScreenHeight()/100 + (float)graph.getScreenWidth()/20*3/2 - graph.myMeasureText(players[pl].getActionBindStr(A_LEFT).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*2, 80, RED);
        this->setBind(opt ,changed, graph, players[pl], players, A_LEFT, 3, pl);
    }

    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20}, 2, RED);
    graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - (graph.getScreenWidth()/20)/2 - graph.getScreenWidth()/20, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, (float)graph.getScreenWidth()/20*3, (float)graph.getScreenWidth()/20})) {
        graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2) {
            if (!this->checkBool(changed))
                changed[4] = true;
        }
    }
    graph.displayText("Bomb", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText("Bomb", 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4 + graph.getScreenHeight()/20*2, 80, RED);
    if (changed[4]) {
        graph.displayText(players[pl].getActionBindStr(A_BOMB).c_str(), (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 - graph.myMeasureText(players[pl].getActionBindStr(A_BOMB).c_str(), 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 + graph.getScreenHeight()/10 + graph.getScreenHeight()/20*4, 80, RED);
        this->setBind(opt ,changed, graph, players[pl], players, A_BOMB, 4, pl);
    }
}

bool menus::checkBool(bool changed[]) {
    for (int i = 0; i < 5; i++) {
        if (changed[i])
            return true;
    }
    return false;
}

void menus::setBind(options &opt, bool changed[], graphLib &graph, binds &current, binds other[], action act, int nb, int pl_id)
{
    int in = 0;
    int temp = 0;
    KeyboardKey key;
    KeyboardKey tempKey;

    temp = graph.myGetKeyPressed();
    if (temp != 0)
        in = temp;
    if (changed[nb]) {
        if(in != 0) {
            key = static_cast<KeyboardKey>(in);
            tempKey = current.getActionBind(act);
            if (current.checkBind(current, other, key)) {
                changed[nb] = false;
                opt.setBind(pl_id, act, tempKey);
                return;
            }
            current.setActionBind(act, key);
            opt.setBind(pl_id, act, key);
            if (current.getActionBind(act) == KEY_NULL || current.getActionBind(act) == KEY_ESCAPE)
                current.setActionBind(act, tempKey);
            changed[nb] = false;
        }
    }
}

menu_ret menus::pauseMenu(options &opt, graphLib &graph)
{
    char title[] = "Pause - Options";
    static bool first = true;
    menu_ret ret = NOPE;
    menu_ret intra_ret = NOPE;
    binds players[4] {opt.getBinds(0), opt.getBinds(1), opt.getBinds(2), opt.getBinds(3)};

    ClearBackground((Color){0, 35, 73});
    if (first) {
        graph.displayText(title, graph.getScreenWidth()/2 - graph.myMeasureText(title, 100)/2, 50, 100, (Color){214, 97, 1, 255});
        this->displayVolMusic(graph, opt);
        this->displayVolSound(graph, opt);
        this->displayPlayerOpt(graph, opt, true);
        this->displayBotOpt(graph, opt, true);
        this->displayFullscreen(graph, opt);
        ret = this->displayReturnArrow(graph);
        if (this->goToKeyBindings(graph))
            first = false;
    } else {
        intra_ret = this->displayReturnArrow(graph);
        this->displayKeyBindingsp1(graph, opt, players);
        this->displayKeyBindingsp2(graph, opt, players);
        if (intra_ret == RETURN)
            first = true;
    }
    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 - graph.getScreenHeight()/5, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18}, 8, RED);
    graph.displayText("Quit", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Quit", 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 - graph.getScreenHeight()/5 + graph.myMeasureText("Restart", 80)/20, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 - graph.getScreenHeight()/5, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18})) {
            graph.displayText("Quit", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Quit", 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 - graph.getScreenHeight()/5 + graph.myMeasureText("Restart", 80)/20, 80, ORANGE);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
            graph.displayText("Quit", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Quit", 80)/2, (float)graph.getScreenHeight()/2 - graph.getScreenHeight()/4 - graph.getScreenHeight()/5 + graph.myMeasureText("Restart", 80)/20, 80, RED);
        if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
            return (RESTART);
    }
    return (ret);
}

menu_ret menus::gameOverMenu(graphLib &graph, std::vector<player> _players, int player_id)
{
    ClearBackground(LIGHTGRAY);
    static std::vector<int> anim = {0, 0, 0, 0};
    static int anime = 0;
    BeginMode3D(camera);
        anime++;
        UpdateModelAnimation(graph.getPlayerModel()[player_id][3], graph.getPlayerAnimations()[3][0], anime);
        graph.drawMyModel(graph.getPlayerModel()[player_id][3], (Vector3) {10, 10, 20}, 3.0f, LIGHTGRAY, (Vector3) {DEG2RAD * 75, 0, 0});
        if (anime >= graph.getPlayerAnimations()[3][0].frameCount)
            anime = 0;
    EndMode3D();
    graph.displayText("Congratulation !", graph.getScreenWidth()/2 - graph.myMeasureText("Congratulation !", 100)/2, 50, 100, (Color){214, 97, 1, 255});
    graph.drawRectEx((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/2, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18}, 8, (Color){0, 35, 73, 255});
    graph.displayText("Exit", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Exit", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, (Color){250, 230, 0, 255});
    if (graph.checkCollision((Rectangle){(float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.getScreenWidth()/15*3/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/2, (float)graph.getScreenWidth()/15*3, (float)graph.getScreenWidth()/18})) {
    graph.displayText("Exit", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Exit", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, RED);
    if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 1)
        graph.displayText("Exit", (float)graph.getScreenWidth()/2 + graph.getScreenWidth()/4 + graph.getScreenWidth()/8 - graph.myMeasureText("Exit", 80)/2, (float)graph.getScreenHeight()/2 + graph.getScreenHeight()/4 + graph.getScreenHeight()/8 - graph.getScreenWidth()/18/3, 80, ORANGE);
    if (graph.stateMouse(MOUSE_BUTTON_LEFT) == 2)
        return (RETURN);
    }
    return NOPE;
}

//SETERS

void menus::setScreenWidth(graphLib &graph)
{
    this->screenWidth = graph.getScreenWidth();
}

void menus::setScreenHeight(graphLib &graph)
{
    this->screenHeight = graph.getScreenHeight();
}

Texture2D *menus::get_sprites()
{
    return _sprites;
}

//Sprites managing functions

void menus::save_sprites_in_array(graphLib &graph)
{
    this->_sprites[0] = graph.loadMyTexture2D("assets/menu/Play_Pos_1.png");
    this->_sprites[1] = graph.loadMyTexture2D("assets/menu/Play_Pos_2.png");
    this->_sprites[2] = graph.loadMyTexture2D("assets/menu/Play_Pos_3.png");
    this->_sprites[3] = graph.loadMyTexture2D("assets/menu/Options_Pos_1.png");
    this->_sprites[4] = graph.loadMyTexture2D("assets/menu/Options_Pos_2.png");
    this->_sprites[5] = graph.loadMyTexture2D("assets/menu/Options_Pos_3.png");
    this->_sprites[6] = graph.loadMyTexture2D("assets/menu/Exit_Pos_1.png");
    this->_sprites[7] = graph.loadMyTexture2D("assets/menu/Exit_Pos_2.png");
    this->_sprites[8] = graph.loadMyTexture2D("assets/menu/Exit_Pos_3.png");
    this->_sprites[9] = graph.loadMyTexture2D("assets/menu/Bomberman.png");
    this->_sprites[10] = graph.loadMyTexture2D("assets/menu/White_Arrow.png");
}

void menus::unloadSprites()
{
        // UnloadTexture(this->_sprites[0]);
}

// int main(void)
// {
//     graphLib graph;
//     options opt;
//     menus menus;
//     menu_ret ret;
//     bool mode = false;
//     menus.setScreenWidth(graph);
//     menus.setScreenHeight(graph);
//     graph.startLib(1920, 1080, 60);
//     while (!graph.getStatusWindow())
//     {
//         graph.startDrawing();
//         graph.clearBack(RAYWHITE);
//         if (!mode) {
//             ret = menus.displayMainMenu(graph);
//         } else {
//             ret = menus.displayOptions(opt, graph);
//         }
//         if (ret == EXIT)
//             break;
//         if (ret == OPTIONS)
//             mode = true;
//         if (ret == RETURN)
//             mode = false;
//         graph.stopDrawing();
//         ret = NOPE;
//     }
//     graph.closeLib();
//     return 0;
// }