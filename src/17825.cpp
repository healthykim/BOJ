#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int max_score = 0;
int stone_roads[4] = {3,3,3,3};
int stone_pos[4] = {0,0,0,0};
vector<vector<int> > roads;

bool same_pos(int p1, int p2, int r1, int r2) {
    //25
    if(roads[r1][p1] == 25 && roads[r2][p2] == 25) return true;
    if(roads[r1][p1] == 40 && roads[r2][p2] == 40) return true;
    if(roads[r1][p1] == 10 && roads[r2][p2] == 10) return true;
    if(roads[r1][p1] == 20 && roads[r2][p2] == 20) return true;
    if(roads[r1][p1] == 30 && roads[r2][p2] == 30) return (p1 == p2);
    return r1 == r2 && p1 == p2;
} 

int get_road(int position, int road) {
    int nr = road;
    if(roads[road][position] == 10) {
        nr = 0;
    }
    else if(roads[road][position] == 20) {
        nr = 1;
    } 
    else if(roads[road][position] == 30 && nr == 3) {
        nr = 2;
    }
    return nr;
}

void dfs(vector<int>& dice, int index, int result) {
    if(index == 10) {
        max_score = max(max_score, result);
        return;
    }
    int k = dice[index];
    for(int i=0; i<4; i++) {
        int p = stone_pos[i]; int r = stone_roads[i];
        if(p == roads[r].size()) continue;
        
        int np = p + k; int nr = get_road(p, r);

        //범위를 벗어나는 이동일 경우 -> 도착 칸에서 마친다.
        if(np > roads[nr].size()) {
            np = roads[nr].size();
        }
        //도착한 칸에 다른 말이 있는 경우
        if(np != roads[nr].size()) {
            bool hasAnother = false;
            for(int j=0; j<4; j++) {
                if(j == i) continue;
                int jr = stone_roads[j]; int jp = stone_pos[j];
                if(same_pos(np, jp, nr, jr)) hasAnother = true; 
            }
            if(hasAnother) continue;
        }

        if(np != roads[nr].size()) {
            result += roads[nr][np];
        }
        stone_pos[i] = np; stone_roads[i] = nr;
        dfs(dice, index+1, result);
        if(np != roads[nr].size()) {
            result -= roads[nr][np];
        }
        stone_pos[i] = p; stone_roads[i] = r;
    }
}

void make_roads() {
    roads.resize(4); //0번- 10에서 꺾음 //1번-20에서 //2번-30에서 //4번-쭉
    for(int i=0; i<=10; i+=2) {
        roads[0].push_back(i); roads[1].push_back(i);
        roads[2].push_back(i); roads[3].push_back(i);
    }
    roads[0].push_back(13); roads[0].push_back(16);
    roads[0].push_back(19); roads[0].push_back(25);
    for(int i=12; i<=20; i+=2) {
        roads[1].push_back(i); roads[2].push_back(i);
        roads[3].push_back(i);
    }
    roads[1].push_back(22); roads[1].push_back(24);
    roads[1].push_back(25);
    for(int i=22; i<=30; i+=2) {
        roads[2].push_back(i); roads[3].push_back(i);
    }
    roads[2].push_back(28); roads[2].push_back(27);
    roads[2].push_back(26); roads[2].push_back(25);
    for(int i=32; i<=40; i+=2) {
        roads[3].push_back(i);
    }
    for(int i=30; i<=40; i+=5) {
        roads[0].push_back(i); roads[1].push_back(i);
        roads[2].push_back(i);
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<roads[i].size(); j++)
            cout << roads[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> dice; dice.resize(10);
    for(int i=0; i<10; i++) cin >> dice[i];
    
    make_roads();
    dfs(dice, 0, 0);
    cout << max_score << endl;

    return 0;
}
