#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> wheels;
vector<vector<int> > neighbors; // = {{-1, 1}, {0,2}, {1,3}, {2, 4}}; (doesn't work when the version is lower than c11)
bool rotated[4];

void rotate(int index, int direction) {
    rotated[index] = true;
    int next_1 = neighbors[index][0];
    int next_2 = neighbors[index][1];
    if(next_1 != -1 && !rotated[next_1] && wheels[next_1]%1000000/100000!=wheels[index]%100/10) { //3th & 7th
        rotate(next_1, -direction);
    }
    if(next_2 != 4 && !rotated[next_2] && wheels[next_2]%100/10!=wheels[index]%1000000/100000) {
        rotate(next_2, -direction);
    }

    if(direction == -1) {
        int first = wheels[index]/10000000;
        wheels[index] = (wheels[index]%10000000)*10 + first;
    }
    else {
        int end = wheels[index]%10;
        wheels[index] = (wheels[index]/10) + end*10000000;
    }
    rotated[index] = false;
    return;
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<4; i++) {
        vector<int> neighbor;
        rotated[i] = false;
        neighbor.push_back(i-1);
        neighbor.push_back(i+1); 
        neighbors.push_back(neighbor);      
        int c;
        cin >> c;
        wheels.push_back(c);
    }

    int K;
    cin >> K;
    for(int i=0; i<K; i++) {
        int index, direction;
        cin >> index >> direction;
        rotate(index-1, direction);
    }

    int score = 0;
    for(int i=0; i<4; i++) {    
        score += wheels[i]/10000000 * pow(2, i);
    }
    cout << score << "\n";

	return 0;
}