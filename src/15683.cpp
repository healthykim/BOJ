#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int N, M;
int** map;
int** tmp;
int dx[4] = {-1, 0, 1, 0}; // up right down left
int dy[4] = {0, 1, 0, -1}; // up right down left
vector<int> cameras;
vector<vector<int> > directions;
int result = 65;

void watch(int x_y, int direction) {
    int x = x_y/M;
    int y = x_y%M;
    int new_x = x + dx[direction];
    int new_y = y + dy[direction];
    while(new_x >= 0 && new_y >= 0 && new_x < N && new_y < M) {
        if(tmp[new_x][new_y] == 6) {
            break;
        }
        if(tmp[new_x][new_y] == 0) {
            tmp[new_x][new_y] = -1;
        }
        new_x = new_x + dx[direction];
        new_y = new_y + dy[direction];
    }
}

void calculate() {
    int sum = 0;

    for(int i=0; i<cameras.size(); i++) {
        for(int j=0; j<directions[i].size(); j++) {
            watch(cameras[i], directions[i][j]);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(tmp[i][j] == 0) {
                sum += 1;
            }
            if(tmp[i][j] == -1) {
                tmp[i][j] = 0;
            }
        }
    }
    result = min(sum, result);
}

void dfs(int index) {
    if(directions.size() == cameras.size()) {
        calculate();
        return;
    }
    for(int i=index; i<cameras.size(); i++) {
        int x = cameras[i]/M;
        int y = cameras[i]%M;
        int number = map[x][y];
        if(number == 1) {
            for(int j=0; j<4; j++) {
                vector<int> vec;
                vec.push_back(j);
                directions.push_back(vec);
                dfs(i+1);
                directions.pop_back();
            }
        }
        else if (number == 2) {
            for(int j=0; j<2; j++) {
                vector<int> vec;
                vec.push_back(j);
                vec.push_back(j+2);
                directions.push_back(vec);
                dfs(i+1);
                directions.pop_back();
            }
        }
        else if (number == 3) {
            for(int j=0; j<4; j++) {
                vector<int> vec;
                if(j != 3) {
                    vec.push_back(j);
                    vec.push_back(j+1);
                }
                else {
                    vec.push_back(0);
                    vec.push_back(3);
                }
                directions.push_back(vec);
                dfs(i+1);
                directions.pop_back();
            }
        }
        else if (number == 4) {
            for(int j=0; j<4; j++) {
                vector<int> vec;
                for(int k=0; k<4; k++) {
                    if(k != j) {
                        vec.push_back(k);
                    }
                }
                directions.push_back(vec);
                dfs(i+1);
                directions.pop_back();
            }
        }
        else {
            vector<int> vec;
            for(int k=0; k<4; k++) {
                vec.push_back(k);
            }
            directions.push_back(vec);
            dfs(i+1);
            directions.pop_back();
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
    tmp = new int*[N];

    for(int i=0; i<N; i++) {
        map[i] = new int[M];
        tmp[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            tmp[i][j] = map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6) {
                cameras.push_back(i*M+j);
            }
        }
    }
    
    dfs(0);

    cout << result << "\n";
	return 0;
}

