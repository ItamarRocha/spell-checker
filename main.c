#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define MAX_LENGTH 40
#define NUM_BUCKETS 215503//Arrumar
#define NUM_ELEMENTOS 307855
#define DICTIONARY_DIR "dictionary.txt"
#define FILE_DIR "test.txt"

typedef struct node{
    char value[MAX_LENGTH];
    struct node *next;
}tNode;

typedef struct hashTable{
    int numBuckets;
    tNode** buckets;
}tHashTable;

tHashTable* newHashTable(){
    tHashTable* t = (tHashTable*) malloc(sizeof(tHashTable));
    t->numBuckets = NUM_BUCKETS;
    t->buckets = (tNode**) malloc(NUM_BUCKETS*sizeof(tNode*));
    
    for(int i = 0; i < NUM_BUCKETS; i++)
        t->buckets[i] = NULL;
    
    return t;
}

size_t h2(char * key){
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

size_t h(char * key){
    size_t hash = 0, i =0;
    
    while(key[i] != '\0'){
        hash = NUM_ELEMENTOS * hash + key[i];
        i++;
    }
    
    return hash % NUM_BUCKETS;
}

void printBucket(tHashTable* t,int bucket){
    tNode* n;
    int i = 0;
    
    n = t->buckets[bucket];
    while(n != NULL){
        printf("Elemento %d do bucket = %s\n",i+1,n->value);
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
        printf("%d elements in bucket %d\n",i,j);
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
        
    }
    
    size_t index;
    tNode* aux;
    int numberOfWordsInDictionary = 0;
    
    char string[MAX_LENGTH];
    
    while(fscanf(fp,"%s",string)!= EOF){
        index = h(string);
        numberOfWordsInDictionary++;
        aux = (tNode*) malloc(sizeof(tNode));
        strcpy(aux->value, string);
        aux->next = t->buckets[index];
        t->buckets[index] = aux;
       
        //printf("%s ---- key = %ld\n", aux->value,index);
    }
    printf("number of words = %d\n",numberOfWordsInDictionary);
    fclose(fp);
}

int check(tHashTable* t, char* directory){
    FILE *fp = fopen(directory, "r");
    
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return -1;
    }
    
    tNode* cursor;
    char string[MAX_LENGTH], found;#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define MAX_LENGTH 40
#define NUM_BUCKETS 215503//Arrumar
#define NUM_ELEMENTOS 307855
#define DICTIONARY_DIR "dictionary.txt"
#define FILE_DIR "test.txt"

typedef struct node{
    char value[MAX_LENGTH];
    struct node *next;
}tNode;

typedef struct hashTable{
    int numBuckets;
    tNode** buckets;
}tHashTable;

tHashTable* newHashTable(){
    tHashTable* t = (tHashTable*) malloc(sizeof(tHashTable));
    t->numBuckets = NUM_BUCKETS;
    t->buckets = (tNode**) malloc(NUM_BUCKETS*sizeof(tNode*));
    
    for(int i = 0; i < NUM_BUCKETS; i++)
        t->buckets[i] = NULL;
    
    return t;
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
        printf("Elemento %d do bucket = %s\n",i+1,n->value);
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
        printf("%d elements in bucket %d\n",i,j);
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
        
    }
    
    uint32_t index;
    tNode* aux;
    int numberOfWordsInDictionary = 0;
    
    char string[MAX_LENGTH];
    
    while(fscanf(fp,"%s",string)!= EOF){
        index = h(string);
        numberOfWordsInDictionary++;
        aux = (tNode*) malloc(sizeof(tNode));
        strcpy(aux->value, string);
        aux->next = t->buckets[index];
        t->buckets[index] = aux;
       
        //printf("%s ---- key = %ld\n", aux->value,index);
    }
    printf("number of words = %d\n",numberOfWordsInDictionary);
    fclose(fp);
}

int check(tHashTable* t, char* directory){
    FILE *fp = fopen(directory, "r");
    
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura\n");
        return -1;
    }
    
    tNode* cursor;
    char string[MAX_LENGTH], found;
    int errorSum = 0;
    
    while(fscanf(fp, "%s", string) != EOF){
        cursor = t->buckets[h(string)];   //Sujeito a alteracoes, de acordo com a implementacao dos buckets.
        found = 0;
        
        while(cursor != NULL){    //Ou seja, caso chegarmos ao fim do bucket, paramos.
            if(!strcmp(cursor->value, string)){
                found = 1;
                break;
            }
            cursor = cursor->next;
        }
        
        if(!found)
            errorSum++;
    }
    
    fclose(fp);
    return errorSum;
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

int main(int argc, char** argv){    
    double media;
    tHashTable* hashT = newHashTable();
    readDictionary(hashT);
    //printBucket(hashT,5);
    media = bucketScattering(hashT);
    desvio_padrao(hashT,media);
    if(argc < 2)
        printf("\nNumero de erros: %d\n", check(hashT, FILE_DIR));
    else if(argc == 2)
        printf("\nNumero de erros: %d\n", check(hashT, argv[1]));
    else{
        printf("\nMuitos parametros\n");
        printf(" ./exec [Arquivo.txt] ou somente ./exec \n");
        return 1;
    }

    return 0;
}

    int errorSum = 0;
    
    while(fscanf(fp, "%s", string) != EOF){
        cursor = t->buckets[h(string)];   //Sujeito a alteracoes, de acordo com a implementacao dos buckets.
        found = 0;
        
        while(cursor != NULL){    //Ou seja, caso chegarmos ao fim do bucket, paramos.
            if(!strcmp(cursor->value, string)){
                found = 1;
                break;
            }
            cursor = cursor->next;
        }
        
        if(!found)
            errorSum++;
    }
    
    fclose(fp);
    return errorSum;
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


int main(int argc, char** argv){    
    double media;
    tHashTable* hashT = newHashTable();
    readDictionary(hashT);
    //printBucket(hashT,5);
    media = bucketScattering(hashT);
    desvio_padrao(hashT,media);
    if(argc < 2)
        printf("\nNumero de erros: %d\n", check(hashT, FILE_DIR));
    else if(argc == 2)
        printf("\nNumero de erros: %d\n", check(hashT, argv[1]));
    else{
        printf("\nMuitos parametros\n");
        printf(" ./exec [Arquivo.txt] ou somente ./exec \n");
        return 1;
    }

    return 0;
}
