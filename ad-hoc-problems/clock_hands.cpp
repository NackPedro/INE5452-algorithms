// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=520

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() 
{
    float hours, minutes;
    
    float hours_angle, minutes_angle, angle;
    
    while (true) {
      scanf("%f:%f", &hours, &minutes);
      if ((hours == minutes) && (hours == 0)) {
        break;
      }
      if (hours == 12.0) {
        hours = 0.0;
      }
      if (minutes == 60.0) {
        minutes = 0.0;
      }
  
      hours_angle = hours*30 + minutes*0.5;
      minutes_angle = minutes*6.0;
      
      angle = hours_angle - minutes_angle;
      if (angle < 0) {
        angle = angle*-1;
      }
      if (angle > 180) {
        angle = 360 - angle;
      }
      
      
      
      printf("%.3f\n", angle);

    }
    

}