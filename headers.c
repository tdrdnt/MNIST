#include "headers.h"

float min(float a, float b)
{
    return (a < b) ? a : b;
}

float max(float a, float b)
{
    return (a > b) ? a : b;
}

float ReLU(float x)
{
    return max(0, x);
}

float ReLU_prim(float x)
{
    if (x > 0)
        return 1;
    else
        return 0;
}

float biasedWeightedSum(float *weights, float *inputs, int lungime, float bias)
{
    float sum = 0.0;
    for (int i = 0; i < lungime; i++)
    {
        sum += weights[i] * inputs[i];
    }
    sum += bias;
    return sum;
}

// functie pentru produsul a doua matrice
// merge si pt vectori daca pun lX/ cX = 1
// ramane poate de optimizat !!
float **produsMatrice(float **A, int lA, int cA, float **B, int lB, int cB)
{
    if (cA != lB)
    {
        printf("dimensiuni incorecte\n");
        return NULL;
    }

    float **C = (float **)malloc(lA * sizeof(float *));
    for (int i = 0; i < lA; i++)
    {
        C[i] = (float *)malloc(cB * sizeof(float));
    }

    for (int i = 0; i < lA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < cA; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}