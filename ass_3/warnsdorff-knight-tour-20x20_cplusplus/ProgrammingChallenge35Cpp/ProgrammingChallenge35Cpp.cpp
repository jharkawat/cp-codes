//-----------------------------------------------------------------------
// <copyright file="ProgrammingChallenge35Cpp.cpp" company="Tiaan.com">
//   Copyright (c) 2010 Tiaan Geldenhuys
//
//   Permission is hereby granted, free of charge, to any person
//   obtaining a copy of this software and associated documentation
//   files (the "Software"), to deal in the Software without
//   restriction, including without limitation the rights to use,
//   copy, modify, merge, publish, distribute, sublicense, and/or
//   sell copies of the Software, and to permit persons to whom the
//   Software is furnished to do so, subject to the following
//   conditions:
//
//   The above copyright notice and this permission notice shall be
//   included in all copies or substantial portions of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//   OTHER DEALINGS IN THE SOFTWARE.
// </copyright>
//-----------------------------------------------------------------------

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include "HiResTimer.h"
#include "KnightTour.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int* sequence = NULL;
    const int RepeatCount = 30000;
    int i;
    double totalSeconds;
    long totalRepeatCount = 0;
    CStopWatch watch;
    watch.startTimer();
    do
    {
        totalRepeatCount += RepeatCount;
        for (i = RepeatCount; i > 0; i--)
        {
            if (sequence != NULL)
            {
                delete[] sequence;
                sequence = NULL;
            }

            sequence = KnightTour::Solve20x20();
        }
    }
    while ((totalSeconds = watch.getElapsedTime()) < 2.5);

    double averageSeconds = totalSeconds / (double)totalRepeatCount;
    cout << "Average Time = " << setiosflags(ios::fixed) << setprecision(12) << averageSeconds << " secs" << endl;

    fstream file("output.txt", ios::out);
    file << "Average Time = " << setiosflags(ios::fixed) << setprecision(12) << averageSeconds << " secs";
    for (int i = 0; i < 400; i++)
    {
        file << endl << sequence[i];
    }
    file.close();

    delete[] sequence;
    sequence = NULL;

    return 0;
}
