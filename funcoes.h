/*Henrique e Leon */

#ifndef __FUNCOES__
#define __FUNCOES__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>

/* Leitura das funções e armazenamento delas em um vetor. */
void ** leFuncoes(char * funcao, int k);

/* Preenche vetor das diagonais. */
void preencheDiagonais(double * sl, void ** f, int n, int k);

/* Preenche vetor dos termos independentes. */
void preencheTermos(double * termos, void ** f, int n, int k);

/* Imprime vetor das diagonais. */
void imprimeDiagonais(double * sl, int n, int k);

/* Imprime vetor dos termos independentes. */
void imprimeTermos(double * termos, int n);

/* Imprime vetor das variáveus. */
void imprimeVariaveis(double * res, int n);

#endif