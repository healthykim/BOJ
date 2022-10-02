#include<iostream>
#include<set>
#include<vector>
#include<cmath>

using namespace std;
int N;
int** map;
int** near_empty; //인접한 칸 중 비어있는 칸의 개수를 저장
vector<set<int> > favorites;

void decide(int student) {
    int x;
    int y;
    int fav_num = -1;
    for(int i=0;i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == 0) {
                int cnt = 0;
                if(i>0 && favorites[student].find(map[i-1][j])!=favorites[student].end()) {
                    cnt += 1;
                }
                if(j>0 && favorites[student].find(map[i][j-1])!=favorites[student].end()) {
                    cnt += 1;
                }
                if(i<N-1 && favorites[student].find(map[i+1][j])!=favorites[student].end()) {
                    cnt += 1;
                }
                if(j<N-1 && favorites[student].find(map[i][j+1])!=favorites[student].end()) {
                    cnt += 1;
                }
                if(cnt == fav_num) {
                    if(near_empty[i][j] > near_empty[x][y]) {
                        x = i; y = j;
                    }
                }
                else if(cnt > fav_num) {
                    x = i; y = j; fav_num = cnt;
                }
            }
        }
    }
    map[x][y] = student;
    if(x > 0) {
        near_empty[x-1][y] -= 1;
    }
    if(y > 0) {
        near_empty[x][y-1] -= 1;
    }
    if(x < N-1) {
        near_empty[x+1][y] -= 1;
    }
    if(y < N-1) {
        near_empty[x][y+1] -= 1;
    }
    return;
}

int calculate() {
    int result = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int student = map[i][j];
            int cnt = 0;
            if(i>0 && favorites[student].find(map[i-1][j])!=favorites[student].end()) {
                cnt += 1;
            }
            if(j>0 && favorites[student].find(map[i][j-1])!=favorites[student].end()) {
                cnt += 1;
            }
            if(i<N-1 && favorites[student].find(map[i+1][j])!=favorites[student].end()) {
                cnt += 1;
            }
            if(j<N-1 && favorites[student].find(map[i][j+1])!=favorites[student].end()) {
                cnt += 1;
            }
            result += cnt == 0 ? 0 : pow(10, cnt-1);
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    map = new int*[N];
    near_empty = new int*[N];
    favorites.resize(N*N+1);
    //init
    for(int i=0; i<N; i++) {
        map[i] = new int[N];
        near_empty[i] = new int[N];
        for(int j=0; j<N; j++) {
            near_empty[i][j] = 4;
            if(i == 0 || i == N-1) {
                near_empty[i][j] -= 1;
            }
            if(j == 0 || j == N-1) {
                near_empty[i][j] -= 1;
            }
        }
    }
    //calculate
    for(int i=0; i<N*N; i++) {
        int student;
        cin >> student;
        for(int j=0; j<4; j++) {
            int c;
            cin >> c;
            favorites[student].insert(c);
        }
        decide(student);
    }

    cout << calculate() << "\n";

	return 0;
}