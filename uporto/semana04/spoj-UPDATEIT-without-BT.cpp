/*
 * Nome do arquivo: spoj-UPDATEIT-without-BT.cpp
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

const int MAXN = 10005;

int a[MAXN];

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n, u;
        cin >> n >> u;
        for (int i=0; i<n; ++i) {
            a[i] = 0;
        }
        
        while (u--) {
            int l, r, v;
            cin >> l >> r >> v;
            a[l] += v;
            a[r+1] -= v;
        }
        
        int sum = 0;
        for(int i=0; i<n; ++i) {
            sum += a[i];
            a[i] = sum;
        }

        int q;
        cin >> q;
        while (q--) {
            int index;
            cin >> index;
            cout << a[index] << endl;
        }
    }


    return 0;
}
