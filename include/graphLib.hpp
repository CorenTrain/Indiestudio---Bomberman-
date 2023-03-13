/*
** EPITECH PROJECT, 2022
** raylib encapsulation header
** File description:
** graphLib
*/

#ifndef GRAPHLIB_HPP_
#define GRAPHLIB_HPP_

#include "core.hpp"
#include "renderables.hpp"
#include "player.hpp"
#include "options.hpp"
#include "powerUp.hpp"

class graphLib {
    public:
        graphLib();
        ~graphLib();
        void startLib(int width, int height, int setfps);
        void closeLib();
        void startDrawing();
        void stopDrawing();
        void begin3D(Camera3D Camera);
        void end3D(Camera3D Camera);
        void clearBack(Color color);
        int stateMouse(MouseButton button);
        int stateKeyboard(KeyboardKey button);
        int getScreenWidth() const;
        int getScreenHeight() const;
        bool getStatusWindow() const;
        bool checkCollision(Rectangle rec);
        Model loadMyModel(std::string modelp, Texture2D texture);
        void drawMyModel(Model m, Vector3 pos, float scale, Color tint, Vector3 rotatexyz);
        void drawRect(Rectangle rec, Color color);
        void drawTexturePro(Texture2D texture, Rectangle rect1,Rectangle rect2, Vector2 origin, float rotation, Color color);
        void drawRectEx(Rectangle rec, float borderSize, Color color);
        void displayText(const char *text, int posX, int posY, int fontSize, Color color);
        int myMeasureText(const char *text, int fontSize);
        const char *myTextFormat(const char *text, ...);
        void display_map(int **map, size_t height, size_t width);
        void displayRenderables(std::vector<renderables *> renderables, options &_options);
        void setCameraPosition(Vector3 pos);
        void setCameraRotation(Vector3 pos);
        Texture2D loadMyTexture2D(std::string texture_path);
        void unloadMyTexture2D(Texture2D texture);
        void displayTexture2D(Texture2D texture, Vector2 pos);
        void freeSound(Sound s);
        void freeTexture(Texture2D txt);
        void freeModel(Model modl);
        Sound loadMySound(std::string path);
        void playMySound(Sound s);
        void setupSound(std::string path, int i);
        void setupTexture(std::string path, int i, int h, int w);
        void setupModel(std::string path, int i, Texture2D texture);
        void setCameraFov(float fov);
        std::map<int, Sound> getAllSounds() const;
        std::map<int, Texture2D> getAllTextures() const;
        std::map<int, std::map<int, Model>> getAllModels() const;
        void levitate_texture(Texture2D t, bool set, int newx, int newy);
        int myGetKeyPressed();
        void myToggleFullscreen();
        Camera getCamera() const;
        int setSkinPlayer(int indexSkin, int playernb);
        std::map<int, Texture2D> getAllSkins() const;
        std::map<int, ModelAnimation *> getPlayerAnimations() const;
        std::map<int, std::map<int, Model>> getPlayerModel() const;
    private:
        int screenWidth;
        int screenHeight;
        int fpsrate;
        Camera camera = {0};
        std::map<int, Sound> AllSounds;
        std::map<int, Texture2D> AllTextures;
        std::map<int, Texture2D> AllSkins;
        std::map<int, std::map<int, Model>> AllModels;
        std::map<int, ModelAnimation *> PlayerAnimations;
        std::map<int, unsigned int> NumberAnimations;
        std::map<int, std::map<int, Model>> PlayerModel;
};

#endif /* !GRAPHLIB_HPP_ */
