/*
 * Nome do arquivo: codeforces-508D.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 22/01/2025
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// Esse é daquele tipo de problema que você tem de ir atrás de soluções, pois a sacada para a
// solução dificilmente viria de forma natural. A primeira ideia seria tratar as substrings como nós e
// considerar que temos um grafo conectado, procurariamos então um caminho Hamiltoniano, ou seja, um
// caminho que visite cada nó uma única vez. O problema? Esse é um problema NP-Completo, não há algoritmo
// pronto que o resolva. Assim percebemos que essa não deve ser a nossa abordagem. Após a pesquisa, entendi
// a sacada, podemos dividir as substrings em nós e arestas direcionadas, por exemplo:
// Dada a substring ABC, a transformaremos nos nós AB e BC e na aresta AB->BC. Com essa nova estrutura,
// damos mais importância para as arestas do que aos nós, precisamos verificar se há uma maneira de visitar
// todas as arestas uma única vez, reduzindo o problema a encontrar um caminho Eureliano. Por se tratar de
// um grafo direcionado, utilizaremos o algoritmo de Hierholzer para resolvê-lo.

// Definições úteis para programação competitiva
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const ll MOD = 1e9 + 7;


// Definição das variáveis
int t;
unordered_map<string, vector<string>> al; //adjacency list
unordered_map<string, int> in_degree;
unordered_map<string, int> out_degree;
unordered_set<string> vertices;
deque<string> path;  

// Verifica se o grafo possui um caminho euleriano por meio da verificação
// dos in e out degrees dos seus vértices
bool hasEulerianPath(){
    int start_nodes=0, end_nodes=0;
    
    for(auto node: vertices){
        if (out_degree[node] - in_degree[node] > 1 or in_degree[node] - out_degree[node] > 1) {
            return false;
        } else if (out_degree[node] - in_degree[node] == 1) {
            start_nodes++;
        } else if (in_degree[node] - out_degree[node] == 1) {
            end_nodes++;
        }
    }

    return (end_nodes == 0 and start_nodes == 0) or 
        (end_nodes == 1 and start_nodes == 1);
}

// Encontra o nó que começa o caminho
// Isso é importante para que o algoritmo funcione
string findStartNode() {
    string start;
    for(auto node: vertices) {
        if (out_degree[node] - in_degree[node] == 1) return node;

        if (out_degree[node] > 0) start = node;
    }

    return start;
}

// Aqui que esta o algoritmo de Hierholzer, uma dfs modificada.
// O que fazemos basicamente é percorrer em profundidade, quando chegarmos em um
// vértice que não tem mais arestas de saída a serem visitadas, ele é então adicionado
// ao caminho. Construimos o caminho de trás para frente, por isso usamos uma deque para
// adicionarmos a esquerda a medida que encontramos os vértices.
void dfs(string current_node) {
    while (out_degree[current_node] != 0) {
        string next_node = al[current_node][--out_degree[current_node]];
        dfs(next_node);
    }

    path.push_front(current_node);
}

// Função principal
int main() {
    fast_io;
    
    cin >> t;
    // Leitura da entrada e criação do grafo pela lista de adjacência,
    // lista de degrees, vertices e etc.
    for (int i=0; i < t; i++){
        string node;
        cin >> node;
        string node1 = node.substr(0,2);
        string node2 = node.substr(1,2);
        out_degree[node1]++;
        in_degree[node2]++;
        al[node1].push_back(node2);
        vertices.insert(node1);
        vertices.insert(node2);
    }

    // Antes de retornar o caminho euleriano, precisamos primeiramente verificar se ele existe,
    // para isso verificamos se:
    //  1. Todos os vértices têm graus de entrada e saída iguais, exceto dois vértices:
    //    - Um vértice tem o grau de saída exatamente 1 maior que o grau de entrada (o início do caminho).
    //    - Um vértice tem o grau de entrada exatamente 1 maior que o grau de saída (o fim do caminho).
    //  2. O grafo deve ser fortemente conectado (todas as arestas estão acessíveis a partir de qualquer 
    //  vértice conectado ao caminho).
    // Verificaremos primeiro a 1 condição utilizando o in e out degrees, a segunda condição poderá ser
    // verificada ao final do algoritmo
    
    if (hasEulerianPath()) {
        dfs(findStartNode()); // realiza a dfs e faz o caminho
        if (path.size() == t+1) { // pelo tamanho do caminho final, podemos verificar a 2 condição
            cout << "YES" << endl;

            string answer = path[0];
            for(int i=1; i <= t; i++) {
                answer += path[i].substr(1);
            }

            cout << answer << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        //cout << "nao tem caminho" << endl;
        cout << "NO" << endl;
    }

    return 0;
}
