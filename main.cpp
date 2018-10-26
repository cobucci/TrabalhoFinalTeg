#include "cartesiano.h"

int main(){

    int V = 6;
	Grafo grafo(V);
    double y;
    
    y = (double)rand()/RAND_MAX*1.000-0.000;
    pair <double, double> coordenada (5, y);
    grafo.adicionarAresta(0, coordenada);
    /*
    vector <pair <double, double> > coord;
    gerandoCoord(coord, V);

    gerandoLigacaoEPesoAresta(grafo, V, coord);
    grafo.printGrafo(V, coord);
    */
    printf()
	return 0;
}