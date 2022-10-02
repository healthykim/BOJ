#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int N, S;
int* input;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;
    input = new int[N];
    for(int i=0; i<N; i++) {
        cin >> input[i];
        if(input[i]==S) {
            cout << "1\n";
            return 0;
        }
    }
    int lo = 0; int hi = 1; int result = INT_MAX; long long sum = input[lo] + input[hi];
    while(lo<=hi && hi < N) {
        if(sum < S) {
            hi ++;
            sum += input[hi];
        }
        else {
            result = min(result, hi-lo+1);
            sum -= input[lo];
            lo ++;
        }
    }

    if(result == INT_MAX) {
        result = 0;
    }

    cout << result << "\n";
    return 0;
}