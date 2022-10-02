#include<queue>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K, L;
int** apple;
int** snake;
pair<int, int> head; //xy, 도착시의 second
pair<int, int> tail; //xy, 도착시의 second
vector<int> directions; //index초 시작할 때의 방향
int dx[4] = {0,1,0,-1}; //right down left up <- +1이 오른쪽 회전, -1이 왼쪽 회전
int dy[4] = {1,0,-1,0};

bool move() {
    int x = head.first/(N+1); int y = head.first%(N+1);
    int hd = directions[head.second+1];
    int nx = x + dx[hd]; int ny = y + dy[hd];
    head.first = nx*(N+1) + ny;
    head.second += 1;

    if(nx < 1 || nx > N || ny < 1 || ny > N) return true; // 머리가 벽에 닿은 경우
    if(snake[nx][ny] == 1) return true;
    snake[nx][ny] = 1;

    
    if(apple[nx][ny] == 0) { //꼬리를 줄이기
        int tx = tail.first/(N+1); int ty = tail.first%(N+1);
        int td = directions[tail.second+1];
        snake[tx][ty] = 0;
        tx = tx + dx[td]; ty = ty + dy[td];
        tail.first = tx*(N+1) + ty;
        tail.second = tail.second+1;
    }
    else {
        apple[nx][ny] = 0;
    }

    return false;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    apple = new int*[N+1];
    snake = new int*[N+1];
    for(int i=0; i<=N; i++) {
        apple[i] = new int[N+1];
        snake[i] = new int[N+1];
    }
    snake[1][1] = 1; head = {N+1 + 1, 0}; tail = {N+1 + 1, 0};
    for(int i=0; i<K; i++) {
        int x, y;
        cin >> x >> y;
        apple[x][y] = 1;
    }
    cin >> L;
    directions.resize(10002);
    int prev_sec = 0;
    for(int i=0; i<L; i++) {
        int sec; char direction;
        cin >> sec >> direction;
        if(direction == 'L') directions[sec+1] = -1;
        else if(direction == 'D') directions[sec+1] = 1;
    }
    for(int i=0; i<10000; i++) {
        directions[i+1] = (directions[i] + directions[i+1]);
        directions[i+1] %= 4;
        if(directions[i+1] < 0) directions[i+1] += 4;
    }

    bool isOver = false;
    while(!isOver) {
        isOver = move();
    }
    cout << head.second << "\n";

    return 0;
}