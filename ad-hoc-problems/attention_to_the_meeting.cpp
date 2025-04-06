// https://codeforces.com/gym/105327/problem/A

#include <iostream>
using namespace std; 


int main() {
    int directors;
    int available_time;

    cin >> directors;
    cin >> available_time;



    int intervals = directors - 1;
    

    available_time = available_time - intervals;

    cout << available_time / directors;



    return 0;
}

