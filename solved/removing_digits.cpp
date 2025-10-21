#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= n; ++i){
        string s = to_string(i);

        for (char c : s){
            int d = c - '0';
            if (d != 0){
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }

    cout << dp[n];

    return 0;
}