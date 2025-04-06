// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2323

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main() 
{
  int number_of_tests;
  cin >> number_of_tests;
  for (int i = 0; i < number_of_tests; i++) {
    map<int, set<int>> stamps;
    map<int, int> points;
    int number_of_friends;
    cin >> number_of_friends;
    for (int j = 0; j < number_of_friends; j++) {
      points[j] = 0;
      int number_of_stamps, stamp;
      cin >> number_of_stamps;
      for (int k = 0; k < number_of_stamps; k++) {
        cin >> stamp;
        auto it = stamps.find(stamp);
        if (it != stamps.end()) {
          it->second.insert(j);
          
        } else {
          set<int> owner = {j};
          stamps[stamp] = owner;
        }
      }
    }
    float sum = 0;
    for (const auto& stamp : stamps) {
        if (stamp.second.size() == 1) {
            int owner = *stamp.second.begin();
            points[owner]++;
            sum++;
        }
    }

    cout << "Case " << i + 1 << ": ";
    for (int j = 0; j < number_of_friends; j++) {
        cout << fixed << setprecision(6) << (points[j] / (double)sum) * 100 << "%";
        if (j+1 != number_of_friends) {
          cout << " ";
        }
    }
    cout << endl;
  }
}