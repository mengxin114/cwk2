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
void load(char fileName[]);

void creatMaze();
char getInput();
void printMap();
void checkData(char buf[]);







#endif
