#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

struct shark {
    int x; int y; int number;
    int dir; bool isdead;
    vector<vector<int> > ranks;
    shark() {
        x = 0; y = 0; number = 0;
        dir = 0; isdead = false; 
        ranks.resize(5); //1~4 사용
        for(int i=0; i<=4; i++) {
            ranks[i].resize(4);
        }
    }
    shark(int nx, int ny, int nn, int nd, bool ni, vector<vector<int> > nr) {
        x = nx; y = ny; number = nn;
        dir = nd; isdead = ni;
        ranks = nr;
    }
};
vector<shark> sharks;
vector<vector<pair<int, int> > > smell;

void make_smell(int k) {
    for(int i=1; i<sharks.size(); i++) {
        if(sharks[i].isdead) continue;
        shark s = sharks[i];
        smell[s.x][s.y] = pair<int, int>(s.number, k);
    }
}

void move_sharks(int n) {
    for(int i=1; i<sharks.size(); i++) {
        if(sharks[i].isdead) continue;
        shark s = sharks[i];
        int dir = s.dir; int x = s.x; int y = s.y;
        int nx = x; int ny = y; int ndir = dir;
        vector<vector<int> > rank = s.ranks;
        for(int j=0; j<4; j++) {
            nx = x + dx[rank[dir][j]]; ny = y + dy[rank[dir][j]];
            if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1 || smell[nx][ny].first != 0) continue;
            else {
                ndir =rank[dir][j]; break;
            }
        }
        if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1 || smell[nx][ny].first != 0) {
            //냄새가 없는 칸이 없다. 자기 냄새가 있는 칸을 선택
            for(int j=0; j<4; j++) {
                nx = x + dx[rank[dir][j]]; ny = y + dy[rank[dir][j]];
                if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1 || smell[nx][ny].first != s.number) continue;
                else {
                    ndir = rank[dir][j]; break; 
                }
            }
        }
        sharks[i].dir = ndir; sharks[i].x = nx; sharks[i].y = ny;
    }
}

void remove_smell(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(smell[i][j].first == 0) continue;
            smell[i][j].second -= 1;
            if(smell[i][j].second == 0) smell[i][j].first = 0;
        }
    }
}

void remove_sharks() {
    for(int i=1; i<sharks.size(); i++) { 
        if(sharks[i].isdead) continue;
        for(int j=i+1; j<sharks.size(); j++) {
            if(sharks[j].isdead) continue;
            if(sharks[i].x == sharks[j].x && sharks[i].y == sharks[j].y) {
                if(sharks[i].number > sharks[j].number) {
                    sharks[i].isdead = true;
                    break;
                }
                else {
                    sharks[j].isdead = true;
                }
            }
        }
    }
}

bool isOver() {
    for(int i=2; i<sharks.size(); i++) {
        if(sharks[i].isdead == false) return false;
    } 
    return true;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    smell.resize(n);
    for(int i=0; i<n; i++) {
        smell[i].resize(n);
    }
    for(int i=0; i<=m; i++) {
        sharks.push_back(shark());
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a; cin >> a;
            if(a != 0) {
                sharks[a].x = i; sharks[a].y = j;
                sharks[a].number = a;
            }
        }
    }
    for(int i=1; i<=m; i++) {
        cin >> sharks[i].dir;
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<5; j++) {
            for(int k=0; k<4; k++)
                cin >> sharks[i].ranks[j][k];
        }
    }

    make_smell(k);
    for(int i=1; i<=1000; i++) {
        move_sharks(n);
        remove_smell(n);
        remove_sharks();
        make_smell(k);
        if(isOver()) {
            cout << i << endl; 
            break;
        }
        if(i == 1000) {
            cout << "-1\n"; 
            break;
        }
    }
    return 0;
}