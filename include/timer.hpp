/*
** EPITECH PROJECT, 2022
** timer class
** File description:
** timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include "core.hpp"

class timer {
    public:
        timer();
        ~timer() = default;
        void start();
        void reset();
        void pause();
        void unpause();
        bool isStarted();
        bool isPaused();
        double getElapsedTime();
    private:
        bool _started;
        bool _paused;
        double _pauseTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> _clock;
};

#endif /* !TIMER_HPP_ */
