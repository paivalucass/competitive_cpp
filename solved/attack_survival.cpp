#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k, q;
    int p;

    cin >> n >> k >> q;

    vector<int> answers(n , 0);

    for (int i = 0; i < q; ++i){
        cin >> p;
        answers[p - 1]++;
    }

    for (int i = 0; i < n; ++i){
        int result = k - (q - answers[i]);

        if (result <= 0){
            cout << "No" << "\n";
        }
        else{
            cout << "Yes" << "\n";
        }
    }
    return 0;
}