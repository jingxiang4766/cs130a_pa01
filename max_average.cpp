#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "heap.h"
using namespace std;

int main(){
  // string str;
  // getline(cin, str);
  // cout << str << endl;
  // cout << str.find(" ") << endl;
  // cout << str.find(" ") << endl;
  // if(str ==  "") cout << "success" << endl;
  int k, pos, score;
  string str, sstr;
  bool first(true), isFind(false);
  vector<string> s;
  vector<heap> vh;
  getline(cin, str);
  k = stoi(str);

  while(1){
    getline(cin, str);
    if(!first && str == "") break;
    if(first && str == "") {first = false; continue;}
    if(str != "") first = true;

    pos = str.find(" ");
    sstr = str.substr(0, pos);
    score = stoi(str.substr(pos+1));

    for(int i = 0; i < s.size(); i++){
      if (s[i] == sstr){
        isFind = true;
        vh[i].add(score);
      }
    }
    if(!isFind){
      s.push_back(sstr);
      heap h;
      vh.push_back(h);
      vh[vh.size()-1].add(score);
    }
    isFind = false;
  }

  vector<double> ave;
  for(int j = 0; j < vh.size(); j++){
    vh[j].build_heap();
    int sum = 0;
    int size = vh[j].getsize();
    if(size < k) {
      ave.push_back(-1);
      continue;
    }
    for(int z = 0; z < k; z++){
      sum += vh[j].delete_max();
    }
    ave.push_back(sum/k);
  }

  double max = ave[0];
  int maxindex = 0;
  for(int h = 0; h < ave.size(); h++){
    if(h == 0) continue;
    if(ave[h] > max){
      max = ave[h];
      maxindex = h;
    }
  }

  cout << s[maxindex] << endl;
  return 0;
}
