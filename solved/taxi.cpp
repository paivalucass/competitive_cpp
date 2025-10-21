#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;

    cin >> n;
    
    int c4 = 0;
    int c3 = 0;
    int c2 = 0;
    int c1 = 0;

    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;

        if (x == 4){
            c4++;
        }
        else if (x == 3){
            c3++;
        }
        else if (x == 2){
            c2++;
        }
        else{
            c1++;
        }
    }

    int answer = c4;
    
    int pairs = min(c3, c1);

    c3 -= pairs;
    c1 -= pairs;

    answer += pairs;
    answer += c3;

    answer += c2 / 2;
    if (c2 % 2) {
        answer++;
        c1 -= min(2, c1);
    }


    if (c1 != 0){ 
        answer += ceil(c1 / 4.0);
    }

    cout << answer;
}