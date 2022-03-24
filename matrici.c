#include <stdio.h>
#define N 6

int main () {
   int vettore1[N], vettore2[N];
int i, j, k, p;

int mat[3][4] = { {1, 2, 3, 4}, {10, 20, 30, 40}, {100, 200, 300, 400} };
int matt[][4] = { {1, 2, 3}, {10, 20, 30}, {100, 200, 300, 400} };
int mattt[3][4] = { 1, 2, 3, 4, 10, 20, 30, 40, 100, 200, 300, 400 };

int mat2[2][2][2] = { { {10,20}, {30,40} }, { {100,200}, {300,400} }};
int mat3[2][2][2][2] = { { { {10,20}, {30,40} }, { {100,200}, {300,400} }}, { { {10,20}, {30,40} }, { {100,200}, {300,400} }}};
int mat4[2][2][2][2][2];
int mat5[2][2][2][2][2][2];

  for (i=0; i<3; i++) 
      for (j=0; j<4; j++) 
          printf("elemento  mat[%d][%d]: %d\n", i, j, mat[i][j]);

  printf("\n e adesso una stampa migliore ...\n\n");

      putchar('\n');
      putchar('\n');
  for (i=0; i<3; i++) {              /* per ogni riga i-esima */       
                                     /* stampa la riga i-esima  ... */
      for (j=0; j<4; j++) 
          printf(" mat[%d][%d]: %3d ", i, j, mat[i][j]);
                                      /* ... e poi va a capo */
      putchar('\n');
  }

      putchar('\n');
      putchar('\n');
  for (i=0; i<3; i++) {              /* per ogni riga i-esima */       
                                     /* stampa la riga i-esima  ... */
      for (j=0; j<4; j++) 
          printf(" matt[%d][%d]: %3d ", i, j, matt[i][j]);
                                      /* ... e poi va a capo */
      putchar('\n');
  }

      putchar('\n');
      putchar('\n');
  for (i=0; i<3; i++) {              /* per ogni riga i-esima */       
                                     /* stampa la riga i-esima  ... */
      for (j=0; j<4; j++) 
          printf(" mattt[%d][%d]: %3d ", i, j, mattt[i][j]);
                                      /* ... e poi va a capo */
      putchar('\n');
  }



printf("\n\nprima di finire\nnel codice c'e' qualche spunto per sperimentare l'uso delle altre ");
printf("matrici definite in questo programma;\nSperimentate:\n"); 
printf("- l'inizializzazione, \n- l'assegnazione di elementi, \n- l'accesso ad elementi \ndi array ");
printf("multidimensionali (tre dimensioni, quattro, cinque ... vedi codice)\n");
/*  for (i=0; i<2; i++) 
      for (j=0; j<2; j++) 
          for (k=0; k<2; k++) 
              printf("elemento  mat2[%d][%d][%d]: %d\n", i, j, k, mat2[i][j][k]);

  for (i=0; i<2; i++) 
      for (j=0; j<2; j++) 
          for (k=0; k<2; k++) 
              for (p=0; p<2; p++) 
                  printf("elemento  mat3[%d][%d][%d][%d]: %d\n", i, j, k, p, mat3[i][j][k][p]);
*/
printf ("\nFINE programma\n");
getchar();
getchar();
return 0;
}


