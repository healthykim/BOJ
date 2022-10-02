#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N, K;
int* value;
int* weight;
int** dp;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    value = new int[N+1];
    weight = new int[N+1];
    dp = new int*[N+1];
    dp[0] = new int[K+1];
    for(int i=1; i<=N; i++) {
        dp[i] = new int[K+1];
        cin >> weight[i] >> value[i];
    }
    int result = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            if(j-weight[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=1; i<=N; i++) {
        result = max(result, dp[i][K]);
    }

    cout << result << endl;

    return 0;
}