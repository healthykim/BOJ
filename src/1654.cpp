#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int K, N;
vector<unsigned int> lans;

int slice_lans(unsigned int len) {
    int cnt = 0;
    for(int i=0; i<K; i++) {
        cnt += lans[i]/len;
    }
    return cnt;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    for(int i=0; i<K; i++) {
        unsigned int j;
        cin >> j;
        lans.push_back(j);
    }

    sort(lans.begin(), lans.end());
    unsigned int lo = 1;
    unsigned int hi = lans[K-1];
    unsigned int result = 0;
    while(lo <= hi) {
        unsigned int mid = (lo+hi)/2;
        int cnt = slice_lans(mid);
        if(cnt >= N) {
            result = max(result, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    
    cout << result << "\n";

    return 0;
}
