/*
** EPITECH PROJECT, 2022
** timer implementation
** File description:
** timer
*/

#include "timer.hpp"

timer::timer()
{
    _started = false;
    _paused = false;
    _pauseTime = 0;
}

void timer::start()
{
    _started = true;
    _clock = std::chrono::high_resolution_clock::now();
}

void timer::reset()
{
    _started = false;
    _paused = false;
    _pauseTime = 0;
}

void timer::pause()
{
    if (_started && !_paused) {
        _paused = true;
        _pauseTime = getElapsedTime();
    }
    else {
        std::cerr << "[CLOCK] Timer is not started or already paused" << std::endl;
    }
}

void timer::unpause()
{
    if (_started && _paused) {
        _paused = false;
        _clock = std::chrono::high_resolution_clock::now();
    }
    else {
        std::cerr << "[CLOCK] Timer is not started or not paused" << std::endl;
    }
}

bool timer::isPaused()
{
    return _paused;
}

bool timer::isStarted()
{
    return _started;
}

double timer::getElapsedTime()
{
    if (_started) {
        if (_paused) {
            std::cout << "[CLOCK] Timer is paused" << std::endl;
            return _pauseTime;
        }
        else {
            return std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - _clock).count();
        }
    }
    else {
        std::cerr << "[CLOCK] Timer is not started" << std::endl;
        return 0;
    }
}