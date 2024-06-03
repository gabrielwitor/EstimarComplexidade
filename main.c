#include <stdio.h>
#include "listas.h"
#include <time.h>

int main(){
    FILE* f = fopen("resultados.txt","w+");

    for(int tamanho = 5000; tamanho <= 50000; tamanho += 5000){
        for (int repeticoes = 0; repeticoes < 30; repeticoes++){
            Lista* lst = cria_lista();
            for (int i = 0; i < tamanho; ++i) {
                lst = cria_noLista(lst, i);
            }

            clock_t start_t = clock();
            Lista* ordenada = insere_ordenado(lst);
            clock_t end_t = clock();

            double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            fprintf(f,"%f ",tamanho,repeticoes, total_t);
            printf("TAMANHO[%d] REP[%d] Total time taken by CPU: %f\n",tamanho,repeticoes, total_t);
            lst = libera_lista(lst);
        }
        fprintf(f,"\n");
    }
    fclose(f);
    return 0;
}