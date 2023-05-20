#ifndef ALEATORIO_HPP
#define ALEATORIO_HPP

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

typedef struct Item2{
	int x, y;
}Item2;


void read3();
bool beco_sem_saida1(vector<vector<string>> mat, int i, int j);
void randomico(vector<vector<string>> mat, vector<vector<string>> mat_guardar);
void print1(vector<vector<string>> mat);


#endif