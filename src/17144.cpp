#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int R, C, T;
int** room;
int** new_room;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pair<int, int> upper = pair<int, int>(-1, -1);
pair<int, int> lower = pair<int, int>(-1, -1);
int result;

void diffuse() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            int dust = room[i][j];
            if(dust>0) {
                for(int k=0; k<4; k++) {
                    if(i+dx[k] >= 0 && i+dx[k] < R && j+dy[k] >=0 && j+dy[k] < C && room[i+dx[k]][j+dy[k]] != -1) {
                        new_room[i+dx[k]][j+dy[k]] += dust/5;
                        new_room[i][j] -= dust/5;
                    } 
                }
            }
        }
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            room[i][j] = new_room[i][j];
        }
    }
    //upper-right
    for(int i=upper.second+1; i<C-1; i++) {
        room[upper.first][i+1] = new_room[upper.first][i];
    }
    room[upper.first][upper.second+1] = 0;
    room[upper.first+1][upper.second+1] = 0;
    //upper-up
    for(int i=upper.first; i>0; i--) {
        room[i-1][C-1] = new_room[i][C-1];
    }
    //upper-left
    for(int i=C-1; i>=upper.second; i--) {
        room[0][i-1] = new_room[0][i];
    }
    //upper-down
    for(int i=0; i<=upper.first; i++) {
        room[i+1][upper.second] = new_room[i][upper.second];
    }
    room[upper.first][upper.second] = -1;

    //lower-right
    for(int i=lower.second+1; i<C-1; i++) {
        room[lower.first][i+1] = new_room[lower.first][i];
    }
    //lower-down
    for(int i=lower.first; i<R-1; i++) {
        room[i+1][C-1] = new_room[i][C-1];
    }    
    //lower-left
    for(int i=C-1; i>=lower.second; i--) {
        room[R-1][i-1] = new_room[R-1][i];
    }
    room[lower.first][lower.second+1] = 0;
    //lower-up
    for(int i=R-1; i>=lower.first; i--) {
        room[i-1][0] = new_room[i][0];
    }
    room[lower.first][lower.second] = -1;

    result = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            new_room[i][j] = room[i][j];
            if(room[i][j] != -1) {
                result += room[i][j];
            }
        }
    }

}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> T;
	room = new int* [R];
	new_room = new int* [R];
    for(int i=0; i<R; i++) {
        room[i] = new int[C];
        new_room[i] = new int[C];
        for(int j=0; j<C; j++) {
            cin >> room[i][j];
            new_room[i][j] = room[i][j];
            if(room[i][j] == -1) {
                if(upper.first == -1) {
                    upper = pair<int, int>(i, j);
                }
                else {
                    lower = pair<int, int>(i, j);
                }
            }
        }
    }
    for(int i=0; i<T; i++) {
        diffuse();
    }
    cout << result << "\n";
    return 0;
}