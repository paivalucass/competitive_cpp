#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }

    stack<int> stb;

    vector<string> answer;

    int order = 1;

    int steps = 0;

    while (order <= n){
        if (v.back() == order){
            v.pop_back();
            order++;
            answer.push_back("A C");
        }
        else if (stb.top() == order){
            stb.pop();
            order++;
            answer.push_back("B C");
        }
        else if (stb.top() < v.back()){
            cout << -1;
            return 0;
        }
        else{
            stb.push(v.back());
            v.pop_back();
            answer.push_back("A B");
        }
        steps++;
    }

    cout << steps << "\n";
    for (int i = 0; i < answer.size(); ++i){
        cout << answer[i] << "\n";
    }
}