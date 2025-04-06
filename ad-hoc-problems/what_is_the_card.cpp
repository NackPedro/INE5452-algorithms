// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1587

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int calculate_value(std::string card) {
  int value;
  if ((card[0] == 'A') || (card[0] == 'K') || (card[0] == 'Q') || (card[0] == 'J') || (card[0] == 'T')) {
    value = 10;
  } else {
    value = std::stoi(std::string(1, card[0]));
  }
  return value;
}


int main()
{
    int test_cases, y;
    std::cin >> test_cases;
    
    std::string card;
    
    for (int i = 0; i < test_cases; i++) {
      y = 0;
      std::vector<std::string> deck = {};
      std::vector <std::string> hand_cards = {};
      for (int j = 0; j < 27; j++) {
        std::cin >> card;
        deck.push_back(card);        
      }
      for (int j = 0; j < 25; j++) {
        std::cin >> card;
        hand_cards.push_back(card);        
      }
      int removed_cards = 0;
      for (int j = 0; j < 3; j++) {
        int value = calculate_value(deck.back());
        deck.pop_back();
        y += value;
        removed_cards += 10 - value;
        for (int k = 0; k < 10 - value; k++) {
          deck.pop_back();
        }
      }
      for (int j = 0; j < 25; j++) {
        deck.push_back(hand_cards[j]);
      }
      std::cout << "Case " << i + 1 << ": " << deck[y-1] << std::endl;
    }
    return 0;
}