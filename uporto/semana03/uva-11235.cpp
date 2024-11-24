/*
 * Nome do arquivo: uva-11235.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 18/11/2024
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

const int MAX = 100005;

struct Node {
    int leftValue, leftFrequency;
    int rightValue, rightFrequency;
    int maxFrequency;
};

int n, q;
int a[MAX];
Node st[4*MAX];

Node merge(Node& leftNode, Node& rightNode) {
    Node answer;

    answer.leftValue = leftNode.leftValue;
    answer.leftFrequency = leftNode.leftFrequency;
    if (leftNode.leftValue == rightNode.leftValue) {
        answer.leftFrequency += rightNode.leftFrequency;
    }
    
    answer.rightValue = rightNode.rightValue;
    answer.rightFrequency = rightNode.rightFrequency;
    if (leftNode.rightValue == rightNode.rightValue) {
        answer.rightFrequency += leftNode.rightFrequency;
    }

    answer.maxFrequency = max(leftNode.maxFrequency, rightNode.maxFrequency);
    if (leftNode.rightValue == rightNode.leftValue) {
        answer.maxFrequency = max(answer.maxFrequency, leftNode.rightFrequency+rightNode.leftFrequency);
    }

    return answer;

}

void build(int pos, int start, int end){
    if (start == end) {
        st[pos] = {a[start], 1, a[start], 1, 1};
    } else {
        int mid = start + (end-start)/2;
        build(pos*2, start, mid);
        build(pos*2+1, mid+1, end);
        st[pos] = merge(st[pos*2], st[pos*2+1]);
    }
}

Node query(int pos, int start, int end, int l, int r) {
    if (start > r || end < l) return {0,0,0,0,0};
    if (start >= l && end <= r) return st[pos];

    int middle = start + (end-start)/2;
    Node a = query(pos*2, start, middle, l, r); 
    Node b = query(pos*2+1, middle+1, end, l, r); 
    return merge(a,b);
}

// Função principal
int main() {
    fast_io;
    while(true) {
        cin >> n;
        if (n == 0) break;

        cin >> q;
        for(int i=1; i<=n ; i++) cin >> a[i];
        build(1, 1, n);
        int l, r;
        for(int i=0; i<q ; i++) {
            cin >> l >> r;
            Node answer = query(1, 1, n, l, r);
            cout << answer.maxFrequency << endl;
        }
    }

    return 0;
}



