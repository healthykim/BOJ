#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

char op[4] = {'+','-','*','/'};
vector<vector<char> > permu;


void permutation(vector<char> numbers, int index) {
    if(index == numbers.size()) {
        permu.push_back(numbers);
        return;
    }
    else {
        for(int i = index; i<numbers.size(); i++) {
            swap(numbers[i], numbers[index]);
            permutation(numbers, index + 1);
            swap(numbers[i], numbers[index]);
        }
    }
}

int calculate(vector<int> numbers, vector<char> ops) {
    int N = numbers.size();
    int result = numbers[0];
    for(int i=0; i<N-1; i++) {
        char op = ops[i];
        int num = numbers[i+1];
        if(op == '+') {
            result += num;
        }
        else if(op == '-') {
            result -= num;
        }
        else if(op == '*') {
            result *= num;
        }
        else {
            result /= num;
        }
    }
    return result;
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    vector<int> numbers;
    vector<char> ops;
    cin >> N;
    numbers.resize(N);
    for(int i=0; i<N; i++) {
        cin >> numbers[i];
    }
    for(int i=0; i<4; i++) {
        int num;
        cin >> num;
        for(int j=0; j<num; j++) {
            ops.push_back(op[i]);
        }
    }

    int max = -1000000000;
    int min = 1000000000;
    sort(ops.begin(), ops.end());

    do {
        int result = calculate(numbers, ops);
        if(result > max) {
            max = result;
        }
        if(result < min) {
            min = result;
        }

    } while(next_permutation(ops.begin(), ops.end()));

    cout << max << "\n" << min;


	return 0;
}
