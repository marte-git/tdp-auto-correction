/* problema dei guadagni dei negozi, come NEGOZI.C

qui definizmo e usiamo le funzioni massimo, minimo
 */

#include <stdio.h>

#define N 6


/* definizione della funzione che, ricevendo un array, arr,
   restituisce il massimo valore contenuto in arr */
double massimo (double arr[N]) {
  double maxparz;
  int i;

  maxparz=arr[0];
  for(i=1; i<N; i++)
    if (maxparz<arr[i]) maxparz=arr[i];

  return maxparz;
}


/* definizione della funzione che, ricevendo un array, arr, restituisce il minimo valore contenuto in arr */
double minimo (double arr[]) {
  double minparz;
  int i;

  minparz=arr[0];
  for(i=1; i<N; i++)
    if (minparz>arr[i]) minparz=arr[i];

  return minparz;
}


int main () {
  double guadagni[N], media, media2,
     somma,             /* per calcolare le medie */
     max, min;          /* massimo e minimo guadagno */
  int i;                    /* contatore */


              /* lettura dei guadagni mensili, negozio per negozio */
  for (i=0; i<N; i++) {
     printf(" fornire il guadagno mensile del negozio %d: ", i);
     scanf("%lf", &guadagni[i]);
  }

              /* accumulazione in somma di tutti i guadagni */
  somma = 0.0;

  for (i=0; i<N; i++)
    somma += guadagni[i];

              /* calcolo media */
  media = somma/N;

  printf(" (media=%g) ecco i negozi che guadagnano poco:\n", media);
  for (i=0; i<N; i++)
    if (guadagni[i] < media/3)
      printf(" - negozio %d con Euro %g\n", i, guadagni[i]);


              /* ricerca massimo e minimo nell'array */
  max = massimo(guadagni);
  min = minimo(guadagni);

              /* calcolo media2 */
  media2 = (somma - max -min) / (N-2);

  printf(" (media2=%g) ecco le pecore nere:\n", media2);
  for (i=0; i<N; i++)
    if (guadagni[i] < media2/3)
      printf(" *** negozio %d con Euro %g\n", i, guadagni[i]);


printf("FINE\n");

return 0;
}



