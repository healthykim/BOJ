#include<queue>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int** input;
int** melt;
queue<int> q;
int total;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs() {
    int result = 0;
    if(q.empty()){
        q.push(0);
        melt[0][0] = 1;
    }
    while(!q.empty()) {
        int x = q.front()/M; int y = q.front()%M;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) {
                continue;
            }
            if(melt[nx][ny]==0) {
                if(input[nx][ny] == 1) {melt[nx][ny] = -1; result += 1;}
                else {melt[nx][ny] = 1; q.push(nx*M+ny);}
            }
        }
    }
    return result;
}

void do_melt() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(melt[i][j] == -1) {
                q.push(i*M + j);
                input[i][j] = 0;
                melt[i][j] = 0;
            }
        }
    }
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    input = new int*[N];
    melt = new int*[N];
    for(int i=0; i<N; i++) {
        input[i] = new int[M];
        melt[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> input[i][j];
            if(input[i][j]) {
                total += 1;
            }
        }
    }

    int time = 0;
    int result = 0;
    while(total - result != 0) {
        total -= result;
        result = bfs();
        do_melt();
        time++;
    }

    cout << time << "\n" << total << "\n";


    


    return 0;
}