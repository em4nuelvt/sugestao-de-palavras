#include "words.hpp"

void run(){
    vector<string> palavras;
    vector<string> stopwords;


    //obter as palavras que irão ser trabalhadas 
    readWords(palavras);
    /* for(int i=0;i<palavras.size();i++){
        cout<<palavras[i]<<endl;
    } */

    //obter as stopwords
    readStopWords(stopwords);
    for(int i=0;i<stopwords.size();i++){
        cout<<stopwords[i]<<endl;
    }
    
    //obter as hashes
    vector<unordered_map<string,int>> wordFrequence;
    obterHash(wordFrequence,stopwords);

    printMap(wordFrequence[5]);

}

void readWords(vector<string>& palavras){
    string aux;
    ifstream file;
    file.open("dataset/palavras.txt");
    if(file.is_open()){
        while(true){
            file>>aux;
            if(file.fail()){
                break;
            }
            trataPalavra(aux);
            palavras.push_back(aux);
        }
    }else{
        cout<<"Não foi possível ler as palavras."<<endl;
    }

}

void readStopWords(vector <string> &stopwords){
    string aux;
    ifstream file;
    file.open("dataset/stopwords.txt");
    if(file.is_open()){
        while(true){
            file>>aux;
            if(file.fail()){
                break;
            }
            stopwords.push_back(aux);
        }
    }else{
        cout<<"Não foi possível ler as palavras."<<endl;
    }
}

bool isStopword(string palavra, vector <string> stopwords){
    for(const string &word: stopwords){
        if (word==palavra){
            return true;
        }
    }
    return false;
}

void insertMap(unordered_map<string,int> &wordFrequence, string palavra){
    istringstream iss(palavra);
    string word;
    while(iss>>word){
        wordFrequence[word]++;
    }
}



void obterHash(vector<unordered_map<string, int>>& wordFrequence, vector<string>& stopwords) {
    string palavra;
    int i = 0;
    
    while (true) {
        unordered_map<string, int> auxHash; // Crie uma nova tabela hash para cada arquivo

        ifstream file("dataset/texto" + to_string(i) + ".txt");

        if (!file.is_open()) {
            cout << "parou no " << i << endl;
            break;
        }

        while (file >> palavra) {
            trataPalavra(palavra);
            if (!isStopword(palavra, stopwords)) {
                insertMap(auxHash, palavra);
            }
        }

        wordFrequence.push_back(auxHash);
        i++;

        file.close();
    }
}
