/*
 * Nome do arquivo: uva-108.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 26/11/2024
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

int n;

int kadane(vector<int> numbers) {
    int best_sum = INT_MIN;
    int current_sum = 0;
    for (auto number: numbers) {
        current_sum = max(number, current_sum+number);
        best_sum = max(best_sum, current_sum);
    }
    
    return best_sum;
}

// Função principal
int main() {
    fast_io;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int answer = INT_MIN;
    vector<int> temp(n);

    for (int i=0; i < n; ++i) {
        fill(temp.begin(), temp.end(), 0);
        
        for(int j=i; j < n; ++j) {
           
            for (int k=0; k < n; ++k) {
                temp[k] += matrix[k][j];
            }
            
            int current_sum = kadane(temp);
            answer = max(current_sum, answer);
        }


    }

    cout << answer << endl;
    return 0;
}
