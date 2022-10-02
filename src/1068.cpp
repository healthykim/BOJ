#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;
int N;
vector<vector<int> > childs;
int root = 0;
int removed = 0;
int result = 0;

void dfs(int node) {
    if(childs[node].size() == 0) {
        result += 1; return;
    }
    else if(childs[node].size() == 1 && childs[node][0] == removed) {
        result += 1; return;
    }
    else {
        for(int i=0; i<childs[node].size(); i++) {
            if(childs[node][i] != removed)
                dfs(childs[node][i]);
        }
    }
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    childs.resize(N);
    for(int i=0; i<N; i++) {
        int p;
        cin >> p;
        if(p == -1) root = i;
        else {
            childs[p].push_back(i);
        }
    }
    cin >> removed;

    if(removed == root) {
        result = 0;
    }
    else {
        dfs(root);
    }

    cout << result;


    return 0;
}

