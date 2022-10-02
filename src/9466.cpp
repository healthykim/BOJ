#include<map>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int T;
int N;
int input[100001];
bool visited[100001];
int result;
map<int, int> team; //원소 - 삽입순서

void dfs(int index) {
    visited[index] = true;
    team[index] = team.size()+1;
    int next = input[index];
    if(team.find(next) != team.end()) {
        result = result - (team.size()-team[next]+1);
    }
    else if(!visited[next]) {
        dfs(next);
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;        

    for(int tc=0; tc<T; tc++) {
        cin >> N;
        result = N;
        for(int i=1; i<=N; i++) {
            cin >> input[i];
        }
        for(int i=1; i<=N; i++) {
            if(!visited[i]){
                if(input[i] == i) {
                    result -= 1;
                    visited[i] = true;
                }
                else {
                    dfs(i);
                    team.clear();
                }
            }

        }
        fill_n(visited, N+1, false);
        fill_n(input, N+1, 0);
        cout << result << "\n";
    }
    return 0;
}
