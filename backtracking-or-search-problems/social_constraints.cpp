// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2842

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

bool is_valid_chairs(const vector<int>& chairs, const vector<tuple<int, int, int>>& rules) {
    vector<int> position(chairs.size());
    for (size_t i = 0; i < chairs.size(); ++i) {
        position[chairs[i]] = i;
    }
    for (const auto& [a, b, c] : rules) {
        int dist = abs(position[a] - position[b]);

        if (c > 0 && dist > c) {
          return false;
        }
        if (c < 0 && dist < -c) {
          return false;
        }
    }
    return true;
}

void backtrack(vector<int>& chairs, vector<bool>& used, int n, const vector<tuple<int, int, int>>& rules, int& valid_count) {
    if (chairs.size() == n) {
        if (is_valid_chairs(chairs, rules)) {
            valid_count++;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            chairs.push_back(i);
            used[i] = true;
            backtrack(chairs, used, n, rules, valid_count);
            chairs.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n + m == 0) {
          break;
        }

        vector<tuple<int, int, int>> rules;
        vector<int> chairs;
        vector<bool> used(n, false);

        int valid_count = 0;
        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            rules.emplace_back(a, b, c);
        }
        backtrack(chairs, used, n, rules, valid_count);

        cout << valid_count << endl;
    }

    return 0;
}
