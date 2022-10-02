#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int N;
bool* visited;
vector<vector<pair<int, int> > > adj;
int result = 0;

void dfs(int node, int weight) {
    result = max(result, weight);

    for(int i=0; i<adj[node].size(); i++) {
        int nn = adj[node][i].first;
        int nw = adj[node][i].second;
        if(!visited[nn]) {
            visited[nn] = true;
            dfs(nn, weight+nw);
            visited[nn] = false;
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
    
    for(int i=0; i<N-1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        adj[p].push_back(pair<int, int>(c, w));
        adj[c].push_back(pair<int, int>(p, w));
    }

    for(int i=0; i<N; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << result << "\n";
    

    return 0;
}