#include <stdio.h>
#include <stdlib.h>

int main () {
    int **v = NULL, **vTemp; //ponteiros usados para alocar 
    int line, col; //dimensoes da matriz
    int i, j, x; //variaveis auxiliares
    printf("Digite as dimensoes da matriz[x][y]: ");
    scanf("%d %d", &col, &line);
    vTemp = v;
    v = (int **) realloc(v, line*sizeof(int *)); //alocando as linhas da matriz
    if(v == NULL) {
        printf("ERRO: Memoria insuficiente\n");
        free(vTemp);
        exit(1);
    }
    for(i = 0; i < line; i++) {
        vTemp = v;
        vTemp[i] = v[i];
        v[i] = (int *) realloc(v[i], col*sizeof(int)); //alocando as colunas da matriz
        if(v[i] == NULL) {
            printf("ERRO: Memoria insuficiente\n");
            free(vTemp[i]);
            exit(1);
        }
        for(j = 0; j < col; j++) {
            printf("Digite o valor da matriz[%d][%d]: ", i+1, j+1);
            scanf("%d", &x);
            v[i][j] = x;
        }
    }
    printf("\n");
    for(i = 0; i < line; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
        free(v[i]);
    }
    free(v);
    return 0;
}
