#include<iostream>
#include<queue>

using namespace std;

int** board;
int** temp;
int N, M;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int contaminate() {
    int safe = 0;
    queue<int> virus;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == 2) {
                virus.push(i*M+j);
            }
        }
    }
    while(!virus.empty()) {
        int x = virus.front()/M;
        int y = virus.front()%M;
        virus.pop();
        
        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x>=0 && new_x<N && new_y>=0 && new_y<M && temp[new_x][new_y] == 0) {
                temp[new_x][new_y] = 2;
                virus.push(new_x*M + new_y);
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(temp[i][j] == 0) {
                safe += 1;
            }
        }
    }
    return safe;
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board = new int*[N];
    temp = new int*[N];
    for(int i=0; i<N; i++) {
        board[i] = new int[M];
        temp[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            temp[i][j] = board[i][j];
        }
    }

    int max_safe = -1;

    for(int i=0; i<N*M; i++) {
        int x_1 = i/M;
        int y_1 = i%M;
        if(temp[x_1][y_1] == 0) {
            for(int j=i+1; j<N*M; j++) {
                int x_2 = j/M;
                int y_2 = j%M;
                if(temp[x_2][y_2] == 0) {
                    for(int k=j+1; k<N*M; k++) {
                        int x_3 = k/M;
                        int y_3 = k%M;
                        if(temp[x_3][y_3] == 0) {
                            temp[x_1][y_1] = 1;
                            temp[x_2][y_2] = 1;
                            temp[x_3][y_3] = 1;
                            max_safe = max(max_safe, contaminate());
                        }
                        for(int i=0; i<N; i++) {
                            for(int j=0; j<M; j++) {
                                temp[i][j] = board[i][j];
                            }
                        }
                    }
                }
            }
        }

    }

    cout << max_safe << "\n";


	return 0;
}