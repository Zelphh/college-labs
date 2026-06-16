#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"
#include "rb.h"
#include "btree.h"

#define MAX_N 10000
#define STEP 500
#define SAMPLES 10

void shuffle(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    srand(42);
    
    printf("N,AVL_Add,AVL_Rem,RB_Add,RB_Rem,B1_Add,B1_Rem,B5_Add,B5_Rem,B10_Add,B10_Rem\n");

    for (int n = 1; n <= MAX_N; n = (n < STEP ? STEP : n + STEP)) {
        double avl_add_avg = 0, avl_rem_avg = 0;
        double rb_add_avg = 0, rb_rem_avg = 0;
        double b1_add_avg = 0, b1_rem_avg = 0;
        double b5_add_avg = 0, b5_rem_avg = 0;
        double b10_add_avg = 0, b10_rem_avg = 0;

        for (int s = 0; s < SAMPLES; s++) {
            int *keys = malloc(n * sizeof(int));
            for (int i = 0; i < n; i++) keys[i] = i;
            shuffle(keys, n);

            AVLNode* avl_root = NULL;
            avl_ops = 0;
            for (int i = 0; i < n; i++) avl_root = avl_insert(avl_root, keys[i]);
            avl_add_avg += (double)avl_ops / n;
            shuffle(keys, n);
            avl_ops = 0;
            for (int i = 0; i < n; i++) avl_root = avl_delete(avl_root, keys[i]);
            avl_rem_avg += (double)avl_ops / n;
            avl_free(avl_root);

            RBNode* rb_root = NULL;
            rb_ops = 0;
            for (int i = 0; i < n; i++) rb_root = rb_insert(rb_root, keys[i]);
            rb_add_avg += (double)rb_ops / n;
            shuffle(keys, n);
            rb_ops = 0;
            for (int i = 0; i < n; i++) rb_root = rb_delete(rb_root, keys[i]);
            rb_rem_avg += (double)rb_ops / n;
            rb_free(rb_root);

            int t_vals[] = {2, 5, 10};
            double *b_add_avgs[] = {&b1_add_avg, &b5_add_avg, &b10_add_avg};
            double *b_rem_avgs[] = {&b1_rem_avg, &b5_rem_avg, &b10_rem_avg};

            for(int j=0; j<3; j++) {
                int t = t_vals[j];
                BTreeNode* b_root = NULL;
                btree_ops = 0;
                shuffle(keys, n);
                for (int i = 0; i < n; i++) b_root = btree_insert(b_root, keys[i], t);
                *b_add_avgs[j] += (double)btree_ops / n;
                
                shuffle(keys, n);
                btree_ops = 0;
                for (int i = 0; i < n; i++) b_root = btree_delete(b_root, keys[i], t);
                *b_rem_avgs[j] += (double)btree_ops / n;
                btree_free(b_root);
            }
            free(keys);
        }

        fprintf(stderr, "Done N=%d\n", n);
        printf("%d,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n", 
               n, avl_add_avg/SAMPLES, avl_rem_avg/SAMPLES, 
               rb_add_avg/SAMPLES, rb_rem_avg/SAMPLES,
               b1_add_avg/SAMPLES, b1_rem_avg/SAMPLES,
               b5_add_avg/SAMPLES, b5_rem_avg/SAMPLES,
               b10_add_avg/SAMPLES, b10_rem_avg/SAMPLES);
    }
    return 0;
}
