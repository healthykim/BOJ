#include <iostream>
#include "map"

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    map<string, string> passwordMap;

    for(int i=0; i<N; i++){
        string site, password;
        cin>> site >> password;
        passwordMap[site] = password;
    }

    for(int i=0; i<M; i++){
        string a;
        cin>> a;
        cout << passwordMap[a]<<"\n";
    }


}
