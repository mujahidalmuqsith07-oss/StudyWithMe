#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BARIS 4
#define KOLOM 4

int main(){
    int A[BARIS][KOLOM], B[KOLOM], C[BARIS], i, j;

    srand(time(NULL));

    for(i = 0; i < BARIS; i++){
        for(j = 0; j < KOLOM; j++){
            A[i][j] = rand() % 10;
        }
    }

    for(i = 0; i < KOLOM; i++){
        B[i] = rand() % 10;
    }

    for(i = 0; i < BARIS; i++){
        C[i] = 0;
        for(j = 0; j < KOLOM; j++){
            C[i] += A[i][j] * B[j];
        }
    }

    printf("Matriks A:\n");
    for(i = 0; i < BARIS; i++){
        for(j = 0; j < KOLOM; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(i = 0; i < KOLOM; i++){
        printf("%d\n", B[i]);
    }

    printf("\n\nHasil perkalian A * B:\n");
    for(i = 0; i < BARIS; i++){
        printf("%d\n", C[i]);
    }
    return 0;
}