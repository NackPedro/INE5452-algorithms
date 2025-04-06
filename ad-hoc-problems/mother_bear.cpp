// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1886

#include <iostream>
using namespace std; 


string clear_string(string sentence) {
    string clear_sentence;
    string unwanted = ".,!?";
    for (int i = 0; i < sentence.length(); i++) {
        if ((sentence[i] != '?') && (sentence[i] != '!') && (sentence[i] != ',') && (sentence[i] != '.') && (sentence[i] != ' ')) {
            clear_sentence += tolower(sentence[i]);
        }
    }
    return clear_sentence;
}

int main() {

    string dirty_sentence;

    while (true) {
        getline(cin, dirty_sentence);
        if (dirty_sentence == "DONE") {
            break;
        }
        string sentence = clear_string(dirty_sentence);
        int start = 0;
        int end = sentence.length() - 1;
        bool is_palindrome = true;
        while (is_palindrome) {
            if (start >= end) {
                break;
            }
            if (sentence[start] != sentence[end]) {
                is_palindrome = false;
                break;
            }
            start++;
            end--;
        }
        if (is_palindrome) {
            cout << "You won't be eaten!";
            cout << endl;
        } else {
            cout << "Uh oh..";
            cout << endl;
        }
    }

    return 0;
}
