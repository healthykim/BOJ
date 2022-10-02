#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> tmp;
int sum = 0;
int result = 0;

void dfs(int index) {

    if(sum == M && index != 0) {
        result += 1;
    }

    //for(int i=index; i<N; i++) {
        sum += numbers[index];
        dfs(index + 1);
        sum -= numbers[index];
    //}

}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int j;
        cin >> j;
        numbers.push_back(j);
    }
    dfs(0);

    cout << result << "\n";
    return 0;
}
