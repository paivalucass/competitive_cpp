#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;

    cin >> t;

    while (t--){
        int l, m;
        int size;
        string bank;
        queue<int> left;
        queue<int> right;
        
        cin >> l >> m;
        
        l = l * 100;

        for (int i = 0; i < m; ++i){
            cin >> size >> bank;

            if (bank == "left"){
                left.push(size);
            }
            else{
                right.push(size);
            }
        }

        bank = "left";
        int load = 0;
        int result = 0;

        while (!left.empty() || !right.empty()) {
            load = 0;

            if (bank == "left") {
                while (!left.empty() && load + left.front() <= l) {
                    load += left.front();
                    left.pop();
                }
                bank = "right";
            } else {
                while (!right.empty() && load + right.front() <= l) {
                    load += right.front();
                    right.pop();
                }
                bank = "left";
            }

            result++;  // always after a trip
        }

        cout << result << "\n";
    }

}