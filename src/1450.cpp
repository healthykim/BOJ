#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int N, C;
int input[31];
vector<long long> combi1;
vector<long long> combi2;
void combination(int start, int end, long long sum, vector<long long>& vec) {
    if(start > end) {
        vec.push_back(sum);
    }
    else {
        combination(start+1, end, sum, vec);
        combination(start+1, end, sum+input[start], vec);
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> C;
    for(int i=0; i<N; i++) {
        cin >> input[i];
    }
    
    combination(0, N/2, 0, combi1);
    sort(combi1.begin(), combi1.end());
    combination(N/2+1, N-1, 0, combi2);
    sort(combi2.begin(), combi2.end());
    long long result = 0;
    for(int i=0; i<combi1.size(); i++) {
        long long x = C - combi1[i];
        result += upper_bound(combi2.begin(), combi2.end(), x) - combi2.begin();
    }

    cout << result << "\n";

    return 0;
}