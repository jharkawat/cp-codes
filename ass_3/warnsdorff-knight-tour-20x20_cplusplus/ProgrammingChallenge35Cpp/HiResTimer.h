#pragma once

#include <windows.h>

typedef struct {
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
} stopWatch;

class CStopWatch
{
private:
    stopWatch timer;
    LARGE_INTEGER frequency;
    double LIToSecs( LARGE_INTEGER & L);
    bool isStarted;
public:
    CStopWatch();
    void startTimer( );
    void stopTimer( );
    double getElapsedTime();
};
