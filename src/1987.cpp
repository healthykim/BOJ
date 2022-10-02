#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int R, C;
char input[20][20];
int result = 0;
vector<char> path;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool isPromising(int x, int y) {
    for(int i=0; i<path.size(); i++) {
        if(path[i] == input[x][y]) {
            return false;
        }
    }
    return true;
}

void dfs(int x, int y) {
    if(path.size()>result)
        result = path.size();
    for(int i=0; i<4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx > R-1 || ny < 0 || ny > C-1) continue;
        if(isPromising(nx, ny)) {
            path.push_back(input[nx][ny]);
            dfs(nx, ny);
            path.pop_back();
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> input[i][j];
        }
    }

    path.push_back(input[0][0]);
    dfs(0, 0);
    cout << result << "\n";


    
    return 0;
}