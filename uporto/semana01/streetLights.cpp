#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);  
    cin.tie(NULL);  
    int x; // street length
    int n; // number of traffic lights 
    cin >> x >> n;

    set<int> lights_positions {0,x};
    multiset<int> passage_distances {x};
    for (int i=0; i < n; i++) {
        int light;
        cin >> light;

        // Find the two points where we will place the new light in the middle.
        auto point1 = lights_positions.upper_bound(light);
        auto point2 = point1--;
        lights_positions.insert(light); // place the new light

        passage_distances.erase(passage_distances.find(*point2-*point1)); // erase the previous distance between the two points
        passage_distances.insert(light - *point1);
        passage_distances.insert(*point2 - light);

        auto answer = prev(passage_distances.end());
        cout << *answer << " ";
    }

    return 0;
}