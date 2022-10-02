#include <string>
#include <vector>
#include <map>
#include<iostream>

using namespace std;
int N;
int board[25][25];
bool visited[25][25];
vector<int> areas;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int result = 0;

void dfs(int x, int y, int area) {
    areas[area] += 1;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || nx > N-1 || ny < 0 || ny > N-1) continue;
        if(board[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, area);
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j] && board[i][j] != 0) {
                visited[i][j] = true;
                areas.push_back(0);
                dfs(i, j, result);
                result ++;
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << result << "\n";
    for(int i=0; i<result; i++)
        cout << areas[i] << "\n";
    


    
    return 0;
}