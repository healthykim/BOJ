#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N, K;
int* input;

void swap(int i, int j) {
    int tmp = input[i];
    input[i] = input[j];
    input[j] = tmp;
}

int partition(int start, int end) {
    int pivot = end;
    int i = start-1;
    for(int j=start; j<=end; j++) {
        if(input[pivot] < input[j]) {
            swap(++i, j);
        }
    }
    swap(i+1, pivot);
    return i+1;
}

int select(int k, int start, int end) {
    if(start == end) {
        return input[start];
    }
    int pivot = partition(start, end);
    if(pivot-start+1 == k) {
        return input[pivot];
    }
    else if(pivot-start+1 > k) {
        return select(k, start, pivot-1);
    }
    else {
        return select(k-(pivot-start+1), pivot+1, end);
    }
    
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    input = new int[N];
    for(int i=0; i<N; i++) {
        cin >> input[i];
    }
    cout << select(K, 0, N-1) << endl;



    return 0;
}