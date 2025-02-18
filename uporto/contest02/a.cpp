/*
 * Nome do arquivo: a.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 17/12/2024
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int T;
int R, C;

vector<vector<char>> snowflakes;
vector<vector<bool>> vis;
map<string, vector<int>> directions = { "n"= [1, 2], } ; 

int dfs(int i, int j, char character, string direction) {
    if (i>=0 && j >= 0 && i < R && j < C && vis[i][j] == false && snowflakes[i][j] == character) {
        vis[i][j] = true;
        int a[8] = {1+dfs(i+1, j, '|'),
                    1+dfs(i-1, j, '|'),
                    1+dfs(i, j+1, '-'),
                    1+dfs(i, j-1, '-'),
                    1+dfs(i-1, j-1, '\\'),
                    1+dfs(i+1, j+1, '\\'),
                    1+dfs(i-1, j+1, '/'),
                    1+dfs(i+1, j-1, '/')
                    };
    
        int answer = INT_MAX; 
        for (auto size: a) {
            answer= min(a[i], answer);
        }

        return answer;
    }
    
    return 0;
}

int main() {
    fast_io;
    cin >> T;
    while (T--){
        cin >> R >> C;
        snowflakes.resize(R, vector<char>(C, '.'));
        vis.resize(R, vector<bool>(C, false));
        for(int i=0; i < R; ++i) {
            for(int j=0; j < C; ++j) {
                cin >> snowflakes[i][j];
            }   
        }

        int answer = INT_MIN;
        for(int i=0; i < R; ++i) {
            for(int j=0; j < C; ++j) {
                if (snowflakes[i][j] == '+') {
                    int calls[8] = {dfs(i+1, j, '|'),
                                    dfs(i-1, j, '|'),
                                    dfs(i, j+1, '-'),
                                    dfs(i, j-1, '-'),
                                    dfs(i-1, j-1, '\\'),
                                    dfs(i+1, j+1, '\\'),
                                    dfs(i-1, j+1, '/'),
                                    dfs(i+1, j-1, '/')
                                    };

                    int inside_size = INT_MAX;
                    for (auto call: calls) {
                        inside_size = min(inside_size, call);
                    }

                    answer = max(inside_size, answer);
                    vis.resize(R, vector<bool>(C, false));
                }
                
            }
        }

        cout << answer << endl;
    }

    return 0;
}
