#include<iostream>

using namespace std;

int look_left[4] = {3,0,1,2}; // up right down left -> left up right down
int dx[4] = {-1, 0, 1, 0}; // up right down left
int dy[4] = {0, 1, 0, -1}; // up right down left

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int **board;
    bool **clear;
    int now_x, now_y, now_direction;
    cin >> N >> M;
    cin >> now_x >> now_y >> now_direction;

    board = new int*[N];
    clear = new bool*[N];
    for(int i=0; i<N; i++) {
        board[i] = new int[M];
        clear[i] = new bool[M];
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            clear[i][j] = false;
        }
    }

    bool done = false;
    bool from_one = true;
    int area = 0;

    while(!done) {
        if(from_one){
            //case 1
            clear[now_x][now_y] = true;
            area += 1;
            from_one = false;
        }
        int i=0;
        for(; i<4; i++) {
            now_direction = look_left[now_direction]; // case 2-1's first step & case 2-2 : rotate
            if (!clear[now_x + dx[now_direction]][now_y + dy[now_direction]] && board[now_x + dx[now_direction]][now_y + dy[now_direction]] != 1) {
                //case 2-1 : move
                now_x += dx[now_direction];
                now_y += dy[now_direction];
                from_one = true;
                break;
            }
        }
        if(i == 4) {
            // returned to the first direction
            int back = look_left[look_left[now_direction]];
            if(board[now_x + dx[back]][now_y + dy[back]] == 1) {
                // case 2-4
                done = true;
            }
            else {
                now_x += dx[back];
                now_y += dy[back];
            }
        }
    }

    cout << area << "\n";

	return 0;
}