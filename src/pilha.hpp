#ifndef PILHA_HPP 
#define PILHA_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <unistd.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
	int x, y;
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};


void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);

#endif