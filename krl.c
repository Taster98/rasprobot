#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    Display *display;
    Window window;
    XEvent event;
    int s;
    int status;
    /* open connection with the server */
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }
 
    s = DefaultScreen(display);
 
    /* create window */
    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1,
                           BlackPixel(display, s), WhitePixel(display, s));
 
    /* select kind of events we are interested in */
    XSelectInput(display, window, KeyPressMask | KeyReleaseMask );
    
    /* map (show) the window */
    XMapWindow(display, window);
    bool det = 1;
    XkbSetDetectableAutoRepeat (display, det, NULL);
    /* event loop */
    while (1)
    {
        XNextEvent(display, &event);
 
        /* keyboard events */
        if (event.type == KeyPress)
        {
            printf( "KeyPress: %x\n", event.xkey.keycode );
            // UP (w)
            if (event.xkey.keycode == 0x19){
                // Pausa e
                //status=system("python3 movements/pause.py");
                //status=system("sudo killall python3");
                // Up
                status=system("python3 movements/forward.py&");
            }
            // DOWN (s)
            if (event.xkey.keycode == 0x27){
                // Pausa e
                //status=system("python3 movements/pause.py");
                //status=system("sudo killall python3");
                // Down
                status=system("python3 movements/backward.py&");
            }
            // LEFT (a)
            if (event.xkey.keycode == 0x26){
                // Pausa e 
                //status=system("python3 movements/pause.py");
                //status=system("sudo killall python3");
                // Sinistra
                status=system("python3 movements/left.py&");
            }
            // RIGHT (d)
            if (event.xkey.keycode == 0x28){
                // Pausa e
                //status=system("python3 movements/pause.py");
                //status=system("sudo killall python3");
                // Destra
                status=system("python3 movements/right.py&");
            }
            // PAUSE (p)
            if (event.xkey.keycode == 0x21){
                status=system("python3 movements/pause.py");
                status=system("sudo killall python3");
            }
            //EXIT (n)
            if (event.xkey.keycode == 0x39){
                break;
            }       
        }
        else if (event.type == KeyRelease)
        {
            printf( "KeyRelease: %x\n", event.xkey.keycode );
            status=system("python3 movements/pause.py");
            status=system("sudo killall python3");
        }
    }

    /* close connection to server */
    XCloseDisplay(display);
 
    return 0;
}
/*
W -> 19
S -> 27
D -> 28
A -> 26
P -> 21
N -> 39
*/