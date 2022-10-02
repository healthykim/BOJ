#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, result = 0;
vector<int> map;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++) {
        int j;
        cin >> j;
        map.push_back(j);
    }
    sort(map.begin(), map.end());
    for(int i=0; i<N; i++) {
        int number = map[i];
        int right = 0;
        int left = N-1;
        while(right < left) {
            if(right == i) {
                right ++;
                continue;
            }
            else if(left == i) {
                left --;
                continue;
            }
            int sum = map[right] + map[left];
            if(sum == number) {
                result ++;
                break;
            }
            else if(sum < number) {
                right ++;
            }
            else {
                left --;
            }
        }
    }

    cout << result << "\n";

    return 0;
}