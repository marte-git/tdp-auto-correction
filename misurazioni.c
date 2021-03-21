/* istogramma dei dati di una centralina di misurazione inquinamento
viene fatta una misurazione ogni 10 minuti dalle 6 di mattina alle
2 del mattino successivo

e al termine viene prodotto un istogramma come il seguente

da 00:00 a 00:59 *******
da 01:00 a 01:59 *****
da 02:00 a 02:59 **
...
da 16:00 a 16:59 **********************************************
...
da 23:00 a 23:59 **********

(supponiamo che le misurazioni siano numeri di microgrammi compresi tra 0 e 61,
quindi la linea piu' lunga e' di 61 asterischi)

per ogni ora vengono fatte 6 rilevazioni; la media (troncata) di
queste rilevazioni sara' il valore di inquinamento per quell'ora.
*/

#include <stdio.h>
#include <stdlib.h>     /* rand() */
#include <time.h>       /* clock() */

#define PUNTO '*'
#define ESTREMO 61
#define DIM 24


/* restituisce una misurazione in microgrammi
   compresa tra 0 e il parametro passato */
int misurazione(int estremo) {
    return(rand() % estremo);
}


/* stampa un array di misurazioni in cui le
linee dell'istogramma sono composte dal
carattere passato come secondo argomento     */
void stampaIstogramma (int arr[], char c) {
   int i, j;

   for (i=0; i<24; i++) {

      printf("da %2d:00 a %2d:59 ", i, i);

      for (j=0; j<arr[i]; j++)
         printf("%c", c);

      printf("\n");
   }
return;
}


/* questa stampa solo i dati delle ore da inizio a fine */
void stampaIstogramma2 (int arr[], char c, int inizio, int fine) {
   int i, j;

   for (i=inizio; i<fine; i++) {

      printf("da %2d:00 a %2d:59 ", i, i);

      for (j=0; j<arr[i]; j++)
         printf("%c", c);

      printf("\n");
   }
return;
}





int main () {
    int i, j, somma,
         dati[DIM],                       /* array di misurazioni */
       dato;                          /* una misurazione      */

  /* init di rand() (con il valore fornito da clock()) */
  srand(clock());

  printf("lettura dati:\n");

  for (i=0; i<24; i++) {              /* lettura dei dati di un'ora per 24 volte */

     somma=0;
     for (j=0; j<6; j++) {        /* lettura di 6 dati nell'ora */
          /* printf("ore %d e %d: ", i, j*10); */

        dato = misurazione(ESTREMO);    /* lettura */


        somma += dato;           /* accumulazione */
     }

     dati[i] = somma/6;          /* media delle misurazioni nell'elemento dell'array
                                  relativo all'ora i (e' un valore intero) */ 
  }


  /* usare questo codice (invece della chiamata di stampaIstogramma ())
  se si vuole adottare la soluzione stampaIstogramma2;
  ci vogliono i due parametri in piu', da chiedere all'utente ...
  printf("stampa dati: fornire ora inizio e fine (es. 8 23): ");
  scanf("%d %d", &i, &j);
  stampaIstogramma2 (dati, PUNTO, i, j);
  */
  stampaIstogramma (dati, PUNTO); 

printf("FINE\n");

return 0;
}



