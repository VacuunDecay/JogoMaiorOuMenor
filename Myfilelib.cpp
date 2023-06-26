#include "Myfilelib.h"
#include "MyUtil.h"


int nomeToId(FILE* fp, char* nome){
    if(!fp || !nome) return -3; // pointer to NULL
 
    Jog aux;

    fread(&aux, sizeof(Jog), 1, fp);

    while(fread(&aux, sizeof(Jog), 1, fp)){
        if(strcmp(aux.nome, nome) == 0){
            return aux.id;
        }
    }

    return -1; // not found
}

int isIdUnique(FILE *fp, int id){
    if (!fp) {
        printf("Error: File pointer is NULL.\n");
        return 0;
    }

    Jog aux;

    fread(&aux, sizeof(Jog), 1, fp);

    while(fread(&aux, sizeof(Jog), 1, fp)){
        if(aux.id == id){
            return 0; //nao
        }
    }

    return 1; // sim

}

void loadJog(FILE *fp, int id, char* nome){
    if (!fp) {
        printf("Error: File pointer is NULL.\n");
        return;
    }

    Jog aux;
    aux.id = id;
    aux.nome = nome;
    aux.balance = 0;
    aux.maxPoint = 0;

    fwrite(&aux, sizeof(Jog), 1, fp);
}