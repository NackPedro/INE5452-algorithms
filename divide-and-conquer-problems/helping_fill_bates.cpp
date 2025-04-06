// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1508

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() 
{
    string S, search;
    cin >> S;
    int amount;
    map<char, vector<int>> occurrences;
    
    for (int i = 0; i < S.length(); i++) {
      occurrences[S[i]].push_back(i);
    }
    
    cin >> amount;
    while (amount--) {
      int min, max;
      bool matched = true;
      bool first = true;
      string search;
      cin >> search;
      int index = -1;
      for (int i = 0; i < search.length(); i++) {
        int current = search[i];
        auto pos = upper_bound(occurrences[current].begin(), occurrences[current].end(), index);
        if (pos == occurrences[current].end()) {
          matched = false;
          break;
        }
        index = *pos;
        if (first) {
          first = false;
          min = index;
        }
        if (i == (search.length() - 1)) {
          max = index;
        }
      }
      if (!matched) {
        cout << "Not matched" << endl;
      } else {
        cout << "Matched " << min << " " << max << endl;
      }
    }
    return 0;
}