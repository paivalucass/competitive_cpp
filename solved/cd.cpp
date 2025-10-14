#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int d;

    while (cin >> d){
        int n;

        cin >> n;

        vector<long long> s(n);

        for (int i = 0; i < n; ++i){
            cin >> s[i];
        }

        long long final_sum = 0;

        vector<long long> result;

        for (int i = 0; i < (1 << n); ++i){
            long long sum = 0;
            vector<long long> v;

            for (int j = 0; j < n; ++j){
                if (i & (1 << j)){
                    sum += s[j];
                    if (sum > d){
                        break;
                    }
                    v.push_back(s[j]);
                }
            }

            if (sum <= d && sum > final_sum){
                final_sum = sum;
                result = v;
            }
        }

        for (int i = 0; i < result.size(); ++i){
            cout << result[i] << " ";
        }

        cout << "sum:" << final_sum << "\n";
    }
}