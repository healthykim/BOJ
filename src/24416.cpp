#include<iostream>

using namespace std;

int N;
int fibCnt = 0;
int fibonacciCnt = 0;

void fib(int n) {
    if(n > 2) {
        fib(n-1);
        fib(n-2);
        return;
    }
    else {
        fibCnt ++;
        return;
    }
}

void fibonacci(int n) {
    for(int i=3; i<=n; i++) {
        fibonacciCnt ++;
    }
    return;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    fib(N); fibonacci(N);

    cout << fibCnt << " " << fibonacciCnt << "\n";

    return 0;
}