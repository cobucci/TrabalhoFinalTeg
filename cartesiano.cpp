#include "cartesiano.h"

void gerandoCoord(vector <pair <double, double> > &coord, int quantidade){

    cout << "CRIANDO COORDENADAS ALEATORIAS : " << endl;
    srand(time(NULL));
    for(int i=0 ; i<quantidade ; i++){

        double x, y;
        x = (double)rand()/RAND_MAX*1.000-0.000;
        y = (double)rand()/RAND_MAX*1.000-0.000;
        pair <double, double> coordenada (x, y);
        coord.push_back(coordenada);
        printf("%d -> (%.4lf , %.4lf)\n", i, coordenada.first, coordenada.second);       
    }  
}

void printCoordenadas(vector <pair <double, double> > &coord){

    for(int i=0 ; i<coord.size() ; i++){

        printf("(%.3lf , %.3lf)\n", coord[i].first, coord[i].second);
    }
}

void Grafo::gerandoLigacaoEPesoAresta(int vertices, vector <pair <double, double> > &coordDouble){

    srand (time(NULL));
    vector <pair <int, int> > coord; //esta inteiro pq ira referenciar o indice do vetor de coordenadas, que tera (double, double)
    int qa = calculaLog(vertices);
    
    for(int i=0 ; i<vertices ; i++){

        int vI[qa];
        double vD[qa];
        maisProximos(coordDouble, vI, vD, i, qa);
    
        for(int j=0 ; j<qa ; j++){
            pair <int, int> coordenada (i, vI[j]);
            if(i != vI[j] && verificaPar(coord, i, vI[j])){ //x!=y && a coord(x,y) nao pode ter sido colocada ainda
                coord.push_back(coordenada);
            }
              
        } 
    }
    
    
    cout << "\nO GRAFO TEM LIGACOES ENTRE OS PONTOS" << endl;
     for(int i=0 ; i<coord.size() ; i++){

        printf("(%d , %d)\n", coord[i].first, coord[i].second);
    }
    cout << endl << endl;
    
    
    for(int i=0 ; i<coord.size() ; i++){

        double x1 = coordDouble[ coord[i].first ].first;
        double y1 = coordDouble[ coord[i].first ].second;
        double x2 = coordDouble[ coord[i].second ].first;
        double y2 = coordDouble[ coord[i].second ].second;
        double peso = distanciaEntreDoisPonto(x1, y1, x2, y2);
        
        /*
        printf("( %.3lf , %.3lf ) | ( %.3lf , %.3lf )\n", x1, y1, x2,y2);
        cout << peso << endl;
        */
        
        pair <int, double> p1 (coord[i].second, peso);
        adicionarAresta(coord[i].first, p1);
        pair <int, double> p2 (coord[i].first, peso);
        adicionarAresta(coord[i].second, p2);   
    }
    
}

void Grafo::maisProximos(vector <pair <double, double> > coordDouble, int *vI, double *vD, int i, int qa){

    double aux[V];
    for(int j=0 ; j<V; j++){

        if(i == j){
            aux[j] = 10000.0;
        }
        else{
            aux[j] = distanciaEntreDoisPonto(coordDouble[i].first,coordDouble[i].second, coordDouble[j].first, coordDouble[j].second);
            //printf("(%.4lf,%.4lf) -> (%.4lf, %.4lf) = %.4lf\n", coordDouble[i].first,coordDouble[i].second, coordDouble[j].first, coordDouble[j].second, aux[j]);
        }
    }

    //ordenar
    double ordenado[V];
    for(int j=0 ; j<V ; j++){
        ordenado[j] = aux[j];
        //cout << aux[j] << endl;
    }
    //cout << endl;
    for(int i=0 ; i<V ; i++){
        for(int j=i+1 ; j<V ; j++){
            if(ordenado[i] > ordenado[j]){
                double aux = ordenado[i];
                ordenado[i] = ordenado[j];
                ordenado[j] = aux;
            }
        }
    }
    /*
    for(int j=0 ; j<V ; j++){

        cout << ordenado[j] << endl;
    }
    */
    //cout << endl;
    for(int j=0 ; j<qa ; j++){

        vD[j] = ordenado[j];
        int temp = qualPosicaoNoVetor(aux, ordenado[j]);
        vI[j] = temp;
        //cout << vD[j] << " " << vI[j] << endl;
    }

    //cout << endl << endl << endl;

}

int Grafo::qualPosicaoNoVetor(double *aux, double x){

    for(int i=0 ; i<V ; i++){

        if(aux[i] == x){
            return i;
        }
    }
    cout << "Problema na qual posicao Vetor" << endl;
    return 0;
}

int calculaLog(int x){

    if(x == 0)
        return 1;

    int res = log2(x);
    return res;
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

    cout << "IMPRIMINDO GRAFO";
    for(int i=0 ; i<v ; i++){

        printf("\nCOORDERNADA [%d] = (%.4lf , %.4lf) tem ligacao com: \n", i, coordDouble[i].first, coordDouble[i].second);
        for(int j=0 ; j<adj[i].size() ; j++){

            int aux1 = adj[i][j].first;
            int qualCoord = qualCoordenada(coordDouble, coordDouble[aux1].first, coordDouble[aux1].second);
            printf("\tCOORDERNADA [%d] = (%.4lf , %.4lf) com peso = : %.4lf\n", qualCoord, coordDouble[aux1].first, coordDouble[aux1].second, adj[i][j].second);
        }
    }

}


int Grafo :: qualCoordenada(vector <pair <double, double> > coordDouble, double x, double y){

    for(int i=0 ; i<coordDouble.size() ; i++){

         if(coordDouble[i].first == x && coordDouble[i].second == y)
            return i;  
    }
    cout << "TA TUDO ERRADO MALUCO" << endl;
    return 0;
}


Grafo::Grafo(int V){
	this->V = V; // atribui o número de vértices
	//adj = new vector < vector < pair <int, double> > >; // cria as listas
    
    for(int i=0 ; i<V ; i++){
        adj.push_back(vector < pair <int, double> > ());
        //coord.push_back(vector < pair <int, double> > ());
        ////mind.push_back(vector <int> ());
    }
}

void Grafo::adicionarAresta(int v1, pair<int, double> par){
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(par);
    //printf("adj[%d] -> ( %d , %.3lf )\n\n\n", v1, par.first, par.second);
    
}

void Grafo::DFS(vector <pair <double, double> > &coordDouble){

    srand (time(NULL));
    int v = rand() % V;
    //int v=0;
    cout << "\n\n\n\n\n RODANDO DFS\nVALOR DA RAIZ INICIAL EH = " << v << endl<< endl << endl;

    stack<int> pilha;
    int j=0;
	bool visitados[V]; // vetor de visitados


	for(int i = 0; i < V; i++)
            visitados[i] = false; // marca todos como não visitados

        while(true){

            if(!visitados[v]){
                cout << "Vertice " << v << " Visitado!\n";
                visitados[v] = true; // marca como visitado
                pilha.push(v); // insere "v" na pilha
                printf("COORDERNADA [%d] = (%.4lf , %.4lf)\n", v, coordDouble[v].first, coordDouble[v].second);
            }

            bool achou = false;

            // buscando por um vizinho não visitado
            for(j=0 ; j<adj[v].size() ; j++){
                if(!visitados[adj[v][j].first]){
                    achou = true;
                    int qualCoord = qualCoordenada(coordDouble, coordDouble[adj[v][j].first].first, coordDouble[adj[v][j].first].second);
                    std::this_thread::sleep_for (std::chrono::seconds(0)); //PARA IR PRINTANDO A CADA TANTOS SEGUNDOS
                    printf("\tTEM LIGACAO COM A COORDERNADA [%d] = (%.4lf , %.4lf) com peso = : %.4lf\n\n", qualCoord, coordDouble[adj[v][j].first].first, coordDouble[adj[v][j].first].second, adj[v][j].second);
                    break;
                }
            }

            if(achou)
			    v = adj[v][j].first;
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


void Grafo::DFSModificado(vector <pair <double, double> > &coordDouble){

    
    int v = minimo(coordDouble);
    //int v=0;
    cout << "\n\n\n\n\n\n\nRODANDO DFS PARA GRAFO DIRECIONADO\nVALOR DA RAIZ INICIAL EH = " << v << endl<< endl << endl;

    stack<int> pilha;
    int j=0;
	bool visitados[V]; // vetor de visitados


	for(int i = 0; i < V; i++)
            visitados[i] = false; // marca todos como não visitados

        while(true){

            if(!visitados[v]){
                cout << "Vertice " << v << " Visitado!\n";
                visitados[v] = true; // marca como visitado
                pilha.push(v); // insere "v" na pilha
                printf("COORDERNADA [%d] = (%.4lf , %.4lf)\n", v, coordDouble[v].first, coordDouble[v].second);
            }

            bool achou = false;
            //list<int>::iterator it;

            // buscando por um vizinho não visitado
            for(j=0 ; j<adj[v].size() ; j++){
                if(!visitados[adj[v][j].first] && coordDouble[v].first < coordDouble[adj[v][j].first].first){
                    achou = true;
                    int qualCoord = qualCoordenada(coordDouble, coordDouble[adj[v][j].first].first, coordDouble[adj[v][j].first].second);
                    std::this_thread::sleep_for (std::chrono::seconds(0));
                    printf("\tTEM LIGACAO COM A COORDERNADA [%d] = (%.4lf , %.4lf) com peso = : %.4lf\n\n", qualCoord, coordDouble[adj[v][j].first].first, coordDouble[adj[v][j].first].second, adj[v][j].second);
                    break;
                }
            }

            if(achou)
			    v = adj[v][j].first;
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


int minimo (vector <pair <double, double> > c){

    double minimo = 1.0;
    int retorno=0;
    for(int i=0 ; i<c.size() ; i++){

        if(c[i].first < minimo){
            minimo = c[i].first;
            retorno = i;
        }
    }
    return retorno;
}

void Grafo::BFSAleatorio(vector <pair <double, double> > &coordDouble)
{ 

    int s = rand() % V;
    cout << "\n\nBFS com inicio em " << s << endl;
    int j;
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true;
    vector <int> ordem;
    vector <int> origem;
    vector <int> nivel; 
    queue.push_back(s); 
    origem.push_back(-1);
    
    
    while(!queue.empty()) 
    { 
        
        s = queue.front(); 
        cout << s << " ";
        ordem.push_back(s); 
        queue.pop_front(); 
  

        for (j=0 ; j<adj[s].size() ; j++) 
        { 
            if (!visited[adj[s][j].first]) 
            { 
                visited[adj[s][j].first] = true; 
                queue.push_back(adj[s][j].first);
                origem.push_back(s); 
            } 
        } 
    } 
    cout << endl;
    /*
    for(int i=0 ; i<origem.size() ; i++){
        cout << ordem[i] << " " << origem[i] << endl;
    }
    */

}




int Grafo::minDistance(double dist[], bool sptSet[]) { 
   
   double min = 10000.00;
   int min_index; 
   
   for (int v = 0; v < V; v++){
       if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
   } 
   return min_index; 
} 
   

void Grafo::printDistancia(double dist[], int n) 
{ 
   printf("\n\nVERTICE \tDISTANCIA ATE %d\n", n); 
   for (int i = 0; i < V; i++) 
      printf("%d  \t\t  %.4lf\n", i, dist[i]); 
} 
   
 
void Grafo::dijkstra() 
{ 
     int src = rand() % V;
     //cout << "FONTE = " << src << endl;
     double dist[V];   
     bool sptSet[V];  
     for (int i = 0; i < V; i++){
         dist[i] = 10000.0;
         sptSet[i] = false; 
     }

     dist[src] = 0.0;
     for (int count = 0; count < V; count++){ 

       int u = minDistance(dist, sptSet); 
       sptSet[u] = true;
    

        //lista de adjacencia de u
       for (int v = 0; v < adj[u].size(); v++){
           /*
                se spt[na posicao adjacente] for false
                se a dist[u] for diferente de 10000.0
                se dist[u] + adj[u][v].second < dist[adj[u][v].first]
           */
            if (!sptSet[adj[u][v].first] && dist[u] != 10000.0 && dist[u] + adj[u][v].second < dist[adj[u][v].first]){
                dist[adj[u][v].first] = dist[u] + adj[u][v].second;
            }       
        } 
     } 
     printDistancia(dist, src);
     //dijkstra2(src);  
}

void Grafo::dijkstra2(int src){

    for(int i=0 ; i<V ; i++){

        if(src == i){
            cout << "vertice " << i << endl;
            cout << "tam = 0" << endl << endl;

        }
        else{

            vector <vector <int>> caminhoCompleto;
            vector <double> pesoCompleto;
            
            vector <int> pilha;
            pilha.push_back(i);
            double tamCaminho=0;
            bool podem[V];
            for(int i=0 ; i<V ; i++){
                podem[i] = true;
            }
            //podem[src] = false;
            vector <int> pesos;

            while(!pilha.empty()){
                pair <int, double> par;
                cout << "topo = " << pilha.back() << endl;
                std::this_thread::sleep_for (std::chrono::seconds(1));
                if(pegarAdjacente(pilha, podem, par)){
                    pilha.push_back(par.first);
                    tamCaminho += par.second;
                    pesos.push_back(par.second);
            
                    
                    if(pilha.back() == src){
                        cout << "Oi" << endl;
                        insereCaminhosCompletos(caminhoCompleto, pesoCompleto, pilha, tamCaminho);
                        podem[pilha.back()] = true;
                        pilha.pop_back();
                        double p = pesos.back();
                        pesos.pop_back();
                        tamCaminho -= p;    
                    }
                    
                }
                else{
                    pilha.pop_back();
                    double p = pesos.back();
                    pesos.pop_back();
                    tamCaminho -= p;
                }
                
            }
            cout << "vertice " << i << endl;
            escolherMelhorCaminho(caminhoCompleto, pesoCompleto);
        }
    }

}

bool Grafo::pegarAdjacente(vector <int> caminho, bool *podem, pair <int, double> &par){


    for(int j=0 ; j<adj[caminho.back()].size() ; j++){
            cout << adj[caminho.back()][j].first << " " << endl;
    }
    

    for(int i=0 ; i<adj[caminho.back()].size() ; i++){

        if(podem[ adj[caminho.back()][i].first ] ){
            par = make_pair(adj[caminho.back()][i].first, adj[caminho.back()][i].second);
            podem[ adj[caminho.back()][i].first ] = false;
            return true;
        }
    }
    podem[caminho.back()] = true;
    return false;
}

void Grafo::insereCaminhosCompletos(vector < vector <int> > &cc, vector <double> &pc, vector <int> pilha, double peso){

    cc.push_back(vector <int> ());
    for(int i=0 ; i<pilha.size() ; i++){

        cc[cc.size()-1].push_back(pilha[i]);
    }
    pc.push_back(peso);
}

void Grafo::escolherMelhorCaminho(vector < vector <int> > &cc, vector <double> &pc){

    double menor = 10000.00;
    int posi=0;
    for(int i=0 ; i<pc.size() ; i++){
        if(pc[i] < menor){
            menor = pc[i];
            posi = i;
        }
    }

    for(int i=0 ; i<cc[posi].size() ; i++){
        cout << cc[posi][i] << " ";
    }
    cout << endl;
    cout << "tam = " << menor << endl << endl;
}
