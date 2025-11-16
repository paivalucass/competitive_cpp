#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; ++i){
        cin >> prices[i];
    }

    int q;

    cin >> q;

    sort(prices.begin(), prices.end());

    while (q--){
        int v;

        cin >> v;

        auto it = upper_bound(prices.begin(), prices.end(), v);

        if (it == prices.end()){
            cout << prices.size() << "\n";
        }

        else{
            cout << it - prices.begin() << "\n";
        }
    }

}