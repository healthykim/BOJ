#include <iostream>
#include "cstdio"
#include "set"
#include "vector"

int main() {
    std::set<std::string> noSee;
    std::set<std::string> noSeeHear;
    int N, M;
    scanf("%d %d\n", &N, &M);
    for(int i=0; i<N; i++){
        char j[20];
        scanf("%s\n", j);
        noSee.insert(j);
    }

    for(int i=0; i<N; i++){
        char j[20];
        scanf("%s\n", j);
        if(noSee.find(j)!=noSee.end()){
            noSeeHear.insert(j);
        }
    }

    int size = noSeeHear.size();
    printf("%d\n", size);
    auto it = noSeeHear.begin();
    while(it!=noSeeHear.end()){
        printf("%s\n", (*it).c_str());
        it++;
    }
    return 0;
}
