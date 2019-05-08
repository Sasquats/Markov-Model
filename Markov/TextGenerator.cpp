// Copyright 2017 Adrien Forkum
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "MarkovModel.hpp"

int main(int argc,char* argv[]){
 int k=0,T=0;
 std::string build_str,kgram;
 if (argc < 2) {
  throw std::runtime_error("Too few arguments.");
 }
 k = atoi(argv[1]);
 T = atoi(argv[2]);
 if (T < k) {
  throw std::runtime_error("T value needs to be greater than or equal to k vlaue.");
 }
 std::cin >> kgram;
 MarkovModel mm(kgram,k);
 for (int i=0;i<k;i++) {
  kgram.push_back(build_str[i]);
 }
 std::cout << mm.gen(kgram,T) << std::endl;
}