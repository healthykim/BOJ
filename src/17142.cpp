#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>

using namespace std;

int min_time = INT_MAX;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(vector<vector<int> > &board) {
    int n = board.size();
    bool visited[n][n]; 
    for(int i=0; i<n; i++) {
        fill_n(visited[i], n, false);
    }
    int max_time = 0;
    queue<pair<int, int> > q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 3) {
                q.push(pair<int, int>(i*n+j, 0));
                visited[i][j] = true;
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first/n; int y = q.front().first%n;
        int time = q.front().second; 
        if(board[x][y] == 0)
            max_time = max(time, max_time);
        if(max_time > min_time) return max_time;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1 || visited[nx][ny]) continue;
            if(board[nx][ny] != 1) {
                visited[nx][ny] = true;
                q.push(pair<int, int>(nx*n + ny, time+1));
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && board[i][j] == 0) return INT_MAX;
        }
    }
    return max_time;
}

void dfs(vector<vector<int> > &board, int index, int n, int m) {
    if(m == 0) {
        int x = bfs(board);
        min_time = min(min_time, x);
        return;
    }
    for(int i=index; i<n*n; i++) {
        int x = i/n; int y = i%n;
        if(board[x][y] == 2) {
            board[x][y] = 3;
            dfs(board, i+1, n, m-1);
            board[x][y] = 2;
        }
    }
}

int solution(vector<vector<int> > board, int n, int m) {
    dfs(board, 0, n, m);
    if(min_time == INT_MAX) return -1;
    return min_time;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > board;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(n);
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    int answer = solution(board, n, m);
    cout << answer << "\n";

    return 0;
}