// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077

#include <iostream>
#include <set>
using namespace std;

int main() 
{
    int amount_days;
    while (true) {
      cin >> amount_days;
      if (amount_days == 0) {
        break;
      }
      int amount_bills, bill;
      long int promotion_sum;
      promotion_sum = 0;
      multiset<int> urn;
      for (int i = 0; i < amount_days; i++) {
        cin >> amount_bills;
        for (int i = 0; i < amount_bills; i++) {
          cin >> bill;
          urn.insert(bill);
        }
        promotion_sum += *urn.rbegin() - *urn.begin();
        urn.erase(urn.begin());
        urn.erase(prev(urn.end()));
      }
      cout << promotion_sum << endl;
    }
}