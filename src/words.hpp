#ifndef WORDS_HPP
#define WORDS_HPP
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <string>
#include "load.hpp"
#include "heap.hpp"
using namespace std;

void run();
void readWords(vector<string> & palavras);
void obterHash(vector<unordered_map<string,int>> &wordFrequence,vector<string> &stopwords);
void readStopWords(vector <string> &stopwords);
bool isStopword(string palavra, vector <string> stopwords);
void insertMap(unordered_map<string,int> &wordFrequence, string palavra);


#endif