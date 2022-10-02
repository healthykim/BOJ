#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>

using namespace std;

int N, M;
int** input;
int*** dp;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(int argc, char** argv)
{
    cin >> N >> M;
    input = new int*[N];
    dp = new int**[N];
    for(int i=0; i<N; i++) {
        input[i] = new int[M];
        dp[i] = new int*[M];
        for(int j=0; j<M; j++) {
            scanf("%1d", &input[i][j]);
            dp[i][j] = new int[2];
        }
    }

    queue<pair<int, int> > q;
    q.push(pair<int, int>(0, 0));
    dp[0][0][0] = 1;
    while(!q.empty()) {
        int x = q.front().second/M; int y = q.front().second%M;
        int broke = q.front().first;
        q.pop();
    
        if(x == N-1 && y == M-1) {
            cout << dp[x][y][broke]<<"\n"; return 0;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || dp[nx][ny][broke]) {
                continue;
            }
            if(input[nx][ny]==1) {
                if(broke==0) {
                    dp[nx][ny][1] = dp[x][y][broke] + 1;
                    q.push(pair<int, int>(1, nx*M+ny));
                }
            }
            else {
                dp[nx][ny][broke] = dp[x][y][broke] + 1;
                q.push(pair<int, int>(broke, nx*M+ny));
            }
            
        }


    }
    cout << "-1\n";
    
    return 0;
}