/*
 * Nome do arquivo: spoj-PPATH.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 15/01/2025
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// Esse problema pode ser 'facilmente' resolvido com uma bfs, mas como poderá ver,
// reduzir o problema para um grafo demanda um certo cuidado.
// Para isso, primeior iremos utilizar o Crivo de Eratóstenes para descobrir de forma eficiente
// todos os primos de 4 dígitos. A partir disso, iremos então gerar um grafo que conecta todos os primos
// que diferem 1 dígito entre sí. Assim, para saber se podemos chegar de um dado número primo a outro, modificando
// um algarismo por vez, basta fazer a bfs nesse grafo resultante, verificando se podemos chegar de um número a outro
// e se possível, em quantos passos.


// Declaração dos tipos das variáveis
int t;
int start, finish;

vector<int> primeNumbers;
vector<vector<int>> adj;
vector<int> dist;
map<int, int> valueToIndex;

// Crivo de Eratóstenes, usado para descobrir os primos até um dado n
void Sieve() {
    int n = 9999;
    bool isPrime[n+1];
    memset(isPrime, true, sizeof(isPrime));

    for (int p=2; p*p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p*p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p=1000; p <= n; p++) {
        if (isPrime[p]) {
            primeNumbers.push_back(p);
        }
    }
}

// Criar um comparador que verifica se dois número diferem entre sí por 1 dígito
// vai ser útil para deixar o código mais limpo e compreensível
bool comparator(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);

    int diff_counter = 0;

    for(int i=0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff_counter++;
        }

        if (diff_counter > 1) {
            return false;
        }
    }

    return (diff_counter == 1);
}

// Cria a lista de adjacência do grafo, unindo os números primos que diferem por somente 1 dígito
void createAdjList() {
    adj.resize(primeNumbers.size());
    for(int i=0; i < primeNumbers.size(); i++) {
        for(int j=i+1; j < primeNumbers.size(); j++) {
            if (comparator(primeNumbers[i], primeNumbers[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

// Como faremos várias consultas, precomputar isso deixa o código mais eficiente
// pois os números primos estão unidos internamente pelos seus índices, não seus valores
// assim ter esse mapa pronto "come in handy"
void createAuxValueToIndex() {
    for(int i=0; i < primeNumbers.size(); i++) {
        valueToIndex[primeNumbers[i]] = i;
    }
}

// A nossa estrela do show, faz uma busca em largura, o que nos ajuda a ter um controle da 
// 'distância' ou seja, quantos passos de um número ao outro
int bfs(int start, int finish) {
    if (start == finish) {
        return 0;
    }

    dist.assign(primeNumbers.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int current_number = q.front();
        q.pop();
        for(int neighbor: adj[current_number]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[current_number] + 1;
                q.push(neighbor);

                if (neighbor == finish) {
                    return dist[neighbor];       
                }
            }
        }
    }

    return -1;

}

// Função principal
int main() {
    fast_io;
    Sieve();
    createAdjList();
    createAuxValueToIndex();

    //cout << primeNumbers.size() << " tamanho" << endl;
    cin >> t;
    while(t--){
        cin >> start >> finish;
        int answer = bfs(valueToIndex[start], valueToIndex[finish]);
        if (answer != -1) {
            cout << answer;
        } else {
            cout << "Impossible";
        }
        
        cout << endl;
    }


    return 0;
}
