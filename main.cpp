#include "cartesiano.h"

int main(){

    cout << "G50" << endl;
    int V = 50;
	Grafo grafo(V);
    vector <pair <double, double> > coord;
    gerandoCoord(coord, V);
    grafo.gerandoLigacaoEPesoAresta(V, coord);
    grafo.printGrafo(V, coord);
    grafo.DFS(coord);
    grafo.DFSModificado(coord);
    grafo.BFSAleatorio(coord);
    grafo.dijkstra();

    
    cout << "G100" << endl;
    int V1 = 100;
	Grafo grafo1(V1);
    vector <pair <double, double> > coord1;
    gerandoCoord(coord1, V1);
    grafo1.gerandoLigacaoEPesoAresta(V1, coord1);
    grafo1.printGrafo(V1, coord1);
    grafo1.DFS(coord1);
    grafo1.DFSModificado(coord1);
    grafo1.BFSAleatorio(coord1);
    grafo1.dijkstra();

    cout << "G500" << endl;
    int V2 = 500;
	Grafo grafo2(V2);
    vector <pair <double, double> > coord2;
    gerandoCoord(coord2, V2);
    grafo2.gerandoLigacaoEPesoAresta(V2, coord2);
    grafo2.printGrafo(V2, coord2);
    grafo2.DFS(coord2);
    grafo2.DFSModificado(coord2);
    grafo2.BFSAleatorio(coord2);
    grafo2.dijkstra();

    cout << "G1000" << endl;
    int V3 = 1000;
	Grafo grafo3(V3);
    vector <pair <double, double> > coord3;
    gerandoCoord(coord3, V3);
    grafo3.gerandoLigacaoEPesoAresta(V3, coord3);
    grafo3.printGrafo(V3, coord3);
    grafo3.DFS(coord3);
    grafo3.DFSModificado(coord3);
    grafo3.BFSAleatorio(coord3);
    grafo3.dijkstra();
    





    
    
    
    return 0;
}
