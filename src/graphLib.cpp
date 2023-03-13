/*
** EPITECH PROJECT, 2022
** B-YEP-400-REN-4-1-indiestudio-corentin.pilard
** File description:
** graphLib
*/

#include "graphLib.hpp"
#include "raylib.h"

graphLib::graphLib()
{
}

graphLib::~graphLib() // Part commentend causing crash on some OSes
{
    // for (size_t i = 0; i < AllSounds.size(); i++)
    //     freeSound(AllSounds[i]);
    // for (int i = 0; i < AllTextures.size(); i++)
    //     freeTexture(AllTextures[i]);
    // for (int i = 0; i < AllModels.size(); i++)
    //     freeModel(AllModels[i]);
    // for (int i = 0; i < AllSkins.size(); i++)
    //     freeTexture(AllSkins[i]);
    // for (int i = 0; i < PlayerAnimations.size(); i++) {
    //     for (unsigned int j = 0; j < NumberAnimations[i]; j++)
    //         UnloadModelAnimation(PlayerAnimations[i][j]);
    //     RL_FREE(PlayerAnimations[i]);
    // }
    // for (int i = 0; i < PlayerModel.size(); i++)
    //     freeModel(PlayerModel[i]);
    CloseAudioDevice();
}

void graphLib::startDrawing()
{
    BeginDrawing();
}

void graphLib::stopDrawing()
{
    EndDrawing();
}

void graphLib::begin3D(Camera3D Camera)
{
    BeginMode3D(Camera);
}

void graphLib::end3D(Camera3D Camera)
{
    EndMode3D();
}

void graphLib::clearBack(Color color)
{
    ClearBackground(color);
}

void graphLib::startLib(int width, int height, int setfps)
{
    screenWidth = width;
    screenHeight = height;
    fpsrate = setfps;
    InitWindow(width, height, "Bomberman");
    SetExitKey(KEY_NULL);
    SetTargetFPS(setfps);
    camera.position = (Vector3){ 0.0f, 50.0f, 0.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, -10.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 2.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 30.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FREE);
    InitAudioDevice();
    AllModels[0][0] = LoadModel("./assets/wall/StoneBrick.obj");
    AllModels[0][1] = LoadModel("./assets/wall/BedRock.obj");
    AllModels[1][0] = LoadModel("./assets/wall/StoneBrick.obj");
    AllModels[1][1] = LoadModel("./assets/wall/BedRock.obj");
    AllModels[2][0] = LoadModel("./assets/wall/StoneBrick.obj");
    AllModels[2][1] = LoadModel("./assets/wall/BedRock.obj");
    AllModels[3][0] = LoadModel("./assets/wall/StoneBrick.obj");
    AllModels[3][1] = LoadModel("./assets/wall/BedRock.obj");
    AllTextures[0] = LoadTexture("./assets/wall/Bedrock.png");
    SetMaterialTexture(&AllModels[0][1].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[0]);
    SetMaterialTexture(&AllModels[1][1].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[0]);
    SetMaterialTexture(&AllModels[2][1].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[0]);
    SetMaterialTexture(&AllModels[3][1].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[0]);
    AllModels[0][2] = LoadModel("./assets/wall/Grass.obj");
    AllModels[1][2] = LoadModel("./assets/wall/Grass.obj");
    AllModels[2][2] = LoadModel("./assets/wall/Grass.obj");
    AllModels[3][2] = LoadModel("./assets/wall/Grass.obj");
    AllTextures[1] = LoadTexture("./assets/wall/Grass.png");
    SetMaterialTexture(&AllModels[0][2].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[1]);
    SetMaterialTexture(&AllModels[1][2].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[1]);
    SetMaterialTexture(&AllModels[2][2].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[1]);
    SetMaterialTexture(&AllModels[3][2].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[1]);
    AllModels[0][3] = LoadModel("./assets/wall/TNT.obj");
    AllModels[1][3] = LoadModel("./assets/wall/TNT.obj");
    AllModels[2][3] = LoadModel("./assets/wall/TNT.obj");
    AllModels[3][3] = LoadModel("./assets/wall/TNT.obj");
    AllTextures[2] = LoadTexture("./assets/wall/Minecraft_TNT_tex.png");
    SetMaterialTexture(&AllModels[0][3].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[2]);
    SetMaterialTexture(&AllModels[1][3].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[2]);
    SetMaterialTexture(&AllModels[2][3].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[2]);
    SetMaterialTexture(&AllModels[3][3].materials[0], MATERIAL_MAP_DIFFUSE, AllTextures[2]);
    AllModels[0][4] = LoadModel("./assets/player/SteveWaiting.obj");
    AllModels[1][4] = LoadModel("./assets/player/SteveWaiting.obj");
    AllModels[2][4] = LoadModel("./assets/player/SteveWaiting.obj");
    AllModels[3][4] = LoadModel("./assets/player/SteveWaiting.obj");
    AllSkins[0] = LoadTexture("./assets/player/Steve.png");
    SetMaterialTexture(&AllModels[0][4].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    SetMaterialTexture(&AllModels[0][4].materials[1], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    PlayerModel[0][0] = LoadModel("./assets/player/Bombing.iqm");
    PlayerModel[1][0] = LoadModel("./assets/player/Bombing.iqm");
    PlayerModel[2][0] = LoadModel("./assets/player/Bombing.iqm");
    PlayerModel[3][0] = LoadModel("./assets/player/Bombing.iqm");
    SetMaterialTexture(&PlayerModel[0][0].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    PlayerAnimations[0] = LoadModelAnimations("./assets/player/BombingAnim.iqm", &NumberAnimations[0]);
    PlayerModel[0][1] = LoadModel("./assets/player/Walking.iqm");
    PlayerModel[1][1] = LoadModel("./assets/player/Walking.iqm");
    PlayerModel[2][1] = LoadModel("./assets/player/Walking.iqm");
    PlayerModel[3][1] = LoadModel("./assets/player/Walking.iqm");
    SetMaterialTexture(&PlayerModel[0][1].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    PlayerAnimations[1] = LoadModelAnimations("./assets/player/WalkingAnim.iqm", &NumberAnimations[1]);
    PlayerModel[0][2] = LoadModel("./assets/player/Rotating.iqm");
    PlayerModel[1][2] = LoadModel("./assets/player/Rotating.iqm");
    PlayerModel[2][2] = LoadModel("./assets/player/Rotating.iqm");
    PlayerModel[3][2] = LoadModel("./assets/player/Rotating.iqm");
    SetMaterialTexture(&PlayerModel[0][2].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    PlayerAnimations[2] = LoadModelAnimations("./assets/player/RotatingAnim.iqm", &NumberAnimations[2]);
    PlayerModel[0][3] = LoadModel("./assets/player/VictoryJump.iqm");
    PlayerModel[1][3] = LoadModel("./assets/player/VictoryJump.iqm");
    PlayerModel[2][3] = LoadModel("./assets/player/VictoryJump.iqm");
    PlayerModel[3][3] = LoadModel("./assets/player/VictoryJump.iqm");
    SetMaterialTexture(&PlayerModel[0][3].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    SetMaterialTexture(&PlayerModel[1][3].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    SetMaterialTexture(&PlayerModel[2][3].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    SetMaterialTexture(&PlayerModel[3][3].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    PlayerAnimations[3] = LoadModelAnimations("./assets/player/VictoryJumpAnim.iqm", &NumberAnimations[2]);
    PlayerModel[0][4] = LoadModel("./assets/player/VictorySneak.iqm");
    PlayerModel[1][4] = LoadModel("./assets/player/VictorySneak.iqm");
    PlayerModel[2][4] = LoadModel("./assets/player/VictorySneak.iqm");
    PlayerModel[3][4] = LoadModel("./assets/player/VictorySneak.iqm");
    SetMaterialTexture(&PlayerModel[0][4].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[0]);
    PlayerAnimations[4] = LoadModelAnimations("./assets/player/VictorySneakAnim.iqm", &NumberAnimations[2]);
    AllSkins[1] = LoadTexture("./assets/skin/astro.png");
    AllSkins[2] = LoadTexture("./assets/skin/Astro.png");
    AllSkins[3] = LoadTexture("./assets/skin/craftinggaming.png");
    AllSkins[4] = LoadTexture("./assets/skin/Cursesteve.png");
    AllSkins[5] = LoadTexture("./assets/skin/dam1246.png");
    AllSkins[6] = LoadTexture("./assets/skin/judge.png");
    AllSkins[7] = LoadTexture("./assets/skin/Mickey.png");
    AllSkins[8] = LoadTexture("./assets/skin/Parumezan.png");
    setSkinPlayer(0, 1);
    setSkinPlayer(0, 2);
    setSkinPlayer(0, 3);
}

Camera graphLib::getCamera() const
{
    return camera;
}

void graphLib::closeLib()
{
    CloseWindow();
}

void graphLib::setCameraFov(float fov)
{
    camera.fovy = fov;
}

std::map<int, Texture2D> graphLib::getAllSkins() const
{
    return AllSkins;
}

std::map<int, std::map<int, Model>> graphLib::getPlayerModel() const
{
    return PlayerModel;
}

std::map<int, ModelAnimation *> graphLib::getPlayerAnimations() const
{
    return PlayerAnimations;
}

int graphLib::getScreenWidth() const
{
    return screenWidth;
}

int graphLib::getScreenHeight() const
{
    return screenHeight;
}

int graphLib::stateMouse(MouseButton button)
{
    if (IsMouseButtonDown(button))
        return 1;
    if (IsMouseButtonReleased(button))
        return 2;
    return 0;
}

int graphLib::stateKeyboard(KeyboardKey button)
{
    if (IsKeyPressed(button))
        return 1;
    if (IsKeyDown(button))
        return 2;
    return 0;
}

bool graphLib::getStatusWindow() const
{
    return WindowShouldClose();
}

int graphLib::setSkinPlayer(int indexSkin, int playernum)
{
    if (indexSkin >= (int)AllSkins.size())
        indexSkin = 0;
    if (indexSkin == -1)
        indexSkin = AllSkins.size() - 1;
    std::cout << "setSkinPlayer2: " << indexSkin << std::endl;
    SetMaterialTexture(&AllModels[playernum][4].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[indexSkin]);
    SetMaterialTexture(&AllModels[playernum][4].materials[1], MATERIAL_MAP_DIFFUSE, AllSkins[indexSkin]);
    SetMaterialTexture(&PlayerModel[playernum][0].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[indexSkin]);
    SetMaterialTexture(&PlayerModel[playernum][1].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[indexSkin]);
    SetMaterialTexture(&PlayerModel[playernum][2].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[indexSkin]);
    SetMaterialTexture(&PlayerModel[playernum][3].materials[0], MATERIAL_MAP_DIFFUSE, AllSkins[indexSkin]);
    return indexSkin;
}

bool graphLib::checkCollision(Rectangle rec)
{
    if (CheckCollisionPointRec(GetMousePosition(), rec))
        return true;
    return false;
}

Model graphLib::loadMyModel(std::string modelpath, Texture2D texture)
{
    Model model = LoadModel(modelpath.c_str());
    SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    return model;
}

void graphLib::drawMyModel(Model m, Vector3 pos, float scale, Color tint, Vector3 rotatexyz)
{
    m.transform = MatrixRotateXYZ(rotatexyz);
    DrawModel(m, pos,scale, tint);
}

void graphLib::drawRect(Rectangle rec, Color color)
{
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
}

void graphLib::drawRectEx(Rectangle rec, float borderSize, Color color)
{
    DrawRectangleLinesEx(rec, borderSize, color);
}

void graphLib::drawTexturePro(Texture2D texture, Rectangle rect1,Rectangle rect2, Vector2 origin, float rotation, Color color)
{
    DrawTexturePro(texture, rect1, rect2, origin, rotation, color);
}

void graphLib::displayText(const char *text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text, posX, posY, fontSize, color);
}

int graphLib::myMeasureText(const char *text, int fontSize)
{
    return (MeasureText(text, fontSize));
}

const char *graphLib::myTextFormat(const char *text, ...)
{
    static char str[256];
    va_list ap;

    va_start(ap, text);
    std::vsprintf(str, text, ap);
    va_end(ap);
    return (str);
}


void graphLib::display_map(int **map, size_t height, size_t width)
{
    Vector3 cubePosition = { 0.5f, 0.5f, 0.5f };
    ClearBackground(BLACK);
    BeginMode3D(camera);
    for (size_t i = 0; i != height; i++) {
        for (size_t j = 0; j != width; j++) {
            if (map[i][j] == 2) {
                cubePosition = {(float)(j + 0.5), 0.5f, (float) (i + 0.5f)};
                DrawModel(AllModels[0][0], cubePosition, 0.5f, WHITE);
            }
            if (map[i][j] == 1) {
                cubePosition = {(float)(j + 0.5), 0.5f, (float) (i + 0.5f)};
                DrawModel(AllModels[0][1], cubePosition, 0.5f, WHITE);
            }
            if (map[i][j] == 0) {
                cubePosition = {(float)(j + 0.5), -0.5f, (float) (i + 0.5f)};
                DrawModel(AllModels[0][2], cubePosition, 0.5f, WHITE);
            }
        }
    }
    EndMode3D();
}

void graphLib::displayRenderables(std::vector<renderables *> objects, options &_options)
{
    pos objectPos;
    Vector3 truePos;
    player *currPlayer;
    size_t playernb = 0;
    powerUp *currPowerUp;
    static std::vector<Vector3>rota = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    static std::vector<int>anime = {0, 0, 0, 0};
    static std::vector<int>bombing = {0, 0, 0, 0};

    BeginMode3D(camera);
    for (int i = 0; i < objects.size(); i++) {
        objectPos = objects[i]->getPos();
        truePos = {(float)objectPos.getPosX() + 0.5f, 0.5f, (float)objectPos.getPosY() + 0.5f};
        if (objects[i]->getRenderType() == PLAYER) {
            currPlayer = static_cast<player *>(objects[i]);
            playernb = currPlayer->getId();
            truePos.x = currPlayer->getScreenPos().getPosX() + 0.5f;
            truePos.z = currPlayer->getScreenPos().getPosY() + 0.5f;
            if (stateKeyboard(_options.getBinds(playernb).getActionBind(A_BOMB)) == 1)
                bombing[playernb] = 1;
            if (bombing[playernb]) {
                anime[playernb]++;
                UpdateModelAnimation(PlayerModel[playernb][0], PlayerAnimations[0][0], anime[playernb]);
                drawMyModel(PlayerModel[playernb][0], truePos, 0.595f, LIGHTGRAY, rota[playernb]);
                if (anime[playernb] >= PlayerAnimations[0][0].frameCount) {
                    anime[playernb] = 0;
                    bombing[playernb] = 0;
                }
            } else if (stateKeyboard(_options.getBinds(playernb).getActionBind(A_UP)) != 0) {
                rota[playernb].y = DEG2RAD  * 180;
                anime[playernb]++;
                UpdateModelAnimation(PlayerModel[playernb][1], PlayerAnimations[1][0], anime[playernb]);
                drawMyModel(PlayerModel[playernb][1], truePos, 0.6328f, LIGHTGRAY, rota[playernb]);
                if (anime[playernb] >= PlayerAnimations[1][0].frameCount)
                    anime[playernb] = 0;
            } else if (stateKeyboard(_options.getBinds(playernb).getActionBind(A_DOWN)) != 0) {
                rota[playernb].y = DEG2RAD  * 0;
                anime[playernb]++;
                UpdateModelAnimation(PlayerModel[playernb][1], PlayerAnimations[1][0], anime[playernb]);
                drawMyModel(PlayerModel[playernb][1], truePos, 0.6328f, LIGHTGRAY, rota[playernb]);
                if (anime[playernb] >= PlayerAnimations[1][0].frameCount)
                    anime[playernb] = 0;
            } else if (stateKeyboard(_options.getBinds(playernb).getActionBind(A_RIGHT)) != 0) {
                rota[playernb].y = DEG2RAD  * 270;
                anime[playernb]++;
                UpdateModelAnimation(PlayerModel[playernb][1], PlayerAnimations[1][0], anime[playernb]);
                drawMyModel(PlayerModel[playernb][1], truePos, 0.6328f, LIGHTGRAY, rota[playernb]);
                if (anime[playernb] >= PlayerAnimations[1][0].frameCount)
                    anime[playernb] = 0;
            } else if (stateKeyboard(_options.getBinds(playernb).getActionBind(A_LEFT)) != 0) {
                rota[playernb].y = DEG2RAD  * 90;
                anime[playernb]++;
                UpdateModelAnimation(PlayerModel[playernb][1], PlayerAnimations[1][0], anime[playernb]);
                drawMyModel(PlayerModel[playernb][1], truePos, 0.6328f, LIGHTGRAY, rota[playernb]);
                if (anime[playernb] >= PlayerAnimations[1][0].frameCount)
                    anime[playernb] = 0;
            } else {
                drawMyModel(AllModels[playernb][4], truePos, 1.0f, WHITE, rota[playernb]);
                anime[playernb] = 0;
            }
            playernb++;
        }
        if (objects[i]->getRenderType() == BOMB)
            DrawModel(AllModels[0][3], truePos, 3.0f, WHITE);
        if (objects[i]->getRenderType() == POWERUP) {
            currPowerUp = static_cast<powerUp *>(objects[i]);
            if (currPowerUp->getPowerUpType() == P_SPEED)
                DrawCube(truePos, 0.5f, 0.5f, 0.5f, BLUE);
            if (currPowerUp->getPowerUpType() == P_CAPCITY)
                DrawCube(truePos, 0.5f, 0.5f, 0.5f, RED);
            if (currPowerUp->getPowerUpType() == P_POWER)
                DrawCube(truePos, 0.5f, 0.5f, 0.5f, GREEN);
        }
    }
    EndMode3D();
}

void graphLib::setCameraPosition(Vector3 pos)
{
    camera.position = pos;
}

void graphLib::setCameraRotation(Vector3 pos)
{
    camera.target = pos;
}

void graphLib::displayTexture2D(Texture2D texture, Vector2 pos)
{
    DrawTexture(texture, (int)pos.x, (int)pos.y, WHITE);
}

Texture2D graphLib::loadMyTexture2D(std::string texture_path)
{
    Texture2D texture = LoadTexture(texture_path.c_str());
    return texture;
}

void graphLib::unloadMyTexture2D(Texture2D texture)
{
    UnloadTexture(texture);
}

void graphLib::freeSound(Sound s)
{
    UnloadSound(s);
}

Sound graphLib::loadMySound(std::string path)
{
    Sound s = LoadSound(path.c_str());
    return s;
}

void graphLib::freeTexture(Texture2D texture)
{
    UnloadTexture(texture);
}

void graphLib::freeModel(Model mdl)
{
    UnloadModel(mdl);
}

void graphLib::playMySound(Sound s)
{
    PlaySound(s);
}

std::map<int, Sound> graphLib::getAllSounds() const
{
    return AllSounds;
}

std::map<int, Texture2D> graphLib::getAllTextures() const
{
    return AllTextures;
}

std::map<int, std::map<int, Model>> graphLib::getAllModels() const
{
    return AllModels;
}

void graphLib::setupSound(std::string path, int i)
{
    AllSounds[i] = loadMySound(path);
}

void graphLib::setupTexture(std::string path, int i, int height, int width)
{
    AllTextures[i] = loadMyTexture2D(path);
}

void graphLib::setupModel(std::string path, int i, Texture2D texture)
{
    AllModels[0][i] = loadMyModel(path, texture);
}

void graphLib::levitate_texture(Texture2D t, bool set, int newx, int newy)
{
    static int x = 0;
    static int y = 0;
    static bool speed = false;
    static int max_y = 50;
    static int min_y = 0;

    if (set) {
        x = newx;
        y = newy;
        max_y = y + 50;
        min_y = y - 50;
        return;
    }
    // DrawTexture(t, x, y, WHITE);
    DrawTexturePro(t, {0, 0, (float)t.width, (float)t.height}, {(float)x, (float)y, (float)(t.width*1.7), (float)(t.height*1.7)}, {0, 0}, 0, WHITE);
    if (y > max_y)
        speed = false;
    if (y < min_y)
        speed = true;
    if (speed == true)
        y++;
    else
        y--;
}

int graphLib::myGetKeyPressed()
{
    return GetKeyPressed();
}

void graphLib::myToggleFullscreen()
{
    ToggleFullscreen();
}
