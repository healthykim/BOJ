#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
vector<vector<pair<int, int> > > board; 
vector<pair<int, int> > fishes; //fish idx - x,y position
int answer = 0;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void move_fish() {
    for(int i=1; i<=16; i++) {
        int x = fishes[i].first; int y = fishes[i].second;
        if(x == -1 && y == -1) continue;
        int dir = board[x][y].second;
        int nx = x + dx[dir]; int ny = y + dy[dir];
        int ndir = dir;
        bool cannotMove = false;
        while(nx < 0 || nx > 3 || ny < 0 || ny > 3 || board[nx][ny].first == -1) {
            ndir += 1; ndir %= 8;
            nx = x + dx[ndir]; ny = y + dy[ndir];
            if(ndir == dir) {
                cannotMove = true;
                break;
            }
        }
        if(cannotMove) continue;
        else {
            pair<int, int> otherFish = board[nx][ny];
            board[nx][ny] = board[x][y];
            board[nx][ny].second = ndir;
            board[x][y] = otherFish;
            fishes[otherFish.first] = pair<int, int>(x, y);
            fishes[i] = pair<int, int>(nx, ny);
        }
    }
}

void dfs(int x, int y, int result) { //shark position, total number
    answer = max(answer, result);
    vector<vector<pair<int, int> > > prev_board(board.size());
    copy(board.begin(), board.end(), prev_board.begin()); 
    vector<pair<int, int> > prev_fishes(fishes.size()); //fish idx - x,y position
    copy(fishes.begin(), fishes.end(), prev_fishes.begin());

    move_fish();
    int dir = board[x][y].second;
    int nx = x; int ny = y;
    for(int i=0; i<3; i++) {
        nx += dx[dir]; ny += dy[dir];
        if(nx < 0 || nx > 3 || ny < 0 || ny > 3 || board[nx][ny].first == 0) continue;
        else {
            int num = board[nx][ny].first;
            int ndir = board[nx][ny].second;
            pair<int, int> p = fishes[num];

            fishes[num] = pair<int, int>(-1, -1);
            board[nx][ny].first = -1;
            board[x][y].first = 0;
            dfs(nx, ny, result + num);
            board[nx][ny].first = num;
            board[nx][ny].second = ndir;
            fishes[num] = p;
            board[x][y].first = -1;
            board[x][y].second = dir;
        }
    }
    board = prev_board;
    fishes = prev_fishes;

}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    board.resize(4);
    fishes.resize(17);
    for(int i=0; i<4; i++) {
        board[i].resize(4);
        for(int j=0; j<4; j++) {
            cin >> board[i][j].first >> board[i][j].second;
            board[i][j].second -= 1;
            fishes[board[i][j].first] = pair<int, int>(i, j);
        }
    }

    int tmp = board[0][0].first;
    fishes[board[0][0].first] = pair<int, int>(-1, -1);
    board[0][0].first = -1;
    dfs(0,0,tmp);
    cout << answer << endl;

    return 0;
}

