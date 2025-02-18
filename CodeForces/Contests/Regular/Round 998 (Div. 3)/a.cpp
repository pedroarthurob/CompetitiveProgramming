/*
 * Nome do arquivo: a.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 19/01/2025
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


int t;
int fibNumbers[5];

int countFibonacciness(int a3) {
    fibNumbers[2] = a3;
    int counter = 0;
    for (int i=0; i < 3; i++) {
        if (fibNumbers[i+2] == fibNumbers[i] + fibNumbers[i+1]) {
            counter++;
        }
    }

    return counter;
}

// Função principal
int main() {
    fast_io;
    cin >> t;

    while(t--) {
        cin >> fibNumbers[0] >> fibNumbers[1] >> fibNumbers[3] >> fibNumbers[4];
        cout << max({countFibonacciness(fibNumbers[0]+fibNumbers[1]), 
                countFibonacciness(fibNumbers[3]-fibNumbers[1]),
                countFibonacciness(fibNumbers[4]-fibNumbers[3])}) << endl;
    }
    
    return 0;
}
