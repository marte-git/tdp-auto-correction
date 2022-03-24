#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define N 5
#define MAXLUNG 50
#define TERMINANTE "STOP"

/* ****** dichiarazioni delle funzioni usate ****** */
int presenteIn (char *v[], char *cercata);
void rivolta(char *);
char * duplicato(char *);

main(){
 int i, continua;
 char *stringhe[N],       /* array di N stringhe */
       buffer[MAXLUNG+1]; /* buffer per la lettura delle stringhe */

 printf(" - immissione stringhe da input -\n");

 for (i=0; i<N; i++) {
   printf("stringa di al piu' %d caratteri: ", MAXLUNG);
   scanf("%s", buffer);                    /*lettura stringa*/
   stringhe[i] = duplicato(buffer);        /* copia con allocazione esatta */
   if (stringhe[i]==NULL) {
     printf("problemi in allocazione\n");
     break;
   }
 }

 printf(" - stringhe lette -\n");          /* controllo */
 for (i=0;i<N;i++) printf("%s\n", stringhe[i]);

 /* ricerca di stringhe nell'array */
 continua=1;
 while (continua==1) {
   printf(" - stringa da cercare (%s per terminare): ", TERMINANTE);
   scanf("%s", buffer);

   if (strcmp(buffer, TERMINANTE)==0)
     continua=0;      /* dovremo uscire dal while */
   else               /* dovremo cercare buffer nell'array */
     if ( presenteIn(stringhe, buffer) )
       printf(" - SI'!!! C'E'!!!\n");
     else {
       printf(" - NO!!! NON C'E'!!!\n");
       rivolta(buffer);
       printf(" - eccola rivoltata: %s\n", buffer);
     }
  } /* fine while */
 printf("\nFINE\n");
return 0;
}


/* ************* funzioni usate ********************** */

/* descrizione */
int presenteIn (char *v[], char *cercata) {
  int trovata, i;

  trovata=0;
  for (i=0; ((i<N)&&(!trovata)) ; i++)
    if (strcmp(v[i],cercata)==0)
      trovata=1;

return trovata;
}
/* che succede se si elimina il controllo !trovata? */



/* descrizione */
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



/* descrizione */
char * duplicato(char * str) {
/* riceve una stringa e ne crea e restituisce un duplicato */
  char * new;

  new = malloc(strlen(str));
  if (new)
    strcpy(new, str);

return new;
}
