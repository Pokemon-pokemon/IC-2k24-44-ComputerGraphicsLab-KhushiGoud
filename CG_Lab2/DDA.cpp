#include <iostream>
#include <graphics.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x1, y1, x2, y2;
    float dx, dy, steps;
    float x_increment, y_increment;
    float x, y;

    // Input endpoints
    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    // Calculate differences
    dx = x2 - x1;
    dy = y2 - y1;

    // Calculate number of steps
    steps = max(abs(dx), abs(dy));

    // Set line color
    setcolor(WHITE);

    if (steps == 0)
    {
        putpixel(round(x1), round(y1), WHITE);
    }
    else
    {
        // Calculate increments
        x_increment = dx / steps;
        y_increment = dy / steps;

        x = x1;
        y = y1;

        // Draw the line using DDA
        for (int i = 0; i <= steps; i++)
        {
            putpixel(round(x), round(y), WHITE);

            x += x_increment;
            y += y_increment;
        }
    }

    cout << "\nDDA Line Drawing completed!";
    cout << "\nPress any key in the graphics window to exit.";

    getch();
    closegraph();

    return 0;
}