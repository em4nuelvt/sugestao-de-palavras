#ifndef LOAD_HPP
#define LOAD_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include "heap.hpp"
#define K 20

using namespace std;

void lerStopwords(unordered_set <string> &stopwords);
void readMultiple();
void loadInputs();
string removePunctuation(string word);
void lowerString(string &palavra);
void trataPalavra(string &palavra);
void printMap(unordered_map<string, int> &wordFrequence);


#endif