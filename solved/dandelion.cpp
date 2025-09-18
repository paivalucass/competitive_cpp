#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int t, n;
    
    cin >> t;

    while (t--){
        cin >> n;
        long long v = 0;
        vector<long long> odds;
        long long dandelions = 0;

        for (int i = 0; i < n; ++i){
            cin >> v;
            if (v % 2 != 0){
                odds.push_back(v);
            }
            else{
                dandelions += v;
            }
        }

        if (odds.empty()){
            cout << 0 << "\n";
            continue;
        }

        sort(odds.begin(), odds.end(), greater<int>());
        int s = (int)odds.size();

        int limit = (s + 1) / 2;

        for (int i = 0; i < limit; ++i){
            dandelions += odds[i];
        }

        cout << dandelions << "\n";
    }

    return 0;
}