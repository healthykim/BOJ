#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int N;
vector<string> input;
set<string> input_set;

bool compare(string s1, string s2) {
    if(s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    return s1 < s2;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        if(input_set.find(s) == input_set.end()) {
            input.push_back(s);
            input_set.insert(s);
        }
    }

    sort(input.begin(), input.end(), compare);
    N = input.size();
    for(int i=0; i<N; i++) {
        cout << input[i] << "\n";
    }


}