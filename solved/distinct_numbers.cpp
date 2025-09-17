#include <bits/stdc++.h> // Not a good thing to do in real conditions (increase compiling time, since it drags all libraries)

using namespace std; 

int main(){
    std::ios::sync_with_stdio(false);  // enabled by default
    std::cin.tie(nullptr);            // actually tied to cout by default
    int n;
    int v;
    cin >> n; 
    set<int> s;

    for (int i = 0; i < n; ++i){
        cin >> v;
        s.insert(v);
    }
    
    cout << s.size();
    

    return 0;
}