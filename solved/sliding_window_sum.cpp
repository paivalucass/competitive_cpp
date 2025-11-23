#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<long long int> v(n+1,0);

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    v[1] = x;
    for (int i = 2; i <= n; ++i){
        v[i] = (a * v[i - 1] + b) % c;
    }

    long long int sum = 0;

    for (int i = 1; i <= k; ++i){
        sum += v[i];
    }

    long long int answer = sum;

    for (int i = k + 1; i <= n; ++i){
        sum += v[i] - v[i - k];
        answer = answer ^ sum;
    }


    cout << answer;
}