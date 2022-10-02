#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
int up=0; int down=0;

void move_belt(int n) {
    up -= 1; down -= 1;
    up += (2*n); down += (2*n);
    up %= 2*n; down %= 2*n;
}

void move_robot(int n, vector<int>& robots, vector<int>& a) {
    for(int i=0; i<robots.size(); i++) {
        int np = (robots[i]+1)%(2*n); //한 칸 이동
        if(a[np] == 0) continue; //내구도가 다 떨어졌으면 이동 안함
        bool anotherRobot = false;
        for(int j=0; j<robots.size(); j++) {
            if(robots[j] == np) {
                anotherRobot = true; break;
            }
        }
        if(anotherRobot) continue; //다른 로봇이 있는 경우 이동 안함
        robots[i] = np; // 다른 경우 이동함
        a[np] -= 1; //내구도 감소
    }
}

void add_robot(vector<int>& robots, vector<int>& a) {
    if(a[up] > 0) {
        robots.push_back(up);
        a[up] -= 1; //내구도 감소
    }
    
}

void remove_robot(vector<int>& robots) {
    for(int i=0; i<robots.size(); i++) {
        if(robots[i] == down) {
            robots.erase(robots.begin() + i);
            return;
        }
    }
}

bool isOver(vector<int>& a, int k) {
    int num = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] == 0) num++;
        if(num == k) return true;
    }
    return false;
}


int solution(int n, int k, vector<int> a) {
    up = 0; down = n-1;
    vector<int> robots;
    int round = 1;
    while(true) {
        //step 1
        move_belt(n);
        remove_robot(robots);

        //step 2
        move_robot(n, robots, a);
        remove_robot(robots);

        //step 3
        add_robot(robots, a);
        remove_robot(robots);

        //step 4
        if(isOver(a, k)) {
            return round;
        }
        round ++;
    }
    
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a; a.resize(2*n);
    for(int i=0; i<2*n; i++) {
        cin >> a[i];
    }
    cout << solution(n, k, a) << "\n";

    return 0;
}

