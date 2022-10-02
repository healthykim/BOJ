#include<iostream>

using namespace std;

int N;
int* dp;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    dp = new int[N+1];

    dp[0] = 0; dp[1] = 1; dp[2] = 2;

    for(int i=3; i<=N; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }

    cout << dp[N] << "\n";

    return 0;
}