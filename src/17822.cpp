#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
vector<int> tops;

void to_average(int n, int m, double average, vector<vector<int> >& circles) {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m-1; j++) {
            if(circles[i][j] == 0) continue;
            if(circles[i][j] > average) {
                circles[i][j] -= 1;
            }
            else if(circles[i][j] < average) {
                circles[i][j] += 1;
            }
        }
    }
}

void remove(int n, int m, vector<vector<int> >& circles) {
    bool near[n+1][m];
    for(int i=0; i<=n; i++) fill_n(near[i], m, false);

    // 0~m-1까지 인접한 수를 찾기
    for(int i=0; i<=m-1; i++) {
        //각 원판의 i번째 수를 찾아서 비교
        for(int j=2; j<=n; j++) {
            int ith = (tops[j] + i)%m;
            int prev_ith = (tops[j-1] + i)%m;
            if(circles[j][ith] == circles[j-1][prev_ith] && circles[j][ith] != 0) {
                near[j][ith] = true; near[j-1][prev_ith] = true;
            }
        }
    }
    //1~n 개의 원판 각각에서 인접한 수를 찾기
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m-1; j++) {
            int jth = (tops[i] + j)%m;
            int jnext = (tops[i] + j + 1)%m;
            if(circles[i][jth] == circles[i][jnext] && circles[i][jth] != 0) {
                near[i][jth] = true; near[i][jnext] = true;
            }
        }
    }
    //지워 준다.
    bool removed = false;
    double total = 0; double num = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m-1; j++) {
            if(circles[i][j] != 0) {
                total += circles[i][j];
                num += 1;
            }
            if(near[i][j]) {
                circles[i][j] = 0; //0: 지워짐 의미
                removed = true;
            }
        }
    }
    if(!removed) {
        to_average(n, m, total/num, circles);
    }
}

void rotate_circle(int num, int m, int dir, int k) {
    if(dir == 0) {
        //시계 방향
        tops[num] -= k;
        tops[num] += m;
        tops[num] %= m;
    }
    else {
        //반시계 방향
        tops[num] += k;
        tops[num] %= m;
    }
}

int solution(int n, int m, int t, vector<vector<int> >& circles, vector<vector<int> >& commands) {
    int answer = 0; //몇 번 턴을 진행중인지

    tops.resize(n+1); //m으로 나머지 연산 해서 사용하자(0~m-1)
    fill_n(tops.begin(), n+1, 0);
    for(int i=0; i<t; i++) {
        int x = commands[i][0]; int d = commands[i][1]; int k = commands[i][2];
        int add = x;
        while(x <= n) {
            rotate_circle(x, m, d, k);
            x += add;
        }
        remove(n, m, circles);
    }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m-1; j++) {
            answer += circles[i][j];
        }
    }
    return answer;
}
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int> > circles;
    circles.resize(n+1);
    for(int i=1; i<=n; i++) {
        circles[i].resize(m);
        for(int j=0; j<m; j++) {
            cin >> circles[i][j];
        }
    }
    vector<vector<int> > commands; 
    commands.resize(t);
    for(int i=0; i<t; i++) {
        commands[i].resize(3);
        cin >> commands[i][0] >> commands[i][1] >> commands[i][2];
    }
    int answer = solution(n, m, t, circles, commands);
    cout << answer << endl;

    return 0;
}
