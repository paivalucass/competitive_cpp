#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int t;

    cin >> t;


    while (t--){

        int n, q;

        cin >> n >> q;

        vector<int> sugar(n);

        for (int i = 0; i < n; ++i){
            cin >> sugar[i];
        }

        sort(sugar.begin(), sugar.end(), greater<int>());

        vector<int> prefix_sum(n);

        ll sum = 0;
        for (int i = 0; i < n; ++i){
            sum += sugar[i];
            prefix_sum[i] = sum;
        }

        for (int i = 0; i < q; ++i){
            int v;

            cin >> v;

            auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), v);

            if (it == prefix_sum.end()){
                cout << -1 << "\n";
            }
            else {
                cout << (it - prefix_sum.begin()) + 1 << "\n"; 
            }
        }
    }
}