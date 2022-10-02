#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int N, M, H;
int*** tomatos;
int dx[6] = {0,0,0,0,-1,1};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {1,-1,0,0,0,0};

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N >> H;
    queue<int> q;

    tomatos = new int**[H];
    for(int i=0; i<H; i++) {
        tomatos[i] = new int*[N];
        for(int j=0; j<N; j++) {
            tomatos[i][j] = new int[M];
            for(int k=0; k<M; k++) {
                cin >> tomatos[i][j][k];
                if(tomatos[i][j][k] == 1) {
                    q.push(i*N*M + j*M + k);
                }
            }
        }
    }

    while(!q.empty()) {
        int h = q.front()/(N*M); int n = (q.front()%(N*M))/M; int m = q.front()%M;
        q.pop();
        for(int i=0; i<6; i++) {
            int nh = h+dz[i]; int nn = n+dx[i]; int nm = m+dy[i];
            if(nh < 0 || nh > H-1 || nn < 0 || nn > N-1 || nm < 0 || nm > M-1 || tomatos[nh][nn][nm] != 0) {
                continue;
            }
            tomatos[nh][nn][nm] = tomatos[h][n][m] + 1;
            q.push(nh*N*M + nn*M + nm);
        }
    }
    

    int result = 0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                
                if(tomatos[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }
                result = max(result, tomatos[i][j][k]);
                
            }
        }
    }

    cout << result -1 << "\n";
    
    return 0;
}