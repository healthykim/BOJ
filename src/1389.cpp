#include <iostream>
#include "cstdio"

using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    int distance[101][101];

    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        distance[a][b] = 1;
        distance[b][a] = 1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(distance[i][j]!=1 && i!=j) {
                distance[i][j] = 10000000;
            }
        }
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if (i == j) continue;
                else if (distance[i][k] != 0 && distance[k][j] != 0) {
                    if (distance[i][j] > distance[i][k] + distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

    int min = 10000000;
    int res;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) {
            if(i!=j)
                tmp += distance[i][j];
        }
        if (tmp < min) {
            min = tmp;
            res = i;
        }
    }

    printf("%d", res);

    return 0;

}
