#include <string.h>
#include <stdio.h>


int Tokenize(char * directory){
    FILE *fp = fopen(directory, "r");
    FILE *fo = fopen("plano13_Tok.txt", "w+");
    
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return -1;
    }
    if(fo == NULL){
        printf("Erro ao abrir o arquivo para escrita\n");
        return -1;
    }
    
    char string[101];
    char * tok = " \t\r!\"#$%&()*+,./0123456789:;<=>?@[\\]^_`{|}~\n";

    char * token;

    while(fscanf(fp, "%s", string) != EOF){
        
        token = strtok(string , tok);

        while(token != NULL){
            fprintf(fo,"%s\n",token);

            token = strtok(NULL, tok);
        }

    }
    
    fclose(fp);
    fclose(fo);

    return 0;
}



int main () {
   
   Tokenize("plano17.txt");
   
   return(0);
}