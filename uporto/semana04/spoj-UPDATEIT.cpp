/*
 * Nome do arquivo: spoj-UPDATEIT.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 27/11/2024
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
const int MAXN = 10005;

ll bit[MAXN];

void update(int idx, int v, int n){
    while (idx <= n){
        bit[idx] += v;
        idx += (idx & -(idx));
    }
}

void update(int l, int r, int v, int n) {
    update(l, v, n);
    update(r+1, -v, n);
}

ll query(int idx){
    ll answer = 0;
    while (idx > 0){
        answer += bit[idx];
        idx -= (idx & -(idx));
    }

    return answer;
}

// Função principal
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n, u;
        cin >> n >> u;
        for(int i=0; i<=n+1; i++) bit[i]=0;
        int l, r, v;
        while(u--) {
            cin >> l >> r >> v;
            l++;
            r++;
            update(l, r, v, n);
        }

        int q;
        cin >> q;
        while (q--){
            int idx;
            cin >> idx;
            idx++;
            cout << query(idx) << endl;
        }
    }    

    return 0;
}
