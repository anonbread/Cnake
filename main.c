#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    WINDOW* win = initscr();
    keypad(win, true);
    nodelay(win, true);
    int posX = 0;
    int posY = 0;
    int foodX = rand() % 20 ;
    int foodY = rand() % 20 ;
    int dirX = 1;
    int dirY = 0;
    while (true) {
        int pressed = wgetch(win);
        if (pressed == KEY_LEFT || pressed == 'A' || pressed == 'a')  {
            dirX = -1;
            dirY = 0;
        }
        if (pressed == KEY_RIGHT || pressed == 'D' || pressed == 'd' ) {
            dirX = 1;
            dirY = 0;
        }
        if (pressed == KEY_UP || pressed == 'W' || pressed == 'w') {
            dirX = 0;
            dirY = -1;
        }
        if (pressed == KEY_DOWN || pressed == 'S' || pressed == 's' ) {
            dirX = 0;
            dirY = 1;
        }
        posX += dirX;
        posY += dirY;
        erase();
        mvaddstr(posY, posX, "*");
        mvaddstr(foodY, foodX, "@");
        if (foodX == posX && foodX == posY) {
            foodX = rand() % 20;
            foodY = rand() % 20;
        }
        usleep(100000);
    }
    endwin();

}