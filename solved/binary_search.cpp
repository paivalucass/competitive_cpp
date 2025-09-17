#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, q;
    int num;

    cin >> n >> q;

    vector<int> v(n);

    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }

    for (int i = 0; i < q; ++i){
        cin >> num;

        auto it = lower_bound(v.begin(), v.end(), num);

        if (*it == num){
            cout << it - v.begin() << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }

    return 0;
}