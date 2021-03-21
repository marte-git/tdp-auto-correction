/* somma di due matrici in una terza, con relative stampe
 */

#include <stdio.h>

#define N 3
#define M 4

int main () {
  int mat1[N][M], mat2[N][M], mat3[N][M],
      i, j;             /* indici */

              /* lettura della prima matrice */
  printf(" lettura prima matrice:\n");
  for (i=0; i<N; i++) {
      printf(" - riga %d: fornire %d valori interi:\n", i, M);
      for (j=0; j<M; j++)
    scanf("%d", &mat1[i][j]);
  }

	      /* lettura della seconda */
  		/* matrice */
  printf(" lettura secnda matrice:\n");
  for (i=0; i<N; i++) {
      printf(" - riga %d: fornire %d valori interi:\n", i, M);
      for (j=0; j<M; j++)
    scanf("%d", &mat2[i][j]);
  }

	      /* calcolo della matrice somma */
  for (i=0; i<N; i++)
    for (j=0; j<M; j++)
      mat3[i][j] = mat1[i][j] + mat2[i][j];


              /* stampa della prima matrice */
  printf(" prima matrice:\n");
  for (i=0; i<N; i++) {
      for (j=0; j<M; j++)
    printf("%5d", mat1[i][j]);
      printf("\n");
  }

              /* stampa della seconda matrice */
  printf(" seconda matrice:\n");
  for (i=0; i<N; i++) {
      for (j=0; j<M; j++)
    printf("%5d", mat2[i][j]);
      printf("\n");
  }

              /* stampa della matrice somma */
  printf(" matrice somma:\n");
  for (i=0; i<N; i++) {
      for (j=0; j<M; j++)
    printf("%5d", mat3[i][j]);
      printf("\n");
  }


printf("TERMINE PROGRAMMA\n");


return 0;
}
