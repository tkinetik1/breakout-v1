// Developed for PSET4 cs50x SPR 14.  Testing init bricks.  Tyson Frederick.  10/7/2014
// Completed under cs50x.  Instructed by David J. Malan of Harvard University.

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

#define PADDLEWIDTH 40
#define PADDLEHEIGHT 20

#define PADDLEY 280

#define PERCHEIGHT .3

// .2 %
#define PERC .2

#define PERCWIDTH .05



// number of rows of bricks
#define ROWS 12

// number of columns of bricks
#define COLS 10

// initialize and instantiate bricks
void initBricks(GWindow window);

GOval initBall(GWindow window);
GRect initPaddle(GWindow window);


int main(void)
{
    
    // instantiate window
    GWindow window = newGWindow(520, 500);

    // initialize and instantiate bricks in the given window.
    initBricks(window);

    
    
    // instantiate circle
    GRect paddle = newGRect(((getWidth(window)/2)- (PADDLEWIDTH/2)), (getHeight(window) - PADDLEWIDTH) , PADDLEWIDTH, PADDLEHEIGHT);

    // add circle to window
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
    
    double xlen = xloc - (xloc * .05);
    double ylen = yloc - (yloc * PERC);

    double offsetx = xlen * .001;

    
    for (int i = 0; i <= ROWS; i++)
    {
        
        for (int j = 0; j <= COLS ; j++)
        {            
            
            // TODO COMMENT 
            GRect brick = newGRect(((xloc*j)+ (xloc * .05)), ((yloc*i) + (yloc *PERC)), xlen - offsetx  , ylen);
            add(window, brick);
        }
    }
}
