#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<vector<vector<pair<int, int> > > > stone_map;

bool isOver(vector<vector<int> >& stones) {
    //턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.
    return true;
}

bool move(vector<vector<int> >& board, int num, vector<vector<int> >& stones) {
    int idx = 0; 
    int r, c, dir;
    r = stones[num][0]; c = stones[num][1]; dir = stones[num][2];

    for(idx=0; idx<stone_map[r][c].size(); idx++) {
        if(stone_map[r][c][idx].first == num) {
            break;
        }
    }
    vector<pair<int, int> > uppers(stone_map[r][c].begin()+idx, stone_map[r][c].end());
    stone_map[r][c] = vector<pair<int, int> >(stone_map[r][c].begin(), stone_map[r][c].begin() + idx);

    int nr = r + dx[dir-1]; int nc = c + dy[dir-1]; int ndir = dir;

    //체스판을 벗어나는 경우에는 파란색과 같은 경우이다.
    if(nr < 0 || nr > board.size()-1 || nc < 0 || nc > board.size()-1 || board[nr][nc] == 2) {
        if(ndir == 1 || ndir == 3) ndir += 1;
        else ndir -= 1;
        //파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
        int nnr = r + dx[ndir-1]; int nnc = c + dy[ndir-1];
        nr = nnr; nc = nnc;
    }
    //방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
    if(nr < 0 || nr > board.size()-1 || nc < 0 || nc > board.size()-1 || board[nr][nc] == 2) {
        nr = r; nc = c;
    }
    else if(board[nr][nc] == 1) {
        reverse(uppers.begin(), uppers.end());
    }


    //이동 준비 끝, 이동하기
    for(int i=0; i<uppers.size(); i++) {
        vector<int> new_stone; new_stone.push_back(nr); new_stone.push_back(nc);
        if(uppers[i].first == num) {
            new_stone.push_back(ndir);
            uppers[i].second = ndir;
        }
        else new_stone.push_back(stones[uppers[i].first][2]);
        stones[uppers[i].first] = new_stone;
    }
    stone_map[nr][nc].insert(stone_map[nr][nc].end(), uppers.begin(), uppers.end());

    if(stone_map[nr][nc].size() > 3) return false;
    return true;
}

int solution(vector<vector<int> >& board, vector<vector<int> >& stones) {
    int answer = 0; //몇 번 턴을 진행중인지
    stone_map.resize(board.size());
    for(int i=0; i<stone_map.size(); i++) {
        stone_map[i].resize(board.size());
    }
    for(int i=0; i<stones.size(); i++) {
        stone_map[stones[i][0]][stones[i][1]].push_back(pair<int, int>(i, stones[i][2]));
    }
    /*
    턴 한 번은 1번 말부터 K번 말까지 순서대로 이동시키는 것이다.
    */
    bool isOver = false;
    while(!isOver) {
        answer ++;
        //1번 말부터 K번 말까지 순서대로 이동
        for(int i=0; i<stones.size(); i++) {
            if(!move(board, i, stones)) {
                isOver = true;
                break;
            }
        }
        if(answer > 1000) return -1;
    }

    return answer;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > board;
    board.resize(n);
    for(int i=0; i<n; i++) {
        board[i].resize(n);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<int> > stones;
    stones.resize(k);
    for(int i=0; i<k; i++) {
        stones[i].resize(3);
        cin >> stones[i][0] >> stones[i][1] >> stones[i][2];
        stones[i][0] -= 1;
        stones[i][1] -= 1;
    }
    int answer = solution(board, stones);
    cout << answer << "\n";

    return 0;
}
