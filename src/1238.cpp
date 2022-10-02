#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int N, M, X;
int* two_way;
vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    adj.resize(N+1);
    two_way = new int[N+1];

    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(pair<int, int>(v, w));
    }

    for(int i=1; i<=N; i++) {
        int* dist = new int[N+1];
        fill_n(dist, N+1, INT_MAX);
        dist[i] = 0;
        pq.push(pair<int, int>(0, i));
        while(!pq.empty()) {
            int top_idx = pq.top().second;
            int top_dist = -pq.top().first;
            pq.pop();
            for(int j=0; j<adj[top_idx].size(); j++) {
                int adj_idx = adj[top_idx][j].first;
                if(dist[adj_idx] > top_dist + adj[top_idx][j].second) {
                    dist[adj_idx] = top_dist + adj[top_idx][j].second;
                    pq.push(pair<int, int>(-dist[adj_idx], adj_idx));
                }
            }
        }
        if(i!=X) {
            two_way[i] += dist[X];
        }
        else {
            for(int j=1; j<=N; j++) {
                two_way[j] += dist[j];
            }
        }
    }
    int result = 0;
    for(int i=1; i<=N; i++) {
        result = max(result, two_way[i]);
    }

    cout << result << endl;
    
}