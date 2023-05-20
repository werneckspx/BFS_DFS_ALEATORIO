#ifndef LARGURA_HPP
#define LARGURA_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include "fila.hpp"
#include <chrono>

using namespace std;

void read();
void imprimindo(vector<vector<string>> mat);
void movimento(vector<vector<string>> mat,vector<vector<string>> mat_guardar, int i, int j, Fila f);
void movimento_x_y(vector<vector<string>> &mat, int *i, int *j, Fila *f,Item posicao);
void movimento_x(vector<vector<string>> &mat, int *i, int *j, Fila *f,Item posicao);
void movimento_y(vector<vector<string>> &mat, int *i, int *j, Fila *f,Item posicao);
#endif