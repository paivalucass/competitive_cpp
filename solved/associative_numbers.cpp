#include <bits/stdc++.h> // Not a good thing to do in real conditions (increase compiling time, since it drags all libraries)

using namespace std; 

int main(){
    std::ios::sync_with_stdio(false);  // enabled by default
    std::cin.tie(nullptr);            // actually tied to cout by default
    map<long long, long long> m;
    int q;

    cin >> q;

    for (int i = 0; i < q; ++i){
        int querry;
        long long k, v;
        cin >> querry >> k;

        if (querry){
            cout << m[k] << "\n";
        }
        else{
            cin >> v;
            m[k] = v;
        }
    }
    

    return 0;
}