#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;
int n;
vector<int> heights;
vector<int> costs;

ll calcCost(int height) {
    ll cost = 0;
    for (int k=0; k<n; k++) {
        cost += costs[k]*abs(height-heights[k]); 
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        heights.clear();
        costs.clear();
        heights.resize(n);
        costs.resize(n);
        for (ll i=0; i<n; i++) cin >> heights[i];
        for (ll i=0; i<n; i++) cin >> costs[i];
        
        int i=0;
        int j=10000;
        ll answer = LLONG_MAX;
        while (j-i>3) {
            int middle1 = i + (j-i)/3;
            int middle2 = j - (j-i)/3; 

            ll candidateCost1 = calcCost(middle1);
            ll candidateCost2 = calcCost(middle2);

            if(candidateCost1 < candidateCost2){
                j = middle2-1;
            }else {
                i = middle1+1;
            }
            
        }
        for(int k=i;k<=j;k++){
            answer = min(answer, calcCost(k));
        }
       
        cout << answer << endl;
    }
    return 0;
}
