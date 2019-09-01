#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define MAX_LENGTH 40
#define NUM_BUCKETS 230891
#define NUM_ELEMENTOS 307855
#define DICTIONARY_DIR "txt/dictionary.txt"
#define FILE_DIR "txt/constituicaoASCII.txt"

typedef struct node{
    char value[MAX_LENGTH];
    struct node *next;
}tNode;

typedef struct hashTable{
    int numBuckets;
    tNode** buckets;
}tHashTable;

typedef struct array{
    char** data;
    size_t size,
           maxSize; 
}tArray;

tHashTable* newHashTable(){
    tHashTable* t = (tHashTable*) malloc(sizeof(tHashTable));
    t->numBuckets = NUM_BUCKETS;
    t->buckets = (tNode**) malloc(NUM_BUCKETS*sizeof(tNode*));
    
    for(int i = 0; i < NUM_BUCKETS; i++)
        t->buckets[i] = NULL;
    
    return t;
}

tArray* newArray(){
    tArray* ar = (tArray*) malloc(sizeof(tArray));
    ar->data = (char**) malloc(sizeof(char*));
    ar->size = 0;
    ar->maxSize = 1;
    
    return ar;
}

void push(tArray* ar, char* value){
    if(ar->size == ar->maxSize){
        ar->maxSize *= 2;
        
        char** new = (char**) malloc(ar->maxSize*sizeof(char*));
        
        for(size_t i = 0; i < ar->size; i++)
            new[i] = ar->data[i];
            
        free(ar->data);
        ar->data = new;
    }
    ar->data[ar->size] = (char*) malloc(strlen(value)*sizeof(char));
    strcpy(ar->data[ar->size++], value);
}

size_t h3(char * key){
    size_t hash;
    int sum = 0;
    int i = 0;
    double a =0.618033;
    
    while(key[i] != '\0'){
        sum += key[i];
        i++;
    }
    int kA = sum *a;
    hash = NUM_ELEMENTOS * (kA);
    return hash%NUM_BUCKETS;
}

size_t h1(char * key){
    size_t hash = 0, i =0;
    
    while(key[i] != '\0'){
        hash = NUM_ELEMENTOS * hash + key[i];
        i++;
    }
    
    return hash % NUM_BUCKETS;
}

uint32_t h(char * key) {
    size_t i = 0;
    uint32_t hash = 0;
    
    while (key[i] != '\0') {
        hash += key[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash % NUM_BUCKETS;
}

void printBucket(tHashTable* t,int bucket){
    tNode* n;
    int i = 0;
    
    n = t->buckets[bucket];
    while(n != NULL){
        //printf("Elemento %d do bucket = %s\n",i+1,n->value);
        n = n->next;
        i++;
    }
}

double bucketScattering(tHashTable* t){
    tNode* n;
    int j,i = 0;
    int minimo = 100, maximo = -1; 
    double media = 0;
    
    for(j = 0; j < (NUM_BUCKETS) ;j++){
        n = t->buckets[j];
        while(n != NULL){
            n = n->next;
            i++;
        }
        if(i < minimo)
            minimo = i;
        else if(i > maximo)
            maximo = i;
        media = i + media;
        //printf("%d elements in bucket %d\n",i,j);
        i = 0;
    }
    media = media/NUM_BUCKETS;
    printf("minimo = %d\nmaximo = %d\n",minimo,maximo);
    printf("media = %lf\n",media);
    return media;
} 

void readDictionary(tHashTable* t){
    FILE *fp = fopen(DICTIONARY_DIR, "r");
    
    if(fp == NULL){
        printf("Erro ao abrir o dicionario\n");
        exit(-1);
    }
    
    uint32_t index;
    tNode* aux;
    
    
    char string[MAX_LENGTH];
    
    while(fscanf(fp,"%s",string)!= EOF){
        index = h(string);
        aux = (tNode*) malloc(sizeof(tNode));
        strcpy(aux->value, string);
        aux->next = t->buckets[index];
        t->buckets[index] = aux;
       
        //printf("%s ---- key = %ld\n", aux->value,index);
    }
    
    fclose(fp);
}

int check(tHashTable* t, char* directory, tArray* errors){
    FILE *fp = fopen(directory, "r");
    
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return -1;
    }
    
    tNode* cursor;
    char *string, recebido[300], found,
         *token = " \n\r\t!\"#$%&()*+,./0123456789:;<=>?@[\\]^_`{|}~";
    int numberOfWords = 0;
    
    while(!feof(fp)){
        fgets(recebido,300,fp);
        recebido[strlen(recebido) - 1] = '\0';
        string = strtok(recebido, token);
        while(string != NULL){
            numberOfWords++;
            cursor = t->buckets[h(string)];   //Sujeito a alteracoes, de acordo com a implementacao dos buckets.
            found = 0;
            
            while(cursor != NULL){    //Ou seja, caso chegarmos ao fim do bucket, paramos.
                if(!strcmp(cursor->value, string)){
                    found = 1;
                    break;
                }
                cursor = cursor->next;
            }
            
            if(!found){
                push(errors, string);
            }
            string = strtok(NULL, token);
        }
    }   
    
    fclose(fp);
    return numberOfWords;
}

void desvio_padrao(tHashTable* t, double media){
    tNode* n;
    int j,i = 0;
    int dif, dif_pow;
    double sum = 0;
    double var,dp;
    
    for(j = 0; j < (NUM_BUCKETS) ;j++){
        n = t->buckets[j];
        while(n != NULL){
            n = n->next;
            i++;
        }
        
        dif = i-media;
        dif_pow = pow(dif,2);
        sum += dif_pow;
        i = 0;
    }
    var = sum/j;
    dp = sqrt(var);
    printf("desvio padrao = %lf\n",dp);

}

void archiveRelatory(int numberOfWords,double timeTaken, tArray* errors){
    FILE* archive;
    archive = fopen("txt/result.txt","w");
    
    if(archive == NULL){
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(-1);
    }
    
    fprintf(archive, "Numero total de palavras do texto: %d\n", numberOfWords);
    fprintf(archive, "Tempo total de verificação: %.4lf ms\n", timeTaken);
    fprintf(archive, "Numero de palavras que falharam no spell check %ld\n", errors->size);
    fprintf(archive, "Lista de palavras que falharam no spell check \n\n");
    fprintf(archive, "Num.Ocorrencia - Palavra\n--------------------------------\n");
    for(size_t i = 0; i < errors->size; i++)
        fprintf(archive, "%ld - %s\n", i+1, errors->data[i]);
    
    fclose(archive);
}

int main(int argc, char** argv){   
    tHashTable* hashT = newHashTable(); 
    tArray* errors = newArray();
    int numberOfWords;
    clock_t time;
    
    readDictionary(hashT);

    if(argc < 2){
        time = clock();
        numberOfWords = check(hashT, FILE_DIR, errors);
        time = clock() - time;
    }else if(argc == 2){
        time = clock();
        numberOfWords = check(hashT, argv[1], errors);
        time = clock() - time;
    }else{
        printf("\nMuitos parametros\n");
        printf(" ./exec [Arquivo.txt] ou somente ./exec \n");
        return 1;
    }
    
    archiveRelatory(numberOfWords, ((double)time)/CLOCKS_PER_SEC, errors);
    return 0;
}
