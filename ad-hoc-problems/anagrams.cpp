// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=395

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() 
{
    int amount;
    cin >> amount;
    
    vector<string> words;
    vector<string> sorted_words;
    
    string current_word, current_word_sorted;
    
    cin.ignore();
    cin.ignore();
    
    for (int i = 0; i < amount; i++) {
      words = {};
      sorted_words = {};
      while (getline(cin, current_word)) {
          if (current_word.empty()) {
            break;
          }
          words.push_back(current_word);
      }
      sort(words.begin(), words.end());
      for (int j = 0; j < words.size(); j++) {
        string clear_word = "";
        current_word = words[j];
        for (int k = 0; k < current_word.length(); k++) {
          if (current_word[k] != ' ') {
            clear_word += current_word[k];
          }
        }
        sort(clear_word.begin(), clear_word.end());
        sorted_words.push_back(clear_word);
      }
      
      for (int j = 0; j < words.size(); j++) {
          for (int k = j + 1; k < words.size(); k++) {
              if (sorted_words[j] == sorted_words[k]) {
                  cout << words[j] << " = " << words[k] << endl;
              }
          }
          
      }
      if (i + 1 != amount) {
        cout << endl;
      }
    }
}