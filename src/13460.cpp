#include<iostream>
#include<queue>
#include<climits>

using namespace std;
char** board;
int n;
int m;

struct node {
    int R[2];
    int B[2];
    int move;
    void init(int* _R, int* _B, int _move) {
        R[0] = *_R;
        R[1] = *(_R + 1);
        B[0] = *_B;
        B[1] = *(_B + 1);
        move = _move;
    }

};

node move(int* R, int* B, int direction, int move) {
    node result;
    result.init(R, B, move);
    int r_x = result.R[0];
    int r_y = result.R[1];
    int b_x = result.B[0];
    int b_y = result.B[1];
    if(direction == 0) {
        //up
        while (board[r_x-1][r_y] == '.') {
            r_x -= 1;
        }
        if(board[r_x-1][r_y] == 'O'){
            r_x -= 1;
        }
        result.R[0] = r_x;

        while (board[b_x-1][b_y] == '.') {
            b_x -= 1;
        }
        if(board[b_x-1][b_y] == 'O'){
            b_x -= 1;
        }
        result.B[0] = b_x;
        if(!(board[r_x][r_y] == 'O') && result.R[0] == result.B[0] && result.R[1] == result.B[1]) {
            if(*R > *B) {
                result.R[0] = r_x + 1;
            }
            else {
                result.B[0] = b_x + 1;
            }
        }
    }
    else if (direction == 1) {
        //down
        while (board[r_x+1][r_y] == '.') {
            r_x += 1;
        }
        if(board[r_x+1][r_y] == 'O'){
            r_x += 1;
        }
        result.R[0] = r_x;

        while (board[b_x+1][b_y] == '.') {
            b_x += 1;
        }
        if(board[b_x+1][b_y] == 'O'){
            b_x += 1;
        }
        result.B[0] = b_x;
        if(!(board[r_x][r_y] == 'O') && result.R[0] == result.B[0] && result.R[1] == result.B[1]) {
            if(*R < *B) {
                result.R[0] = r_x - 1;
            }
            else {
                result.B[0] = b_x - 1;
            }
        }
    }
    else if (direction == 2) {
        //right
        while (board[r_x][r_y+1] == '.') {
            r_y += 1;
        }
        if(board[r_x][r_y+1] == 'O'){
            r_y += 1;
        }
        result.R[1] = r_y;

        while (board[b_x][b_y+1] == '.') {
            b_y += 1;
        }
        if(board[b_x][b_y+1] == 'O'){
            b_y += 1;
        }
        result.B[1] = b_y;
        if(!(board[r_x][r_y] == 'O') && result.R[0] == result.B[0] && result.R[1] == result.B[1]) {
            if(*(R+1) < *(B+1)) {
                result.R[1] = r_y - 1;
            }
            else {
                result.B[1] = b_y - 1;
            }
        }
    }
    else {
        //left
        while (board[r_x][r_y-1] == '.') {
            r_y -= 1;
        }
        if(board[r_x][r_y-1] == 'O'){
            r_y -= 1;
        }
        result.R[1] = r_y;

        while (board[b_x][b_y-1] == '.') {
            b_y -= 1;
        }
        if(board[b_x][b_y-1] == 'O'){
            b_y -= 1;
        }
        result.B[1] = b_y;
        if( !(board[r_x][r_y] == 'O') && result.R[0] == result.B[0] && result.R[1] == result.B[1]) {
            if(*(R+1) > *(B+1)) {
                result.R[1] = r_y + 1;
            }
            else {
                result.B[1] = b_y + 1;
            }
        }
    }
    result.move += 1;

    return result;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    board = new char*[n];
    int R[2];
    int B[2];
    int min = INT_MAX;
    for (int i=0; i<n; i++) {
        board[i] = new char[m];
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                R[0] = i;
                R[1] = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                B[0] = i;
                B[1] = j;
                board[i][j] = '.';
            }
        }
    }
    queue<node> q;
    node first;
    first.init(R, B, 0);
    q.push(first);

    while(!q.empty()) {
        node now = q.front();
        q.pop();
        if(now.move == 10) {
            continue;
        }
        for(int i=0; i<4; i++) {
            node moved = move(now.R, now.B, i, now.move);
            if(moved.R[0] == now.R[0] && moved.R[1] == now.R[1] && moved.B[0] == now.B[0] && moved.B[1] == now.B[1] ) {
                continue;
            }
            if(board[moved.B[0]][moved.B[1]] == 'O') {
                continue;
            }
            if(board[moved.R[0]][moved.R[1]] == 'O') {
                if(min > moved.move){
                    min = moved.move;
                } 
                continue;
            }
            q.push(moved);
        }

    }
    if(min > 10) {
        cout << "-1\n";
    }
    else {
        cout << min << "\n";
    }
	return 0;
}







