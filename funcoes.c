/*Henrique e Leon */
#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>

void ** leFuncoes(char * funcao, int k) {
    void **f = (void **)malloc(k * sizeof(void *));
    for (int i = 0; i <= k; i++) {
        scanf("%s", funcao);
        f[i] = evaluator_create(funcao);
    }
    return f;
}

void preencheDiagonais(double * sl, void ** f, int n, int k) {
    int meio = (k-1)/2;
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n - abs(meio - j); i++) {
            sl[(j*n) + i] = evaluator_evaluate_x(f[j], (double)i);
        }
    }
}

void preencheTermos(double * termos, void ** f, int n, int k) {
    for (int i = 0; i < n; i++) {
        termos[i] = evaluator_evaluate_x(f[k], i);
    }
}

void imprimeDiagonais(double * sl, int n, int k) {
    int meio = (k-1)/2;
    printf("Diagonais: \n");
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n - abs(meio - j); i++) {
            printf("%lf ", sl[(j*n) + i]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeTermos(double * termos, int n) {
    printf("Termos independentes:\n");
    for (int i=0; i < n; i++) {
        printf("%lf ", termos[i]);
    }
    printf("\n");
}