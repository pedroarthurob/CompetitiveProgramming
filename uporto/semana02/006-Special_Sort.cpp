#include <bits/stdc++.h>
using namespace std;

int n;
map<int, multiset<int>> bits_map;
int x;

int main(){
    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> x;
        bitset<sizeof(int) * 8> bin(x);
        int bits_count = bin.count();
        bits_map[bits_count].insert(x); 
    }
    
    bool first = true;
    for (auto rit = bits_map.rbegin(); rit != bits_map.rend(); rit++) {
        auto numbers = rit->second;
        for (auto it = numbers.begin(); it != numbers.end(); it++){
            if (!first){
                cout << " ";
            }
            cout << *it;
            first = false;
        
        }
    }

    cout << endl;
    return 0;
}
