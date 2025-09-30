#include <bits/stdc++.h>

// solved with multiset due to the need to erase elements in a shorter time

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, m;

    multiset<int> tickets;

    cin >> n >> m;

    for (int i = 0; i < n; ++i){
        int v;
        cin >> v;
        tickets.insert(v);
    }

    while (m--){
        int v;
        cin >> v;
        auto it = tickets.upper_bound(v);

        if (it == tickets.begin()){
            cout << -1 << "\n";
        }
        else{
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}