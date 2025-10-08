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

void initWeights(float w1[128][784], float b1[128], float w2[10][128], float b2[10]) 
{
    int i, j;

    for (i=0; i<128; ++i) 
    {
        b1[i]=0.0f;
        for (j= 0; j < 784; ++j) 
        {
            float r = (float)rand() / (float)RAND_MAX;  
            w1[i][j] = r - 0.5f; //valori intre -0.5 si 0.5
        }
    }

    for (int i = 0; i < 10; ++i) 
    {
        b2[i] = 0.0f;
        for (int j = 0; j < 128; ++j) 
        {
            float r = (float)rand() / (float)RAND_MAX;   
            w2[i][j] = r - 0.5f; //valori intre -0.5 si 0.5
        }
    }
}

void forwardPass(const float img[784], const float w1[128][784], const float b1[128], const float w2[10][128], const float b2[10], float out1[128], float out2[10], float p[10]) 
{
    
    int i, j;
    float zMax,out_pre[128];
    
    //first layer
    for(i=0; i<128; i++)
    { out_pre[i]=b1[i]; 
        for(j=0; j<784; j++)
            out_pre[i] += w1[i][j] * img[j];
    }

    for(i=0; i<128; i++)
        out1[i] = ReLU(out_pre[i]);

 //second layer
    for(i=0; i<10; i++)
    {   out2[i]=b2[i];
        for(j=0; j<128; j++)
            out2[i] += w2[i][j] * out1[j];
    }

    zMax=out2[0];  
    for(i=1; i<10; i++)
        if(out2[i]>zMax)
            zMax=out2[i];
    float sum=0.0;
    for(i=0; i<10; i++)
    {
        p[i]=expf(out2[i]-zMax); // e formula matematica softmax
        sum+=p[i];
    }
    for(i=0; i<10; i++)
        p[i]/=sum;

}  
