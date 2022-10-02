#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int V, E, K;
int* dist;
vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    cin >> K;
    adj.resize(V+1);
    dist = new int[V+1];
    fill_n(dist, V+1, INT_MAX);
    dist[K] = 0;
    for(int i=0; i<E; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(pair<int, int>(v, w));
    }

    pq.push(pair<int, int>(0, K));
    while(!pq.empty()) {
        int top_idx = pq.top().second;
        int top_dist = -pq.top().first;
        pq.pop();
        for(int i=0; i<adj[top_idx].size(); i++) {
            int adj_idx = adj[top_idx][i].first;
            if(dist[adj_idx] > dist[top_idx] + adj[top_idx][i].second) {
                dist[adj_idx] = dist[top_idx] + adj[top_idx][i].second;
                pq.push(pair<int, int>(-dist[adj_idx], adj_idx));
            }
        }
    }
    for(int i=1; i<=V; i++) {
        if(dist[i] == INT_MAX) {
            cout << "INF\n";
        }
        else
            cout << dist[i] << "\n";
    }
    
}