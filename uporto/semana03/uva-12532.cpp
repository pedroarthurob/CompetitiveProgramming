/*
 * Nome do arquivo: uva-12532.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 11/11/2024
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define MAX     100005
#define MAX_ST  800005
#define NEUTRAL 1

// Definições úteis para programação competitiva
typedef long long ll;
typedef pair<int, int> pii;

int v[MAX];      // Array of values
int st[MAX_ST];  // Segtree (in this case storing interval sums)

int n, k;

int get_sing(int x){
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

// Merge contents of nodes a and b
int merge(int a, int b) {
    if (a==0||b==0) return 0;
    return a*b;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end) {
    if (start == end) {
        st[pos] = get_sing(v[start]);
    } else {      
        int middle = start + (end-start)/2;
        build(pos*2, start, middle);
        build(pos*2+1, middle+1, end);
        st[pos] = merge(st[pos*2], st[pos*2+1]);
    }  
}

// Update node x to value r
void update(int pos, int start, int end, int x, int r) {
    if (start>x || end<x) return;
    if (start == end && start==x) {
        st[pos] = get_sing(r);
    } else {      
        int middle = start + (end-start)/2;
        update(pos*2, start, middle, x, r);
        update(pos*2+1, middle+1, end, x, r);
        st[pos] = merge(st[pos*2], st[pos*2+1]);
    }  
}

// Make a query of interval [x,y]
int query(int pos, int start, int end, int x, int y) {
    if (start>y || end<x) return NEUTRAL;
    if (start>=x && end<=y) return st[pos];

    int middle = start + (end-start)/2;
    int a = query(pos*2, start, middle, x, y);
    int b = query(pos*2+1, middle+1, end, x, y);
    return merge(a, b);
}

int main() {
    //fast_io;
    while (cin >> n >> k) {
        for (int i=1; i<=n; i++) cin >> v[i];

        build(1, 1, n);
        string answer="";
        for(int i=0; i < k; i++){
            char command;
            int a, b;
            cin >> command >> a >> b;
            if (command == 'C') {
                update(1, 1, n, a, b);	
            } else {
                int query_result = query(1, 1, n, a, b);
                if (query_result > 0){
                    answer += "+";
                } else if (query_result < 0) {
                    answer += "-";
                } else {
                    answer += "0";
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}
