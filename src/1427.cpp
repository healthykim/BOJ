#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int number;
vector<int> input;

bool compare(int a, int b) {
    return a>b;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> number;
    for(int i=0; number != 0; i++) {
        input.push_back(number%10);
        number = number/10;
    }
    sort(input.begin(), input.end(), compare);

    for(int i=0; i<input.size(); i++) {
        cout << input[i];
    }
    cout << "\n";

    return 0;
}