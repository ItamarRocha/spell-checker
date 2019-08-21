#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    char str[50], bStr[50];
    int bIndex = 1;
    
    if (argc < 2) {
        printf("\nFaltando parametros\n");
        printf(" ./exec [Dicionario] \n");
        return 1;
    }

    if (argc > 2) {
        printf("\nMuitos parametros\n");
        printf(" ./exec [Dicionario] \n");
        return 1;
    }
    
    char *file;
    file = argv[1];

    FILE *fp = fopen(file, "r");
    
    if(fp != NULL){
        for(int i = 1; !feof(fp); i++){
            fgets(str, 50, fp);
            str[strlen(str)-1] = '\0';
            
            if(i==1)
                strcpy(bStr, str);
            
            if(strlen(str) > strlen(bStr)){
                bIndex = i;
                strcpy(bStr, str);
            }
        } 
        
        fclose(fp);
        
        printf("Biggest: %s\nSize: %ld\nIndex : %d\n", bStr, strlen(bStr), bIndex);

    }else{
        printf("Erro ao abrir  o arquivo para leitura\n");
        return -1;
    }
    
    return 0;
}
