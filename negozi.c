/* problema dei guadagni dei negozi:
una societa' possiede N negozi e vuole valutarli, in base al loro
guadagno mensile. I negozi sono numerati da 0 a N, per semplicita'.
Il programma deve
- leggere i guadagni mensili
- calcolare e stampare la media di tali guadagni
- indicare quali negozi guadagnano meno di media/3
- calcolare e stampare la media dei guadagni escludendo il maggiore
  e il minore (questa media si chiama media2)
  (si suppone di considerare uno solo dei massimi e minimi, se ce ne sono di piu')
- indicare le pecore nere, cioe' i negozi guadagnano meno di media2/3
 */
#include <stdio.h>

#define N 6

int main () {
  double guadagni[N], media, media2,
	 somma,             /* per calcolare le medie */
	 maxparz, minparz;  /* per calcolare massimo e minimo guadagno */
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
  media2 = (somma - maxparz -minparz) / (N-2);

  printf(" (media2=%g) ecco le pecore nere:\n", media2);
  for (i=0; i<N; i++)
    if (guadagni[i] < media2/3)
      printf(" *** negozio %d con Euro %g\n", i, guadagni[i]);


printf("FINE\n");

return 0;
}
