#include "words.hpp"

void run(){
    
    


    //obter as palavras que irão ser trabalhadas 
    vector<string> palavras;
    readWords(palavras);

    //obter as stopwords
    vector<string> stopwords;
    readStopWords(stopwords);

    
    //obter as hashes
    vector<unordered_map<string,int>> wordFrequence;
    obterHash(wordFrequence,stopwords);


    //para cada palavra, fazendo a análise da palavra para cada texto: heap, arvóre binária e huffman.
    workWithEachWord(wordFrequence,palavras);

}

void workWithEachWord(vector<unordered_map<string,int>> &wordFrequence,vector<string> &palavras ){
    //para cada palavra, fazendo a análise da palavra para cada texto: heap, arvóre binária e huffman.

    //abrir arquivo de escrita
    ofstream print;
    print.open("dataset/output.txt");
    if(!print.is_open()){
        print<<"falha na abertura do arquivo de escrita"<<endl;
        return;
    }
    for(int i=0;i<palavras.size();i++){
        print<<"PALAVRA "<<i<<": "<<palavras[i]<<endl;
        for(int j=0;j<wordFrequence.size();j++){
            print<<endl<<"Texto "<<j<<"("<<palavras[i]<<")"<<endl;
            if(wordFrequence[j][palavras[i]]==0){
                print<<"Palavra: " <<palavras[i]<<" não está presente no texto "<<j<<endl;
            }else{
                //garantindo que e palavra analisada nao vai aparecer entre as k mais frequentes
                int tmp = wordFrequence[j][palavras[i]];
                wordFrequence[j][palavras[i]]=0;
                
                //criando heap para essa palavra, analisando nesse texto
                Heap* heap = createHeap(K);
                for (const auto& entry : wordFrequence[j]) {
                    insert(heap, entry.first.c_str(), entry.second);
                }

                //criando a árvore binária
                treeNode* raizBT=NULL;
                for(int i=1;i<=K;i++){
                    raizBT=inserir(raizBT,heap->heap[i].word,heap->heap[i].frequency); //inserindo cada elemento
                }
                //imprimindo a árvore binária
                print<<endl<<"ÁRVORE BINÁRIA(inorder): "<<endl;
                imprimir(raizBT,print);

                //criando a árvore AVL
                No* raizAVL=NULL;
                for(int i=1;i<=K;i++){
                    raizAVL=inserirAVL(raizAVL,heap->heap[i].word,heap->heap[i].frequency); //inserindo cada elemento
                }
                //imprimindo a árvore AVL
                print<<endl<<"ÁRVORE AVL(inorder): "<<endl;
                imprimeEmOrdem(raizAVL,print);
                
                // Criar a árvore de Huffman
                HuffmanNode* huffmanTree = buildHuffmanTree(heap);

                // Imprimir a árvore de Huffman
                print << endl << "ÁRVORE DE HUFFMAN:" << endl;
                printHuffmanTree(huffmanTree, print);

                // Destruir a árvore de Huffman após o uso
                destroyHuffmanTree(huffmanTree);


                //printHeapUnsorted(heap, print);

                //volta o valor da palavra na hash
                wordFrequence[j][palavras[i]]=tmp;
            }
        }
        print<<"---------------------------------------------------------------------------------";
        print<<endl<<endl;
    }


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

void printMap(unordered_map<string, int> &wordFrequence){
    ofstream ouputFile("dataset/HashOutput.txt");

    for (const auto &pair : wordFrequence) {
        ouputFile << pair.first << ": " << pair.second << endl;
    }
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

        ifstream file("dataset/input" + to_string(i) + ".txt");

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

