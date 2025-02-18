#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int A, Q;
int MAXN;
vector<int> truePosition;

void calcPosition() {
    truePosition.assign(MAXN + 1, 0);
    string a = to_string(A);
    for (int i = 1; i <= MAXN; i++) {
        string s = to_string(i);
        if (s.find(a) == string::npos) {
            truePosition[i] = truePosition[i - 1] + 1;
        } else {
            truePosition[i] = truePosition[i - 1];
        }
    }
}

bool contains(int num, int A) {
    if (A == 0 && num == 0) return true;
    while (num > 0) {
        if (num % 10 == A) return true;
        num /= 10;
    }
    return false;
}

void optmizedCalcPosition() {
    truePosition.assign(MAXN + 1, 0);
    for (int i = 1; i <= MAXN; i++) {
        if (!contains(i, A)) {
            truePosition[i] = truePosition[i - 1] + 1;
        } else {
            truePosition[i] = truePosition[i - 1];
        }
    }
}

int main() {
    fast_io;
    cin >> A >> Q;

    vector<int> queries(Q);
    MAXN = 0;

    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
        MAXN = max(MAXN, queries[i]);
    }

    if (to_string(A).size() == 1) {
        optmizedCalcPosition();
    } else {
        calcPosition();
    }

    for (int ni : queries) {
        cout << truePosition[ni] << endl;
    }

    return 0;
}

