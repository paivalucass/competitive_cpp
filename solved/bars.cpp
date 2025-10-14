#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--){
        int n, p;

        cin >> n;
        cin >> p;
        vector<int> bars(p);

        for (int i = 0; i < p; ++i){
            cin >> bars[i];
        }

        bool ok = false;
        for (int i = 0; i < (1 << p); ++i){ // run through all subsets
            int sum = 0;

            for (int j = 0; j < p; ++j){
                if (i & (1 << j)){ // Check if that number is in the current subset
                    sum += bars[j];
                }
            }

            if (sum == n){
                cout << "YES" << "\n";
                ok = true;
                break;
            }
        }

        if (!ok){
            cout << "NO" << "\n";
        }
    }
    
}