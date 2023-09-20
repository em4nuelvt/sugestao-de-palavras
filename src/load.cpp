#include "load.hpp"


//lê os arquivos e inicializa a execução

void printMap(unordered_map<string, int> &wordFrequence){
    ofstream ouputFile("dataset/output.txt");

    for (const auto &pair : wordFrequence) {
        ouputFile << pair.first << ": " << pair.second << endl;
    }
}

void trataPalavra(string &palavra){
    palavra=removePunctuation(palavra);
    lowerString(palavra);    
}

void lowerString(string &palavra){
    for(string::size_type i=0;i<palavra.size();i++){
       palavra[i]=tolower(palavra[i]); 
    }
}

void lerStopwords(unordered_set <string> &stopwords){
    ifstream arquivo;
    arquivo.open("dataset/stopwords.txt");

    string palavra;

    while(!arquivo.fail()){
        arquivo>>palavra;
        lowerString(palavra);
        stopwords.insert(palavra);
    }

}



string removePunctuation(string word) {
    
    string cleanedWord;
    size_t pos = 0;
     //substituir esses caracteres esquisitos
    while ((pos = word.find_first_of("”—", pos))!= std::string::npos) {
        word.replace(pos, 3, " "); // Substitui por espaço
        pos += 1; // Avança para evitar substituições em loop
    }
    for (size_t i = 0; i < word.length(); i++) {
        char c = word[i];
        if( ((c=='.'||c==','||c=='!'||c=='?'||c==':'||c==';')&& isalnum(word[i+1]))||
            (c=='-'&&i==(word.length()-1))){
            word[i]=' ';
        }
        c=word[i];
        if(word[i]=='-'&&word[i+1]=='-'){
            word[i]=' ';
            word[i+1]=' ';
        }
        c = word[i];
        if (!ispunct(c) || ((c == '-')) || c == '/' || c == '_') {
            cleanedWord += c;
        }
        
    }
    return cleanedWord;
}

void readMultiple(){
    ifstream file;
    string palavra;
    int aux =0;
    file.open("dataset/input"+ to_string(aux)+".txt");
    do{
        aux++;
        while(true){
            file>>palavra;
            if(file.fail())
                break;
            cout<<palavra<<" ";
        }
        file.close();
        file.open("dataset/input"+ to_string(aux)+".txt");
    }while(file);

}