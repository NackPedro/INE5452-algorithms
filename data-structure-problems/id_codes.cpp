// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=82

#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    string sequence;
    bool next_sequence;
    while (true) {
      cin >> sequence;
      if (sequence == "#") {
        break;
      }
      
      next_sequence = next_permutation(sequence.begin(), sequence.end());
      if (next_sequence) {
        for (int i = 0; i < sequence.size(); i++) {
          cout << sequence[i];
        }
        cout << endl;
      } else {
        cout << "No Successor" << endl;
      }
    }
    return 0;
}