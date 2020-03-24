//-----------------------------------------------------------------------
// <copyright file="KnightTour.cpp" company="Tiaan.com">
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

#include "StdAfx.h"
#include "KnightTour.h"

#include <assert.h>
#include <cstring>

// Solves the 20x20 Knight's Tour of Programming Challenge 35 using Warnsdorff's Algorithm.
int* KnightTour::Solve20x20()
{
    static const int SideLength = 20;
    static const int SequenceLength = SideLength * SideLength;
    static const int WidthShift = 5;
    static const int WidthMask = 0x1F;
    static const int WidthCount = 32;
    static const int HeightCount = 28;
    static const int MarginCount = 4;
    static const int TotalCount = WidthCount * HeightCount;
    static const int SquareOneOffset = 1;
    static const int TopLeftPosition = MarginCount | (MarginCount << WidthShift);
    static const int DirectionNNW = -1 + (-2 * WidthCount);
    static const int DirectionNNE = +1 + (-2 * WidthCount);
    static const int DirectionWNW = -2 + (-1 * WidthCount);
    static const int DirectionENE = +2 + (-1 * WidthCount);
    static const int DirectionWSW = -2 + (+1 * WidthCount);
    static const int DirectionESE = +2 + (+1 * WidthCount);
    static const int DirectionSSW = -1 + (+2 * WidthCount);
    static const int DirectionSSE = +1 + (+2 * WidthCount);
    static const int PickScoreUndefined = 15;

    int currentPosition;
    int testScore, testPosition, *testPositionPtr;
    int pickScore, pickPosition = 0;
    int sequenceCounter = 0;
    int* sequence = new int[SequenceLength];
    int* isAvailable = new int[TotalCount];

    memset(isAvailable, 0, (TotalCount * sizeof(*isAvailable)));
    for (int y = 0, *i = &isAvailable[TopLeftPosition]; y < SideLength; y++)
    {
        for (int x = 0; x < SideLength; x++)
        {
            *i++ = 1;
        }

        i += (WidthCount - SideLength);
    }

    currentPosition = TopLeftPosition;
    isAvailable[currentPosition] = 0;
    sequence[sequenceCounter++] = SquareOneOffset;
    while (sequenceCounter < SequenceLength)
    {
        pickScore = PickScoreUndefined;
#ifdef _DEBUG
        pickPosition = 0;
#endif
        testPosition = currentPosition + DirectionNNW;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +
                isAvailable[testPosition + DirectionNNE] +
                isAvailable[testPosition + DirectionWNW] +
                isAvailable[testPosition + DirectionENE] +
                isAvailable[testPosition + DirectionWSW] +
                isAvailable[testPosition + DirectionESE] +
                isAvailable[testPosition + DirectionSSW];  // Ignore DirectionSSE
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionNNE;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +
                isAvailable[testPosition + DirectionNNE] +
                isAvailable[testPosition + DirectionWNW] +
                isAvailable[testPosition + DirectionENE] +
                isAvailable[testPosition + DirectionWSW] +
                isAvailable[testPosition + DirectionESE] +  // Ignore DirectionSSW
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionWNW;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +
                isAvailable[testPosition + DirectionNNE] +
                isAvailable[testPosition + DirectionWNW] +
                isAvailable[testPosition + DirectionENE] +
                isAvailable[testPosition + DirectionWSW] +  // Ignore DirectionESE
                isAvailable[testPosition + DirectionSSW] +
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionENE;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +
                isAvailable[testPosition + DirectionNNE] +
                isAvailable[testPosition + DirectionWNW] +
                isAvailable[testPosition + DirectionENE] +  // Ignore DirectionWSW
                isAvailable[testPosition + DirectionESE] +
                isAvailable[testPosition + DirectionSSW] +
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionWSW;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +
                isAvailable[testPosition + DirectionNNE] +
                isAvailable[testPosition + DirectionWNW] +  // Ignore DirectionENE
                isAvailable[testPosition + DirectionWSW] +
                isAvailable[testPosition + DirectionESE] +
                isAvailable[testPosition + DirectionSSW] +
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionESE;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +
                isAvailable[testPosition + DirectionNNE] +  // Ignore DirectionWNW
                isAvailable[testPosition + DirectionENE] +
                isAvailable[testPosition + DirectionWSW] +
                isAvailable[testPosition + DirectionESE] +
                isAvailable[testPosition + DirectionSSW] +
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionSSW;
        if (isAvailable[testPosition] != 0)
        {
            testScore =
                isAvailable[testPosition + DirectionNNW] +  // Ignore DirectionNNE
                isAvailable[testPosition + DirectionWNW] +
                isAvailable[testPosition + DirectionENE] +
                isAvailable[testPosition + DirectionWSW] +
                isAvailable[testPosition + DirectionESE] +
                isAvailable[testPosition + DirectionSSW] +
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

        testPosition = currentPosition + DirectionSSE;
        if (isAvailable[testPosition] != 0)
        {
            testScore =  // Ignore DirectionNNW
                isAvailable[testPosition + DirectionNNE] +
                isAvailable[testPosition + DirectionWNW] +
                isAvailable[testPosition + DirectionENE] +
                isAvailable[testPosition + DirectionWSW] +
                isAvailable[testPosition + DirectionESE] +
                isAvailable[testPosition + DirectionSSW] +
                isAvailable[testPosition + DirectionSSE];
            if (testScore < pickScore)
            {
                pickScore = testScore;
                pickPosition = testPosition;
            }
        }

#ifdef _DEBUG
        assert(pickScore != PickScoreUndefined);
        assert(pickPosition != 0);
        assert(isAvailable[pickPosition] != 0);
#endif
        currentPosition = pickPosition;
        isAvailable[currentPosition] = 0;
        pickPosition -= (TopLeftPosition - SquareOneOffset);
        sequence[sequenceCounter++] =
            (pickPosition & WidthMask) + (SideLength * (pickPosition >> WidthShift));
    }

    delete[] isAvailable;
    return sequence;
}
