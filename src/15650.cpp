#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> numbers;

void dfs(int left, int index) {

    if(left == 0) {
        for(int i=0; i<M; i++) {
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=index; i<=N; i++) {
        numbers.push_back(i);
        dfs(left-1, i+1);
        numbers.pop_back();
    }

}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dfs(M, 1);


    return 0;
}
