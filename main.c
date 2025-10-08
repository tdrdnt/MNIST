#include <stdlib.h>
#include <stdio.h>
#include "headers.h"


int main() 
{
    float w1[128][784], b1[128], w2[10][128], b2[10];
    float out1[128], out2[10], p[10];
    float img[784];
    int i,j;

    // Initialize weights and biases
    initWeights(w1, b1, w2, b2);

    // Forward pass
    forwardPass(img, w1, b1, w2, b2, out1, out2, p);

    for (i=0; i<10; i++) 
        for (j=0; j<128; j++) 
    printf("%f ", w2[i][j]);
        

    return 0;
}

  