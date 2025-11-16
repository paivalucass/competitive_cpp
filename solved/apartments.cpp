#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    ll n, m, k;

    cin >> n >> m >> k;

    vector<ll> sizes(n);

    for (int i = 0; i < n; ++i){
        cin >> sizes[i];
    }

    vector<ll> apart(m);

    for (int i = 0; i < m; ++i){
        cin >> apart[i];
    }

    sort(sizes.begin(), sizes.end());

    sort(apart.begin(), apart.end());

    ll i = 0;
    ll j = 0;
    ll answer = 0;

    while (i != n && j != m){
        if (apart[j] == sizes[i]){
            j++;
            i++;
            answer++;
            continue;
        }

        if (apart[j] + k < sizes[i]){
            j++;
        }
        else if (apart[j] - k > sizes[i]){
            i++;
        }
        else{
            i++;
            j++;
            answer++;
        }
    }

    cout << answer;

}