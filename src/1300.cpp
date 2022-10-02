#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
vector<int> map;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    int left = K;
    int right = 0;
    while(right < left) {
        int mid = (right + left) / 2;
        int count = 0;
        for(int i = 1; i<=N; i++) {
            count += min(mid/i, N);
        }
        if(K <= count) {
            left = mid;
        }
        else {
            right = mid+1;
        }
    }

    cout << right << "\n";

    return 0;
}