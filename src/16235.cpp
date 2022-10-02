#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, M, K;
int** additional;
int** nourish;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
vector<vector<vector<int> > > map;
int result = 0;

void spring_summer_winter() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            vector<int> trees = map[i][j];
            vector<int> new_trees;
            int n = nourish[i][j];
            sort(trees.begin(), trees.end());
            int k=0;
            for(; k<trees.size(); k++) {
                //spring
                if(n >= trees[k]) {
                    n -= trees[k];
                    new_trees.push_back(trees[k]+1);
                }
                else {
                    break;
                }
            }
            for(; k<trees.size(); k++) {
                //summer
                n += trees[k]/2;
            }
            map[i][j] = new_trees;
            result -= trees.size() - new_trees.size();
            nourish[i][j] = n + additional[i][j]; //winter
        }
    }
}

void autumn() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            vector<int> trees = map[i][j];
            for(int k=0; k<trees.size(); k++) {
                //autumn
                if(trees[k]%5 == 0) {
                    for(int l=0; l<8; l++) {
                        if(i+dx[l] >= 0 && i+dx[l] < N && j+dy[l] >= 0 && j+dy[l] < N) {
                            map[i+dx[l]][j+dy[l]].push_back(1);
                            result += 1;
                        }
                    }
                }
            }
        }
    }    
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    additional = new int*[N];
    nourish = new int*[N];
    map.resize(N);
    for(int i=0; i<N; i++) {
        additional[i] = new int[N];
        nourish[i] = new int[N];
        map[i].resize(N);
        for(int j=0; j<N; j++) {
            cin >> additional[i][j];
            nourish[i][j] = 5;
        }
    }

    for(int i=0; i<M; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        map[x-1][y-1].push_back(age);
    }
    result = M;
    for(int i=0; i<K; i++) {
        spring_summer_winter();
        autumn();
    }
    cout << result << "\n";

    
	return 0;
}