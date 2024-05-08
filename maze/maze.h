#ifndef __TASKOP_H__
#define __TASKOP_H__
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define LINE_MAX 1024
int width;
int height;
char** map;
int count = 0;
int win = 0;
char in = '\0';
int x;
int y;
void load(char fileName[]);
void checkWin();
void creatMaze();
char getInput(char input);
void printMap();
void checkData(char buf[],int height);
void move(char input);
struct dir
{
    char tag;
    int x;
    int y;
};
struct dir direction[4] = {
    {
        .tag = 'W',
        .x = 0,
        .y = -1
    },
    {
        .tag = 'A',
        .x = -1,
        .y = 0
    },
    {
        .tag = 'S',
        .x = 0,
        .y = 1
    },
    {
        .tag = 'D',
        .x = 1,
        .y = 0
    },
};





#endif
