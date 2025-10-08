#ifndef HEADERS_H
#define HEADERS_H

// Include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



// Functii
float min(float a, float b);
float max(float a, float b);
float ReLU(float x);
float ReLU_prim(float x);
float biasedWeightedSum(float *weights, float *inputs, int lungime, float bias);
void forwardPass(const float img[784], const float w1[128][784], const float b1[128], const float w2[10][128], const float b2[10], float out1[128], float out2[10], float p[10]);
void initWeights(float w1[128][784], float b1[128], float w2[10][128], float b2[10]);

#endif // HEADERS_H

// git add nume_fisier
// git commit -m "mesaj"
// git push 

// git pull