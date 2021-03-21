/* come negozi.c, ma con due errori ...
 */

#include <stdio.h>

#define N 6

int main ()
{
  double guadagni[N], media, media2,
	 somma,             /* per calcolare le medie */
	 maxparz, minparz;  /* per calcolare massimo e minimo guadagno */
  int i;                    /* contatore */


		      /* lettura dei guadagni mensili, negozio per negozio */
  for (i=0; i<N; i++) {
     printf(" fornire il guadagno mensile del negozio %d: ", i);
     scanf("%lf", guadagni[i]);
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


		      /* ricerca massimo nell'array */
  maxparz = guadagni[0];

  for (i=1; i<N; i++)        /* NB 1 e non 0*/
    if (maxparz<guadagni[i]) maxparz=guadagni[i];

		      /* ora in maxparz c'e' il massimo degli elemnti nell'array */

		      /* ricerca minimo nell'array */
  minparz = guadagni[0];

  for (i=1; i<N; i++)
    if (minparz>guadagni[i]) minparz=guadagni[i];

		      /* e ora in minparz c'e' il minimo degli elemnti nell'array */

		      /* calcolo media2 */
  media2 = (somma - maxparz -minparz) / N;

  printf(" (media2=%g) ecco le pecore nere:\n", media2);
  for (i=0; i<N; i++)
    if (guadagni[i] < media2/3)
      printf(" *** negozio %d con Euro %lf\n", i, guadagni[i]);


printf("FINE\n");
return 0;
}
