#include "StdAfx.h"
#include "HiResTimer.h"

#include <windows.h>

double CStopWatch::LIToSecs( LARGE_INTEGER & L) {
    return ((double)L.QuadPart /(double)frequency.QuadPart);
}

CStopWatch::CStopWatch(){
    timer.start.QuadPart=0;
    timer.stop.QuadPart=0;	
    isStarted = false;
    QueryPerformanceFrequency( &frequency );
}

void CStopWatch::startTimer( ) {
    isStarted = true;
    QueryPerformanceCounter(&timer.start);
}

void CStopWatch::stopTimer( ) {
    QueryPerformanceCounter(&timer.stop);
    isStarted = false;
}


double CStopWatch::getElapsedTime() {
    LARGE_INTEGER time;
    if (isStarted)
        QueryPerformanceCounter(&timer.stop);
    time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
    return LIToSecs( time) ;
}
