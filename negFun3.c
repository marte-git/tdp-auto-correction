/* come NEGFUN1.C e NEGFUN2.C,
ma qui abbiamo anche
la funzione di lettura di un array ... */

#include <stdio.h>
#define N 6

/* dichiarazioni delle funzioni usate  */
double massimo (double []);
double minimo(double []);
double accumulazione(double []);
void stampaNegoziScarsi(double [], double);
void leggiGuadagni(double []);


int main () {
  double guadagni[N], media, media2,
     somma,             /* per calcolare le medie */
     max, min;          /* massimo e minimo guadagno */


  leggiGuadagni(guadagni);

  somma = accumulazione(guadagni);
  media = somma/N;

  printf(" (media=%g) ecco i negozi che guadagnano poco:\n", media);
  stampaNegoziScarsi(guadagni, media/3);

  max = massimo(guadagni);
  min = minimo(guadagni);
  media2 = (somma - max -min) / (N-2);

  printf(" (media2=%g) ecco le pecore nere:\n", media2);
  stampaNegoziScarsi(guadagni, media2/3);

printf("FINE\n");
getchar();
getchar();

return 0;
}



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


/* definizione della funzione che, ricevendo un array, arr,
   restituisce il minimo valore contenuto in arr */
double minimo (double arr[]) {
  double minparz;
  int i;

  minparz=arr[0];
  for(i=1; i<N; i++)
    if (minparz>arr[i]) minparz=arr[i];

  return minparz;
}


/* definizione della funzione che, ricevendo un array, arr,
   restituisce la somma complessiva dei suoi elementi */
double accumulazione (double g[]) {
  double s=0.0;
  int i;

  for(i=0; i<N; i++)
    s += g[i];

return s;
}


/* definizione della funzione che, ricevendo un array di
guadagni g,
e un numero reale soglia, stampa gli elementi dell'array
inferiori a soglia (con i relativi indici) */

void stampaNegoziScarsi (double g[N], double soglia) {
  int i;

  for(i=0; i<N; i++)
    if (g[i] < soglia)
      printf(" negozio %d, con guadagno %g\n", i, g[i]);

return;
}


void leggiGuadagni (double g[]) {
  int i;

  for (i=0; i<N; i++) {
     printf(" fornire il guadagno mensile del negozio %d: ", i);
     scanf("%lf", &g[i]);
  }

return;
}
