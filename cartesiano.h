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
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <math.h>       /* log */
#include <limits.h>

using namespace std;

class Grafo{
	int V; // número de vértices
	vector < vector < pair <int, double> > > adj; // ponteiro para um array contendo as listas de adjacências
public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, pair<int, double> par); // adiciona uma aresta no grafo
    void printGrafo(int v, vector <pair <double, double> > &coordDouble);
    void gerandoLigacaoEPesoAresta(int vertices, vector <pair <double, double> > &coordDouble);
	void DFS(vector <pair <double, double> > &coordDouble);
	void DFSModificado(vector <pair <double, double> > &coordDouble);
	void BFSAleatorio(vector <pair <double, double> > &coordDouble);
	int qualCoordenada(vector <pair <double, double> > coordDouble, double x, double y);
	void maisProximos(vector <pair <double, double> > coordDouble, int *vI, double *vD, int i, int qa);
	int qualPosicaoNoVetor(double *aux, double x);
	void printDistancia(double dist[], int n);
	void dijkstra();
	int minDistance(double dist[], bool sptSe[]);

	void dijkstra2(int src);
	bool pegarAdjacente(vector <int> caminho, bool *podem, pair <int, double> &par);
	void insereCaminhosCompletos(vector < vector <int> > &cc, vector <double> &pc, vector <int> pilha, double peso);
	void escolherMelhorCaminho(vector < vector <int> > &cc, vector <double> &pc);

};

void gerandoCoord(vector <pair <double, double> > &coord, int quantidade);
void printCoordenadas(vector <pair <double, double> > &coord);
bool verificaPar(vector <pair <int, int> > coord, int x, int y);
double distanciaEntreDoisPonto(double x1, double y1, double x2, double y2);
int calculaLog(int x);
int minimo (vector <pair <double, double> > coordDouble);

