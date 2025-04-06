// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2261

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() 
{
    int frosh;
    while (true) {
      cin >> frosh;
      if (frosh == 0) {
        break;
      }
      map<set<int>, int> count;
      int d1, d2, d3, d4, d5;
      for (int i = 0; i < frosh; i++) {
        cin >> d1 >> d2 >> d3 >> d4 >> d5;
        set<int> classes = {d1, d2, d3, d4, d5};
        auto it = count.find(classes);
        if (it == count.end()) {
          count.insert(make_pair(classes, 1));
        } else {
          it->second++;
        }
      }
      int max = 0;
      for (auto combination : count) {
        if (combination.second > max) {
          max = combination.second;
        }
      }
      int student_count = 0;
      for (auto combination : count) {
        if (combination.second == max) {
          student_count += max;
        }
      }
      cout << student_count << endl;
    }
    
}