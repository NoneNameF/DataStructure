#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define Success true;
#define Fail false;

typedef struct {
	int ID;
	char name[10];
} LData;

typedef struct {
	LData Data;
} LNode;

/******************************************************************/
