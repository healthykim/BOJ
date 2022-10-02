#include <iostream>
#include "cstdio"

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    int distance[N][N];

    int a;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &a);
            if(a)
                distance[i][j] = a;
            else
                distance[i][j] = 10000000;
        }
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(distance[i][j]!=10000000)
                printf("1");
            else
                printf("0");
            if(j+1<N)
                printf(" ");
        }
        printf("\n");
    }
}
