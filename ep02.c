/*Henrique e Leon */
#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>
#include "utils.h"

#define MAX 50

int main() {
    /* Declarando variáveis */
    int n, k, maxIt;
    double epsilon;
    char funcao[MAX];

    /* Lê dimensão da matriz e diagonais */
    scanf("%d %d", &n, &k);

    /* Declara e lê vetor de funções */
    void **f = (void **)malloc(k * sizeof(void *));
    for (int i = 0; i < k; i++) {
        scanf("%s", funcao);
        f[i] = evaluator_create(funcao);
    }

    /* Lê epsilon e número máximo de iterações */
    scanf("%lf %d", &epsilon, &maxIt);

    /* Criar matriz */

    /* Resolver por Gauss-Seidel */

    /* Imprime tempo de execução */
    printf("%lf\n", timestamp());

    return 0;
}