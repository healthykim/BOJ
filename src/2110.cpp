#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, C;
vector<int> map;
int result = 0;

int install(int space) {
    int cnt = 1;
    int prev = 0; //0번에 미리 설치
    for(int i=1; i<N; i++) {
        if(map[i]-map[prev] >= space) {
            prev = i;
            cnt ++;
        }
    }
    return cnt;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for(int i=0; i<N; i++) {
        int j;
        cin >> j;
        map.push_back(j);
    }
    sort(map.begin(), map.end());
    
    int start = 0;
    int end = map[N-1] - map[0];
    while(start <= end) {
        int mid = (start + end) / 2;
        int cnt = install(mid);
        if(cnt >= C) {
            result = max(result, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}