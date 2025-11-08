#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, x;

    cin >> n >> x;

    vector<int> weights(n);

    for (int i = 0; i < n; ++i){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    ll l = 0;

    ll r = weights.size() - 1;

    ll answer = 0;

    while (l <= r){
        if (weights[l] + weights[r] <= x){
            answer++;
            l++;
            r--;
        }
        else{
            answer++;
            r--;
        }
    }

    cout << answer;
}


