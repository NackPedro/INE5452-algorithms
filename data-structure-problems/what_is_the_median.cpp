// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1048

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    int amount, middle, element1, element2;
    vector<int> numbers;
    while (cin >> amount) {
      numbers.push_back(amount);
      middle = numbers.size() / 2;
      if (numbers.size() % 2) {
        nth_element(numbers.begin(), numbers.begin() + (middle), numbers.end());
        cout << numbers[middle] << endl;
      } else {
        nth_element(numbers.begin(), numbers.begin() + middle - 1, numbers.end());
        element1 = numbers[middle - 1];
        nth_element(numbers.begin(), numbers.begin() + middle, numbers.end());
        element2 = numbers[middle];
        cout << (element1 + element2) / 2 << endl;
      }
    }
    return 0;
}