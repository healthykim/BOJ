#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int N;
vector<int> input;
vector<pair<int, int> > sorted_input;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    input.resize(N);
    sorted_input.resize(N);
    for(int i=0; i<N; i++) {
        cin >> input[i];
        sorted_input[i] = pair<int, int>(i, input[i]);
    }
    
    sort(sorted_input.begin(), sorted_input.end(), compare);
    int idx = 0;
    sorted_input[0].second = idx;
    for(int i=1; i<N; i++) {
        if(input[sorted_input[i].first] != input[sorted_input[i-1].first]) {
            idx ++;
        }
        sorted_input[i].second = idx;
    }
    sort(sorted_input.begin(), sorted_input.end());
    
    for(int i=0; i<N; i++) {
        cout << sorted_input[i].second << " ";
    }
    cout << "\n";
}