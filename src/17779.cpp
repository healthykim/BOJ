#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int calculate(int x, int y, int d1, int d2, int n, vector<vector<int> >& board) {
    /*
    (x, y), (x+1, y-1), ..., (x+d1, y-d1)
    (x, y), (x+1, y+1), ..., (x+d2, y+d2)
    (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
    (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
    */
    vector<int> area; area.resize(5);
    bool five[n+1][n+1]; 
    for(int i=0; i<=n;i++) {
        fill_n(five[i], n+1, false);
    }
    //경계선 만들기
    int bx = x; int by = y; five[bx][by] = true;
    while(bx < x+d1 && by > y-d1) {
        bx += 1; by -= 1;
        five[bx][by] = true;
    }
    bx = x; by = y; five[bx][by] = true;
    while(bx < x + d2 && by < y+d2) {
        bx += 1; by += 1;
        five[bx][by] = true;
    }
    bx = x+d1; by = y-d1; five[bx][by] = true;
    while(bx < x+d1+d2 && by < y-d1+d2) {
        bx += 1; by += 1;
        five[bx][by] = true;
    }
    bx = x+d2; by = y+d2; five[bx][by] = true;
    while(bx < x+d1+d2 && by > y-d1+d2) {
        bx += 1; by -= 1;
        five[bx][by] = true;
    }
    for(int i=1; i<=n; i++) {
        bool betweenBorder = false;
        for(int j=1; j<=n; j++) {
            if(five[i][j]) {
                area[4] += board[i][j];
                if(betweenBorder)
                    betweenBorder = false;
                else if(!(i==x && j==y) && !(i==x+d1+d2 && j==y-d1+d2))
                    betweenBorder = true;
            }
            else if(betweenBorder) {
                area[4] += board[i][j];
                five[i][j] = true;
            }
        }
    }


    /*
    1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
    2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
    3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
    */

    for(int r=1; r<=n; r++) {
        for(int c=1; c<=n; c++) {
            if(five[r][c]) continue;
            else if(r < x+d1 && c <= y) area[0] += board[r][c];
            else if(r <= x+d2 && y < c) area[1] += board[r][c];
            else if(x+d1 <= r && c < y-d1+d2) area[2] += board[r][c];
            else if(x+d2 < r && y-d1+d2 <= c) area[3] += board[r][c];
        }
    }
    int min_area = *min_element(area.begin(), area.end());
    int max_area = *max_element(area.begin(), area.end());
    return max_area - min_area;
    
}



int solution(vector<vector<int> >& board, int n) {
    int answer = INT_MAX;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x = i; int y = j;
            //1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
            for(int d1 = 1; d1<=n; d1++) {
                for(int d2 = 1; d2<=n; d2++) {
                    if(x >= x+d1+d2 || x+d1+d2 > n) continue;
                    if(y-d1 < 1 || y+d2 > n) continue;
                    int result = calculate(x, y, d1, d2, n, board);
                    answer = min(result, answer);
                }
            }
        }
    }

    return answer;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int> > board;
    board.resize(n+1);
    for(int i=0; i<n+1; i++) {
        board[i].resize(n+1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> board[i][j];
        }
    }
    int answer = solution(board, n);
    cout << answer << "\n";

    return 0;
}