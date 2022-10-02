#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N, M;
vector<int> cards;

int find_start(int num) {
    int lo = 0;
    int hi = N-1;
    int result = INT_MAX;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(cards[mid] == num) {
            result = min(result, mid);
            hi = mid -1;
        }
        else if(cards[mid] > num) {
            hi = mid -1;
        }
        else {
            lo = mid + 1;
        }
    }
    return result;
}
int find_end(int num) {
    int lo = 0;
    int hi = N-1;
    int result = -1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(cards[mid] == num) {
            result = max(result, mid);
            lo = mid + 1;
        }
        else if(cards[mid] > num) {
            hi = mid -1;
        }
        else {
            lo = mid + 1;
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        int j;
        cin >> j;
        cards.push_back(j);
    }
    sort(cards.begin(), cards.end());

    cin >> M;
    for(int j=0; j<M; j++) {
        int k;
        cin >> k;
        int start = find_start(k);
        int end = find_end(k);
        if(start == INT_MAX) {
            cout << "0 ";
        } 
        else {
            cout << end-start+1 << " ";
        }
    }

    return 0;
}
