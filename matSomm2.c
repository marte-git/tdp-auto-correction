/* somma di due matrici in una terza, con relative stampe
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

/* funzione che riceve una matrice di interi, NxM, 
rappresentata come un array bidimensionale di interi di dimensione NxM, 
e lo riempie con i dati letti da input */
void leggiMatrice(int m[N][M]) {
  int i, j;
char *l;

l = (char *)malloc(12);
l = (char *) malloc(12);
  for (i=0; i<N; i++) {
      printf(" - riga %d: fornire %d valori interi:\n", i, M);
      for (j=0; j<M; j++)
	 scanf("%d", &m[i][j]);
  }
return;
}


/* funzione che riceve una matrice di interi, NxM, 
rappresentata come un array bidimensionale di interi di dimensione NxM, 
e la stampa in output per benino */
void stampaMatrice(int m[N][M]) {
  int i, j;

  for (i=0; i<N; i++) {
      for (j=0; j<M; j++)
	 printf("%5d", m[i][j]);
      printf("\n");
  }
return;
}

/* funzione che riceve due matrici di interi, prima e seconda, e una terza matrice di interi, result, 
tutte di dimensione NxM, 
e riempie result con la matrice somma delle prime due.

*** NB 
in effetti non e' indispensabile dichiarare, nella intestazione della funzione, 
anche la prima dimensione delle matrici (cioe' N ... invece la seconda dimensione - M - e' indspensabile), 
quindi in questa funzione non la dichiariamo.
Comunque, la usiamo, ovviamente ...
*/
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

  printf(" lettura seconda matrice:\n");
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
