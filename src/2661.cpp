#include<iostream>
#include<vector>
#include<climits>
#include<string>

using namespace std;

int N;
char numbers[3] = {'1', '2', '3'};
string number = "";
bool found = false;

bool isBad(int len) {
    for(int i=1; i<=len/2; i++) {
        int lo = 0;
        int hi = i;
        while(hi != len) {
            bool same = true;
            for(int j=0; j<i; j++) {
                if(number[lo+j]!=number[hi+j]) {
                    same = false;
                    break;
                }
            }
            if(same) {
                return true;
            }
            hi ++; lo++;
        }
    }
    return false;

}

void dfs(int len) {
    if(found || isBad(len)) {
        return;
    }
    if(len == N) {
        found = true;
        cout << number << "\n";
        return;
    }
    for(int i=0; i<3; i++) {
        number.push_back(numbers[i]);
        dfs(len+1);
        number.pop_back();
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dfs(0);
    return 0;
}
