#include<iostream>
#include<queue>
#include<climits>

using namespace std;

int find_max(int** board, int n) {
    int max = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] > max) {
                max = board[i][j];
            }
        }
    }
    return max;
}

int** move(int** board, int n, int direction) {
    int** result;
    int** combined;
    result = new int*[n];
    combined = new int*[n];
    bool changed = false;
    
    for(int i=0; i<n; i++) {
        result[i] = new int[n];
        combined[i] = new int[n];
        for(int j=0; j<n; j++) {
            result[i][j] = board[i][j];
            combined[i][j] = 0;
        }
    }

    if(direction == 0) {
        //up
        bool moved = true;
        while(moved==true) {
            moved = false;
            for(int i=1; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(result[i][j] != 0 && result[i-1][j] == 0) {
                        result[i-1][j] = result[i][j];
                        combined[i-1][j] = combined[i][j];
                        combined[i][j] = 0;
                        result[i][j] = 0;
                        moved = true;
                    }
                    else if(result[i][j] != 0 && combined[i][j] == 0 && result[i-1][j] == result[i][j] && combined[i-1][j] == 0) {
                        result[i-1][j] = 2*result[i][j];
                        result[i][j] = 0;
                        combined[i-1][j] = 1;
                        moved = true;
                    }
                    else {
                        result[i][j] = result[i][j];
                    }
                }
            }
        }
    }
    else if (direction == 1) {
        //down
        bool moved = true;
        while(moved==true) {
            moved = false;
            for(int i=n-2; i>=0; i--) {
                for(int j=0; j<n; j++) {
                    if(result[i][j] != 0 && result[i+1][j] == 0) {
                        result[i+1][j] = result[i][j];
                        combined[i+1][j] = combined[i][j];
                        combined[i][j] = 0;
                        result[i][j] = 0;
                        moved = true;
                    }
                    else if(result[i][j] != 0 && combined[i][j] == 0 && result[i+1][j] == result[i][j] && combined[i+1][j] == 0) {
                        result[i+1][j] = 2*result[i][j];
                        result[i][j] = 0;
                        combined[i+1][j] = 1;
                        moved = true;
                    }
                    else {
                        result[i][j] = result[i][j];
                    }
                }
            }
        }
    }
    else if (direction == 2) {
        //right
        bool moved = true;
        while(moved==true) {
            moved = false;
            for(int i=0; i<n; i++) {
                for(int j=n-2; j>=0; j--) {
                    if(result[i][j] != 0 && result[i][j+1] == 0) {
                        result[i][j+1] = result[i][j];
                        combined[i][j+1] = combined[i][j];
                        combined[i][j] = 0;
                        result[i][j] = 0;
                        moved = true;
                    }
                    else if(result[i][j] != 0 && combined[i][j] == 0 && result[i][j+1] == result[i][j] && combined[i][j+1] == 0) {
                        result[i][j+1] = 2*result[i][j];
                        result[i][j] = 0;
                        combined[i][j+1] = 1;
                        moved = true;
                    }
                    else {
                        result[i][j] = result[i][j];
                    }
                }
            }
        }
    }
    else {
        //left
        bool moved = true;
        while(moved==true) {
            moved = false;
            for(int i=0; i<n; i++) {
                for(int j=1; j<n; j++) {
                    if(result[i][j] != 0 && result[i][j-1] == 0) {
                        result[i][j-1] = result[i][j];
                        combined[i][j-1] = combined[i][j];
                        combined[i][j] = 0;
                        result[i][j] = 0;
                        moved = true;
                    }
                    else if(result[i][j] != 0 && combined[i][j] == 0 && result[i][j-1] == result[i][j] && combined[i][j-1] == 0) {
                        result[i][j-1] = 2*result[i][j];
                        result[i][j] = 0;
                        combined[i][j-1] = 1;
                        moved = true;
                    }
                    else {
                        result[i][j] = result[i][j];
                    }
                }
            }
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int** first;
    
    first = new int*[n];
    for(int i=0; i<n; i++) {
        first[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin >> first[i][j];
        }
    }

    queue<pair<int**, int> > queue;
    queue.push(pair<int**, int>(first, 0));
    int max = -1;
    while(!queue.empty()) {
        pair<int**, int> now = queue.front();
        queue.pop();

        if(now.second == 5) {
            int now_max = find_max(now.first, n);
            if(now_max > max) {
                max = now_max;
            }
            continue;
        }

        for(int i=0; i<4; i++) {
            int** moved = move(now.first, n, i);
            queue.push(pair<int**, int>(moved, now.second + 1));
        }
    }
    cout << max << "\n";
	return 0;
}







