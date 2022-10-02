#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int N, M;
int** input;
int** water;
bool** visited;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int cnt = 0;
int year = 0;

void melt() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(input[i][j] != 0) {
                int w = 0;
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k]; int ny = j + dy[k];
                    if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
                    if(input[nx][ny] == 0) w += 1;
                }
                water[i][j] = w;
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(input[i][j] != 0)
                input[i][j] = max(input[i][j]-water[i][j], 0);
            water[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || visited[nx][ny]) continue;
        if(input[nx][ny] != 0) {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    input = new int*[N];
    water = new int*[N];
    visited = new bool*[N];
    for(int i=0; i<N; i++) {
        input[i] = new int[M];
        water[i] = new int[M];
        visited[i] = new bool[M];
        for(int j = 0; j<M; j++) {
            cin >> input[i][j];
        }
    }
    
    bool sep = false;
    while(!sep) {
        melt();
        year ++;
        cnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!visited[i][j] && input[i][j]!=0) {
                    if(cnt == 0) {
                        visited[i][j] = true;
                        dfs(i, j); cnt = 1;
                    }
                    else {
                        cout << year << "\n";
                        return 0;
                    }
                }
            }
        }
        sep = true;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                visited[i][j] = false;
                if(input[i][j] != 0) {
                    sep = false;
                }
            }
        }
    }

    cout << "0\n";

    return 0;
}