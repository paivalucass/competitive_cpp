#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int n;
    string w;
    string a;

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> w;
        a = w;
        int f = 0;
        for (int j = w.size() - 1; j >= 0; --j){
            if (w[j] == 'p'){
                a[f] = 'q';
            }
            else if (w[j] == 'q'){
                a[f] = 'p';
            }
            else{
                a[f] = 'w';
            }
            f++;
        }
        cout << a << "\n";
    }

    return 0;
}