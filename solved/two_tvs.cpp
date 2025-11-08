#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    vector<ll> start(n);
    vector<ll> end(n);

    for (int i = 0; i < n; ++i){
        cin >> start[i] >> end[i];
    }

    sort(start.begin(), start.end());

    sort(end.begin(), end.end());

    ll a = 0;
    ll d = 0;
    string answer = "YES";
    ll cur = 0;

    while (a != n && d != n){
        if (start[a] <= end[d]){
            a++;
            cur += 1;
            if (cur > 2){
                answer = "NO";
                break;
            }
        }
        else{
            d++;
            cur--;
        }
    }

    cout << answer;
}