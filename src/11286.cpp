#include <iostream>
#include "cstdio"
#include "queue"

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if(abs(a)==abs(b))
            return a>b;
        return abs(a) > abs(b);
    }
};

int main() {

    priority_queue<int, vector<int>, cmp> queue;
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int j;
        scanf("%d", &j);
        if(j!=0)
            queue.push(j);
        else {
            if(!queue.empty()) {
                j = queue.top();
                queue.pop();
                printf("%d\n", j);
            }
            else{
                printf("0\n");
            }
        }
    }
    return 0;

}
