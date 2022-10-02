#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct shark {
    bool exist;
    int s;
    int d;
    int z;
    shark() {
        exist = false;
    }
    shark(int s_, int d_, int z_) {
        s = s_; d = d_; z = z_; exist = true;
    }
};


int R, C, M, result;
struct shark map[101][101]; //상어 저장
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void do_fishing(int column) {
    for(int i = 1; i<=R; i++) {
        if(map[i][column].exist) {
            map[i][column].exist = false;
            result += map[i][column].z;
            return;
        } 
    }
}

void move_sharks() {
    struct shark new_map[R+1][C+1]; //이동 후의 상어 저장
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(map[i][j].exist) {
                int new_s = map[i][j].s;
                if(map[i][j].d == 1 || map[i][j].d == 2) {
                    new_s %= (R-1) * 2;
                }
                else {
                    new_s %= (C-1) * 2;
                }
                int new_x = i;
                int new_y = j;
                for(int k=0; k<new_s; k++) {
                    new_x += dx[map[i][j].d];
                    new_y += dy[map[i][j].d];
                    if(new_x >= 1 && new_x <= R && new_y >=1 && new_y <= C) {
                        continue;
                    }
                    else {
                        new_x -= dx[map[i][j].d];
                        new_y -= dy[map[i][j].d];
                        if(map[i][j].d == 1 || map[i][j].d == 3) {
                            map[i][j].d += 1;
                        }
                        else {
                            map[i][j].d -= 1;
                        }                   
                        new_x += dx[map[i][j].d];
                        new_y += dy[map[i][j].d];     
                    }
                }
                if(new_map[new_x][new_y].exist) {
                    if(map[i][j].z > new_map[new_x][new_y].z) {
                        new_map[new_x][new_y] = shark(map[i][j]);
                        new_map[new_x][new_y].exist = true;
                    }
                }
                else{
                    new_map[new_x][new_y] = shark(map[i][j]);
                        new_map[new_x][new_y].exist = true;
                }
            }
        }
    }
    for(int i=0; i<=R; i++) {
        for(int j=0; j<=C; j++) {
            map[i][j] = new_map[i][j];
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;
    int r,c,s,d,z;
    for(int i=0; i<M; i++) {
        cin >> r >> c >> s >> d >> z;
        map[r][c] = shark(s, d, z);
    }
    result = 0;
    for(int i=1; i<=C; i++) {
        do_fishing(i);
        move_sharks();
    }

    cout << result << "\n";
    return 0;
}
