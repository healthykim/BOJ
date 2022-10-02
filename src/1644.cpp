#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int N;
int MAX = 4000000;
int isPrime[4000001];
vector<int> primeNumber;
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=2; i<sqrt(MAX); i++) {
        for(int j=i*i; j<=MAX; j+= i) {
            isPrime[j] = 1;
        }
    }
    int s=0; primeNumber.push_back(0);
    for(int i=2; i<=MAX; i++) {
        if(isPrime[i] == 0) {
            s += i;
            primeNumber.push_back(s);
        }
    }
    int lo = 0; int hi = 0; int result = 0; int sum = primeNumber[0];
    while(lo<=hi && hi < primeNumber.size()) {
        if(primeNumber[hi]-primeNumber[lo] < N) {
            hi ++;
        }
        else if(primeNumber[hi]-primeNumber[lo] > N) {
            lo ++;
        }
        else {
            result ++;
            lo ++;
        }
    }

    cout << result << "\n";

    return 0;
}