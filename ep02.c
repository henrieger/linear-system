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
    double tempoInicio;

    /* Lê dimensão da matriz e diagonais */
    scanf("%d %d", &n, &k);

    /* Declara e lê vetor de funções */
    void **f = leFuncoes(funcao, k);

    /* Lê epsilon e número máximo de iterações */
    scanf("%lf %d", &epsilon, &maxIt);

    /* Vetor de termos independentes */
    double * termos = calloc(n, sizeof(double));

    /* Matriz que funciona como vetor de diagonais. Cada linha é uma diagonal. */
    double * sl = calloc(k * n, sizeof(double));

    /* Calculando elementos do vetor de diagonais e do vetor dos termos independentes */
    preencheDiagonais(sl, f, n, k);
    preencheTermos(termos, f, n, k);

    /*Imprime diagonais e termos independentes */
    imprimeDiagonais(sl, n, k);
    imprimeTermos(termos, n);

    /* Resolver por Gauss-Seidel */
    tempoInicio = timestamp();

    /* Imprime tempo de execução */
    printf("\nTempo:\n%lf\n", timestamp() - tempoInicio);

    return 0;
}