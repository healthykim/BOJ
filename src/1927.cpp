#include <iostream>
#include "cstdio"
#include "queue"

using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> queue;
    int N;
    scanf("%d\n", &N);
    for(int i = 0; i<N; i++){
        int j;
        scanf("%d\n", &j);
        if(j!=0)
            queue.push(j);
        else {
            if(!queue.empty()) {
                j = queue.top();
                queue.pop();
                printf("%d\n", j);
            }
            else{
                printf("%d\n", 0);
            }
        }
    }

}
