// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2612

#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
      bool solved = false;
      cin >> a >> b >> c;
      for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
          for (int z = -100; z <= 100; z++) {
            if ((x != y) && (x != z) && (y != z)) {
              if ((x + y + z == a) && (x * y * z == b) && (x*x + y*y + z*z == c)) {
                cout << x << " " << y << " " << z << endl;
                solved = true;
                break;
              }
            }
          }
          if (solved) {break;}
        }
        if (solved) {break;}
      }
      if (!solved) {
        cout << "No solution." << endl;
      }
    }
}