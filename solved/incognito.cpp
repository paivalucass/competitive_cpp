#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--){
        int n, size;
        cin >> n;
        size = n;
        map<string, int> attributes;

        while (n--){
            string object, type;
            cin >> object >> type;
            
            if (attributes.find(type) != attributes.end()){
                attributes[type]++;
            }
            else{
                attributes[type] = 1;
            }
        }

        if (attributes.size() == 1){
            cout << size << "\n";
        }
        else{
            int total = 1;

            for (auto it = attributes.begin(); it != attributes.end(); ++it) {
                total = total * it->second;
            }
            total += size;
            cout << total << "\n";
        }
    }
}