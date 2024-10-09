    #include <stdio.h>
    #include <iostream>
    #include <set>

    using namespace std;

    int main(){
        set<int> mySet;

        int n, xi;
        cin >> n;
        while (n) {
            cin >> xi;
            mySet.insert(xi);
            n--;
        }

        cout << mySet.size() << endl;
        return 0;
    }