#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, N, M;
vector<int> map1;

int find_map1(int num) {
    int lo = 0;
    int hi = N-1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(map1[mid] == num) {
            return 1;
        }
        else if(map1[mid] < num) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int test_case=0; test_case<T; test_case++) {
        map1.clear();

        cin >> N;
        for(int i=0; i<N; i++) {
            int j;
            cin >> j;
            map1.push_back(j);
        }
        sort(map1.begin(), map1.end());
        cin >> M;
        for(int i=0; i<M; i++) {
            int j;
            cin >> j;
            cout << find_map1(j) << "\n";
        }
    }

    return 0;
}