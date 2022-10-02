#include<iostream>
#include<vector>

using namespace std;

int N;
int result = -1;
vector<vector<int> > dp;
vector<vector<int> > w;
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    w.resize(N);
    dp.resize(N);

    for(int i=0; i<N; i++) {
        w[i].resize(i+1);
        dp[i].resize(i+1);
        for(int j=0; j<i+1; j++) {
            cin >> w[i][j];
            if(i==0 && j==0) {
                dp[i][j] = w[0][0];
            }
            else if(j==0) {
                dp[i][j] = dp[i-1][j] + w[i][j];
            }
            else if(j==i) {
                dp[i][j] = dp[i-1][j-1] + w[i][j];
            } 
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + w[i][j];
            }
            result = max(result, dp[i][j]);
        }
    }
    cout << result << "\n";
    return 0;
}