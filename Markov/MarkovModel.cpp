// Copyright 2017 Adrien Forkum
#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include "MarkovModel.hpp"

int MarkovModel::order(){
 return _order;
}
int MarkovModel::freq(std::string kgram){
 if ((int)kgram.size() != _order) {
  throw std::runtime_error("Kgram different than order!");
 }

 for (std::map<std::string,int>::iterator itr = kgrams.begin();itr != kgrams.end();++itr) {

  if (kgram == itr->first) {
   return itr->second;
  }
 } 
 return 0;
}

int MarkovModel::freq(std::string kgram,char c){
 int counter = 0;
 std::string hold = "";
 char nChar;
 if (static_cast<int>(kgram.size()) != _order) {
  throw std::runtime_error("Kgram is different than order!");
  return 0;
 }

 for (int i = 0;i < static_cast<int>(_text.size()+1);i++) {
  for (int j = 0;j < _order;j++) {
	hold.push_back(_text[(i+j)%static_cast<int>(_text.size())]);
  }

  if (_order == 0) {
   nChar = _text[i];
  } else {
   nChar = _text[(i+static_cast<int>(hold.size()))%static_cast<int>(_text.size())];
  }
	
  if (kgram == hold && c == nChar) {
   counter++;
  }
  hold.clear();
 }
 return counter;
}

char MarkovModel::randk(std::string kgram){
 int counter = 0, random = 0;
 if ((int)kgram.size() != _order) {
  throw std::runtime_error("Kgram is wrong length");
 }
 for (int i = 0; i < static_cast<int>(alphabet.size());i++) {
  if (freq(kgram,alphabet[i]) > 0) {
   counter++;
  }
 }
 random = rand()%counter;
 return alphabet[random];
}

std::string MarkovModel::gen(std::string kgram,int T){
 std::string rStr = kgram,xfer;

 for (int i=0;i < T-_order;i++) {
  for (int j = 0;j < _order;j++) {
   xfer.push_back(rStr[i+j]);
  }
  rStr.push_back(randk(xfer));
  xfer.clear();
 }	
 return rStr;
}
std::ostream& operator<<(std::ostream& os,MarkovModel &mm){
 for (std::map<std::string,int>::iterator itr = mm.kgrams.begin();itr != mm.kgrams.end();++itr) {
  std::cout << "Kgram: " << itr->first << " frequencey: " << itr->second << std::endl;
 }
 std::cout<< "\n";
 return os;
}