#ifndef PROFUNDIDADE_HPP
#define PROFUNDIDADE_HPP

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

using namespace std;

void read2();
void print(vector<vector<string>> mat);

void profundidade(vector<vector<string>> mat, vector<vector<string>> mat_guardar);
bool beco_sem_saida(vector<vector<string>> mat, int i, int j);

void randomico(vector<vector<string>> mat, vector<vector<string>> mat_guardar);


#endif