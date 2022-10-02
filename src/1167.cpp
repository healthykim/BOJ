#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int N;
bool* visited;
vector<vector<pair<int, int> > > adj;
int y = 0;
int result = 0;

void dfs(int node, int weight) {
    if(weight > result) {
        y = node;
        result = weight;
    }
    int s = adj[node].size();
    for(int i=0; i<s; i++) {
        int nn = adj[node][i].first;
        int nw = adj[node][i].second;
        if(!visited[nn]) {
            visited[nn] = true;
            dfs(nn, weight+nw);
        }
    }

}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    adj.resize(N+1);
    visited = new bool[N+1];
    
    for(int i=0; i<N; i++) {
        int p, c, w;
        cin >> p >> c;
        while(c != -1) {
            cin >> w;
            adj[p].push_back(pair<int, int>(c, w));
            adj[c].push_back(pair<int, int>(p, w));
            cin >> c;
        }
    }

    visited[1] = true;
    dfs(1, 0);
    result = 0;
    fill_n(visited, N+1, false);
    visited[y] = true;
    dfs(y, 0);
    cout << result << "\n";
    
    return 0;
}