#include <bits/stdc++.h> // Not a good thing to do in real conditions (increase compiling time, since it drags all libraries)

using namespace std; 

int main(){
    std::ios::sync_with_stdio(false);  // enabled by default
    std::cin.tie(nullptr);            // actually tied to cout by default
    int t;
    
    cin >> t;
    
    while (t--){
        priority_queue<int, vector<int>, greater<int>> q;
        int n;
        cin >> n;
        while(n--){
            int v;
            cin >> v;
            q.push(v);
        }

        while (q.size() != 1){
            int a, b;
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();

            int c = (a + b) - 1;

            q.push(c);
        }
        cout << q.top() << "\n";
    }

    return 0;
}