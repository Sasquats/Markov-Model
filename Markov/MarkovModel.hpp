// Copyright 2017 Adrien Forkum
#ifndef MARKOVMODEL_HPP
#define MARKOVMODEL_HPP
#include <string>
#include <map>
#include <iostream>
class MarkovModel{
 private:
 int _order;
 std::map <std::string, int> kgrams;
 std::string alphabet,_text;
 
 public:
 MarkovModel(std::string text, int k){
  std::string hold;
  int trig = 0;
  _order = k;
  _text = text;
  // Parsing for alphabet.
  alphabet.push_back(text[0]);
 for(int i = 0;i < static_cast<int>(text.size());i++) {
  for(int j = 0;j < static_cast<int>(alphabet.size());j++) {
   if (text[i] == alphabet[j]) {
    trig = 1;
   }
   if (j == static_cast<int>(alphabet.size()-1) && trig == 0) {
    if (text[i] != alphabet[j]) {
     alphabet.push_back(text[i]);
    }
   }
  }
 trig = 0;
 }

//Getting kgrams.
 for(int i = 0;i < static_cast<int>(_text.size()+_order);i++) {
  for (int j = 0;j < k;j++) {
   hold.push_back(text[(i+j)%static_cast<int>(text.size())]);
  }
  std::cout << hold << " ";

  if (kgrams.size() == 0) {
  kgrams[hold] = 1;
  } else {
   for (std::map<std::string,int>::iterator itr = kgrams.begin();itr != kgrams.end();itr++) {
    std::map<std::string,int>::iterator hitr = itr;
    hitr++;
    if (itr->first == hold) {
	 itr->second++;
	 trig = 1;
    } else if (hitr == kgrams.end() && trig == 0) {
	 kgrams[hold] = 1;
    }
   }
   trig = 0;
  }
   hold.clear();
  }
 }
~MarkovModel(){}
friend std::ostream& operator<<(std::ostream& os,MarkovModel& mm);
int order();
int freq(std::string kgram);
int freq(std::string kgram,char c);
char randk(std::string kgram);
std::string gen(std::string kgram,int T);
};
#endif