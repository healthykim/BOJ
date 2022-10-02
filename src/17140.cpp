#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<vector<int> > board;
int R;
int C;

bool sort_v(const pair<int, int> p1, const pair<int, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

void do_R() {
    for(int i=0; i<R; i++) {
        //sort each row
        map<int, int> row;
        for(int j=0; j<C; j++) {
            if(board[i][j] == 0) {
                continue;
            }
            row[board[i][j]]++;
        }
        vector<pair<int, int> > v(row.begin(), row.end());
        sort(v.begin(), v.end(), sort_v);

        int v_size = v.size();
        for(int j=0; j<v_size; j++) {
            board[i][2*j] = v[j].first;
            board[i][2*j+1] = v[j].second;
        }
        for(int j= 2*v.size(); j<C; j++) {
            board[i][j] = 0;
        }
        C = max(C, 2*v_size);
        C = min(C, 100);
        board[i].resize(100);
    }
}

void do_C() {
    for(int i=0; i<C; i++) {
        map<int, int> column;
        for(int j=0; j<R; j++) {
            if(board[j][i] == 0) {
                continue;
            }
            column[board[j][i]]++;
        }
        vector<pair<int, int> > v(column.begin(), column.end());
        sort(v.begin(), v.end(), sort_v);
        int v_size = v.size();
        for(int j=0; j<v_size; j++) {
            board[2*j][i] = v[j].first;
            board[2*j+1][i] = v[j].second;
        }
        for(int j= 2*v_size; j<R; j++) {
            board[j][i] = 0;
        }
        R = max(R, 2*v_size);
        R = min(R, 100);
    }
    board.resize(100);
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;
    board.resize(100);
    for(int i=0; i<100; i++) {
        board[i].resize(100);
    }
    R = 3;
    C = 3;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }
    for(int i=0; i<=100; i++) {
        if(board[r-1][c-1] == k) {
            cout << i << "\n";
            return 0;
        }
        if(C<=R)
            do_R();
        else
            do_C();
    }

    cout << "-1\n";

    return 0;
}