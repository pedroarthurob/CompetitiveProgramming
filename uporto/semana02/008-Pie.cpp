#include <bits/stdc++.h>
#define pi 3.14159265358979323846264338327950
using namespace std;
typedef long double ll;

int t;
int n, f;
vector<ll> pies;

int calcPie(ll volume) {
    int pieces = 0;
    for (int i=0; i < n; i++) {
        ll piece = pies[i]*pies[i]*pi;
        pieces +=(int) floor(piece/volume);
    }
    return pieces;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> f;
        pies.resize(n);
        ll maxValue = -1;
        ++f; 
        for(int i=0;i < n; i++) {
            cin >> pies[i];
            maxValue = max(maxValue, pies[i]);
        }
        
        ll i=0;
        ll j=maxValue*maxValue*pi;
        ll answer;
        while (j-i >= 1e-6) {
            ll middle = (i+j)/2.0;
            ll candidateAnswer = calcPie(middle); 
            if (candidateAnswer >= f) {
                answer = middle;
                i = middle;
            } else {
                j = middle;
            }
        }
        printf("%.4Lf\n", answer);
        cout <<  endl;
    }
    return 0;
}
