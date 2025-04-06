// https://codeforces.com/gym/105327/problem/L

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


std::string to_binary(int number, int size) {
  std::string value = "";
  int i = pow(2, size);
  while (i > 1) {
    if (number >= i) {
      number -= i;
      value += "1";
      i = i / 2;
    } else {
      value += "0";
      i = i / 2 ;
    }
  }
  if (number == 1) {
    value += "1";
  } else {
    value += "0";
  }
  return value;
}

int to_int(std::string bin_number) {
  int value = 0;
  for (int i = 0; i < bin_number.length(); i++) {
    if (bin_number[i] == '1') {
      value += pow(2, bin_number.length() - i - 1);
    }
  }
  return value;
}

int main()
{
    int amount, number;
    std::vector<int> numbers;
    std::vector<std::string> binary_numbers;
    
    std::cin >> amount;
    for (int i = 0; i < amount; i++) {
      std::cin >> number;
      numbers.push_back(number);
    }
    std::sort(numbers.begin(), numbers.end());
    
    int size = log2(numbers.back());
    
    for (int num : numbers) {
      binary_numbers.push_back(to_binary(num, size));
    }
    std::vector<std::string> lec_maximum(amount, std::string(size+1, '0'));
    
    int amount_of_1;
    
    for (int i = 0; i < size + 1; i++) {
      amount_of_1 = 0;
      for (std::string bin_value : binary_numbers) {
        if (bin_value[i] == '1') {
          amount_of_1++;
        }
      }
      for (int j = 0; j < lec_maximum.size(); j++) {
        if (amount_of_1 == 0) {
          break;
        }
        lec_maximum[j][i] = '1';
        amount_of_1--;
      }
    }
    
    

    
    bool first = true;
    
    for (std::string value : lec_maximum) {
      if (first) {
        first = false;
      } else {
        std::cout << " ";
      }
      std::cout << to_int(value);
    }
    return 0;
}