#include<iostream>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>
#include <iomanip> 
#include <list>
#include <algorithm>
#include <stack> // pilha para usar na DFS
#include <utility>
#include <math.h>
     

using namespace std;


class Grafo{
	int V; // número de vértices
	vector < vector < pair <int, double> > > adj; // ponteiro para um array contendo as listas de adjacências
public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, pair<int, double> par); // adiciona uma aresta no grafo
    void printGrafo(int v, vector <pair <double, double> > &coordDouble);
    void gerandoLigacaoEPesoAresta(int vertices, vector <pair <double, double> > &coordDouble);

	//void dfs(int v);
};

void gerandoCoord(vector <pair <double, double> > &coord, int quantidade);
void printCoordenadas(vector <pair <double, double> > &coord);
//void gerandoLigacaoEPesoAresta(Grafo &g, int vertices, vector <pair <double, double> > &coordDouble);
bool verificaPar(vector <pair <int, int> > coord, int x, int y);
double distanciaEntreDoisPonto(double x1, double y1, double x2, double y2);
//void printGrafo(Grafo g, int v, vector <pair <double, double> > &coordDouble);
