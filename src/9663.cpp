#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int N;
int** board;
int result = 0;

bool isPromising(int row, int column) {
    for(int i=0; i<N; i++) {
        if(board[row][i] || board[i][column]) {
            return false;
        }
    }
    int x_bias = row;
    int y_bias = column;
    while(x_bias < N && y_bias < N) {
        if(board[x_bias][y_bias]) {
            return false;
        }
        x_bias ++; y_bias ++;
    }
    x_bias = row;
    y_bias = column;
    while(x_bias >= 0 && y_bias >= 0) {
        if(board[x_bias][y_bias]) {
            return false;
        }
        x_bias --; y_bias --;
    }
    x_bias = row;
    y_bias = column;
    while(x_bias >= 0 && y_bias < N) {
        if(board[x_bias][y_bias]) {
            return false;
        }
        x_bias --; y_bias ++;
    }
    x_bias = row;
    y_bias = column;
    while(x_bias < N && y_bias >= 0) {
        if(board[x_bias][y_bias]) {
            return false;
        }
        x_bias ++; y_bias --;
    }
    return true;
}

void dfs(int row) {
    if(row == N) {
        result ++;
        return;
    }
    for(int i=0; i<N; i++) {
        if(isPromising(row, i)) {
            board[row][i] = 1;
            dfs(row+1);
            board[row][i] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    board = new int*[N];
    for(int i=0; i<N; i++) {
        board[i] = new int[N];
    }
    dfs(0);
    cout << result << endl;

    return 0;
}