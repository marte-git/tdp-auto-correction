/* array e indirizzi (e il bello deve ancora venire ...) */
#include <stdio.h>
#define N 8

/* il programma produce una tabella in cui vengono mostrate, tra l'altro, le due cose importanti 
per ciascuno degli elementi (variabili con indici) di una matrice, 
cioe' il valore contenuto nell'elemento e il suo indirizzo in memoria ... */
int main () {
int i, j, k, p;
int mat[3][4] = { {1, 2, 3, 4}, {10, 20, 30, 40}, {100, 200, 300, 400} };

  for (i=0; i<3; i++) 
      for (j=0; j<4; j++) 
           printf("l'elemento mat[%d][%d] e' di %d byte, ha indirizzo %p e valore %d\n", 
           i, j, sizeof(mat[i][j]), &mat[i][j], mat[i][j]);

printf("FINE\n");
getchar();
getchar();
return 0;
}

