// https://vjudge.net/contest/703349#problem/H

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() 
{
    int n, m, value, test_case;
    set<int> sums;
    vector<int> values;
    test_case = 0;

    while (true) {
      test_case++;
      set<int> sums;
      vector<int> values;
      cin >> n;
      if (n == 0) {
        break;
      }
      for (int i = 0; i < n; i++) {
        cin >> value;
        for (int j = 0; j < i; j++) {
          sums.insert(value + values[j]);
          //cout << value + values[j] << endl;
        }
        values.push_back(value);
        
      }
      cout << "Case " << test_case << ":" << endl;
      cin >> m;
      int closest1, closest2;
      for (int i = 0; i < m; i++) {
        cin >> value;
        cout << "Closest sum to " << value << " is ";
        auto itlow = sums.lower_bound(value);
        if (itlow == sums.end()) {
          cout << *--itlow << "." << endl;
        }
        else if (itlow != sums.begin()) {
          closest1 = *itlow;
          --itlow;
          closest2 = *itlow;
          if ((closest1 - value) >= (value - closest2)) {
            //cout << closest2 << " or " << closest1 << endl;
            cout << closest2 << "." << endl;
          } else {
            //cout << closest2 << " or " << closest1 << endl;

            cout << closest1 << "." << endl;
          }
        } else {
          cout << *itlow << "." << endl;
        }
      }
    }
}