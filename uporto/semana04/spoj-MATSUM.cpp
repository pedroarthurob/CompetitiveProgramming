/*
 * Nome do arquivo: spoj-MATSUM.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 28/11/2024
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

typedef long long ll;
const int MAXN = 1030;

ll bit[MAXN][MAXN];
ll matrix[MAXN][MAXN];
int n;

void update(int x, int y, int delta){
    while(x <= n){
        int temp_y = y;
        while(temp_y <= n){
            bit[x][temp_y] += delta;
            temp_y += (temp_y & -(temp_y));
        }
        x += (x & -(x));
    }
}

ll query(int x, int y){
    ll answer = 0;
    while(x > 0){
        int temp_y = y;
        while(temp_y > 0) {
            answer += bit[x][temp_y];
            temp_y -= (temp_y & -(temp_y));
        }
        x -= (x & -(x));
    }
    return answer;
}

ll query(int x1, int y1, int x2, int y2){
    ll V = query(x2, y2);
    V -= query(x2, y1-1);
    V -= query(x1-1, y2);
    V += query(x1-1, y1-1);
    return V;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        memset(bit, 0, sizeof(bit));
        memset(matrix, 0, sizeof(matrix));

        string command;
        while (true){
            cin >> command;
            if (command == "SET") {
                int x, y, num;
                cin >> x >> y >> num;
                x++; y++;
                ll delta = num - matrix[x][y];
                matrix[x][y] = num;
                update(x, y, delta);

            } else if (command == "SUM") {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                cout << query(x1, y1, x2, y2) << endl;

            } else {
                break;
            }
        } 
        cout << endl;
    }
    return 0;
}
