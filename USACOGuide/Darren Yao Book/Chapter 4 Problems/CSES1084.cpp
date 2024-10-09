#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> applicants;
    int applicantsi;
    while (n) {
        cin >> applicantsi;
        applicants.push_back(applicantsi);
        n--;
    }

    vector<int> apartments;
    int apartmenti;
    while (m) {
        cin >> apartmenti;
        apartments.push_back(apartmenti);
        m--;
    }

    
    

}