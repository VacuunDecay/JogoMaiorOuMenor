#ifndef MYUTIL_H
#define MYUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

typedef struct {
    int id;
    int rodada;
    char resposta;
} Log;

typedef struct {
    int pos;
    int point;
    char* nome;
} Leaderboard;

typedef struct {
    int id, balance, maxPoint;
    char* nome;
} Jog;

void cls(int time);

void ln();

int randRange(int min, int max);

int ask2op(const char* question);

void capStr(char** str);

#endif // MYUTIL_H