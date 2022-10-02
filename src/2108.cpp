#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

int N;
int* input;
int* cnt;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    input = new int[N];
    cnt = new int[8001];

    int maxi = -4001;
    int mini = 4001;
    int total = 0;
    int cnt_elem = -1;
    int max_cnt = -1;
    bool second = false;
    for(int i=0; i<N; i++) {
        cin >> input[i];
    }
    sort(input, input+N);

    for(int i=0; i<N; i++) {
        maxi = max(maxi, input[i]);
        mini = min(mini, input[i]);
        total += input[i];
        cnt[input[i]+4000]++;
        if(max_cnt < cnt[input[i]+4000]) {
            max_cnt = cnt[input[i]+4000];
            cnt_elem = input[i];
            second = false;
        }
        else if(max_cnt == cnt[input[i]+4000] && !second) {
            cnt_elem = input[i];
            second = true;
        }
    }
    

    cout << floor(double(total)/N+0.5) << "\n" << input[N/2] << "\n" << cnt_elem << "\n" << maxi - mini << "\n";


    return 0;
}