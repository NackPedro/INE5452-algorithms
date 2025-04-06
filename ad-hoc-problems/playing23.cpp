// https://codeforces.com/gym/103960/problem/J

#include <iostream>
#include <vector>
#include <algorithm>
int calculate_points(std::vector<int> cards) {
    int sum = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] > 10) {
          sum += 10;
        } else {
          sum += cards[i];
        }
    }
    return sum;
}

int main()
{
    int rounds_played, card1, card2, card3, card4, cardn;
    
    std::vector<int> deck = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    
    int mary_points, john_points;

    scanf("%i", &rounds_played);

    scanf("%i %i", &card1, &card2);
    std::vector<int> john_cards = {card1, card2};
    deck[card1-1] -= 1;
    deck[card2-1] -= 1;

    scanf("%i %i", &card3, &card4);
    std::vector<int> mary_cards = {card3, card4};
    deck[card3-1] -= 1;
    deck[card4-1] -= 1;
    
    for (int i = 0; i < rounds_played; i++) {
        std::cin >> cardn;
        mary_cards.push_back(cardn);
        john_cards.push_back(cardn);
        deck[cardn-1] -= 1;
    }
    
    mary_points = calculate_points(mary_cards);
    john_points = calculate_points(john_cards);
    
    int answer = -1;
    
    if ((mary_points + 10 < 23) && (john_points + 10 <= 23)) {
      
    } else if (mary_points >= john_points) {
      for (int i = 23 - mary_points; i < 14; i++) {
        if ((mary_points + i > 23) && (i < 11)) {
          break;
        } else if (deck[i-1] > 0) {
          answer = i;
          break;
        }
      }
    } else {
      for (int i = 24 - john_points; i < 14; i++) {
        if ((mary_points + i > 23) && (i < 11)) {
          break;
        } else if (deck[i-1] > 0) {
          answer = i;
          break;
        }
      }
    }

    std::cout << answer << std::endl;
    
    return 0;
}