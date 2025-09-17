#include <bits/stdc++.h> // Not a good thing to do in real conditions (increase compiling time, since it drags all libraries)

using namespace std; 


int main(){
    std::ios::sync_with_stdio(false);  // enabled by default
    std::cin.tie(nullptr);            // actually tied to cout by default

    int t;
    string first = "";
    string second = "";
    string third = "";

    cin >> t;

    for (int i = 0; i < t; ++i){
        cin >> first >> second >> third;
        cout << first[0] << second[0] << third[0] << "\n"; 
    }

    return 0;
}