#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXLUNG 50
#define N 5

/* ****** dichiarazioni delle funzioni usate ****** */
int presente (char *v[], char *cercata);
void rivolta(char *);


main(){
 int i;
 char *stringhe[N],       /* array di N stringhe */
       buffer[MAXLUNG+1]; /* buffer per la lettura delle stringhe */

 printf(" - immissione stringhe da input -\n");

 for (i=0; i<N; i++) {
   printf("stringa di al piu' %d caratteri: ", MAXLUNG);
   scanf("%s", buffer);                    /*lettura stringa*/
   stringhe[i] = malloc(strlen(buffer)+1); /*allocazione esatta*/
   if (stringhe[i]==NULL) {
     printf("problemi in allocazione\n");
     break;
   }
   else strcpy(stringhe[i], buffer);       /* copia della stringa nell'array di stringhe */
 }

 printf(" - stringhe lette -\n");          /* controllo */
 for (i=0;i<N;i++) printf("%s\n", stringhe[i]);

 printf(" - adesso dammi una stringa da cercare tra quelle lette: ");
 scanf("%s", buffer);

 if ( presenteIn(stringhe, buffer) )
   printf(" - SI'!!! C'E'!!!");
 else {
   printf(" - NO!!! NON C'E'!!!");
   rivolta(buffer);
   printf(" - eccola rivoltata: %s\n", buffer);
 }

 printf("\nFINE\n");
return 0;
}


/* ************* funzioni usate ********************** */
int presente (char *v[], char *cercata) {
  int trovata, i;

  trovata=0;
  for (i=0; ((i<N)&&(!trovata)) ; i++)
    if (strcmp(v[i],cercata)==0)
      trovata=1;

return trovata;
}
/* che succede di diverso se si elimina il controllo !trovata? */


 void rivolta(char *s) {
 int i, j;
 char aux; /* ausiliario per gli scambi */

 for(i=0, j=strlen(s)-1; i<j; i++, j--) {
   aux=s[i];
   s[i]=s[j];
   s[j]=aux;
 }
return;
}

