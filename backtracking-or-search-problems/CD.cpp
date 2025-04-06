// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=565

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void print_answer(int best_time, vector<int> best_sequence) {
  for (int i = 0; i < best_sequence.size(); i++) {
    cout << best_sequence[i] << " ";
  }
  cout << "sum:" << best_time << endl;
}

void find_answer(vector<int> tracks, int max_length, int total_time, int &best_time, int index, vector<int> current_sequence, vector<int> &best_sequence) {
  
  if (total_time > max_length) {
    return;
  }
  if (total_time > best_time) {
    best_time = total_time;
    best_sequence = current_sequence;
  }
  
  for (int i = index; i < tracks.size(); i++) {
    current_sequence.push_back(tracks[i]);
    total_time += tracks[i];
    find_answer(tracks, max_length, total_time, best_time, i + 1, current_sequence, best_sequence);
    total_time -= tracks[i];
    current_sequence.pop_back();
      
    }
  return;
  
}

int main() 
{
    string input;
    while (getline(cin, input)) {
      stringstream ss(input);
      int max_length, number_of_tracks, track;
      vector<int> best_sequence, current_sequence, tracks;

      int best_time = 0;
      ss >> max_length >> number_of_tracks;
      while (ss >> track) {
        tracks.push_back(track);
      }
      find_answer(tracks, max_length, 0, best_time, 0, current_sequence, best_sequence);
      print_answer(best_time, best_sequence);
    }
    return 0;
}