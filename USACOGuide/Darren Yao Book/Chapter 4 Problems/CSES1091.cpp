#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    int ticket;
    while (n) {
        cin>>ticket;
        tickets.insert(ticket);
        n--;
    }

    vector<int> customers(m);
    for (int i=0; i < m; i++) {
        cin>>customers[i];
    }

    for (int ticket : tickets) {
        cout << ticket << " ";
    }
    cout << endl;

    for (int customer : customers) {
        cout << customer << " ";
    }
    cout << endl;

    for (int customer: customers) {
        auto ticketFound = tickets.lower_bound(customer);
        
        if (ticketFound != tickets.begin()) {
            ticketFound--;
        }

        if ( ticketFound == tickets.end()) {
            cout << -1 << endl;
        } else {
            cout << *ticketFound << "é esse aqui "<< endl;
            tickets.erase(ticketFound);
        }
    }
}