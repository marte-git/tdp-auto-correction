/* somma di due matrici in una terza, con relative stampe
 */

#include <stdio.h>

#define N 3
#define M 4

void leggiMatrice(int m[][M]) {
  int i, j;

  for (i=0; i<N; i++) {
      printf(" - riga %d: fornire %d valori interi:\n", i, M);
      for (j=0; j<M; j++)
	 scanf("%d", &m[i][j]);
  }
return;
}


void stampaMatrice(int m[][M]) {
  int i, j;

  for (i=0; i<N; i++) {
      for (j=0; j<M; j++)
	 printf("%5d", m[i][j]);
      printf("\n");
  }
return;
}

void sommaMatrici(int prima[][M], int seconda[][M], int result[][M]) {
     int i, j;

     for (i=0; i<N; i++)
       for (j=0; j<M; j++)
	 result[i][j] = prima[i][j] + seconda[i][j];
return;
}




int main () {
  int mat1[N][M], mat2[N][M], mat3[N][M],
      i, j;             /* indici */

  printf(" lettura prima matrice:\n");
  leggiMatrice(mat1);

  printf(" lettura secnda matrice:\n");
  leggiMatrice(mat2);

  sommaMatrici(mat1, mat2, mat3);

  printf(" prima matrice:\n");
  stampaMatrice(mat1);

  printf(" seconda matrice:\n");
  stampaMatrice(mat2);

  printf(" matrice somma:\n");
  stampaMatrice(mat3);


printf("FINE\n");
return 0;
}
