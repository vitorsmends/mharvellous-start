    #include <iostream>
    #include <sstream>
    #include <cstdio>
    #include <cstdlib>
    #include <cmath>
    #include <string>
    #include <vector>
    #include <queue>
    #include <stack>
    #include <map>
    #include <set>
    #include <algorithm>
    #include <functional>
    #include <numeric>
    #include <memory.h>
    #include <time.h>
using namespace std;
typedef long long LL;
int tam_rank, tam_player;

set<int> define_rank(){
    cin >> tam_rank;
    set<int> s;
    for (int i = 0; i < tam_rank; ++i){
        int x;
        cin >> x;
        s.insert(x);
    }
    return s;
}

vector<int> define_rank(set<int> ranked){
    cin >> tam_player;
    vector<int> player(ranked.begin(), ranked.end());
    for (int i = 0; i < tam_player; ++i){
        int x;
        cin >> x;
        int pos = upper_bound(player.begin(), player.end(), x) - player.begin();
        int r = (int)player.size() - pos + 1;
        printf("%d\n", r);
    }
    return player;
}

int main(){
    set<int> ranked = define_rank();
    vector<int> player = define_rank(ranked);
    return 0;
}
