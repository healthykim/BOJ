#include<iostream>
#include<queue>

using namespace std;
int N, L, R;
int** map;
bool** checked;

bool bfs(int x, int y) {
    if(checked[x][y]) {
        return false;
    }

    queue<pair<int, int> > q;
    vector<pair<int, int> > uni;
    int sum = 0;
    q.push(pair<int, int>(x, y));
    checked[x][y] = true;
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        uni.push_back(p);
        sum += map[p.first][p.second];
        if(p.first < N-1 && abs(map[p.first][p.second]-map[p.first+1][p.second]) >= L && abs(map[p.first][p.second]-map[p.first+1][p.second]) <=R) {
            if(!checked[p.first+1][p.second]) { 
                checked[p.first+1][p.second] = true;
                q.push(pair<int, int>(p.first+1, p.second));
            }
        }
        if(p.second < N-1 && abs(map[p.first][p.second]-map[p.first][p.second+1]) >= L && abs(map[p.first][p.second]-map[p.first][p.second+1]) <=R) {
            if(!checked[p.first][p.second+1]) { 
                checked[p.first][p.second+1] = true;
                q.push(pair<int, int>(p.first, p.second+1));
            }
        }
        if(p.first > 0 && abs(map[p.first][p.second]-map[p.first-1][p.second]) >= L && abs(map[p.first][p.second]-map[p.first-1][p.second]) <=R) {
            if(!checked[p.first-1][p.second]) { 
                checked[p.first-1][p.second] = true;
                q.push(pair<int, int>(p.first-1, p.second));
            }
        }
        if(p.second > 0 && abs(map[p.first][p.second]-map[p.first][p.second-1]) >= L && abs(map[p.first][p.second]-map[p.first][p.second-1]) <=R) {
            if(!checked[p.first][p.second-1]) { 
                checked[p.first][p.second-1] = true;
                q.push(pair<int, int>(p.first, p.second-1));
            }
        }
    }
    if(uni.size() > 1) {
        for(int i=0; i<uni.size(); i++) {
            int x = uni[i].first;
            int y = uni[i].second;
            map[x][y] = sum/uni.size();
        }
        return true;
    }
    checked[x][y] = false;
    return false;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
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

    bool not_stopped = true;
    int cnt = 0;
    while(not_stopped) {
        not_stopped = false;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(bfs(i, j)) {
                    not_stopped = true;
                }
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                checked[i][j] = false;
            }
        }
        if(not_stopped) {
            cnt += 1;
        }
    }

    cout << cnt << "\n";
	return 0;
}