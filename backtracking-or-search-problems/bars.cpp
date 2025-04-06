// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3886

#include <iostream>
#include <vector>
using namespace std;

void decide(vector<int> &bars, int &desired_length, vector<int> &used, int current, int &found) {
  
  if (found) {
    return;
  }
  if (current > desired_length) {
    return;
  } else if (desired_length == current) {
    cout << "YES" << endl;
    found = true;
    return;
  }
  
  for (int i = 0; i < bars.size(); i++) {
    if (!used[i]) {
      used[i] = 1;
      current += bars[i];
      decide(bars, desired_length, used, current, found);
      used[i] = 0;
      current -= bars[i];
    }
  }
  
  
  
}

int main() 
{
  int test_cases;
  cin >> test_cases;
  for (int i = 0; i < test_cases; i++) {
    int length, amount_bars, bar;
    vector<int> bars;
    cin >> length;
    cin >> amount_bars;
    vector<int> used(amount_bars, 0);
    
    for (int i = 0; i < amount_bars; i++) {
      cin >> bar;
      bars.push_back(bar);
    }
    
    int found = false;
    
    decide(bars, length, used, 0, found);
    if (!found) {
      cout << "NO" << endl;
    }
    
  }
}