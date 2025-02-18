/*
 * Nome do arquivo: e.cp
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

// Declaração de variáveis
int A, Q;
int N;

// Não consegui pensar em uma solução que encaixasse bem com as constraints
// vou para os pontos parciais, com constraints mais leves

// Abordagem de bruteforce, pré-computo tudo e salvo os resultados em um array,
// assim as queries serão em tempo constante
int MAXN;
vector<int> truePosition;

void calcPosition(){
    truePosition.assign(MAXN+1, 0);
    string a = to_string(A);
    for(int i=1; i <= MAXN; i++) {
        string s = to_string(i);
        if (s.find(a) == string::npos) {
            truePosition[i] = truePosition[i-1] + 1;
        } else {
            truePosition[i] = truePosition[i-1];
        }
    }
}

bool contains(int num, int A) {
    if (A==0 && num==0) return true;
    while (num > 0) {
        if (num % 10 == A) return true;
        num /= 10;
    }

    return false;
}

void optmizedCalcPosition(){
    truePosition.assign(MAXN+1, 0);
    for(int i=1; i <= MAXN; i++) {
        if (!contains(i, A)) {
            truePosition[i] = truePosition[i-1] + 1;
        } else {
            truePosition[i] = truePosition[i-1];
        }
    }
}

// Função principal
int main() {
    fast_io;
    cin >> A >> Q;
    
    while (Q--) {
        cin >> N;
        cout << truePosition[N] << endl; 
    }

    MAXN = 0;
    vector<int> queries;
    for(int i=0; i < Q; i++) {
        cin >> queries[i];
        MAXN = max(MAXN, queries[i]);
    }

    if (to_string(A).size() == 1) {
        optmizedCalcPosition();
    } else {
        calcPosition();
    }
    
    for(int ni: queries) {
        cout << truePosition[ni] << endl;
    }

    return 0;
}
