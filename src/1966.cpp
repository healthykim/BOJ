#include<queue>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int T;
int N, M;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for(int test_case = 0; test_case < T; test_case++) {
        cin >> N >> M;
        queue<pair<int, int> > input;
        priority_queue<int> sorted;
        for(int i=0; i<N; i++) {
            int importance;
            cin >> importance;
            input.push(pair<int, int>(importance, i));
            sorted.push(importance);
        }
        while(!input.empty()) {
            if(input.front().first == sorted.top()) {
                if(input.front().second == M) {
                    cout << N-input.size()+1 << "\n";
                    break;
                }
                input.pop(); sorted.pop();
            }
            else {
                input.push(input.front());
                input.pop();
            }
        }

    }
    return 0;
}
