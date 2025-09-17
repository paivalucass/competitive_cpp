#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int t, n;

    cin >> t;

    while (t != 0){
        cin >> n;
        n = n * 2;
        vector<int> v(n);
        int result = 0;
        for (int i = 0; i < n; ++i){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i += 2){
            result += min(v[i], v[i+1]);
        }

        cout << result << "\n";
        t--;
    }

    return 0;
}