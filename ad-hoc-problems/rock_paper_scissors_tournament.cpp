// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1844

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() 
{
    bool first_case = true;
    while (true) {
      int amount_players, amount_turns;
      cin >> amount_players;
      
      if (amount_players == 0) {
        break;
      }
      
      cin >> amount_turns;
      
      int player1, player2;
      string play1, play2;
      
      int games = (amount_players*amount_turns*(amount_players-1))/2;
      
      vector<float> wins(amount_players, 0);
      vector<float> losses(amount_players, 0);
      
      for (int i = 0; i < games; i++) {
        cin >> player1 >> play1 >> player2 >> play2;
        if (play1 == play2) {
        } else if ((play1 == "rock" && play2 == "scissors") || 
          (play1 == "paper" && play2 == "rock") || 
          (play1 == "scissors" && play2 == "paper")) {
            wins[player1 - 1] += 1;
            losses[player2 - 1] += 1;
        } else {
          wins[player2 - 1] += 1;
          losses[player1 - 1] += 1;
        }
      }
      if (!first_case) {
          printf("\n");
      }
      first_case = false;
      for (int i = 0; i < amount_players; i++) {
        if (wins[i] + losses[i] == 0) {
          printf("-\n");
        } else {
          float average = wins[i]/(wins[i] + losses[i]);
          printf("%.3f\n", average);
        }
      }
    }
}