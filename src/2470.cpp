#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> map;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        int j;
        cin >> j;
        map.push_back(j);
    }
    sort(map.begin(), map.end());

    int i=0; int j=N-1;
    int min_i = i;
    int min_j = j;
    while(i != j) {
        int sum = map[i] + map[j];
        if(abs(sum) < abs(map[min_i] + map[min_j])) {
            min_i = i;
            min_j = j;
        }
        if(sum < 0) {
            i ++;
        }
        else if(sum>0) {
            j --;
        }
        else {
            break;
        }
    }
    
    cout << map[min_i] << " " << map[min_j];
    return 0;
}