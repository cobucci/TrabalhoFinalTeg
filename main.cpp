#include "cartesiano.h"

int main(){

    int V = 6;
    Grafo grafo(V);
    vector <pair <double, double> > coord;
    gerandoCoord(coord, V);
    grafo.gerandoLigacaoEPesoAresta(V, coord);
    grafo.printGrafo(V, coord);
        
    return 0;
}
