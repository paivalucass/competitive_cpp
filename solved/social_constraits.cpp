#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, m;

    while (true){
        cin >> n >> m;

        if (!n && !m){
            break;
        } 

        std::vector<int> v(n);
        std::iota(v.begin(), v.end(), 0);
        int counter = 0;

        vector<tuple<int, int, int>> constraints;

        for (int i = 0; i < m; ++i){
            int a, b, c;

            cin >> a >> b >> c;

            constraints.emplace_back(a,b,c);
        }

        do{
            bool ok = true;
            for (auto &[a, b, c] : constraints) {
                int distance = abs(v[a] - v[b]);
                if ((c > 0 && distance > abs(c)) || (c < 0 && distance < abs(c))){
                    ok = false;
                    break;
                }
            }

            if (ok){
                counter++;
            }

        }   while(next_permutation(v.begin(), v.end()));

        cout << counter << "\n";
    }
}