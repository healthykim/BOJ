#include<iostream>

using namespace std;

int N;
int board[9][9];
int dx[9] = {-1,0,1,-1,0, 1,-1,0,1};
int dy[9] = {-1,-1,-1,0,0,0,1,1,1};

bool isPossible(int index, int k) {
    //1. row
    int x = index/9;
    for(int i=0; i<9; i++) {
        if(board[x][i] == k) {
            return false;
        }
    }
    //2. column
    int y = index%9;
    for(int i=0; i<9; i++) {
        if(board[i][y] == k) {
            return false;
        }
    }
    //3. 9
    int o_x = x - x%3+1;
    int o_y = y - y%3+1;
    for(int i=0; i<9; i++) {
        if(board[o_x+dx[i]][o_y+dy[i]] == k) {
            return false;
        }
    }
    return true;
}

void dfs(int index) {
    if(index >= 81) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    if(board[index/9][index%9] != 0) {
        dfs(index+1);
    }
    else {
        for(int j=1; j<10; j++) {
            if(isPossible(index, j)) {
                board[index/9][index%9] = j;
                dfs(index+1);
                board[index/9][index%9] = 0;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0);


    return 0;
}