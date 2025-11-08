#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    vector<ll> arrival(n);
    vector<ll> departure(n);

    for (int i = 0; i < n; ++i){
        cin >> arrival[i] >> departure [i];
    }

    sort(arrival.begin(), arrival.end());

    sort(departure.begin(), departure.end());

    ll a = 0;
    ll d = 0;
    ll answer = 0;
    ll cur = 0;

    while (a != n && d != n){
        if (arrival[a] < departure[d]){
            a++;
            cur += 1;
            answer = max(cur, answer);
        }
        else{
            d++;
            cur--;
        }
    }

    cout << answer;
}