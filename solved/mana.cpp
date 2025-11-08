#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    long long int answer = 0;
    long long int cur = 0;

    for (int i = 0 ; i < n; ++i){
        long long int v;

        cin >> v;

        if (cur + v < 0){
            answer += abs(cur + v);
            cur = 0;
        }
        else{
            cur += v;
        }
    }

    cout << answer;

}