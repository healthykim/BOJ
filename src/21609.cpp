#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
int N, M;
int** map;
int** near_empty; //인접한 칸 중 비어있는 칸의 개수를 저장
bool** checked;
int X, Y; //방금 계산한 그룹의 기준 XY를 저장
int R; // 방금 계산한 그룹의 rainbow block 개수 
int score;

int bfs_cnt(int x, int y) {
    queue<pair<int, int> > q;
    q.push(pair<int, int>(x, y));
    int value = map[x][y];
    checked[x][y] = true;
    int cnt = 0;
    X = x;
    Y = y;
    R = 0;
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        cnt += 1;
        if(map[f.first][f.second]==0) {
            R += 1;
        } 
        else if(f.first < X) {
            X = f.first;
            Y = f.second;
        }
        else if(f.first == X && f.second < Y) {
            X = f.first;
            Y = f.second;
        }
        if(f.first>0 && (map[f.first-1][f.second] == value || map[f.first-1][f.second] == 0) && !checked[f.first-1][f.second]) {
            q.push(pair<int, int>(f.first-1, f.second));
            checked[f.first-1][f.second] = true;
        }
        if(f.second>0 && (map[f.first][f.second-1] == value || map[f.first][f.second-1] == 0) && !checked[f.first][f.second-1]) {
            q.push(pair<int, int>(f.first, f.second-1));
            checked[f.first][f.second-1] = true;
        }
        if(f.first<N-1 && (map[f.first+1][f.second] == value || map[f.first+1][f.second] == 0) && !checked[f.first+1][f.second]) {
            q.push(pair<int, int>(f.first+1, f.second));
            checked[f.first+1][f.second] = true;
        }
        if(f.second<N-1 && (map[f.first][f.second+1] == value || map[f.first][f.second+1] == 0) && !checked[f.first][f.second+1]) {
            q.push(pair<int, int>(f.first, f.second+1));
            checked[f.first][f.second+1] = true;
        }
    }
    return cnt;
}

void bfs_remove(int x, int y) {
    queue<pair<int, int> > q;
    q.push(pair<int, int>(x, y));
    int value = map[x][y];
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        if(f.first>0 && (map[f.first-1][f.second] == value || map[f.first-1][f.second] == 0)) {
            map[f.first-1][f.second] = -2;
            q.push(pair<int, int>(f.first-1, f.second));
        }
        if(f.second>0 && (map[f.first][f.second-1] == value || map[f.first][f.second-1] == 0)) {
            map[f.first][f.second-1] = -2;
            q.push(pair<int, int>(f.first, f.second-1));
        }
        if(f.first<N-1 && (map[f.first+1][f.second] == value|| map[f.first+1][f.second] == 0)) {
            map[f.first+1][f.second] = -2;
            q.push(pair<int, int>(f.first+1, f.second));
        }
        if(f.second<N-1 && (map[f.first][f.second+1] == value || map[f.first][f.second+1] == 0)) {
            map[f.first][f.second+1] = -2;
            q.push(pair<int, int>(f.first, f.second+1));
        }
    }
    return;
}

void gravity() {
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i=0; i<N-1; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] >=0 && map[i+1][j] == -2) {
                    map[i+1][j] = map[i][j];
                    map[i][j] = -2;
                    changed = true;
                }
            }
        }
    }
}

void rotate() {
    int** new_map;
    new_map = new int*[N];
    for(int i=0; i<N; i++) {
        new_map[i] = new int[N];
        for(int j=0; j<N; j++) {
            new_map[i][j] = map[j][N-1-i];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            map[i][j] = new_map[i][j];
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    map = new int*[N];
    checked = new bool*[N];
    for(int i=0; i<N; i++) {
        map[i] = new int[N];
        checked[i] = new bool[N];
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            checked[i][j] = false;
        }
    }

    while(true) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                checked[i][j] = false;
            }
        }
        int result = 0;
        int rainbow = -1;
        int x = -1;
        int y = -1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] > 0 && !checked[i][j]) {
                    int cnt = bfs_cnt(i, j);
                    //cout << cnt << "\n";
                    if(result<cnt && cnt != 1) {
                        result = cnt;
                        x = X;
                        y = Y;
                        rainbow = R;
                    }
                    if(result == cnt && cnt != 1) {
                        if(rainbow < R) {
                            x = X;
                            y = Y;
                            rainbow = R;
                        }
                        else if(rainbow == R) {
                            if(x < X) {
                                x = X;
                                y = Y;
                                rainbow = R;
                            }
                            else if(x == X && y < Y) {
                                x = X;
                                y = Y;
                                rainbow = R;
                            }
                        }
                    }
                    for(int i=0; i<N; i++) {
                        for(int j=0; j<N; j++) {
                            if(map[i][j]==0) {
                                checked[i][j] = false;
                            }
                        }
                    }
                }
            }
        }
        if(x == -1 && y == -1 || result == 1) {
            break;
        }
        else {
            score += pow(result, 2);
        }
        bfs_remove(x, y);
        gravity();
        rotate();
        gravity();
    }
        cout << score << "\n";

    
	return 0;
}

/*
6 4
 2  3  1  0 -1  2
 2 -1  4  1  3  3
 3  0  4  2  2  1
-1  4 -1  2  3  4
 3 -1  4  2  0  3
 1  2  2  2  2  1

6 4
2 3 1 0 -1 2
2 -1 4 1 3 3
3 0 4 2 2 1
-1 4 -1 2 3 4
3 -1 4 2 0 3
1 2 2 2 2 1

*/