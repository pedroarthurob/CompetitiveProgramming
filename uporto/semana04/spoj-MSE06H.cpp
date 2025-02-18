/*
 * Nome do arquivo: spoj-MSE06H.cpp
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

int T;
int N, M, K;

vector<ll> bt(1001);
vector<pii> highways(500000);

ll get(int idx) {
    ll answer = 0;
    while(idx > 0) {
        answer += bt[idx];
        idx -= (idx & -(idx));
    }

    return answer;
}

void update(int idx, int m) {
    while (idx <= m){
        bt[idx]++;
        idx += (idx & -(idx));
    } 
}

int main() {
    fast_io;
    cin >> T;

    for (int i=1; i<= T; ++i){
        
        cin >> N >> M >> K;
        for (int i=0; i<K; ++i) {
            cin >> highways[i].first >> highways[i].second;
        } 
        
        fill(bt.begin(), bt.begin()+M+1, 0);
        sort(highways.begin(), highways.begin()+K);
        
        ll crossings=0;
        for (int i=0; i<K; ++i) {
            crossings += get(M) - get(highways[i].second);
            update(highways[i].second, M);
        }

        cout << "Test case " << i << ": " << crossings << endl;
    }
    return 0;
}
