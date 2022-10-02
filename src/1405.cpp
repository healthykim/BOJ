#include<iostream>
#include<vector>
#include<climits>
#include<set>

using namespace std;

int N;
double result = 0;
double p = 1.0;
double probs[4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int, int> now;
set<pair<int, int> > points;

void dfs(int len) {
    if(len == N) {
        result += p;
        return;
    }
    for(int i=0; i<4; i++) {
        if(probs[i] != 0) {
            pair<int, int> prev = now;
            pair<int, int> next;
            double prev_p = p;
            double next_p = p * probs[i];
            next.first = now.first + dx[i];
            next.second = now.second + dy[i];
            if(points.find(next) != points.end()) {
                //result -= next_p;
                //cout << result << "\n";
                continue;
            }
            points.insert(next);
            p = next_p;
            now = next;
            dfs(len + 1);
            points.erase(next);
            p = prev_p;
            now = prev;
        }
    }
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<4; i++) {
        double j;
        cin >> j;
        if(j != 0)
            probs[i] = j/100.0;
        else 
            probs[i] = 0;
    }
    now.first = 0;
    now.second = 0;
    points.insert(now);
    dfs(0);
    cout.precision(16);
    cout << result << "\n";
    return 0;
}
