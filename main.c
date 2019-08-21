#include <stdio.h>
#include <string.h>

#define MAX_LENGHT 40
#define NUM_BUCKETS 100 //Arrumar
#define DICTIONARY_DIR "*.txt"

typedef struct node{
    char value[MAX_LENGHT];
    struct node *next;
}tNode;

typedef struct TableElements{
    int lengthOfElements;
    tNode* node;
}tTableElements;

typedef struct HashTable{
    int NumBuckets;
    tTableElements* buckets;
}tHashTable;

tHashTable* newHashTable(){
    int i;
    tHashTable* t1 = (tHashTable*) malloc(sizeof(tHashTable));
    t1->NumBuckets = NUM_BUCKETS;
    for(i = 0; i < NUM_BUCKETS; i++)
        t1->buckets[i] = NULL;
    return t1;
}


tNode *buckets[NUM_BUCKETS];

unsigned int h(char* key){
    //Funcao hash
}

void readDictionary(){

}

int check(char** argv, tHashTable* t1){
    FILE *fp = fopen(argv[1], "r");
    tNode* cursor;
    char *string, found;
    int errorSum = 0;
    
    while(fscanf(fp, "%s", string) != EOF){
        cursor = buckets[h(string)];   //Sujeito a alteracoes, de acordo com a implementacao dos buckets.
        found = 0;
        
        while(cursor != NULL){    //Ou seja, caso chegarmos ao fim do bucket, paramos.
            if(!strcmp(cursor->data, string)){
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

int main(int argc, char** argv){
    if (argc < 2) {
        printf("\nFaltando parametros\n");
        printf(" ./exec [Arquivo.txt] \n");
        return 1;
    }

    if (argc > 2) {
        printf("\nMuitos parametros\n");
        printf(" ./exec [Arquivo.txt] \n");
        return 1;
    }
    
    return 0;
}
