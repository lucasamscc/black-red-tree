#include "rubronegra.c"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int findValueInArray(int array[], int size, int value) {
    for(int i=0; i<size; i++) {
        if (array[i]==value) {
            return 1; // found
        }
    }

    return 0; // not found
}

void popula(int vetor[], int tamanho){
    int numero;
    int i = 0;
    while(i!=tamanho) {
        numero = rand() % 5000;
        if (findValueInArray(vetor, tamanho, numero)==0) {
            vetor[i]=numero;
            i++;
        } 
    }
}

int main() {

    int v[1000];
    srand(time(NULL));

    FILE *arquivomedio;
    FILE *arquivopior;

    arquivomedio = fopen("casomedio.csv", "w");
    if (arquivomedio == NULL) {
        printf("Erro ao abrir arquivo Caso Medio\n");
        return 1;
    }

    arquivopior = fopen("piorcaso.csv", "w");
    if (arquivopior == NULL) {
        printf("Erro ao abrir arquivo PiorCaso\n");
        return 1;
    }

    fprintf(arquivomedio, "%s", "n;RN;\n");
    fprintf(arquivopior, "%s", "n;RN;\n");

    // Criação Loop 1000 registros
    for (int j = 1; j < 1000; j++) {
        long int media_rn = 0;
        printf("Execucao: %d\n", j);
        // Arvore a com Caso Medio
        for (int numero = 0; numero < 10; numero++) {
            int v[j];
            popula(v, j);

            Arvore* a = criar();

            for (int i = 0; i < j; i++) {
                RNcontador = 0;

                adicionar(a, v[i]);
                media_rn += RNcontador;
            }
            free(a);
        }

        fprintf(arquivomedio, "%d;%ld;", j, media_rn / 10);
        fprintf(arquivomedio, "\n");

        // Arvore com Pior Caso
        Arvore* rnPior = criar();
        long int contadorRN = 0;
        for (int i = 1; i <= j; i++) {
            RNcontador = 0;
            adicionar(rnPior, i);
            contadorRN += RNcontador;
        }
        free(rnPior);

        fprintf(arquivopior, "%d;%ld;", j, contadorRN);
        fprintf(arquivopior, "\n");
    }

    fclose(arquivomedio);
    fclose(arquivopior);
    printf("FIM");

    return 0;
}