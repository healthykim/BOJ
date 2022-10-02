#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int** S;
bool* joined;
int result;
int N;

int sum_all() {
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(joined[i] && joined[j]) {
                sum1 += S[i][j];
            }
            else if (!joined[i] && !joined[j]) {
                sum2 += S[i][j];
            }
        }
    }
    return abs(sum1-sum2);
}

void dfs(int index, int depth) {
    if(depth == N/2) {
        //do sum
        result = min(sum_all(), result);
        return;
    }
    else if (index >= N) {
        return;
    }

    for(int i=index; i<N; i++) {
        //if(joined[i] == false){
            joined[i] = true;
            dfs(i+1, depth+1);
            joined[i] = false;
        //}
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    S = new int*[N];
    joined = new bool[N];

    for(int i=0; i<N; i++) {
        S[i] = new int[N];
        joined[i] = false;
        for(int j=0; j<N; j++) {
            cin >> S[i][j];
        }
    }

    result = INT_MAX;
    dfs(0, 0);


    cout << result << "\n";


	return 0;
}