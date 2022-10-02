#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int M, N;
int** input;
bool** visited;
int** dp;
int result = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x, int y) {
    if(x == 0 && y == 0) {
        return;
    }
    for(int i=0; i<4; i++) {
        int nx = x+ dx[i]; int ny = y+dy[i];
        if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || visited[nx][ny]) continue;
        if(input[nx][ny] > input[x][y]) {
            if(dp[nx][ny] == -1) {
                dp[nx][ny] = 0;
                visited[nx][ny] = true;
                dfs(nx, ny);
                visited[nx][ny] = false;
            }
            dp[x][y] += dp[nx][ny];
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    input = new int*[N];
    dp = new int*[N];
    visited = new bool*[N];
    for(int i=0; i<N; i++) {
        input[i] = new int[M];
        visited[i] = new bool[M];
        dp[i] = new int[M];
        for(int j = 0; j<M; j++) {
            cin >> input[i][j];
            dp[i][j] = -1;
        }
    }
    visited[N-1][M-1] = true;
    dp[N-1][M-1] = 0;

    dp[0][0] = 1;
    dfs(N-1, M-1);
    cout << dp[N-1][M-1] << "\n";
    
    return 0;
}