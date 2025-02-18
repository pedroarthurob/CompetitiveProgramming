# include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_N = (ll)2e5 + 5;

ll n, k;
ll a[MAX_N];
multiset<ll> up;
multiset<ll> low;
ll sumLow, sumUp;

void window_insert(ll value) {
    ll current_median = *low.rbegin();
    if (value > current_median) {
        up.insert(value);
        sumUp += value;
        if (up.size() > k/2){
            ll value_to_move = *up.begin();
            sumUp -= value_to_move;
            low.insert(value_to_move);
            sumLow += value_to_move;
            up.erase(up.find(value_to_move));
        }
    } else {
        low.insert(value);
        sumLow += value;
        if (low.size() > (k+1) /2){
            ll value_to_move = *low.rbegin();
            sumLow -= value_to_move;
            up.insert(value_to_move);
            sumUp += value_to_move;
            low.erase(low.find(value_to_move));
        }
    }
}

void window_delete(ll value) {
    if (up.find(value) != up.end()) {
        up.erase(up.find(value));
        sumUp -= value;
    } else {
        low.erase(low.find(value));
        sumLow -= value;
    }
    if (low.empty()){
        ll value_to_move = *up.begin();
        low.insert(value_to_move);
        sumLow += value_to_move;
        up.erase(up.find(value_to_move)); 
        sumUp -= value_to_move;
    }
}


ll window_median() {
    return (k % 2 == 0) ? 0 : (*low.rbegin());
}

int main(){
    cin >> n >> k;
    for (ll i=0; i<n; i++) cin >> a[i];
    low.insert(a[0]);
    sumLow += a[0];
    
    for (ll i=1; i<k; i++) window_insert(a[i]);
    cout << sumUp - sumLow + window_median();
    if (n != -1) cout << " ";

    for (ll i=k; i<n; i++){
        if (k == 1) {
            window_insert(a[i]);
            window_delete(a[i-k]);
        } else {
            window_delete(a[i-k]);
            window_insert(a[i]);
        }

        cout << sumUp - sumLow + window_median(); 
        if (i != n-1) cout << " ";
    }

    cout << endl;
    return 0;
}
