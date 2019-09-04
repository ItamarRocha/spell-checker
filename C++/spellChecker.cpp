#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <unordered_set>

#include <cstring>
#include <cstdio>

#define DICTIONARY_DIR "../txt/dictionary.txt"
#define FILE_DIR "../txt/constituicaoASCII.txt"
#define RESULTS_DIR "../txt/results_C++.txt"

std::unordered_set<std::string> hashTable;

void readDictionary(){
    std::ifstream data;
    data.open(DICTIONARY_DIR, std::ios::in);
    
    std::string aux;
    
    if(data.is_open())
        while(data >> aux)
            hashTable.insert(aux);
        
    data.close();
}

int check(char* directory, std::vector<std::string>& errors){
    FILE *fp = fopen(directory, "r");
    
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return -1;
    }
    
    char *string, recebido[500],
         *token = " \n\r\t!\"#$%&()*+,./0123456789:;<=>?@[\\]^_`{|}~";
    int numberOfWords = 0;
    
    while(!feof(fp)){
        fgets(recebido,500,fp);
        recebido[strlen(recebido) - 1] = '\0';
        string = strtok(recebido, token);
        while(string != NULL){
            numberOfWords++;
            
            if(hashTable.find(string) == hashTable.end())
                errors.push_back(string);
            
            string = strtok(NULL, token);
        }
    }   
    
    fclose(fp);
    return numberOfWords;
}

int main(int argc, char** argv){
    int numberOfWords;
    std::vector<std::string> errors;
    std::chrono::high_resolution_clock::time_point t1, t2;

    readDictionary();

    if(argc < 2){
        t1 = std::chrono::high_resolution_clock::now();
        numberOfWords = check(FILE_DIR, errors);
        t2 = std::chrono::high_resolution_clock::now();
    }else if(argc == 2){
        t1 = std::chrono::high_resolution_clock::now();
        numberOfWords = check(argv[1], errors);
        t2 = std::chrono::high_resolution_clock::now();
    }else{
        printf("\nMuitos parametros\n");
        printf(" ./exec [Arquivo.txt] ou somente ./exec \n");
        return 1;
    }

    std::ofstream archive;
    archive.open(RESULTS_DIR, std::ios::out);
    
        
    archive << "Numero total de palavras do texto: " << numberOfWords << "\n"
            << "Tempo total de verificação: " << std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() << " ms\n"
            << "Numero de palavras que falharam no spell check " << errors.size() << "\n"
            << "Lista de palavras que falharam no spell check \n\n"
            << "Num.Ocorrencia - Palavra\n--------------------------------\n";

    for(size_t i = 0; i < errors.size(); i++)
        archive << errors[i] << "\n";
    
    archive.close();

    std::cout << "Number of errors: " << errors.size() << "\n"
              << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() << "ms\n";

    return 0;
}
