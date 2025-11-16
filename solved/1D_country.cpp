#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> c(n);
    vector<long long int> v(n + 1, 0);

    long long int sum = 0;

    for (int i = 0; i < n; ++i){
        cin >> c[i]; 
    }
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x; 
        sum += x;
        v[i] = sum; 
    }

    int q;

    cin >> q;

    for (int i = 0; i < q; ++i){
        int l , r;

        cin >> l >> r;

        int itl = lower_bound(c.begin(), c.end(), l) - c.begin();
        int itr = upper_bound(c.begin(), c.end(), r) - c.begin();

        if (itl >= itr){
            cout << 0 << "\n"; 
        }
        else{
            long long answer = v[itr] - v[itl];
            cout << answer << "\n"; 
        }
    }
}