#include <stdio.h>
#include "display_array.h"

typedef struct matrix{
    int rows, cols;
    float **vals;
} matrix;

matrix make_matrix(int rows, int cols)
{
    int i;
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.vals = calloc(m.rows, sizeof(float *));
    for(i = 0; i < m.rows; ++i){
        m.vals[i] = calloc(m.cols, sizeof(float));
    }
    return m;
}

void loop_array(unsigned char* array, int nb, int h, int w, int c, int step_b, int step_h, int step_w, int step_c)
{
	matrix X = make_matrix(nb, h*w*c);
	for(size_t b = 0; b < nb ; ++b) {
        for(size_t i = 0; i < h; ++i) {
            for(size_t k= 0; k < c; ++k) {
                for(size_t j = 0; j < w; ++j) {
					//printf("Row %d, channel %d, column %d \n", i, k, j);
                    int index1 = k*w*h + i*w + j;
                    int index2 = step_b*b + step_h*i + step_w*j + step_c*k;
                    X.vals[b][index1] = array[index2]/255.;
					//printf("Row %d, channel %d, column %d, value %f \n", i, k, j, array[index2]/255.);
                }
            }
        }
    }
}

