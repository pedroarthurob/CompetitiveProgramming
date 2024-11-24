/*
 * Nome do arquivo: spoj-LITE.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 15/11/2024
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define MAX 100005

// Definições úteis para programação competitiva
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int values[MAX];
int st[4*MAX];
int lazy[4*MAX];

int merge(int a, int b) {
    return a+b;
}

void build(int pos, int start, int end) {
    if (start == end) {
       st[pos] = values[start];
    } else {
        int mid = start + (end-start)/2;
        build(pos*2, start, mid);
        build(pos*2+1, mid+1, end);
        st[pos] = merge(st[pos*2], st[pos*2+1]);
    }
}

void propagate(int pos, int start, int end) {
    if (lazy[pos] % 2 != 0) {
        st[pos] = (end-start+1) - st[pos];

        if (start != end) {
            lazy[pos*2] += lazy[pos];
            lazy[pos*2+1] += lazy[pos];
        }
    } 
    lazy[pos] = 0;
}

void updateRange(int pos, int start, int end, int l, int r) {
    propagate(pos, start, end);
    if (start>r|| end<l) return;
    if (start >= l && end<=r) {
        st[pos] = (end-start+1) - st[pos];

        if (start != end) {
            lazy[pos*2] += 1;
            lazy[pos*2+1] += 1;
        }
    } else {  
        int middle = start + (end-start)/2;
        updateRange(pos*2, start, middle, l, r);
        updateRange(pos*2+1, middle+1 , end, l, r);
        st[pos]=merge(st[pos*2], st[pos*2+1]); 
    }
}

int queryRange(int pos, int start, int end, int l, int r) {
    propagate(pos, start, end);
    if (start>r || end<l) return 0;
    
    if (start >=l && end <=r) return st[pos];
    
    int middle = start + (end-start)/2;
    int a = queryRange(pos*2, start, middle, l, r);
    int b = queryRange(pos*2+1, middle+1, end, l, r) ;
    return merge(a,b);
}

// Função principal
int main() {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    for(int i=0; i<m; i++){
        int op, s, e;
        cin >> op >> s >> e;
        if (op == 0) {
           updateRange(1, 1, n, s, e);
        } else {
            cout << queryRange(1, 1, n, s, e) << endl;
        }
    }
    return 0;
}
