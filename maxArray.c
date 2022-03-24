#include <stdio.h>
#define N 6

/* il programma inzializza per suo conto una array di N elementi double, 
e poi ne calcola e stampa il massimo */

/* se on funziona la perdita di tempo ... #include <unistd.h> */


/* funzione che, ricevuto un array di N elementi double, lo stampa in output per benino */
void stampaArray (double a[N]) {
    int i;

  printf ("(");
  for (i=0; i<N; i++) 
      printf (" %g ", a[i]);
  printf (")\n\n");
return;
}

/* funzione che, ricevuto un array di N elementi double, 
calcola il valore massimo in esso contenuto e lo restituisce */
double findMax (double a[N]) {
    int i;
    double maxParz = a[0];

  for (i=1; i<N; i++) 
     if (maxParz < a[i])
       maxParz=a[i];

return maxParz;
}

int main ()
{
  double arr[]={32.59, 116, 50.08, 56.18, 47, 42};
  double massimo;
  int perditempo=0;
  
		      /* stampa dell'array */
   printf ("caro/a utente, l'array e' \n");
   stampaArray(arr);
   printf ("... sto calcolando il massimo\n");
sleep(3);
   printf ("... ci sono quasi\n");
sleep(3);
   printf ("... ecco ...\n");
sleep(2);

   massimo = findMax(arr);
  
   printf("ok, il massimoe' %g\n", massimo);

printf("FINE\n");
getchar();
getchar();
return 0;
}
