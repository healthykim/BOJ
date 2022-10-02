#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N;
double* input;
int* weight;
int* dp;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    input = new double[N+1];
    weight = new int[N+1];
    dp = new int[N+1];

    int total = 0;
    int result = 0;
    for(int i=1; i<=N; i++) {
        cin >> input[i];
    }
    for(int i=1; i<=N; i++) {
        cin >> weight[i];
        total += weight[i];
    }    
    for(int i=0; i<=N; i++) {
        dp[i] = weight[i];
        for(int j=0; j<i; j++) {
            if(input[j] <= input[i]) {
                dp[i] = max(dp[i], dp[j] + weight[i]);
            }
        }
        result = max(result, dp[i]);
    }

    cout << total - result << endl;

    return 0;
}