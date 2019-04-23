
#include <iostream>
#include <string>
using namespace std;

bool isNumber(char c) { return c >= '0' && c <= '9'; }

void parse(string in, string& prefix, string& postfix, int& times,
           string& inBracket) {
  int state = 0;
  int bracketCnt = 0;
  // states:
  // 0 in prefix string
  // 1 in numbers
  // 2 in first [ start inBracket cnt ++
  // 3 in bracket and not ] append to inBracket
  // 4 in ] (bracketCnt reach down to 0)and end of inBracket
  // 5 in postfix

  // state change:
  // init state 0 or 1
  // 0 -> [0,1]
  // 1 -> [1,2]
  // 2 -> 3
  // 3 -> [3,4]
  // 4 -> 5
  // 5 -> [5,end]
  prefix.clear();
  postfix.clear();

  times = 0;
  if (isNumber(in[0])) {
    state = 1;
  }
  for (int i = 0; i < in.size(); i++) {
    if (state == 0) {
      if (isNumber(in[i])) {
        times = in[i] - '0';
        state = 1;
      } else {
        prefix.push_back(in[i]);
      }
    } else if (state == 1) {
      if (isNumber(in[i])) {
        times = times * 10 + in[i] - '0';
      } else {
        state = 2;
        bracketCnt++;
      }
    }

    else if (state == 2) {
      i--;
      state = 3;
    } else if (state == 3) {
      inBracket.push_back(in[i]);
      if (in[i] == '[')
        bracketCnt++;
      else if (in[i] == ']')
        bracketCnt--;
      if (bracketCnt == 0) {
        state = 4;
        inBracket.pop_back();
      }
    } else if (state == 4) {
      i--;
      state = 5;
    } else if (state == 5) {
      postfix.push_back(in[i]);
    }
  }
}

string parseAndPrint(string input) {
  string prefix;
  string postfix;
  int times;
  string inBracket;
  parse(input, prefix, postfix, times, inBracket);
  string ans;

  ans = prefix;
  //   cout << prefix;
  string mid;
  if (times != 0) {
    mid = parseAndPrint(inBracket);
    for (int i = 0; i < times; i++) {
      // efficience ??
      ans = ans + mid;
      //   mid = parseAndPrint(inBracket);
    }
    ans = ans + parseAndPrint(postfix);
    // parseAndPrint(postfix);
  } else {
    ans = prefix;
  }

  return ans;
}

class Solution {
 public:
  string decodeString(string s) { return parseAndPrint(s); }
};