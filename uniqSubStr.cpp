#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return -1;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int abc[26*2] = {0};
    vector<string> subStr;
    string seq;
    for(int i=0; i<s.size(); i++) {
      for(int j=i; j<s.size(); j++) {
                
	int in = letterIndex(s[j]);
	if(abc[in] == 0) {
	  // keep adding to seq for unique characters
	  seq.push_back(s[j]);
	  abc[in] = 1;
	} else {
	  // no longer unique
	  subStr.push_back(seq);
	  seq = "";
	  fill(abc, abc+26, 0);
	  break;
	}
      }
    }

    // print substrings
    for(int i=0; i<subStr.size(); i++)
      cout << subStr[i] << " ";
    cout << endl;

    return subStr[longestStrIndex(subStr)].size();
  }
    
  int letterIndex(char c) {
    int lowChar = c - 97; //a
    int upperChar = c - 65; //A
    if(lowChar >= 0) return lowChar;
    return upperChar+26;
  }

  int longestStrIndex(vector<string> s) {
    int maxIndex = 0;
    for(int i=1; i<s.size(); i++)
      if(s[i-1].size() < s[i].size())
	maxIndex = i;
    return maxIndex;
  }
};


int main() {
  Solution sol;
  string s = "abbccffFe";
  cout << "Longest substring is " << sol.lengthOfLongestSubstring(s) << endl;
  return 0;
}
