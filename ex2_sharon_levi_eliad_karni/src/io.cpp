//---------------------------- include section -------------------------------
#include "io.h"
#include <Windows.h>

//---------------------------- define section---------------------------------
#define USE_CONIO 1
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
//------------------------------ undef section -------------------------------
#undef VC_EXTRALEAN
#undef WIN32_LEAN_AND_MEAN

#if USE_CONIO
//---------------------------- include section -------------------------------
#include <conio.h>
//---------------------------- keyboard section ------------------------------
int Keyboard::getch()
{
    return _getch();
}

#else // USE_CONIO
//---------------------------- include section -------------------------------
#include <vector>
#include <optional>
//---------------------------- namespce section ------------------------------
namespace
{
    auto buffer = std::vector<INPUT_RECORD>();
    auto console = GetStdHandle(STD_INPUT_HANDLE);
    auto specialKeyBuffer = std::optional<int>();
    auto keyEventBuffer = std::optional<KEY_EVENT_RECORD>();

    void fillBuffer()
    {
        buffer.resize(128);
        auto actuallyRead = DWORD(0);
        ReadConsoleInputA(console,
            &buffer[0],
            static_cast<DWORD>(buffer.size()),
            &actuallyRead);
        buffer.resize(actuallyRead);
    }

    KEY_EVENT_RECORD getKeyEvent()
    {
        while (true)
        {
            while (buffer.empty())
            {
                fillBuffer();
            }

            auto event = buffer.front();
            buffer.erase(buffer.begin());

            if (event.EventType != KEY_EVENT)
            {
                continue;
            }

            if (!event.Event.KeyEvent.bKeyDown)
            {
                continue;
            }
            return event.Event.KeyEvent;
        }
    }
}
//---------------------------- keyboard section ------------------------------
int Keyboard::getch()
{
    while (true)
    {
        if (specialKeyBuffer)
        {
            auto res = specialKeyBuffer.value();
            specialKeyBuffer.reset();
            return res;
        }

        if (!keyEventBuffer || !keyEventBuffer->wRepeatCount)
        {
            keyEventBuffer = getKeyEvent();
        }

        --keyEventBuffer->wRepeatCount;

        if (keyEventBuffer->uChar.AsciiChar)
        {
            return keyEventBuffer->uChar.AsciiChar;
        }

        if (keyEventBuffer->dwControlKeyState & ENHANCED_KEY)
        {
            switch (keyEventBuffer->wVirtualKeyCode)
            {
            case VK_LEFT:
                specialKeyBuffer = KB_LEFT;
                break;
            case VK_UP:
                specialKeyBuffer = KB_UP;
                break;
            case VK_RIGHT:
                specialKeyBuffer = KB_RIGHT;
                break;
            case VK_DOWN:
                specialKeyBuffer = KB_DOWN;
                break;
            default:
                continue;
            }
            return SPECIAL_KEY;
        }
    }
}

#endif // USE_CONIO
//---------------------------- namespce section ------------------------------
namespace
{
COORD locToCoord(const Location& loc)
{
    auto res = COORD{};
    res.Y = (SHORT)loc.row;
    res.X = (SHORT)loc.col;
    return res;
}
}
//----------------------------- screen section -------------------------------
void Screen::resetLocation()
{
    setLocation(Location(0, 0));
}

void Screen::setLocation(const Location& location)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), locToCoord(location));
}
