#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = NULL, *vTemp, x, i = 0, j;
    printf("Digite um valor a ser incluido no vetor: ");
    while(scanf("%d", &x) != EOF) {
        i++;
        vTemp = v;
        v = (int *) realloc(v, i*sizeof(int));
        if(v == NULL) {
            printf("ERRO: Memoria insuficiente");
            free(vTemp);
            exit(1);
        }
        v[i-1] = x;
        printf("Digite o próximo valor a ser inserido: ");
    }
    printf("\n");
    for(j = 0; j < i; j++) {
        printf("v[%d]: %d\n", j+1, v[j]);
    }
    free(v);
    return 0;
}
