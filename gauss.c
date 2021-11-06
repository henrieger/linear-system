#include "gauss.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* Calcula a maior diferença entre as variáveis em módulo */
double maiorAbs(double * res, double * tempRes, int n)
{
    double maior = 0;
    double dif = 0;
    for (int i = 0; i < n; i++)
    {
        dif = fabs(res[i] - tempRes[i]);
        maior = maior > dif ? maior : dif;
    }
    
    return maior;
}

/* Copia n doubles do vetor origem no vetor destino */
void copiaVetor(double *destino, double * origem, int tam)
{
    for (int i = 0; i < tam; i++)
        destino[i] = origem[i];   
}

/* Calcula as respostas do sistema pelas diagonais e coloca as respostas em res */
void gaussSeidel(double * sl, double * termos, double * res, int n, int k, double epsilon, int maxIt) {
    /* Valor atualizado das variáveis */
    double * tempRes = malloc(n * sizeof(double));
    int meio = k >> 1;

    int iter = 0;
    do {
        copiaVetor(tempRes, res, n);

        for (int i = 0; i < n; i++)
        {
            double coeficiente = sl[meio*n+i];

            tempRes[i] = termos[i] / coeficiente;
            for (int j = 0; j < k; j++)
            {
                int diagonalParaSL = i - j + meio;
                if(diagonalParaSL >= 0 && diagonalParaSL != i)
                {
                    if(j < meio)
                        tempRes[i] -= sl[n*j + i] * tempRes[diagonalParaSL] / coeficiente;
                    else
                        tempRes[i] -= sl[n*j + diagonalParaSL] * tempRes[diagonalParaSL] / coeficiente;
                }
                
            }
        }

        void *temp = res;
        res = tempRes;
        tempRes = temp;

        iter++;
    } while (iter < maxIt && maiorAbs(res, tempRes, n) > epsilon);

    free(tempRes);
}