#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll q;
ll n;

bool check(ll vertices, ll edges) {
    if (vertices <= 1) {
        return edges == 0;
    }

    ll bridges_edges = edges % 2 == 0 ? edges/2 : edges/2+1;
    vertices -= bridges_edges;
    edges -= bridges_edges;
    return vertices >= 0 && (vertices*(vertices-1)/2) >= edges;

}

int main() {
    cin >> q;
    while(q--){
        cin >> n;
        
        ll l=0;
        ll r= n * (n-1) /2;
        ll answer = LLONG_MIN;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if (check(n, mid)) {
                l = mid+1;
                answer = max(answer, mid);
            } else {
                r = mid-1;
            }
        }
        cout << answer << endl;
    }
}
