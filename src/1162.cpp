#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int N, M, K;
long long** dist;
vector<vector<pair<int, int> > > adj;
priority_queue<pair<long long, pair<int, int> > > pq;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    adj.resize(N+1);
    dist = new long long*[N+1];
    for(int i=0; i<=N; i++) {
        dist[i] = new long long[K+1];
        fill_n(dist[i], K+1, LONG_LONG_MAX);
    }
    dist[1][0] = 0;

    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(pair<int, int>(v, w));
        adj[v].push_back(pair<int, int>(u, w));
    }
    pq.push(pair<long long, pair<int, int> >(0, pair<int, int>(1, 0)));
    while(!pq.empty()) {
        int top_k = pq.top().second.second;
        int top_idx = pq.top().second.first;
        long long top_dist = -pq.top().first;
        pq.pop();
        if(dist[top_idx][top_k] < top_dist) {
            continue;
        }
        int s = adj[top_idx].size();
        for(int i=0; i<s; i++) {
            int adj_idx = adj[top_idx][i].first;
            int adj_dist = adj[top_idx][i].second;

            if(dist[adj_idx][top_k] > top_dist + adj_dist) {
                dist[adj_idx][top_k] = top_dist + adj_dist;
                pq.push(pair<long long, pair<int, int> >(-(top_dist+adj_dist), pair<int, int> (adj_idx, top_k)));
            }
            if(top_k < K && dist[adj_idx][top_k+1] > top_dist) {
                dist[adj_idx][top_k+1] = top_dist;
                pq.push(pair<long long, pair<int, int> >(-top_dist, pair<int, int> (adj_idx, top_k+1)));
            }
        }
    }
    long long result = LONG_LONG_MAX;
    for(int i=0; i<=K; i++) {
        result = min(result, dist[N][i]);
    }

    cout << result << "\n";

}