#pragma once

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define OK "continue"
#define NO "exit invalid character"

void instruction();

void checkArguments(int argc, char** argv);
void checkFlags(int argc, char** argv);
void checkSymbolFlags(int argc, char** argv);
void checkSizeFlags(int argc, char** argv);
void countFlags(int argc, char** argv);
void genPass(int argc, char** argv);

char* createAlphabet(int argc, char** argv);
