#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;

int dx[5][3] = {{0,0,0}, {-1,0,1}, {-1,0,1}, {-1,-1,-1}, {1,1,1}};
int dy[5][3] = {{0,0,0}, {1,1,1}, {-1,-1,-1}, {-1,0,1}, {-1,0,1}};

int ddx[4] = {0,0,1,-1};
int ddy[4] = {1,-1,0,0};

bool check_path(int xy, int nx, int ny, int d, int r, int c, set<pair<int, int> >& wall) {
    if(nx < 0 || nx > r-1 || ny < 0 || ny > c-1) return false;
    if(d==1 || d==2) {
        int y = xy%c;
        if(wall.find(pair<int, int>(xy, nx*c+y)) == wall.end() && 
            wall.find(pair<int, int>(nx*c+y, nx*c+ny)) == wall.end()) {
                return true;
        }
    }
    else {
        int x = xy/c;
        if(wall.find(pair<int, int>(xy, x*c+ny)) == wall.end() && 
            wall.find(pair<int, int>(x*c+ny, nx*c+ny)) == wall.end()) {
                return true;
        }
    }
    return false;
}

void make_wind(int r, int c, int d, int R, int C, vector<vector<int> >& tem, set<pair<int, int> >& wall) {
    vector<vector<int> > add;
    add.resize(R);
    for(int i=0; i<R; i++) {
        add[i].resize(C);
        fill_n(add[i].begin(), C, 0);
    }
    
    vector<int> next;
    if(d == 1) 
        next.push_back(r*C + c + 1);
    else if(d == 2)
        next.push_back(r*C + c - 1);
    else if(d == 3)
        next.push_back((r-1)*C + c);
    else if(d == 4)
        next.push_back((r+1)*C + c);
    for(int i=5; i>0; i--) {
        vector<int> prev_next = next;
        next.clear();
        for(int j=0; j<prev_next.size(); j++) {
            int xy = prev_next[j];
            int x = xy/C; int y = xy%C;
            add[x][y] = i; 
            for(int k=0; k<3; k++) {
                int nx = x + dx[d][k]; int ny = y + dy[d][k];
                if(check_path(xy, nx, ny, d, R, C, wall)) 
                    next.push_back(nx*C + ny);
            }
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            tem[i][j] += add[i][j];
        }
    }
}

void adjust_tem(int r, int c, vector<vector<int> >& tem, set<pair<int, int> >& wall) {
    vector<vector<int> > add;
    bool visited[r][c];
    add.resize(r);
    for(int i=0; i<r; i++) {
        add[i].resize(c);
        fill_n(visited[i], c, false);
    }
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            for(int k=0; k<4; k++) {
                //상하좌우 인접
                int nx = i + ddx[k]; int ny = j + ddy[k];
                if(nx <0 || nx > r-1 || ny < 0 || ny > c-1 || visited[nx][ny]) continue;
                if(wall.find(pair<int, int>(i*c+j, nx*c+ny)) != wall.end()) continue;
                if(tem[i][j] > tem[nx][ny]) {
                    int delta = (tem[i][j] - tem[nx][ny])/4;
                    add[i][j] -= delta;
                    add[nx][ny] += delta;
                }
                else if(tem[i][j] < tem[nx][ny]) {
                    int delta = (tem[nx][ny] - tem[i][j])/4;
                    add[i][j] += delta;
                    add[nx][ny] -= delta;
                }
            }
            visited[i][j] = true;
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tem[i][j] += add[i][j];
        }
    }
}

void reduce_tem(int r, int c, vector<vector<int> >& tem) {
    for(int i=0; i<c-1; i++) {
        if(tem[0][i] > 0) tem[0][i] -= 1;
    }
    for(int i=0; i<r-1; i++) {
        if(tem[i][c-1] > 0) tem[i][c-1] -= 1;
    }
    for(int i=c-1; i>0; i--) {
        if(tem[r-1][i] > 0) tem[r-1][i] -= 1;
    }
    for(int i=r-1; i>0; i--) {
        if(tem[i][0] > 0) tem[i][0] -= 1;
    }
}

bool check_tem(int r, int c, int k, vector<vector<int> >& tem, vector<vector<int> >& room) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(room[i][j] == 5) {
                if(tem[i][j] < k) {
                    return false;
                }
            }
        }
    }
    return true;
}

int solution(int r, int c, int k, int w, vector<vector<int> >& room, set<pair<int, int> >& wall) {
    int choco = 0;
    vector<vector<int> > tem;
    tem.resize(r);
    for(int i=0; i<r; i++) {
        tem[i].resize(c);
    }

    while(choco <= 100) {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(room[i][j] != 0 && room[i][j] != 5) {
                    make_wind(i, j, room[i][j], r, c, tem, wall);
                }
            }
        }

        adjust_tem(r, c, tem, wall);
        reduce_tem(r, c, tem);
        choco += 1;
        if(check_tem(r, c, k, tem, room)) break;
    }
    return choco;

}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int> > room;
    for(int i=0; i<r; i++) {
        vector<int> row;
        for(int j=0; j<c; j++) {
            int a; cin >> a;
            row.push_back(a);
        }
        room.push_back(row);
    }
    int w;
    cin >> w;
    set<pair<int, int> > wall; // first, second 사이에 벽이 있다는 뜻
    for(int i=0; i<w; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x -= 1; y -= 1; //0,0 sync
        if(t == 1) {
            wall.insert(pair<int, int>(x*c + y, x*c + y+1));
            wall.insert(pair<int, int>(x*c + y+1, x*c + y));
        }
        else {
            wall.insert(pair<int, int>(x*c + y, (x-1)*c + y));
            wall.insert(pair<int, int>((x-1)*c + y, x*c + y));
        }
    }
    cout << solution(r, c, k, w, room, wall) << endl;


    return 0;
}

