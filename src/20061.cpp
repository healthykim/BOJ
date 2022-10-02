#include <string>
#include <vector>
#include<iostream>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
vector<vector<int> > green;
vector<vector<int> > blue;

void special_area() {
    vector<int> add; add.resize(4);

    int greencnt = 0; int bluecnt = 0;
    for(int i = 0; i < 2; i++) {
        for(int j=0; j<4; j++) {
            if(green[i][j] == 1) {
                greencnt += 1;
                break;
            }
        }
        for(int j=0; j<4; j++) {
            if(blue[i][j] == 1) {
                bluecnt += 1;
                break;
            }
        }
    }
    while(greencnt > 0) {
        greencnt --;
        green.erase(green.end()-1);
        green.insert(green.begin(), add);
    }
    while(bluecnt > 0) {
        bluecnt --;
        blue.erase(blue.end()-1);
        blue.insert(blue.begin(), add);
    }
}

int get_score() {
    int score = 0;
    bool greenFull[6]; bool blueFull[6];
    fill_n(greenFull, 6, true);
    fill_n(blueFull, 6, true);
    for(int i=0; i<6; i++) {
        //green
        for(int j=0; j<4; j++) {
            if(green[i][j] == 0) {
                greenFull[i] = false; break;
            }
        }
        //blue
        for(int j=0; j<4; j++) {
            if(blue[i][j] == 0) {
                blueFull[i] = false; break;
            }
        }
    }

    //행 삭제
    vector<int> add; add.resize(4);
    for(int i=0; i<6; i++) {
        if(greenFull[i]) {
            green.erase(green.begin() + i);
            green.insert(green.begin(), add);
            score ++;
        }
        if(blueFull[i]) {
            blue.erase(blue.begin() + i);
            blue.insert(blue.begin(), add);
            score ++;
        }
    }
    return score;
}

void do_command(int t, int x, int y) {
    //green
    int nx = 0; int ny = y;
    if(t == 1) {
        while(nx < 6 && green[nx][ny] == 0) {
            nx ++;
        }
        green[nx-1][ny] = 1;
    }
    else if(t == 2) {
        while(nx < 6 && green[nx][ny] == 0 && green[nx][ny+1] == 0) {
            nx ++;
        }
        green[nx-1][ny] = 1; green[nx-1][ny+1] = 1;
    }
    else if(t == 3) {
        while(nx+1 < 6 && green[nx][ny] == 0 && green[nx+1][ny] == 0) {
            nx ++;
        }
        green[nx-1][ny] = 1; green[nx][ny] = 1;
    }
    //blue
    nx = 0; ny = x;
    if(t == 1) {
        while(nx < 6 && blue[nx][ny] == 0) {
            nx ++;
        }
        blue[nx-1][ny] = 1;
    }
    else if(t == 3) {
        while(nx < 6 && blue[nx][ny] == 0 && blue[nx][ny+1] == 0) {
            nx ++;
        }
        blue[nx-1][ny] = 1; blue[nx-1][ny+1] = 1;
    }
    else if(t == 2) {
        while(nx+1 < 6 && blue[nx][ny] == 0 && blue[nx+1][ny] == 0) {
            nx ++;
        }
        blue[nx-1][ny] = 1; blue[nx][ny] = 1;
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    green.resize(6); blue.resize(6);
    for(int i=0; i<6; i++) {
        green[i].resize(4);
        blue[i].resize(4);
    }

    int score = 0;

    for(int i=0; i<n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        do_command(t, x, y);
        score += get_score();
        special_area();
    }

    int cnt = 0;

    for(int i=0; i<6; i++) {
        for(int j=0; j<4; j++) {
            if(green[i][j] == 1) cnt ++;
            if(blue[i][j] == 1) cnt ++;
        }
    }
    
    cout << score << "\n" << cnt << "\n";

    return 0;
}
