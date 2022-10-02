#include <iostream>
#include "cstdio"
#include "queue"
#include "set"
#include "cmath"

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    int brokenNum;
    set<int> buttons;
    scanf("%d", &brokenNum);
    for(int i=0; i<brokenNum; i++){
        int k;
        scanf("%d", &k);
        buttons.insert(k);
    }
    int min = abs(100-N);
    for(int i=0; i<10000000; i++){
        int click =0;
        int tmp = i;
        while(true){
            if(buttons.find(tmp%10)!=buttons.end())
                break;
            else {
                tmp = tmp / 10;
                click++;
                if (tmp == 0) {
                    click += abs(N - i);
                    if (click < min) {
                        min = click;
                    }
                    break;
                }
            }
        }
    }
    printf("%d", min);



}
