// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1282

#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double equation(double x, int p, int q, int r, int s, int t, int u) {
  return p*(pow(M_E, -x)) + q*(sin(x)) + (r*cos(x)) + s * tan(x) + t * x*x + u;
}

void bisection(double lwr_bound, double upr_bound, int p, int q, int r, int s, int t, int u) {
  float error_margin = 0.00000001;
  
  double c = lwr_bound;
  
  if (equation(upr_bound, p, q, r, s, t, u)*equation(lwr_bound, p, q, r, s, t, u) > 0) {
    cout << "No solution" << endl;
    return;
  }
  
  
  while ((upr_bound - lwr_bound) >= error_margin) {
    c = (lwr_bound + upr_bound)/2;
    
    if (equation(c, p, q, r, s, t, u) == 0.0) {
      break;
    } else if (equation(c, p, q, r, s, t, u)*equation(lwr_bound, p, q, r, s, t, u) < 0) {
      upr_bound = c;
    } else {
      lwr_bound = c;
    }
  }
  if ((c > -0.00001) and (c < 0.00001)) {
    cout << fixed << setprecision(4) << 0.0000 << endl;
  } else {
    cout << fixed << setprecision(4) << c << endl;
  }
  
}

int main() 
{
    int p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u) {
      bisection(-0.0000001, 1.0000001, p, q, r, s, t, u);
    }
    
    return 0;
}