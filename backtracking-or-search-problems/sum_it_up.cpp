// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=515#google_vignette

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print_answer(int t, set<vector<int>> answers) {
  cout << "Sums of " << t << ":" << endl;
  if (answers.empty()) {
    cout << "NONE" << endl;
  }
  vector<vector<int>> final_answers;
  for (auto answer : answers) {
    final_answers.push_back(answer);
  }
  for (int i = final_answers.size() - 1; i > -1; i--) {
    for (int j = 0; j < final_answers[i].size(); j++) {
      cout << final_answers[i][j];
      if (j < final_answers[i].size() - 1) {
        cout << "+";
      }
    }
    cout << endl;
  }
}


void find_sums(int t, vector<int> &numbers, vector<int> &current_answer, set<vector<int>> &answers, int sum, int iterator) {
  
  if (sum == t) {
    answers.insert(current_answer);
    return;
  }
  
  if (sum > t) {
    return;
  }
  
  for (int i = iterator; i < numbers.size(); i++) {
    current_answer.push_back(numbers[i]);
    sum += numbers[i];
    find_sums(t, numbers, current_answer, answers, sum, i+1);
    current_answer.pop_back();
    sum -= numbers[i];
  }
  return;
  
}


int main() 
{
  while (true) {
    int t, n;
    cin >> t >> n;
    if (t + n == 0) {
      break;
    }
    int number;
    vector<int> numbers, current_answer;
    set<vector<int>> answers;
    for (int i = 0; i < n; i++) {
      cin >> number;
      numbers.push_back(number);
    }
    
    find_sums(t, numbers, current_answer, answers, 0, 0);
    print_answer(t, answers);
  }
}