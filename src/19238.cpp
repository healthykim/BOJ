#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
vector<pair<int, int> > customers;
vector<vector<int> > board;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int get_minDist(int sxy, int dxy, int n) {
    //sxy에서 dxy로 가는 최단경로를 구함
    bool visited[n+1][n+1];
    for(int i=0; i<=n; i++) fill_n(visited[i], n+1, false);

    queue<pair<int, int> > q;
    q.push(pair<int, int>(sxy, 0));

    while(!q.empty()) {
        if(q.front().first == dxy) {
            return q.front().second;
        }
        int x = q.front().first/(n+1); int y = q.front().first%(n+1);
        int dist = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x+dx[i]; int ny = y+dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 1 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(pair<int, int>(nx*(n+1) + ny, dist+1));
        }
    }

    return INT_MAX; //dxy에 도착할 수 없는 경우
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, fuel;
    cin >> n >> m >> fuel;
    
    board.resize(n+1);
    for(int i=1; i<=n; i++) {
        board[i].resize(n+1);
        for(int j=1; j<=n; j++) {
            cin >> board[i][j];
        }
    }

    int bxy; int bx; int by;
    cin >> bx >> by;
    bxy = bx*(n+1) + by;
    
    customers.resize(m);
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        customers[i].first = x*(n+1) + y; //출발지
        cin >> x >> y;
        customers[i].second = x*(n+1) + y; //도착지
    }
    sort(customers.begin(), customers.end());

    while(!customers.empty()) {
        int min_customer = 0; int b_to_c = INT_MAX;
        for(int i=0; i<customers.size(); i++) {
            int dist = get_minDist(bxy, customers[i].first, n);
            if(dist < b_to_c) {
                min_customer = i;
                b_to_c = dist;
            }
        }
        int c_to_d = get_minDist(customers[min_customer].first, customers[min_customer].second, n);
        fuel -= (b_to_c + c_to_d);
        if(fuel < 0 || b_to_c == INT_MAX || c_to_d == INT_MAX) {
            cout << "-1" << endl;
            return 0;
        }
        fuel += 2*c_to_d;
        bxy = customers[min_customer].second;
        customers.erase(customers.begin() + min_customer);
    }
    cout << fuel << endl;

    return 0;
}

