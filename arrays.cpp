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
#include <iterator>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;
using std::reverse;

int main() {
    int n, a;
    cin >> n;
    vector<int> vetor;
    for(int i = 0; i < n; i++){
        cin >> a;
        vetor.push_back(a);
    }
    
    reverse(vetor.begin(), vetor.end());
    
    for (const auto &num : vetor){
        cout << num << " ";
    }
    return 0;
    
}