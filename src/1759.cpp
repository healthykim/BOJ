#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<char> numbers;
vector<char> selected;
int aeiou = 0;

void dfs(int len, int index) {
    if(len == L) {
        if(aeiou >= 1 && len-aeiou >= 2) {
            for(int i=0; i<L; i++) {
                cout << selected[i];
            }
            cout << "\n";
        }
        return;
    }
    
    for(int i=index; i<C; i++) {
        selected.push_back(numbers[i]);
        if(numbers[i] == 'a' || numbers[i] == 'e' || numbers[i] == 'i' || numbers[i] == 'o' || numbers[i] == 'u') {
            aeiou++;
        }
        dfs(len + 1, i + 1);
        selected.pop_back();
        if(numbers[i] == 'a' || numbers[i] == 'e' || numbers[i] == 'i' || numbers[i] == 'o' || numbers[i] == 'u') {
            aeiou--;
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
    for(int i=0; i<C; i++) {
        char j;
        cin >> j;
        numbers.push_back(j);
    }
    sort(numbers.begin(), numbers.end());
    dfs(0, 0);

    return 0;
}
