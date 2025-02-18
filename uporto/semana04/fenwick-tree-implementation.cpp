#include <bits/stdc++.h>

// o array original precisa começar com um elemento 0
// para isso podemos fazer
// vll original = {0, 1, 0, 1, 2, 3, 2, 1, 1, 0};
//     
// Adiciona 0 no início do vetor
// original.insert(original.begin(), 0);
//

#define LSB(b) (b & -(b))

struct FT {
    vector<int> bt;

    FT (int n) {
        bt.assign(n+1, 0);
    }

    void build(const vector<int> &f) {
        int m = (int)bt.size()-1;
        bt.assign(m+1,0);
        for (size_t i=1; i<= m; ++i) {  //size_t garante que não der over/under flow 
            bt[i] += f[i];
            if (i+LSB(i) <= m) {
                bt[i + LSB(i)] += ft[i];
            }
        }
    }

    FT (const vector<int> &f) { build(f); }





    FT (vector<int> a) : FT (int a.size()) {
        for(size_t i=0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }

    
    int sum () {


    }

    int sum(int l, int r) {

    }

    void add(int idx, int delta) {
        b
    }


}




int main() {


}

