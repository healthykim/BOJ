#include<iostream>
#include<vector>

using namespace std;

int N;
int now[10];
int dp[10];

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    dp[0] = 0;
    for(int i=1; i<10; i++) {
        dp[i] = 1;
    }

    for(int i=2; i<=N; i++) {
        now[0] = dp[1]%1000000000; now[9] = dp[8]%1000000000;
        for(int i=1; i<9; i++) {
            now[i] = (dp[i-1] + dp[i+1])%1000000000;
        }
        for(int i=0; i<10; i++) {
            dp[i] = now[i];
        }
    }

    int result = 0;
    for(int i=0; i<10; i++) {
        result = (result + dp[i])%1000000000;
    }

    cout << result << "\n";

    return 0;
}