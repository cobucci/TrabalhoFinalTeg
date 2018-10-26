#include "cartesiano.h"

void gerandoCoord(vector <pair <double, double> > &coord, int quantidade){

    srand(time(NULL));
    for(int i=0 ; i<quantidade ; i++){

        double x, y;
        x = (double)rand()/RAND_MAX*1.000-0.000;
        y = (double)rand()/RAND_MAX*1.000-0.000;
        pair <double, double> coordenada (x, y);
        coord.push_back(coordenada);
        //printf("(%.3lf , %.3lf)\n", coordenada.first, coordenada.second);       
    }  
}

void printCoordenadas(vector <pair <double, double> > &coord){

    for(int i=0 ; i<coord.size() ; i++){

        printf("(%.3lf , %.3lf)\n", coord[i].first, coord[i].second);
    }
    
}

void Grafo::gerandoLigacaoEPesoAresta(int vertices, vector <pair <double, double> > &coordDouble){

    srand (time(NULL));
    int max = (vertices*(vertices-1))/2; //numero maximo de arestas de um grafo
    int min = vertices/2; // o grafo vai ter no minimo essa quantidade de arestas
    int dif = max-min;
    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    int quantidadeArestas = rand() % dif + min;
    vector <pair <int, int> > coord; //esta inteiro pq ira referenciar o indice do vetor de coordenadas, que tera (double, double)
    for(int i=0 ; i<quantidadeArestas ; i++){

        int x, y;
        x = rand() % vertices;
        y = rand() % vertices;
        while(x == y || !verificaPar(coord, x, y)){
            x = rand() % vertices;
            y = rand() % vertices;
        }

        pair <int, int> coordenada (x, y);
        coord.push_back(coordenada);
    }

    /*
     for(int i=0 ; i<coord.size() ; i++){

        printf("(%d , %d)\n", coord[i].first, coord[i].second);
    }
    */
    
    for(int i=0 ; i<coord.size() ; i++){

        double x1 = coordDouble[ coord[i].first ].first;
        double y1 = coordDouble[ coord[i].first ].second;
        double x2 = coordDouble[ coord[i].second ].first;
        double y2 = coordDouble[ coord[i].second ].second;
        double peso = distanciaEntreDoisPonto(x1, y1, x2, y2);
        /*
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cout << peso << endl << endl << endl;
        */
        
        pair <int, double> p1 (coord[i].second, peso);
        adicionarAresta(coord[i].first, p1);
        pair <int, double> p2 (coord[i].first, peso);
        adicionarAresta(coord[i].second, p2);   
    }
}

double distanciaEntreDoisPonto(double x1, double y1, double x2, double y2){

    double a = x1-x2;
    a *=a;
    double b = y1-y2;
    b *= b;
    double soma = a+b;
    return sqrt(soma);
}

bool verificaPar(vector <pair <int, int> > coord, int x, int y){

    for(int i=0 ; i<coord.size() ; i++){

        if(coord[i].first == x && coord[i].second == y || coord[i].first == y && coord[i].second == x)
            return false;
    }
    return true;
}


void Grafo::printGrafo(int v, vector <pair <double, double> > &coordDouble){
    list<int>::iterator it;
    cout << "IMPRIMINDO GRAFO" << endl;
    for(int i=0 ; i<v ; i++){

        printf("COORDERNADA (%.3lf , %.3lf) tem ligacao com: \n", coordDouble[i].first, coordDouble[i].second);
        for(it = adj[v].begin(); it != adj[v].end(); it++){

            int aux1 = adj[*it].first;
            printf("\tCOORDERNADA (%.3lf , %.3lf) com peso = : %.3lf\n", coordDouble[i].first, coordDouble[i].second, adj[*it].second);
        }
    }

}





Grafo::Grafo(int V){
	this->V = V; // atribui o número de vértices
	adj = new list<pair <int, double> >[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, pair<int, double> par){
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(par);
}

/*
void Grafo::dfs(int v){
	stack<int> pilha;
	bool visitados[V]; // vetor de visitados


	for(int i = 0; i < V; i++)
		visitados[i] = false; // marca todos como não visitados

	while(true){
		if(!visitados[v]){
			cout << "Vertice " << v << " Visitado!\n";
			visitados[v] = true; // marca como visitado
			pilha.push(v); // insere "v" na pilha
		}

		bool achou = false;
		list<int>::iterator it;

		// buscando por um vizinho não visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				achou = true;
				break;
			}
		}

		if(achou)
			v = *it; // atualiza o "v"
		else{
			// se todos os vizinhos estão visitados ou não existem vizinhos
			// remove da pilha
			pilha.pop();
			// se a pilha ficar vazia, então terminou a busca
			if(pilha.empty())
				break;
			// se chegou aqui, é porque pode pegar elemento do topo
			v = pilha.top();
		}
	}
}
*/  