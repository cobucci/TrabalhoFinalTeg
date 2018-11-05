#include "cartesiano.h"

int main(){

    int V = 5;
	Grafo grafo(V);
    vector <pair <double, double> > coord;
    gerandoCoord(coord, V);
    grafo.gerandoLigacaoEPesoAresta(V, coord);
    grafo.printGrafo(V, coord);
    grafo.DFS(coord);
    grafo.DFSModificado(coord);
    //grafo.BFSAleatorio();
    
    return 0;
}
