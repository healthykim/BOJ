#include <iostream>
#include <algorithm>

int main() {
    int num;
    scanf("%d", &num);
    int input[num+1];
    int dp[num+1];
    dp[0] = 0;

    for(int i=1; i<=num; i++){
        scanf("%d", &input[i]);
        dp[i] = 0;
    }

    dp[1] = input[1];
    dp[2] = input[1] + input[2];
    dp[3] = std::max(input[1]+input[3], input[2]+input[3]);
    for(int i=4; i<=num; i++){
        dp[i] = std::max(dp[i-2]+input[i], dp[i-3]+input[i-1]+input[i]);
    }

    printf("%d", dp[num]);
}

/* 좋지않은 풀이
#include<iostream>
#include<vector>

using namespace std;

int N;
int** dp;
int* w;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    w = new int[N+1];
    dp = new int*[N+1];
    w[0] = 0;
    dp[0] = new int[2];
    dp[0][1] = 0;
    dp[0][0] = 0;

    for(int i=1; i<=N; i++) {
        dp[i] = new int[2];
        cin >> w[i];
        if(i==1) {
            dp[i][0] = w[i];
            dp[i][1] = 0;
        }
        else if(i==2) {
            dp[i][0] = w[i-1] + w[i];
            dp[i][1] = w[i];
        }
        else {
            dp[i][0] = dp[i-1][1] + w[i];
            dp[i][1] = max(dp[i-2][1], dp[i-2][0]) + w[i];
        }
    }

    cout << max(dp[N][1], dp[N][0]) << "\n";


    return 0;
}
*/