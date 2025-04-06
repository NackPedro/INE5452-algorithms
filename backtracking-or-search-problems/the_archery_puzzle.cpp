// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4705

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int choose_solution(std::vector<std::vector<int>>& solutions, int& shortest) {
    solutions.erase(
        std::remove_if(solutions.begin(), solutions.end(),
                       [shortest](const std::vector<int>& s) { return s.size() > shortest; }),
        solutions.end());
    return solutions.size();
}



void backtracking(int &sum, int &score, vector<int> &solution, vector<int> &points, vector<vector<int>> &solutions, int &shortest) {
  if (solution.size() > shortest) {
    return;
  }
  if (sum == score) {
    if (solution.size() < shortest) {
      shortest = solution.size();
    }
    solutions.push_back(solution);
    return;
  } else if (sum > score) {
    return;
  }

  for (int i = points.size() - 1; i > -1; i--) {
    sum += points[i];
    solution.push_back(points[i]);
    backtracking(sum, score, solution, points, solutions, shortest);
    solution.pop_back();
    sum -= points[i];
  }

  return;
}

int main() {
  
  int test_cases;
  cin >> test_cases;
  
  for (int i = 0; i < test_cases; i++) {
    vector<vector<int>> solutions;
    int N, score;
    cin >> N >> score;
    vector<int> points;
    int point;
    for (int j = 0; j < N; j++) {
      cin >> point;
      points.push_back(point);
    }
    
    int sum = 0;
    int shortest = INT_MAX;
    vector<int> solution;
    backtracking(sum, score, solution, points, solutions, shortest);
    choose_solution(solutions, shortest);
    
    cout << "Case " << i + 1 << ": ";
    if (solutions.size() == 0) {
      cout << "impossible" << endl;
    } else {
      sort(solutions.begin(), solutions.end());
      solution = solutions[solutions.size()-1];
      sort(solution.begin(), solution.end());
      cout << "[" << solution.size() << "] ";
      for (int j = solution.size() - 1; j > -1; j--) {
        cout << solution[j];
        if (j - 1 > -1) {
          cout << " ";
        }
      }
      cout << endl;
      
    }

    
    
  }
  return 0;
}


