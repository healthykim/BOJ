#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int N, M;
int** box;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    box = new int*[N];
    queue<int> tomatos;
    for(int i=0; i<N; i++) {
        box[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) {
                tomatos.push(i*M+j);
            }
        }
    }

    while(!tomatos.empty()) {
        int curr_x = tomatos.front()/M;
        int curr_y = tomatos.front()%M;
        tomatos.pop();
        for(int i=0; i<4; i++) {
            int new_x = curr_x + dx[i]; int new_y = curr_y + dy[i];
            if(new_x > N-1 || new_x < 0 || new_y > M-1 || new_y < 0) {
                continue;
            }
            if(box[new_x][new_y] == 0) {
                box[new_x][new_y] = box[curr_x][curr_y] + 1;
                tomatos.push(new_x*M + new_y);
            }
        }
    }
    int result = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(box[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
            result = max(result, box[i][j]);
        }
    }

    
    cout << result-1 << "\n";

    return 0;
}