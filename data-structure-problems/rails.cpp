// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1844

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() 
{
    int amount;
    while (true) {
      cin >> amount;
      if (amount == 0) {
        break;
      }
      
      while (true) {
        
        int needs_to_leave, left;
        vector<int> order;
        stack<int> trains;
    
        for (int i = 0; i < amount; i++) {
          cin >> needs_to_leave;
          if (needs_to_leave == 0) {
            break;
          }
          order.push_back(needs_to_leave);
        }
        if (needs_to_leave == 0) {
          break;
        }
        
        int start = 0;
        needs_to_leave = order[start];
        
        for (int i = 1; i < amount + 1; i++) {
          if (needs_to_leave != i) {
            trains.push(i);
          } else {
            start++;
            needs_to_leave = order[start];
            while (!trains.empty()) {
              if (needs_to_leave == trains.top()) {
                trains.pop();
                start++;
                needs_to_leave = order[start];
              } else {
                break;
              }
            }
          }
        }
        
        
        while (!trains.empty()) {
          if (needs_to_leave != trains.top()) {
            break;
          } else {
            start++;
            needs_to_leave = order[start];
            trains.pop();
          }
        }
        
        if (trains.empty()) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
      cout << endl;



    }

    return 0;
}