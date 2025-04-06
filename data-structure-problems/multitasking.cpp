// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3077

#include <iostream>
#include <bitset>
using namespace std;

int main() 
{
    int one_time_tasks, repeating_tasks;
    bool conflict;
    bitset<1000000> calendar;
    
    while (true) {
      cin >> one_time_tasks >> repeating_tasks;
      calendar.reset();
      if (one_time_tasks + repeating_tasks == 0) {
        break;
      }
      
      int start_time, end_time, interval;
      conflict = false;
      for (int i = 0; i < one_time_tasks; i++) {
        cin >> start_time >> end_time;
        for (int j = start_time; j < end_time; j++) {
          if (calendar.test(j)) {
            conflict = true;
            break;
          } else {
            calendar.set(j);
          }
        }
      }
      
      
      for (int i = 0; i < repeating_tasks; i++) {
        cin >> start_time >> end_time >> interval;
        while ((start_time < 1000000) && (!conflict)) {
          for (int j = start_time; ((j < 1000000) && (j < end_time)); j++) {
            if (calendar.test(j)) {
              conflict = true;
              break;
            } else {
              calendar.set(j);
            }
          }
          start_time += interval;
          end_time += interval;
          if (conflict) {break;}
        }
      }
      
      cout << (conflict ? "CONFLICT" : "NO CONFLICT") << endl;
    }
    return 0;
}