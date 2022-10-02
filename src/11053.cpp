#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int N;
int* dp;
int* x;
int* input;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    dp = new int[N+1]; dp[0] = 0;
    x = new int[N+1]; x[0] = 0;
    input = new int[N+1]; input[0] = 0;
    int result = 0;
    for(int i=1; i<=N; i++) {
        cin >> input[i];
        x[i] = INT_MAX;
        int a = 0;
        for(int j=0; j<i; j++) {
            if(x[j]<input[i]) {
                a = j;
            }
            else {
                break;
            }
        }
        dp[i] = a+1;
        x[a+1] = min(input[i], x[a+1]);
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}