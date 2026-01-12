#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int N;

    cin >> N;

    vector<vector<int>> C(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> C[i][j];

    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(C[i][j] > C[i][k] + C[k][j]){
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    vector<vector<bool>> necessary(N, vector<bool>(N, true));
    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            if(i == k) continue;
            for(int j = i+1; j < N; ++j){
                if(j == k) continue;
                if(C[i][j] == C[i][k] + C[k][j]){
                    necessary[i][j] = false;
                    necessary[j][i] = false;
                }
            }
        }
    }

    int removed = 0;
    for(int i = 0; i < N; ++i)
        for(int j = i+1; j < N; ++j)
            if(!necessary[i][j]) ++removed;

    cout << removed << '\n';
    return 0;
}
