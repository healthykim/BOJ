#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
int N;
int X, Y;
int** map;
bool** checked;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int shark_size = 2;
int size_up = 2;
int sec = INT_MAX;
pair<int, int> fish_dfs;

/*
void dfs(int x, int y, int depth) {
    if(depth > sec) {
        return;
    }
    else if(map[x][y] == 0 || map[x][y] == shark_size) {
        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && !checked[new_x][new_y]) {
                checked[x][y] = true;
                dfs(new_x, new_y, depth+1);
                checked[x][y] = false;
            }
        }
    }
    else if(map[x][y] < shark_size) {
        if(depth < sec || (sec == depth && (x < fish_dfs.first || (x == fish_dfs.first && y < fish_dfs.second)))) {
            sec = depth + 1;
            fish_dfs.first = x;
            fish_dfs.second = y;
        }
    }
    return;
}
*/
pair<int, int> bfs() {
    queue<pair<int, int> > q;
    q.push(pair<int, int>(X*N+Y, 0));
    sec = INT_MAX;
    pair<int, int> fish = pair<int, int>(N, N);
    checked[X][Y] = true;

    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        int x= f.first/N;
        int y = f.first%N;
        if(f.second + 1 > sec) {
            break;
        }
        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && !checked[new_x][new_y]) {
                checked[new_x][new_y] = true;
                if(map[new_x][new_y] == 0 || map[new_x][new_y] == shark_size) {
                    q.push(pair<int, int>(new_x*N+new_y, f.second + 1));
                }
                else if(map[new_x][new_y] < shark_size) {
                    if(f.second+1 < sec || (sec == f.second+1 && (new_x < fish.first || (new_x == fish.first && new_y < fish.second)))) {
                        sec = f.second + 1;
                        fish.first = new_x;
                        fish.second = new_y;
                    } 
                }
            }
        }
    }
    return fish;
}

/*
bool eat() {
    fish = pair<int, int>(N, N);
    sec = INT_MAX;
    dfs(X, Y, 0);
    if(fish.first == N) {
        return false;
    }
    size_up -= 1;
    if(size_up == 0) {
        shark_size += 1;
        size_up = shark_size;
    }
    map[fish.first][fish.second] = 0;
    X = fish.first;
    Y = fish.second;
    return true;
}
*/

bool eat() {
    pair<int, int> fish = bfs();
    if(fish.first == N) {
        return false;
    }
    size_up -= 1;
    if(size_up == 0) {
        shark_size += 1;
        size_up = shark_size;
    }
    map[fish.first][fish.second] = 0;
    X = fish.first;
    Y = fish.second;
    return true;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    map = new int*[N];
    checked = new bool*[N];
    for(int i=0; i<N; i++) {
        map[i] = new int[N];
        checked[i] = new bool[N];
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            checked[i][j] = false;
            if(map[i][j] == 9) {
                X=i;Y=j;
                map[i][j] = 0;
            }
        }
    }
    int result = 0;
    while(eat()) {
        result += sec;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                checked[i][j] = false;
            }
        }
    }
    cout << result << "\n";
	return 0;
}