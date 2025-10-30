#include <bits/stdc++.h>

using namespace std;


int H, W;
vector<string> grid;
string snuke = "snuke";
vector<int> mov1 = {1, -1 , 0 , 0};
vector<int> mov2 = {0, 0 , 1, -1};

bool dfs(int x, int y, int step, vector<vector<bool>> &visited){
    if (x == H - 1 && y == W - 1) return true;

    visited[x][y] = true;

    int snuke_index = (step + 1) % 5;

    for (int i = 0; i < 4; ++i){
        int nx = x + mov1[i];
        int ny = y + mov2[i];

        if (nx >= H || nx < 0 || ny >= W || ny < 0) continue;

        if (!visited[nx][ny] && grid[nx][ny] == snuke[snuke_index]){
            if (dfs(nx,ny, step+1, visited)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    cin >> H >> W;

    grid.resize(H);

    for (int i = 0; i < H; ++i){
        cin >> grid[i];
    }

    if (grid[0][0] != 's'){
        cout << "No";
        return 0;
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    if (dfs(0,0,0, visited)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}