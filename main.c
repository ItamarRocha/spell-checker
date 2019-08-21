#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHT 40
#define NUM_BUCKETS 100 //Arrumar
#define DICTIONARY_DIR "*.txt"

typedef struct node{
    char *value;
    struct node *next;
}tNode;

typedef struct buckets{
    tNode* node;
}tBuckets;

typedef struct HashTable{
    int NumBuckets;
    tBuckets* buckets;
}tHashTable;

tHashTable* newHashTable(){
    int i;
    char* string;
   
    tHashTable* t1 = (tHashTable*) malloc(sizeof(tHashTable));
    t1->NumBuckets = NUM_BUCKETS;
    t1->buckets = (tBuckets *) malloc(sizeof(tBuckets));
    
    for(i = 0; i < NUM_BUCKETS; i++){
        t1->buckets[i].node = (tNode*) malloc(sizeof(tNode));
        t1->buckets[i].node->next = NULL;
    }
        
    return t1;
}

size_t h(char* key){
    size_t result = 0;
    int i = 0;
    
    for(i = 0 ; key[i] != '\0'; i++){
        result += key[i]*(i + 1);
    }
    
    return result%100;
}

void readDictionary(){
    //Implementa JP
}

//int check(char** argv, tHashTable* t1){
//    FILE *fp = fopen(argv[1], "r");
//    tNode* cursor;
//    char *string, found;
//    int errorSum = 0;
//    
//    while(fscanf(fp, "%s", string) != EOF){
//        cursor = t1->buckets[h(string)].node;   //Sujeito a alteracoes, de acordo com a implementacao dos buckets.
//        found = 0;
//        
//        while(cursor != NULL){    //Ou seja, caso chegarmos ao fim do bucket, paramos.
//            if(!strcmp(cursor->value, string)){
//                found = 1;
//                break;
//            }
//            cursor = cursor->next;
//        }
//        
//        if(!found)
//            errorSum++;
//    }
//    
//    fclose(fp);
//    return errorSum;
//}

//int main(int argc, char** argv){
//    if (argc < 2) {
//        printf("\nFaltando parametros\n");
//        printf(" ./exec [Arquivo.txt] \n");
//        return 1;
//    }
//
//    if (argc > 2) {
//        printf("\nMuitos parametros\n");
//        printf(" ./exec [Arquivo.txt] \n");
//        return 1;
//    }
int main(){
    tHashTable* t1 = newHashTable();

    //scanf("%s",t1->buckets[10].node->value);

    return 0;
}
