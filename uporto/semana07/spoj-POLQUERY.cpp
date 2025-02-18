/*
 * Nome do arquivo: spoj-POLQUERY.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 02/02/2025
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// Definições úteis para programação competitiva
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

// Novamente um problema que exige um pensamento mais sofisticado, dificilmente alcançado sozinho.
// Nesse problema precisamos tratar de dois tipos de queries:
// 
// 1. Precisamos saber se dado dois vértices A e B e uma areasta (u,v) podemos ir de A a B
// sem passar por (u,v)
// 
// 2. Precisamos saber se dado dois vértices A, B e C, é possível ir de A até B sem passar por C
//
// O que tinha de base teórica das aulas era o conceito de pontes e pontos de articulação, contudo,
// nesse problema a atenção maior é dada aos elementos ao redor das pontes e pontos de articulação,
// somente achá-los não é o bastante. Assim, após alguma pesquisa acerca do problema entendi melhor
// como utilizar essas propriedades de grafos.
//
// Para a query 1:
// 1. Verificamos se (u,v) é uma ponte. Por quê? Pois caso não seja, ela não separa o grafo, assim
// obviamente podemos ir do ponto A ao B - Podemos fazer essa afirmação pois no enunciado é dito que
// "The test data will be such that it is initially possible to get from each city to every other city."
// logo é um grafo conectado.
//
// 2. (u,v) é uma ponte. Dado que o grafo é inicialmente conectado e (u,v) não pode ser utilizada,
// a aresta acaba dividindo o grafo em dois lados, assim precisamos saber em qual lado da ponte os 
// dois pontos estão, se estiverem no mesmo lado, significa que podemos ir de um ponto ao outro, 
// do contrário não há como. Mas como podemos fazer isso? Podemos ver se os pontos A e B estão na
// mesma componente u, ou seja, se A e B pertencem a subárvore de u. Como fazer isso? 
// Se d[u] <= d[a] e f[u] >= f[a] então a pertence a subárvore u
// Assim, poderiamos verificar se A pertence a subárvore u ou v. Mais elegantemente, podemos
// verificar se (A pertence a u) == (B pertence a u).
// 
// Para a query 2
// 1. Análogamente, caso o ponto C não seja um ponto de articulação, podemos ir de A a B sem maiores
// problemas.
//
// 2. Caso seja um ponto de articulação, sua remoção resultará na divisão do grafo em diferentes componentes.
// Diferentemente da query 1, não podemos abstrair para 2 componentes, pois pode ser 2 ou mais. Assim
// precisamos de uma forma para verificar se após a remoção, os dois pontos farão parte do mesmo
// componente. Como fazer isso? Iteramos pelos filhos do ponto de articulação e verificamos se o ponto
// A e B pertencem a ele, se sim, o retornamos e comparamos o resultado.
// 
// É interessante comentar que em nenhum momento apagamos nenhuma aresta ou vértice, mas utilizamos as
// propriedades, especialmente de componentes e subárvores, para nos ajudar a resolver o nosso problema.

// Declaração de variáveis
int N, E, currentTime;
int Q;
int T, A, B, C1, C2;
vector<vector<int>> al;
vector<int> entranceTime;
vector<int> low;
vector<int> exitTime;
vector<bool> isArticulationPoint;
vector<bool> isVisited;

map<pair<int, int>, bool> isBridge;

void dfs(int current, int p) {
    isVisited[current] = true;
    low[current] = entranceTime[current] = currentTime++;
    int children = 0;
    for(int neighbour: al[current]) {
        if(!isVisited[neighbour]) {
            children++;
            dfs(neighbour, current);
            low[current] = min(low[current], low[neighbour]);
            if (low[neighbour] > entranceTime[current]) isBridge[{current, neighbour}] = isBridge[{neighbour, current}] = true;
            if (p != -1 && low[neighbour] >= entranceTime[current]) isArticulationPoint[current] = true;
                    
        } else if(neighbour != p) {
            low[current] = min(low[current], entranceTime[neighbour]);
        }
    }

    if (p == -1 && children > 1) isArticulationPoint[current] = true;
    exitTime[current] = currentTime++;
}

// Função para saber se um nó b está dentro de uma subávore de raíz a
bool isInside(int b, int a) {
    return entranceTime[a] <= entranceTime[b] && exitTime[a] >= exitTime[b];
}

// Função que retorna em qual componente, filho de u, o nó a está
int componet(int a, int u) {
    if (isInside(a, u)) {
        for(int v: al[u]) {
            if (isInside(a, v) && low[v] >= entranceTime[u]) return v;
        }
        return -1;
    }

    return -1;
}

// Função principal
int main() {
    fast_io;
    cin >> N >> E;
    al.clear();
    al.resize(N+1);
    
    // Leitura da entrada e formação do grafo pela criação da lista de adjacência
    for(int i=0; i < E; i++) {
        cin >> A >> B;
        al[A].push_back(B);
        al[B].push_back(A);
    }
    
    // Limpando e inicializando as estruturas que iremos utilizar
    currentTime = 0;
    entranceTime.clear();
    entranceTime.resize(N+1);
    exitTime.clear();
    exitTime.resize(N+1);
    low.clear();
    low.resize(N+1);
    isArticulationPoint.clear();
    isArticulationPoint.resize(N+1);
    isVisited.clear();
    isVisited.resize(N+1);
    isBridge.clear();

    dfs(1, -1);

    cin >> Q;

    while(Q--){
        cin >> T >> A >> B >> C1;
        if (T==1) {
            cin >> C2;
            if (entranceTime[C1] > entranceTime[C2]) swap(C1, C2);
            if (!isBridge[{C1, C2}]) cout << "da" << endl; // Verifica se é ponte 
            else if (isInside(A, C2) == isInside(B, C2)) cout << "da" << endl; // Verifica se A e B estão do mesmo lado
            else cout << "ne" << endl;

        } else {
            if (!isArticulationPoint[C1]) cout << "da" << endl; //Verifica se é ponto de articulação
            else if (componet(A, C1) == componet(B, C1)) cout << "da" << endl; //Verifica se A e B fazem parte do mesmo componente
            else cout << "ne" << endl;
        }
    }

    return 0;
}
