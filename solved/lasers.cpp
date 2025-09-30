#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--){
        int m, n, x, y;
        int cross_x = 0; 
        int cross_y = 0;
        cin >> n >> m >> x >> y;

        for (int i = 0; i < n; ++i){
            int k;
            cin >> k;
            if (k <= y){
                cross_y++;
            }
        }

        for (int i = 0; i < m; ++i){
            int k;
            cin >> k;
            if (k <= x){
                cross_x++;
            }
        }
        cout << cross_x + cross_y << "\n";
    }
}