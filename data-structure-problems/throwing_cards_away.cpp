// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    int test_case, card, bottom_card, discarded_card;
    
    queue<int> test_cases;
    queue<int> cards;
    queue<int> removed_cards;
    while (true) {
      cin >> test_case;
      if (test_case == 0) {
        break;
      }
      test_cases.push(test_case);
    }
    
    while (!test_cases.empty()) {
      test_case = test_cases.front();
      test_cases.pop();
      for (int i = 1; i < test_case + 1; i++) {
        cards.push(i);
      }
      cout << "Discarded cards:";
      if (test_case > 1) {
        cout << " ";
      }
  
      while (cards.size() >= 2) {
        discarded_card = cards.front();

        cout << discarded_card;
        if (cards.size() >= 3) {
          cout << ", ";
        }

        cards.pop();
        removed_cards.push(cards.front());
        bottom_card = cards.front();
        cards.pop();
        cards.push(bottom_card);
        
      }
      cout << endl;
  
      cout << "Remaining card: " << cards.front() << endl;
      while (!cards.empty()) {
        cards.pop();
      }

    }

    return 0;
}