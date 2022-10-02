#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N;
int* dp;
int* x;
int* input;
vector<int> idx;


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    dp = new int[501]; dp[0] = 0;
    x = new int[501];
    fill_n(x, 501, INT_MAX);
    x[0] = 0;
    input = new int[501]; input[0] = 0;

    for(int i=1; i<=N; i++) {
        int a, b;
        cin >> a >> b;
        input[a] = b;
        idx.push_back(a);
    }

    sort(idx.begin(), idx.end());

    int result = 0;
    int size = idx.size();
    for(int i=0; i<size; i++) {
        int a = 0;
        for(int j=0; j<idx[i]; j++) {
            if(x[j] < input[idx[i]]) {
                a = j;
            }
            else{
                break;
            }
        }
        dp[idx[i]] = a+1;
        x[a+1] = min(x[a+1], input[idx[i]]);
        result = max(result, dp[idx[i]]);
    }

    cout << N-result << "\n";

    return 0;
}