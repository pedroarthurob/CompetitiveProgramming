/*
 * Nome do arquivo: b.cpp
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
int n, m;

vector<vector<int>> cards;

// Função principal
int main() {
    fast_io;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        
        cards.clear();
        for(int i=0; i < n; i++) {
            vector<int> row(m+1);
    
            for (int j=0; j < m; j++) {
                cin >> row[j];
            }
            row[m] = 2001 + i;
            sort(row.begin(), row.end());
            cards.push_back(row);
        }
        
        sort(cards.begin(), cards.end());

        bool isPossible = true;
        int current = -1; 
        for(int j=0; j < m; j++) {
            for(int i=0; i < n; i++) {
                if (cards[i][j] <= current) {
                    isPossible = false;
                    break;
                } else {
                    current = cards[i][j];
                }
            }
            if (!isPossible) {
                break;
            }
        }
        
        if (isPossible) {
            for(int i=0; i < n; i++) cout << cards[i][m]-2000 << " ";
        } else {
            cout << -1; 
        }

        cout << endl;
    }

    return 0;
}
