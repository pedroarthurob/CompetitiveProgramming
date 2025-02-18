#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c;
ll f;
vector<ll> fitems;
ll s;
vector<ll> sitems;

bool calcBoxes(ll nboxes){
    vector<ll> boxes(nboxes);
    ll i = f;
    ll j = s;
    ll fbox = 0;
    ll sbox = nboxes-1;
    while(i || j){
        if (i >= 0) {
            if (boxes[fbox] + fitems[f-i] <= c){
                fbox++;
                i--;
            } else if (boxes[++fbox] + fitems[f-i] <= c) {
                i--;        
            } else {
                break;
            }
        }
        if (j >= 0) {
            if (boxes[sbox] + sitems[s-j] <= c){
                sbox--;
            } else if (boxes[--sbox] + sitems[s-j] <= c) {
                j--;    
            } else {
                break;
            }
        }
    }
    if (i || j) {
        return false;
    } else {
        return true;
    }
}

int main(){
    cin >> c;
    cin >> f;
    fitems.resize(f);
    for (ll i=0; i < f; i++) cin >> fitems[i];
    cin >> s;
    for (ll i=0; i < f; i++) cin >> sitems[i]; 
    
    ll l = 0;
    ll r = f+s;
    ll answer=r;
    while (l<r) {
        ll mid = l+(r-l)/2;
        if (calcBoxes(mid)) {
            r = mid-1;
            answer = mid;
        } else {
            l = mid+1;
        }
    }

    return 0;
}
