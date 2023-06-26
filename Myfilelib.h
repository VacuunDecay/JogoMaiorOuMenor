#ifndef MYFILELIB_H
#define MYFILELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nomeToId(FILE* fp, char* nome);

int isIdUnique(FILE *fp, int id);

void loadJog(FILE *fp, int id, char* nome);
#endif