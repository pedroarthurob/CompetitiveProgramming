/*
 * Nome do arquivo: uva-10336.cpp
 * Autor: Pedro Arthur de Oliveira Barreto
 * Data de criação: 30/11/2024
 * Descrição:
 * Plataforma:
 * Solução:
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n;
int h, w;

vector<vector<char>> lg_map;
vector<vector<bool>> visited;
map<char, int> languages;

void dfs(int i, int j, char lang) {
    if (i >= 0 && j >= 0 && i < h && j < w && visited[i][j] == false && lg_map[i][j]==lang){
        visited[i][j] = true;

        dfs(i-1, j, lang);
        dfs(i+1, j, lang);
        dfs(i, j+1, lang);
        dfs(i, j-1, lang);
    }
}

int main() {
    fast_io;

    cin >> n;
    int world = 1;
    while (n--) {
        cin >> h >> w;

        lg_map.clear();
        lg_map.resize(h, vector<char>(w, '0'));
        visited.clear();
        visited.resize(h, vector<bool>(w, false));
        languages.clear();

        for(int i=0; i < h; ++i) {
            for (int j=0; j < w; ++j) {
                cin >> lg_map[i][j];
            }
        }

        for(int i=0; i < h; ++i) {
            for (int j=0; j < w; ++j) {
                if (visited[i][j]==false){
                    languages[lg_map[i][j]]++;
                    dfs(i, j, lg_map[i][j]);
                }
            }
        }
        
        vector<pair<char, int>> elements(languages.begin(), languages.end());
        sort(elements.begin(), elements.end(), [](const pair<char, int>& a, const pair<char, int>& b){
            if (a.second != b.second) {
                return a.second > b.second;
            }

            return a.first < b.first;
        });

        cout << "World #" << world << endl;
        world++;
        
        for (const pair<char, int>& e : elements) {
            cout << e.first << ": " << e.second << endl;
        }
    }

    return 0;
}
