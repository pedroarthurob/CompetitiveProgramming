/*
 * Nome do arquivo: a.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 12/02/2025
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

// Instancia
int N, E;
vector<int> weights;

// Função principal
int main() {
    fast_io;
    cin >> N >> E;
    for(int i=0; i < N; i++) {
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    sort(weights.begin(), weights.end());

    int energy = 0;
    for (int i=0; i < N; i++) {
        energy += weights[i];
        if (energy >= E) {
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}
