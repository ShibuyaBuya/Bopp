#include "bopp/strings.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <ncurses.h>
#include <signal.h>
volatile sig_atomic_t stop = 0;

void sigint_handler(int sig) {
    stop = 1;
}
int screenWidth, screenHeight;
//int windowWidth, windowHeight, starty, start
static char *test;
const char *testStr = "Yoo WhatsApp!";
static int *b = NULL;
static int width;
static int height;
static int size;
static char *tests()
{
    //size_t testLen = strlen(testStr);
    test = (char *)malloc(2048);
    memset(test, 'A', 2047);
    //memcpy(test, testStr, (testLen + 1) * sizeof(char));
    test[2047] = 0;
    return test;
}
static void sizechanged()
{
    getmaxyx(stdscr, height, width);
    size = width * height;
    b = (int *)realloc(b, (size + width + 1) * sizeof(int));
    memset(b, 0, (size + width + 1) * sizeof(int));
    clear();
};
/*static int onSelect(const char *__s[], int current, void func(), ...)
{
    int sizeopt = sizeof(__s) / sizeof(__s[0]);
    va_list args;
    va_start(args, func);
    for (int i = 0; i < func; i++)
    {
        void function() = va_arg(args, void());
        for (int i = 0; i < sizeopt; i++)
        {
            if (i == current)
            {
                function();
                va_end(args);
                return 0;
            }
        }
    }
    va_end(args);
    return 1;
};*/
//static void sel(current)
void install(){
    printf("work");
}
int main()
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    signal(SIGINT, sigint_handler);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    const char *optionmenu[] = {"(s) START - Start Bopp", "(i) Install - install bopp"};
    int sizeopt = sizeof(optionmenu) / sizeof(optionmenu[0]);
    int current = 0;
    sizechanged();
    setroot("tes");
    if(access(path_root, F_OK) == 0){
        installed = 0;
    }
    if (installed == 0){
        installed_str = "true";
    }else if (installed == 1){
        installed_str = "false";
    }
    while (1)
    {
        refresh();
        getmaxyx(stdscr, height, width);
        int y = height / 2 - sizeopt / 2;
        sizechanged();
        yclear();
        xclear();
        printw("type \"q\" to quit. %i", current);
        refresh();
        mvprintw(Y, x_strings, "Lists: %i\n", sizeopt);
        refresh();
        mvprintw(Y, x_strings, "Installed: %s", installed_str);
        refresh();
        mvprintw(Y, x_strings, "Reallocated: %p\n", b);
        refresh();
        mvprintw(Y, x_strings, "ROOT (default is path the project): %s", PATH_ROOT);
        refresh();
        for (int i = 0; i < sizeopt; i++)
        {
            int x = width / 2 - strlen(optionmenu[i]) / 2;
            if (i == current)
            {
                attron(A_REVERSE);
            }
            mvprintw(y + i, x, "%s", optionmenu[i]);
            if (i == current)
            {
                attroff(A_REVERSE);
            }
        }
        refresh();
        int ch = getch();
        if (ch == 'q')
        {
            break;
        }
        else if (ch == KEY_UP)
        {
            current = (current - 1 + sizeopt) % sizeopt;
        }
        else if (ch == KEY_DOWN)
        {
            current = (current + 1) % sizeopt;
        }
        else if (ch == KEY_RESIZE)
        {
            sizechanged();
        }
        else if (ch == '\n')
        {
            break;
        }
        else
        {
            refresh();
        }
    }
    //onSelect(optionmenu, current, start, install);
    endwin();
    if (current == 0){
        printf("work");
    }
    return 0;
}
