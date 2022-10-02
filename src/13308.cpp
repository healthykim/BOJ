#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int N, M;
long long** dist;
int* oil_cost;
vector<vector<pair<int, int> > > adj;
priority_queue<pair<long long, pair<int, int> > > pq;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    adj.resize(N+1);
    oil_cost = new int[N+1];
    dist = new long long*[N+1];
    for(int i=0; i<=N; i++) {
        dist[i] = new long long[2501];
        fill_n(dist[i], 2501, LONG_LONG_MAX);
    }
    dist[1][0] = 0;
    
    for(int i=1; i<=N; i++) {
        cin >> oil_cost[i];
    }

    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(pair<int, int>(v, w));
        adj[v].push_back(pair<int, int>(u, w));
    }
    
    pq.push(pair<long long, pair<int, int> >(0, pair<int, int>(1, oil_cost[1])));
    while(!pq.empty()) {
        int top_oil = pq.top().second.second;
        int top_idx = pq.top().second.first;
        long long top_dist = -pq.top().first;
        pq.pop();
        if(top_idx == N) {
            cout << top_dist;
            return 0;
        }
        if(dist[top_idx][top_oil] < top_dist) {
            continue;
        }
        int s = adj[top_idx].size();
        for(int i=0; i<s; i++) {
            int adj_idx = adj[top_idx][i].first;
            int adj_dist = adj[top_idx][i].second;
            int adj_oil = oil_cost[adj_idx];

            int next_oil = min(adj_oil, top_oil);

            if(dist[adj_idx][top_oil] > top_dist + adj_dist*top_oil) {
                dist[adj_idx][top_oil] = top_dist + adj_dist*top_oil;
                pq.push(pair<long long, pair<int, int> >(-dist[adj_idx][top_oil], pair<int, int> (adj_idx, next_oil)));
            }
        }
    }
}