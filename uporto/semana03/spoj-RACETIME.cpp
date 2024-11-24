/*
 * Nome do arquivo: spoj-RACETIME.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 16/11/2024
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


vector<vector<int>> blocks;
vector<int> values;
int block_size;

void build(){
    block_size = ceil(sqrt(values.size()));
    blocks.resize(block_size);
    for(int i=0; i<values.size(); i++) {
        blocks[i/block_size].push_back(values[i]);
    }

    for(auto &block: blocks){
        sort(block.begin(), block.end());
    }
}

void update(int i, int x) {
    int old_value = values[i];
    auto& block = blocks[i/block_size]; 
    
    auto it = lower_bound(block.begin(), block.end(), old_value);
    if (it != block.end() && *it==old_value) {
        block.erase(it);
    }
    
    values[i] = x;
    block.insert(upper_bound(block.begin(), block.end(), x),x);
}

int query(int l, int r, int x) {
    int answer = 0;
    int start_block = l/block_size;
    int end_block = r/block_size;

    if (start_block == end_block){
        for(int i=l; i <= r; i++) {
            if (values[i] <= x){
                answer++;
            }
        }
    } else {

        for (int i=l; i < ((start_block+1)*block_size); i++) {
            if (values[i] <= x) {
                answer++;
            }
        }

        for (int i=start_block+1; i < end_block; i++) {
            auto it = upper_bound(blocks[i].begin(), blocks[i].end(), x);
            answer += it - blocks[i].begin(); 
        }

        for (int i=end_block*block_size; i <= r; i++) {
            if (values[i] <= x) {
                answer++;
            }
        }

    }
    return answer;
}

// Função principal
int main() {
    fast_io;
    int n, q;
    cin >> n >> q;
   
    values.resize(n);
    for (int i=0; i<n; i++) cin >> values[i];
    build();
    
    for (int i=0; i<q; i++){
        char op;
        cin >> op;
        if (op == 'C') {
           int l, r, x;
           cin >> l >> r >> x;
           cout << query(--l, --r, x) << endl;

        } else {
            int i, x;
            cin >> i >> x;
            update(--i, x);

        }
    }
    return 0;
}
