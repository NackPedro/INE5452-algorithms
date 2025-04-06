// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() 
{
    int test_case, value;
    while (true) {
      cin >> test_case;
      if (test_case == 0) {
        break;
      }
      
      priority_queue<int> priority;
      for (int i = 0; i < test_case; i++) {
        cin >> value;
        priority.push(100000 - value);
      }
      
      int val1, val2;
      int sum = 0;
      while (priority.size() > 1) {
        val1 = 100000 - priority.top();
        priority.pop();
        val2 = 100000 - priority.top();
        priority.pop();
        sum += val1 + val2;
        priority.push(100000 - (val1 + val2));
        
      }
      cout << sum << endl;
    }
    

    return 0;
}