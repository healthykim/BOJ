#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int N;
char** input;
int** board;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int x, int y) {
    queue<int> q;
    q.push(x*N+y); board[x][y] = 1;
    while(!q.empty()) {
        int x = q.front()/N; int y = q.front()%N;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1 || board[nx][ny]!= 0) {
                continue;
            }
            else {
                if(input[nx][ny] == input[x][y]) {
                    board[nx][ny] = 1;
                    q.push(nx*N+ny);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    input = new char*[N];
    board = new int*[N];
    for(int i=0; i<N; i++) {
        input[i] = new char[N];
        board[i] = new int[N];
        for(int j=0; j<N; j++) {
            cin >> input[i][j];
        }
    }

    int result1 = 0; int result2 = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == 0) {
                bfs(i, j);
                result1 += 1;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            board[i][j] = 0;
            if(input[i][j] == 'R') {
                input[i][j] = 'G';
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == 0) {
                bfs(i, j);
                result2 += 1;
            }
        }
    }
    

    cout << result1 << " " << result2 << "\n";
    return 0;
}