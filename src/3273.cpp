#include<iostream>
#include<algorithm>

using namespace std;

int N, X;
int* input;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    input = new int[N];
    for(int i=0; i<N; i++) {
        cin >> input[i];
    }
    cin >> X;
    sort(input, input+N);
    int lo=0; int hi=N-1; int result=0;
    while(lo<hi) {
        if(input[lo]+input[hi] == X) {
            result ++;
            lo++;
        }
        else if(input[lo]+input[hi] < X) {
            lo++;
        }
        else {
            hi--;
        }
    }

    cout << result << "\n";
}