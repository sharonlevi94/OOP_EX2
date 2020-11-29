#ifndef _Location_H
#define _Location_H
#pragma once

/*----------------------------------------------------------------------------
 * Location
 * The struct contain the row and the col location on the stage and map.
*/
struct Location
{
    //---------------------- explict of the struct----------------------------
    explicit Location(int row = 0, int col = 0) : row(row), col(col) {}
    //------------------------ members section -------------------------------

    int row;
    int col;
};
//--------------------------- prototypes section -----------------------------
bool operator==(const Location& location1, const Location& location2);
bool inRectangle(const Location& topLeft, const Location& botRight,
    const Location& location);
bool isLeftOf(const Location& testLoc, const Location& loc);
bool isRightOf(const Location& testLoc, const Location& loc);
bool isAboveOf(const Location& testLoc, const Location& loc);
bool isBelowOf(const Location& testLoc, const Location& loc);
#endif // !_Location_H
