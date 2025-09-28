#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;  

        while (true) {
            vector<int> perm(N);
            cin >> perm[0];
            if (perm[0] == 0) break; 

            for (int i = 1; i < N; ++i) {
                cin >> perm[i];
            }

            stack<int> st;
            int current = 1; // next arriving coach from A
            bool possible = true;

            for (int x : perm) {
                // push until we can match x
                while (current <= N && (st.empty() || st.top() != x)) {
                    st.push(current);
                    current++;
                }

                if (st.top() == x) {
                    st.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) cout << "Yes\n";
            else cout << "No\n";
        }

        cout << "\n"; 
    }

    return 0;
}
