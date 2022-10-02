#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int N, M, H;
int result = INT_MAX;
bool **placed;

bool calculate() {
    for(int i=1; i<=N; i++) {
        int depth = 1;
        int line = i;
        while(depth != H+1) {
            if(placed[depth][line]) {
                line = line + 1;
            }
            else if(placed[depth][line-1]) {
                line = line -1;
            }
            depth += 1;
        }
        if(line != i) {
            return false;
        }
    }
    return true;
}

void dfs(int depth, int h_n) { //depth == number of new line
    if(depth > 3 || result == 0) {
        return;
    }
    if(calculate()) {
        result = min(result, depth);
        return;
    }
    else if (depth == 3) {
        return;
    }
    for(int i=h_n; i<(H+1)*N; i++) { 
        int a = i/N;
        int b = i%N;
        if(!placed[a][b]) {
            placed[a][b] = true;
            dfs(depth + 1, i+1);
            placed[a][b] = false;
        }
    }    
} 


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    placed = new bool*[H+1];
    for(int i=0; i<H+1; i++) {
        placed[i] = new bool[N+1];
        for(int j=0; j<N+1; j++) {
            placed[i][j] = false;
        }
    }
    
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        placed[a][b] = true;
    }

    dfs(0, 1+1*N);

    if(result == INT_MAX) {
        cout << "-1\n";
    }
    else {
        cout << result << "\n";
    }

	return 0;
}