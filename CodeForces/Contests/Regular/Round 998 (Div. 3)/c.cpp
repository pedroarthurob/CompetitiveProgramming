/*
 * Nome do arquivo: c.cpp
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

int t;
int n, k;
vector<int> sequence;

int contarParesQueSomamX(int x) {
    unordered_map<int, int> freq;
    int contador = 0;
    for (int num : sequence) {
        freq[num]++;
    }

    for (int num : sequence) {
        if (freq[num] > 0) {
            int complemento = x - num;
            if (freq[complemento] > 0) {
                if (num == complemento && freq[num] > 1) {
                    contador++;
                    freq[num] -= 2;
                } else if (num != complemento) {
                    contador++;
                    freq[num]--;
                    freq[complemento]--;
                }
            }
        }
    }
    return contador;
}

// Função principal
int main() {
    fast_io;
    cin >> t;

    while (t--) {
        sequence.clear();
        cin >> n >> k;
        for(int i=0; i < n; i++) {
            int number;
            cin >> number;
            sequence.push_back(number);
        }

        cout << contarParesQueSomamX(k) << endl;
    }

    return 0;
}
