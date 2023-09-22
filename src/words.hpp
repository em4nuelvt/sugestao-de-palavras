#ifndef WORDS_HPP
#define WORDS_HPP

#include "tratamento.hpp"
#include "binaryTree.hpp"
#include "avl.hpp"
#include "huffman.hpp"
using namespace std;


void run();
void readWords(vector<string> & palavras);
void obterHash(vector<unordered_map<string,int>> &wordFrequence,vector<string> &stopwords);
void readStopWords(vector <string> &stopwords);
bool isStopword(string palavra, vector <string> stopwords);
void insertMap(unordered_map<string,int> &wordFrequence, string palavra);
void workWithEachWord(vector<unordered_map<string,int>> &wordFrequence,vector<string> &palavras );
void printMap(unordered_map<string, int> &wordFrequence);
#endif