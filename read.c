#include <string.h>
#include <stdio.h>


void Tokenize(char * directory){
    FILE *fp = fopen(directory, "r");
    
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return -1;
    }
    
    while(fscanf(fp, "%s", string) != EOF){
        
        
    }
    
    fclose(fp);
}



int main () {
   char str[80] = "Essa eh a minha frase legal";
   const char s[2] = " ";
   char * token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}