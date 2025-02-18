/*
 * Nome do arquivo: c.cpp
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
int N, Q;
char queryType;
const int MAX = 1000005;
vector<int> seats;

// Não sei bem se exisita uma maneira mais simples/elegantes, mas a 
// única coisa que me veio a cabeça foi segtree, vamos ver no que da

// Para esse problema pensei e utilizar um Node que guarda informações
// para utilizarmos na hora de fazer o merge, estratégia essa muito 
// utilizada nos problemas semanais propostos para esse tipo de assunto
// O node guarda respectivamente:
// maior grupo que começa a esquerda do intervalo,
// maior grupo que começa a direita do intervalo,
// maior grupo no intervalo,
// tamanho do intervalo.
struct Node {
    int left, right, largestGroup, len;
};

Node st[4*MAX];
Node createNode(int value) {
    Node node;
    node.len = 1;
    if (value == 0) {
        node.right = node.left = node.largestGroup = 1;
    } else {
        node.right = node.left = node.largestGroup = 0;
    }

    return node;
}

Node merge(Node& leftNode, Node& rightNode) {
    Node node;
    node.len = leftNode.len + rightNode.len;
    node.left = (leftNode.left == leftNode.len) ? leftNode.len + rightNode.left : leftNode.left;
    node.right = (rightNode.right == rightNode.len) ? rightNode.len + leftNode.right : rightNode.right;
    node.largestGroup = max({leftNode.largestGroup, rightNode.largestGroup, leftNode.right + rightNode.left});
    return node;
}

// Build padrao de segtree
void build(int pos, int start, int end){
    if (start == end) {
        st[pos] = createNode(seats[start]);
        return;
    }

    int mid = (start+end)/2;
    build(2*pos, start, mid);
    build(2*pos+1, mid+1, end);
    st[pos] = merge(st[2*pos], st[2*pos+1]);
}


void update(int pos, int start, int end, int target, int newValue){
    if (start == end) {
        st[pos] = createNode(newValue);
        return;
    }

    int mid=(start+end)/2;
    if (target <= mid) {
        update(2*pos, start, mid, target, newValue);
    } else {
        update(2*pos+1, mid+1, end, target, newValue);
    }

    st[pos] = merge(st[2*pos], st[2*pos+1]);
}

// Função principal
int main() {
    fast_io;
    cin >> N >> Q;
    string s;
    cin >> s;
    
    seats.resize(N+1);
    for(int i=0; i < N; i++) {
        seats[i+1] = s[i] == '0' ? 0 : 1;
    }
    
    build(1, 1, N);

    while(Q--){
        cin >> queryType;
        if (queryType == 'Q') {
            cout << st[1].largestGroup << endl;
        } else {
            int pos;
            cin >> pos;
            if (queryType == 'D') {
                update(1, 1, N, pos, 1);
            } else {
                update(1, 1, N, pos, 0);
            }
        }
    }

    return 0;
}
