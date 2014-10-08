// Developed for PSET4 cs50x SPR 14.  Testing init bricks.  Tyson Frederick.  10/7/2014
// Completed under cs50x.  Instructed by David J. Malan of Harvard University, SPR 2014.

// INCLUDES STANFORD PORTABLE LIBRARY (SPL)
// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

#define PADDLEWIDTH 80
#define PADDLEHEIGHT 5

#define PADDLEY 280

// 20 % used for offset and scaling of the Y blocks to top 20% of screen.
#define PERC .2

// number of rows of bricks
#define ROWS 8

// number of columns of bricks
#define COLS 10

//PROTOTYPES
//Initializing and instantiating bricks.
void initBricks(GWindow window);

// init ball and paddle, return Gobject to window.
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);


int main(void)
{
    
    // instantiate window
    GWindow window = newGWindow(480, 720);

    // initialize and instantiate bricks in the given window.
    initBricks(window);

    // instantiate paddle
    GRect paddle = newGRect(((getWidth(window)/2)- (PADDLEWIDTH/2)), (getHeight(window) - PADDLEWIDTH) , PADDLEWIDTH, PADDLEHEIGHT);

    // add paddle to window
    add(window, paddle);

    // follow mouse forever
    while (true)
    {
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows top cursor
                double x = getX(event);
                double y = (getHeight(window) - PADDLEWIDTH);
                setLocation(paddle, x, y);
            }
        }
    }
}

void initBricks(GWindow window)
{

    double xloc = ((getWidth(window)/ COLS)); 
    double yloc = ((getHeight(window)/ ROWS) * PERC);
    
    double xlen = xloc - (xloc * PERC);
    double ylen = yloc - (yloc * PERC);

    
    for (int i = 0; i <= (ROWS - 2); i++)
    {
        
        for (int j = 0; j <= (COLS -2 ) ; j++)
        {            
            
            // TODO COMMENT 
            GRect brick = newGRect((((xloc*j)+ (xloc * PERC))+ 15), (((yloc*i) + (yloc * .1))+15), xlen + 4  , ylen);
            add(window, brick);
        }
    }
}
