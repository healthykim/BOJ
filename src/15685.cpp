#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int N, x, y;
bool map[101][101];
int dx[4] = {1, 0, -1, 0}; //right up left down +1하면 90도
int dy[4] = {0, -1, 0, 1};
vector<int> directions;

int calculate() {
    int result = 0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) {
                result += 1;
            }
        }
    }
    return result;
} 

void make_generation() {
    for(int i = directions.size()-1; i>=0; i--) {
        int d = (directions[i] + 1)%4;
        x = x + dx[d];
        y = y + dy[d];
        map[x][y] = true;
        directions.push_back(d);
    }
} 


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int d, g;
    for(int i=0; i<N; i++) {
        cin >> x >> y >> d >> g;
        directions.clear();
        map[x][y] = true;
        x = x + dx[d];
        y = y + dy[d];
        map[x][y] = true;
        directions.push_back(d);
        for(int j=0; j<g; j++) {
            make_generation();
        }
    }
    int result = calculate();
    cout << result << "\n";

	return 0;
}