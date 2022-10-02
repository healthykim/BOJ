#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int dx[4] = {0,0,1,-1}; //right, left, up, down
int dy[4] = {1,-1,0,0}; //right, left, up, down

int ox[4][4] = {{0,0,0,1}, {0,0,0,-1}, {0,1,2,1}, {0,1,2,1}}; // ㅜ ㅗ ㅏ ㅓ
int oy[4][4] = {{0,1,2,1}, {0,1,2,1}, {0,0,0,1}, {0,0,0,-1}}; // ㅜ ㅗ ㅏ ㅓ

bool** check;
int** board;    
int N, M;
int result;


void dfs(int x, int y, int sum, int depth) {

    if(depth == 4) {
        result = max(result, sum);
        return;
    }

    for(int i=0; i<4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x <0 || new_y < 0 || new_x >= N || new_y >= M || check[new_x][new_y]) {
            continue;
        }
        
        check[new_x][new_y] = true;
        dfs(new_x, new_y, sum + board[new_x][new_y], depth + 1);
        check[new_x][new_y] = false;
    }
}

void check_O(int x, int y) {
    for(int i=0; i<4; i++) {
        bool valid = true;
        int sum = 0;
        for(int j=0; j<4; j++) {
            int new_x = x + ox[i][j];
            int new_y = y + oy[i][j];
            
            if(new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) {
                valid = false;
                break;
            }
            sum += board[new_x][new_y];
        }
        if(valid){
            result = max(sum, result);
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board = new int*[N];
    check = new bool*[N];
    result = -1;

    for(int i=0; i<N; i++) {
        board[i] = new int[M];
        check[i] = new bool[M];
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            check[i][j] = false;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            check[i][j] = true;
            dfs(i, j, board[i][j], 1);
            check[i][j] = false;
            check_O(i, j);
        }
    }
    
    
    cout << result << "\n";

	return 0;
}







