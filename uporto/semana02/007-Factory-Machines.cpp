#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 2e5 + 5;

ll n, t;
vector<ll> machines;

ll calcProducedMachines(ll candidateTime){
    ll producedMachines = 0;
    for (auto machine: machines){
        producedMachines += candidateTime/machine; 
        if (producedMachines >= t){
            break;
        }
    }

    return producedMachines;
}

int main(){
     
    cin >> n >> t;
    machines.resize(n);
    ll minValue = INT_MAX;
    for (ll i=0; i<n; i++) {
        cin >> machines[i];
        minValue = min(minValue, machines[i]);
    }
    
    ll maxTime = minValue * t;

    ll i=0;
    ll j=maxTime+1;
    ll answer; 
    while (i <= j) {
        ll mid = (i+j)/2;
        if(calcProducedMachines(mid) >= t){
            answer = mid;
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    
    cout << answer << endl;
    return 0;
}

