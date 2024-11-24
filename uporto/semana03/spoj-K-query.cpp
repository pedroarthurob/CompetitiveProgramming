/*
 * Nome do arquivo: spoj-K-query.cpp
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
#define MAX 30005
// Definições úteis para programação competitiva
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int n, q;
vector<int> st[4*MAX];
vector<int> values(MAX);

struct Query{
    int x, y, k, id;
};

vector<Query> queries;
vector<int> results;

void build(int pos, int start, int end){
    if (start == end) {
        st[pos].push_back(values[start]);
    } else {
        int mid = start + (end-start)/2;
        build(pos*2, start, mid);
        build(pos*2+1, mid+1, end);
        
        merge(st[pos*2].begin(), st[pos*2].end(),
                st[pos*2+1].begin(), st[pos*2+1].end(),
                back_inserter(st[pos]));
    }

}

int query(int pos, int start, int end, int x, int y, int k) {
    if (start > y || end < x) return 0;
    if (start >= x && end <= y) {
        return st[pos].end() - upper_bound(st[pos].begin(), st[pos].end(), k); 
    }

    int mid = start + (end-start)/2;
    return query(pos*2, start, mid, x, y, k) + query(pos*2+1, mid+1, end, x, y, k);
}


int main() {
    cin >> n;
    for(int i=1; i<=n;i++) cin>>values[i];
    build(1, 1, n);
    cin >> q;
    queries.resize(q);
    results.resize(q);
    for(int i=0; i<q;i++) {
        cin >> queries[i].x >> queries[i].y >> queries[i].k;
        queries[i].id = i;     
    }

    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b){
        return a.k < b.k;
    });

    for (const auto &qr: queries) {
        results[qr.id] = query(1, 1, n, qr.x, qr.y, qr.k);
    }

    for (int i=0; i<q; i++) cout << results[i] << endl;
    return 0;
}
