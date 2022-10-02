#include<iostream>

using namespace std;

struct Dice {
    int place[2];
    int numbers[6];
};

Dice move(int command, int** map, Dice dice, int N, int M) {
    Dice result;
    int x = dice.place[0];
    int y = dice.place[1];
    if(command == 1) {
        //right
        if(y == M-1) {
            return dice;
        }
        else {
            result.place[0] = x;
            result.place[1] = y + 1;
        }
        result.numbers[0] = dice.numbers[3];
        result.numbers[1] = dice.numbers[1];
        result.numbers[2] = dice.numbers[0];
        result.numbers[3] = dice.numbers[5];
        result.numbers[4] = dice.numbers[4];
        result.numbers[5] = dice.numbers[2];
        if(map[result.place[0]][result.place[1]] == 0) {
            map[result.place[0]][result.place[1]] = result.numbers[5];
        }
        else {
            result.numbers[5] = map[result.place[0]][result.place[1]];
            map[result.place[0]][result.place[1]] = 0;
        }
    }
    else if(command == 2) {
        //left
        if(y == 0) {
            return dice;
        }
        else {
            result.place[0] = x;
            result.place[1] = y - 1;
        }
        result.numbers[0] = dice.numbers[2];
        result.numbers[1] = dice.numbers[1];
        result.numbers[2] = dice.numbers[5];
        result.numbers[3] = dice.numbers[0];
        result.numbers[4] = dice.numbers[4];
        result.numbers[5] = dice.numbers[3];
        if(map[result.place[0]][result.place[1]] == 0) {
            map[result.place[0]][result.place[1]] = result.numbers[5];
        }
        else {
            result.numbers[5] = map[result.place[0]][result.place[1]];
            map[result.place[0]][result.place[1]] = 0;
        }
    }
    else if(command == 3) {
        //up
        if(x == 0) {
            return dice;
        }
        else {
            result.place[0] = x - 1;
            result.place[1] = y;
        }
        result.numbers[0] = dice.numbers[4];
        result.numbers[1] = dice.numbers[0];
        result.numbers[2] = dice.numbers[2];
        result.numbers[3] = dice.numbers[3];
        result.numbers[4] = dice.numbers[5];
        result.numbers[5] = dice.numbers[1];
        if(map[result.place[0]][result.place[1]] == 0) {
            map[result.place[0]][result.place[1]] = result.numbers[5];
        }
        else {
            result.numbers[5] = map[result.place[0]][result.place[1]];
            map[result.place[0]][result.place[1]] = 0;
        }
    }
    else {
        //down
        if(x == N-1) {
            return dice;
        }
        else {
            result.place[0] = x + 1;
            result.place[1] = y;
        }
        result.numbers[0] = dice.numbers[1];
        result.numbers[1] = dice.numbers[5];
        result.numbers[2] = dice.numbers[2];
        result.numbers[3] = dice.numbers[3];
        result.numbers[4] = dice.numbers[0];
        result.numbers[5] = dice.numbers[4];
        if(map[result.place[0]][result.place[1]] == 0) {
            map[result.place[0]][result.place[1]] = result.numbers[5];
        }
        else {
            result.numbers[5] = map[result.place[0]][result.place[1]];
            map[result.place[0]][result.place[1]] = 0;
        }
    }
    
    return result;
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x, y, K;
    int** map;
    cin >> N >> M >> x >> y >> K;
    map = new int*[N];
    for(int i=0; i<N; i++) {
        map[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }

    Dice dice;
    dice.place[0] = x;
    dice.place[1] = y;
    for(int i= 0; i<6; i++) {
        dice.numbers[i] = 0;
    }
    for(int i=0; i<K; i++) {
        int command;
        cin >> command;
        Dice new_dice = move(command, map, dice, N, M);
        if(new_dice.place[0] == dice.place[0] && new_dice.place[1] == dice.place[1]) {
            continue;
        }
        else {
            cout << new_dice.numbers[0] << "\n";
            dice = new_dice;
        }
    }


	return 0;
}