/*Henrique e Leon */

#ifndef __GAUSS__
#define __GAUSS__

/* Calcula as respostas do sistema pelas diagonais e coloca as respostas em res */
void gaussSeidel(double * sl, double * termos, double * res, int n, int k, double epsilon, int maxIt);

#endif