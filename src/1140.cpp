#include<iostream>

using namespace std;

int N;
int** dp;
int** w;
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    w = new int*[N+1];
    dp = new int*[N+1];
    for(int i=1; i<=N; i++) {
        w[i] = new int[3];
        dp[i] = new int[3];
        for(int j=0; j<3; j++) {
            cin >> w[i][j];
        }
    }
    dp[1][0] = w[1][0]; dp[1][1] = w[1][1]; dp[1][2] = w[1][2];
    for(int i=2; i<=N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + w[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + w[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + w[i][2];
    }
    int result = min(dp[N][0], dp[N][1]);
    result = min(result, dp[N][2]);
    cout << result << "\n";

    return 0;
}