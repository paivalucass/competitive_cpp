#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);


    int n;
    long long total = 0;

    cin >> n;

    vector<long long> w(n);

    for (int i = 0; i < n; ++i){
        cin >> w[i];
        total += w[i];
    }

    long long minimum = LLONG_MAX;
    
    for (int i = 0; i < (1 << n); ++i){
        long long sumSubset1 = 0;
        long long sumSubset2 = 0;

        for (int j = 0; j < n; ++j){
            if (i & (1 << j)){
                sumSubset1 += w[j];
            }
        }

        sumSubset2 = total - sumSubset1;

        if (abs(sumSubset1 - sumSubset2) < minimum){
            minimum = abs(sumSubset1 - sumSubset2);
        }
    }

    cout << minimum;

}