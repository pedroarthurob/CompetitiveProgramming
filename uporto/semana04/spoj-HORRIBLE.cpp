/*
 * Nome do arquivo: spoj-HORRIBLE.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 25/11/2024
 * Descrição: 
 * Plataforma: 
 * Solução: Alterar tudo pra long long e foi:w
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

typedef long long ll;                           
typedef vector<ll> vll;
typedef vector<int> vi;

ll T, N, C;               // Alterado para long long
ll command, p, q, v;       // Alterado para long long

ll bit1[100005];
ll bit2[100005];

void update1(ll idx, ll n, ll v){               // Alterado para long long
    while (idx <= n){
        bit1[idx] += v;
        idx += (idx & -(idx));
    }
}

void update2(ll idx, ll n, ll v){               // Alterado para long long
    while (idx <= n){
        bit2[idx] += v;
        idx += (idx & -(idx));
    }
}

void update(ll l, ll r, ll n, ll v) {          // Alterado para long long
    update1(l, n, v);
    update1(r+1, n, -v);
    update2(l, n, v*(l-1));
    update2(r+1, n, -v*r);
}

ll query1(ll idx) {                            // Alterado para long long
    ll answer = 0;
    while(idx > 0){
        answer += bit1[idx];
        idx -= (idx & -(idx));  
    }

    return answer;
}

ll query2(ll idx) {                            // Alterado para long long
    ll answer = 0;
    while(idx > 0){
        answer += bit2[idx];
        idx -= (idx & -(idx));  
    }

    return answer;
}

ll sum(ll idx) {                               // Alterado para long long
    return query1(idx)*idx - query2(idx);
}

ll query(ll l, ll r) {                         // Alterado para long long
    return sum(r) - sum(l-1);
}

// Função principal
int main() {
    fast_io;
    cin >> T;
    while (T--) {
        cin >> N >> C;
        for(ll i=0; i <= N+1; ++i) bit1[i]=0, bit2[i]=0;   // Alterado para long long
        while (C--) {
            cin >> command;
            if (command == 0) {
                cin >> p >> q >> v;
                update(p, q, N, v); 
            } else {
                cin >> p >> q;
                cout << query(p, q) << endl;
            }
        }
    }
    return 0;
}
