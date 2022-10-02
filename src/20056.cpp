#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

struct  fire {
    int r, c;
    int m, s, d;
    fire(int fr, int fc, int fm, int fs, int fd) {
        m = fm; s = fs; d = fd;
        r = fr; c = fc;
    }
    fire(int nx, int ny) {
        r = nx; c = ny;
    }
};

void move_fire(int n, vector<vector<vector<fire> > >& board) {
    vector<fire> fires;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<board[i][j].size(); k++) {
                fire ball = board[i][j][k];
                int nx = (i + dx[ball.d]*ball.s); int ny = (j + dy[ball.d]*ball.s);
                while(nx < 0) nx += n;
                while(ny < 0) ny += n;
                nx %=n; ny %=n;
                fires.push_back(fire(nx, ny, ball.m, ball.s, ball.d));
            }
            board[i][j].clear();
        }
    }
    for(int i=0; i<fires.size(); i++) {
        fire ball = fires[i];
        board[ball.r][ball.c].push_back(ball);
    }
}

void sum_fire(int n, vector<vector<vector<fire> > >& board) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j].size() < 2) continue;

            int m_sum = 0; int s_sum = 0; int ball_num = board[i][j].size();
            bool hasOdd = false; bool hasEven = false;
            for(int k=0; k<board[i][j].size(); k++) {
                m_sum += board[i][j][k].m;
                s_sum += board[i][j][k].s;
                if(board[i][j][k].d%2 == 0) hasEven = true;
                else hasOdd = true;
            }
            board[i][j].clear();

            if(m_sum/5 == 0) continue;
            for(int k=0; k<4; k++) {
                if(hasOdd && hasEven) {
                    board[i][j].push_back(fire(i, j, m_sum/5, s_sum/ball_num, 2*k+1));
                }
                else {
                    board[i][j].push_back(fire(i, j, m_sum/5, s_sum/ball_num, 2*k));
                }
            }
        }
    }
}



int solution(int n, int m, int k, vector<vector<vector<fire> > >& board) {

    for(int i=0; i<k; i++) {
        move_fire(n, board);
        sum_fire(n, board);
    }
    int sum_m = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<board[i][j].size(); k++) {
                sum_m += board[i][j][k].m;
            }
        }
    }
    return sum_m;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<fire> > > board;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(n);
    }
    
    for(int i=0; i<m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r-1][c-1].push_back(fire(r-1, c-1, m, s, d));
    }

    cout << solution(n, m, k, board) << endl;

    return 0;
}

