#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int N, K;
int sec[100001];

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    fill_n(sec, 100001, INT_MAX);
    sec[N] = 0;
    queue<int> q;
    q.push(N);
    while(!q.empty()) {
        int pos = q.front();
        int s = sec[pos];
        if(pos == K) {
            cout << s << "\n"; return 0;
        }
        q.pop();
        if(pos > 0 && sec[pos-1] >= s+1) {
            sec[pos-1] = s + 1;
            q.push(pos-1);
        }
        if(pos+1 <= 100000 && sec[pos+1] >= s+1) {
            sec[pos+1] = s + 1;
            q.push(pos+1);
        }
        if(2*pos <= 100000 && sec[2*pos] >= s+1) {
            sec[2*pos] = s+1;
            q.push(2*pos);
        }
    }
    cout << sec[K] << endl;

    return 0;
}