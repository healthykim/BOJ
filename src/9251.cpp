#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int** dp;
string s1, s2;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1;
    cin >> s2;
    dp = new int*[s1.size()+1];
    for(int i=0; i<=s1.size(); i++) {
        dp[i] = new int[s2.size()+1];
        dp[i][0] = 0; dp[0][i] = 0;
    }

    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << endl;

    return 0;
}