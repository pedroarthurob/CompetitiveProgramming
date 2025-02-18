#include <bits/stdc++.h>
using namespace std;

int n, x;
int Al[2], Ad[2], Ar[2], Au[2];

int get(int D, int L, int U, int R) {
    cout << "? " << D << " " << L << " " << U << " " << R << endl;
    fflush(stdout);
    cin >> x;
    return x;
}

int get2(int D, int L, int U, int R, bool idx) {
    if (idx && L <= Al[0] && Ar[0] <= R && D <= Ad[0] && Au[0] <= U) {
        return 1;
    }
    return 0; 
}

void findRectangle(int D, int L, int U, int R, bool idx) {
    int l = L, r = R;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (get(D, mid, U, R) - get2(D, mid, U, R, idx)) {
            l = mid + 1;
            Al[idx] = mid;
        } else {
            r = mid - 1;
        }
    }

    l = Al[idx], r = R;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (get(D, Al[idx], U, mid) - get2(D, Al[idx], U, mid, idx)) {
            r = mid - 1;
            Ar[idx] = mid;
        } else {
            l = mid + 1;
        }
    }

    l = D, r = U;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (get(mid, Al[idx], U, Ar[idx]) - get2(mid, Al[idx], U, Ar[idx], idx)) {
            l = mid + 1;
            Ad[idx] = mid;
        } else {
            r = mid - 1;
        }
    }

    l = Ad[idx], r = U;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (get(Ad[idx], Al[idx], mid, Ar[idx]) - get2(Ad[idx], Al[idx], mid, Ar[idx], idx)) {
            r = mid - 1;
            Au[idx] = mid; 
        } else {
            l = mid + 1;
        }
    }
}

int main() {
    cin >> n;

    findRectangle(1, 1, n, n, 0);
    findRectangle(1, 1, n, n, 1);
    
    cout << "! ";
    for (int i = 0; i < 2; i++) {
        cout << Ad[i] << " " << Al[i] << " " << Au[i] << " " << Ar[i] << " ";
    }
    cout << endl;
    fflush(stdout);
    
    return 0;
}

