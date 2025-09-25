#ifndef HEADERS_H
#define HEADERS_H

// Include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



// Functii
int min(int a, int b);
int max(int a, int b);
float ReLU(float x);
float ReLU_prim(float x);
float biasedWeightedSum(float *weights, float *inputs, int lungime, float bias);

#endif // HEADERS_H

// git add nume_fisier
// git commit -m "mesaj"
// git push 

// git pull