/*
** EPITECH PROJECT, 2022
** engine implementation
** File description:
** gengine
*/

#include "gengine.hpp"

gengine::gengine()
{
    pauseMode = false;
}

void gengine::safeVectorCat(std::vector<pos> &dest, std::vector<pos> src)
{
    if (src.empty())
        return;
    for (size_t i = 0; i < src.size(); i++) {
        if (std::find(dest.begin(), dest.end(), src[i]) == dest.end())
            dest.push_back(src[i]);
    }
}

std::vector<renderables *> gengine::regroupRenderables()
{
    std::vector<renderables *> objects;

    for (auto &i : _players)
        objects.push_back(&i);
    for (auto &i : _bombs)
        objects.push_back(&i);
    for (auto &i : _powerUps)
        objects.push_back(&i);
    return objects;
}

size_t gengine::countPlayerBombs(size_t playerNbr)
{
    size_t count = 0;

    for (auto &i : _bombs) {
        if (i.getOwnerID() == playerNbr)
            count++;
    }
    return count;
}

void gengine::initPlayers()
{
    for (size_t i = 0; i < _options.getPlayerNbr(); i++) {
        _players.push_back(player(i));
        switch (i) {
            case 0:
                _players[i].setScreenPos(dpos(static_cast<double>(POS1.getPosX()), static_cast<double>(POS1.getPosY())));
                _players[i].setPos(POS1);
                break;
            case 1:
                _players[i].setScreenPos(dpos(static_cast<double>(POS2.getPosX()), static_cast<double>(POS2.getPosY())));
                _players[i].setPos(POS2);
                break;
            case 2:
                _players[i].setScreenPos(dpos(static_cast<double>(POS3.getPosX()), static_cast<double>(POS3.getPosY())));
                _players[i].setPos(POS3);
                break;
            case 3:
                _players[i].setScreenPos(dpos(static_cast<double>(POS4.getPosX()), static_cast<double>(POS4.getPosY())));
                _players[i].setPos(POS4);
                break;
            default:
                break;
        }
    }
}

void gengine::run()
{
    menu_ret ret;
    bool mode = false;
    bool gaming = false;
    bool skin = false;
    bool end = false;
    int loop_ret = -1;
    static bool init = false;

    _map = _mapGenerator.GetMap();
    if (_map.getIntMap() == nullptr)
        throw gengineError("Map not generated", __LINE__);
    if (!init) {

        Vector3 cameraPos = {static_cast<float>(_map.getSizeX() / 2), 50.0f , static_cast<float>(_map.getSizeY() * 2)};
        Vector3 cameraRot = {static_cast<float>(_map.getSizeX() / 2), -20.0f, 0.0f};

        _menus.setScreenWidth(_graphLib);
        _menus.setScreenHeight(_graphLib);
        _graphLib.startLib(1920, 1080, 60);
        _graphLib.setCameraPosition(cameraPos);
        _graphLib.setCameraRotation(cameraRot);
        _menus.camera = _graphLib.getCamera();
        init = true;
    }
    _players.clear();
    while (!_graphLib.getStatusWindow())
    {
        _graphLib.startDrawing();
        _graphLib.clearBack(BLACK);
        if (!end) {
            if (!gaming) {
                if (!mode)
                    ret = _menus.displayMainMenu(_graphLib);
                else if (mode)
                    ret = _menus.displayOptions(_options, _graphLib);

            }
            if (gaming) {
                if (!skin) {
                    ret = _menus.SkinSelection(_graphLib, _options, _players);
                    if (_players.size() != _options.getPlayerNbr()) {
                        _players.clear();
                        initPlayers();
                        _powerUps.push_back(powerUp(pos(1, 2), P_CAPCITY));
                        _powerUps.push_back(powerUp(pos(_map.getSizeX() - 2, 2), P_POWER));
                        _powerUps.push_back(powerUp(pos(2, _map.getSizeY() - 2), P_CAPCITY));
                        _powerUps.push_back(powerUp(pos(_map.getSizeX() - 3, _map.getSizeY() - 2), P_POWER));
                    }
                }
                else if (skin) {
                    if (!pauseMode) {
                        loop_ret = gameLoop();
                        if (loop_ret > -1) {
                            _graphLib.setCameraFov(30.0f);
                            end = true;
                        }
                    } else if (pauseMode) {
                        if (_menus.pauseMenu(_options, _graphLib) == RETURN) {
                            pauseMode = false;
                        } else if (_menus.pauseMenu(_options, _graphLib) == RESTART) {
                            pauseMode = false;
                            return (this->run());
                        }
                    }
                }
            }
        } else if (end) {
            if (_menus.gameOverMenu(_graphLib, _players, loop_ret) == RETURN) {
                return (this->run());
            }
        }
        _graphLib.stopDrawing();
        if (ret == OPTIONS)
            mode = true;
        else if (ret == RETURN)
            mode = false;
        else if (ret == SKIN)
            gaming = true;
        else if (ret == BACK)
            gaming = false;
        else if (ret == PLAY) {
            _graphLib.setCameraFov(23.0f);
            skin = true;
        }
        else if (ret == EXIT)
            break;
        ret = NOPE;
    }
    _graphLib.closeLib();
}

int gengine::gameLoop()
{
    size_t playersCount = _players.size();

    if (playersCount == 0)
        return -2;
    if (playersCount == 1)
        return _players[0].getId();
    updateBombs();
    updateItems();
    for (size_t i = 0; i < playersCount; i++)
        updatePlayers(i);
    _graphLib.display_map(_map.getIntMap(), _map.getSizeY(), _map.getSizeX());
    _graphLib.displayRenderables(regroupRenderables(),  _options);
    _explosions.clear();
    return -1;
}

void gengine::updateBombs()
{
    if (_bombs.empty())
        return;
    for (size_t i = 0; i < _bombs.size(); i++) {
        if (_bombs[i].hasExploded()) {
            safeVectorCat(_explosions, _map.explode(_bombs[i]));
            _bombs.erase(_bombs.begin() + i);
            i--;
        }
    }
}

void gengine::updateItems()
{
    pos playerPos;

    for (auto &i : _players) {
        playerPos = i.getPos();
        for (auto &j : _powerUps) {
            if (playerPos == j.getPos()) {
                i.powerUp(j.getPowerUpType());
                _powerUps.erase(std::find(_powerUps.begin(), _powerUps.end(), j));
            }
        }
    }
}

void gengine::updatePlayers(size_t playerNbr)
{
    dpos playerScreenPos = _players[playerNbr].getScreenPos();
    dpos nextScreenPos = playerScreenPos;
    double castedSpeed = static_cast<double>(_players[playerNbr].getSpeed());
    double calc = castedSpeed / 8.0;

    for (size_t i = 0; i < _explosions.size(); i++) {
        if (_players[playerNbr].getPos() == _explosions[i]) {
            _players.erase(_players.begin() + playerNbr);
            return;
        }
    }
    if (_graphLib.stateKeyboard(_options.getBinds(_players[playerNbr].getId()).getActionBind(A_LEFT)) != 0)
        movePlayer(playerNbr, playerScreenPos, dpos(-calc, 0.0));
    if (_graphLib.stateKeyboard(_options.getBinds(_players[playerNbr].getId()).getActionBind(A_RIGHT)) != 0)
        movePlayer(playerNbr, playerScreenPos, dpos(calc, 0.0));
    if (_graphLib.stateKeyboard(_options.getBinds(_players[playerNbr].getId()).getActionBind(A_UP)) != 0)
        movePlayer(playerNbr, playerScreenPos, dpos(0.0, -calc));
    if (_graphLib.stateKeyboard(_options.getBinds(_players[playerNbr].getId()).getActionBind(A_DOWN)) != 0)
        movePlayer(playerNbr, playerScreenPos, dpos(0.0, calc));
    if (_graphLib.stateKeyboard(_options.getBinds(_players[playerNbr].getId()).getActionBind(A_BOMB)) == 1) {
        if (countPlayerBombs(playerNbr) < _players[playerNbr].getCapacity())
            _bombs.push_back(bomb(_players[playerNbr].getPos(), _players[playerNbr].getPower(), 3, playerNbr));
    }
    if (_graphLib.stateKeyboard(KEY_ESCAPE) == 2) {
        pauseMode = true;
    }
}

double gengine::getPosDifference(double diff)
{
    double dec = std::modf(diff, &diff);

    return std::fabs(dec);
}

void gengine::movePlayer(size_t playerNbr, dpos playerScreenPos, dpos direction)
{
    dpos calcpos = playerScreenPos;
    pos nextPos;
    pos truePos;
    double diffx = 0.0;
    double diffy = 0.0;

    calcpos += direction;
    diffx = getPosDifference(playerScreenPos.getPosX());
    diffy = getPosDifference(playerScreenPos.getPosY());
    if (diffx == 0.0 && diffy == 0.0) {
        truePos = playerScreenPos;
        _players[playerNbr].setPos(truePos);
        if (direction.getPosX() < 0 || direction.getPosY() < 0)
            nextPos = calcpos;
        else {
            calcpos.ceilAll();
            nextPos = calcpos;
        }
        if (_map.getMapElement(nextPos) == M_EMPTY) {
            playerScreenPos += direction;
            _players[playerNbr].setScreenPos(playerScreenPos);
        }
    }
    else {
        diffx = getPosDifference(calcpos.getPosX());
        diffy = getPosDifference(calcpos.getPosY());
        if (diffx != 0.0 && diffy != 0.0)
            return;
        playerScreenPos += direction;
        _players[playerNbr].setScreenPos(playerScreenPos);
    }
}
