/*
 * Nome do arquivo: uva-11709.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 23/01/2025
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// Esse problema é bastante straight-forward, um problema para encontrar SCCs
// (Strongly Connected Components). Para resolver esse problema temos dois algoritmos:
// o algoritmo de Kosaraju e o de Tarjan.
// Escolhi a abordagem de Tarjan por ser mais simples e mais eficiente, usando somente
// uma dfs no grafo.

// Definições úteis para programação competitiva
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

// Declaração das variáveis

int P, T;
int id, sccCount;
vector<vector<int>> al;
stack<int> nodeStack;
vector<bool> onStack;
vector<int> ids;
vector<int> low;
unordered_map<string, int> nameToIndex;

// Algoritmo de Tarjan para encontrar SCCs(Strongly Connected Components)
void dfs(int current_node){
    nodeStack.push(current_node);
    onStack[current_node] = true;
    ids[current_node] = low[current_node] = id++;

    for(int target_node: al[current_node]) {
        if(ids[target_node] == -1) dfs(target_node);
        if(onStack[target_node]) low[current_node] = min(low[current_node], low[target_node]);
    }

    if(ids[current_node] == low[current_node]) {
        for(int node=nodeStack.top();; node = nodeStack.top()) {
            nodeStack.pop();
            onStack[node] = false;
            low[node] = ids[current_node];
            if(node == current_node) break;        
        }

        sccCount++;
    }
}

// Função que chama a dfs para encontrar o 
// SCC(Strongly Connected Component) para cada nó não visitado
int getSCCS() {
    for(int i=0; i < P; i++) {
        if(ids[i] == -1) {
            dfs(i);
        }
    }
    return sccCount;
}

// Função principal
int main() {
    fast_io;
    cin >> P >> T;
    while (P != 0 && T != 0) {
        // Limpeza e inicialização das estruturas utilizadas
        cin.ignore();
        al.clear();
        al.resize(P);
        nodeStack = stack<int>();
        onStack.clear();
        onStack.resize(P, false);
        ids.clear();
        ids.resize(P, -1);
        low.clear();
        low.resize(P, 0);
        nameToIndex.clear();

        // Leitura das pessoas, que serão os nossos nodes
        // e inicialização da lista de adjacência
        for(int i=0; i < P; i++) {
            string name;
            getline(cin, name);
            nameToIndex[name] = i;
        }

        // Leitura das conexões e posterior adição à lista de
        // adjacência
        for(int i=0; i < T; i++) {
            string person1name, person2name;
            getline(cin, person1name);
            getline(cin, person2name);
            int person1 = nameToIndex[person1name];
            int person2 = nameToIndex[person2name];
            al[person1].push_back(person2);
        }

        id=0;
        sccCount=0;
        cout << getSCCS() << endl;
        cin >> P >> T;
    }

    return 0;
}
