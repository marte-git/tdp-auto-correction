/* Come in ALBERI1.C si legge la rappresentazione
parentetica di un albero
binario e si costriosce la relativa
rappresentazione mediante struct e puntatori.

Stavolta pero',
- l'albero e' di caratteri (maiuscoli)
- la stampa su video dell'albero avviene senza stampare
  le parentesi
- si eseguono tre stampe, usando ogni volta una strategia
  di visita differente: preordine, postordine e simmetrica.

poi si dealloca l'albero.
*/
#include <stdlib.h>
#include <stdio.h>

/* ---------------------------------------------------*/
/* definizione dei tipi di dato */

typedef char TipoElemAlbero;          /* albero di caratteri */

struct StructAlbero {
  TipoElemAlbero info;
  struct StructAlbero *des,
                      *sin;
};

typedef struct StructAlbero TipoNodoAlbero;

typedef TipoNodoAlbero * TipoAlbero;
/* ---------------------------------------------------*/


/* ---------------------------------------------------*/
/* prototipi delle funzioni usate */

/* funzioni da cambiare perche' cambia TipoElemAlbero!*/
void leggiElemAlberoDaFile(FILE *fin, TipoElemAlbero *pelem);
void stampaElemAlbero(TipoElemAlbero elem);
        /* queste rimangono uguali a prima */
TipoAlbero leggiAlberoDaFile(char *nomFile);
TipoAlbero leggiSottoAlberoDaFile(FILE *fin);
void deallocaAlbero(TipoAlbero *pAlb);
        /* nuove funzioni */
void stampaAlberoPreordine(TipoAlbero alb);
void stampaAlberoPostordine(TipoAlbero alb);
void stampaAlberoSimmetrica(TipoAlbero alb);
/* ---------------------------------------------------*/


int main() {
 TipoAlbero albero;
 char nomeFile[20];   /* per il nome del file */


 printf("\n - nome del file con la rappr. par.: ");
 scanf("%s", nomeFile);

 albero = leggiAlberoDaFile(nomeFile);

 printf("\n -  stampa in preordine: ");
 stampaAlberoPreordine(albero);
 printf("\n - stampa in postordine: ");
 stampaAlberoPostordine(albero);
 printf("\n - stampa in simmetrica: ");
 stampaAlberoSimmetrica(albero);

 printf("\n - adesso dealloco l'albero: ");
 deallocaAlbero(&albero);

printf("\nFINE\n");
return 0;
}


TipoAlbero leggiAlberoDaFile(char *nomeDelFile){
  TipoAlbero res;
  TipoElemAlbero el;
  char ccc;
  FILE *f;
                             /* apertura file */
  f = fopen(nomeDelFile, "r");

  fscanf(f, "%c", &ccc);         /* legge la parentesi aperta */
  fscanf(f, "%c", &ccc);         /* legge carattere successivo */

  if (ccc == ')')
    return NULL;             /* ha letto (): albero vuoto */
  else {
             /* ccc non era ')', quindi c'e' da
             leggere l'informazione della radice */
        leggiElemAlberoDaFile(f, &el);
         /* si crea il nodo radice e si avvia la costruzione
         dei due sottoalberi (prima sinistro e poi destro) */
    res = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
    res->info = el;
    res->sin = leggiSottoAlberoDaFile(f);
    res->des = leggiSottoAlberoDaFile(f);
         /* e ora si consuma la parentesi chiusa */
    fscanf(f, "%c", &ccc);
  }

 fclose(f);
return res;
}



/* questa serve a leggere sottoalberi da file:
MA E' QUASI IDENTICA alla leggiAlberoDaFile!!!!!
tranne per la gestione del file:
qui abbiamo ricevuto un file gia' aperto,
mentre la leggiAlbero riceve il nome di un file
e lo apre.
*/
TipoAlbero leggiSottoAlberoDaFile(FILE * fin){
  TipoAlbero res;
  TipoElemAlbero el;
  char ccc;

  fscanf(fin, "%c", &ccc);         /* legge la parentesi aperta */
  fscanf(fin, "%c", &ccc);         /* legge carattere successivo */

  if (ccc == ')')
    return NULL;             /* ha letto (): albero vuoto */
  else {
         /* ccc non era ')', quindi c'e' da
         leggere l'informazione della radice */
    leggiElemAlberoDaFile(fin, &el);
         /* si crea il nodo radice e si avvia la costruzione
         dei due sottoalberi (prima sinistro e poi destro) */
    res = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
    res->info = el;
    res->sin = leggiSottoAlberoDaFile(fin);
    res->des = leggiSottoAlberoDaFile(fin);
         /* e ora si consuma la parentesi chiusa */
    fscanf(fin, "%c", &ccc);
  }
 return res;
}

/* va bene per alberi di caratteri */
void stampaElemAlbero(TipoElemAlbero elem){
 printf("%c",elem);
return;
}

/* va bene per alberi di caratteri */
void leggiElemAlberoDaFile(FILE *fin, TipoElemAlbero *pelem){
 fscanf(fin, "%c", pelem);
return;
}


void deallocaAlbero(TipoAlbero *pAlb)
{
  if( (*pAlb)!=NULL ) {
    deallocaAlbero(&(*pAlb)->sin);
    deallocaAlbero(&(*pAlb)->des);
  }

  free(*pAlb);
  *pAlb=NULL;
return;
}


/* stampa l'albero, senza riportare le parentesi, in preordine */
void stampaAlberoPreordine(TipoAlbero albero)
{
  if (albero == NULL)
    return;
  else {   /* prima la radice poi il sottoalbero sini poi il des */
    stampaElemAlbero(albero->info);
    printf(" ");
    stampaAlberoPreordine(albero->sin);
    stampaAlberoPreordine(albero->des);
  }
return;
}


/* stampa l'albero, senza riportare le parentesi, in postordine */
void stampaAlberoPostordine(TipoAlbero albero)
{
  if (albero == NULL)
    return;
  else {   /* prima la radice poi il sottoalbero sini poi il des */
    stampaAlberoPostordine(albero->sin);
    stampaAlberoPostordine(albero->des);
    stampaElemAlbero(albero->info);
    printf(" ");
  }
return;
}


/* stampa l'albero, senza riportare le parentesi,
con visita simmetrica */
void stampaAlberoSimmetrica(TipoAlbero albero)
{
  if (albero == NULL)
    return;
  else {   /* prima la radice poi il sottoalbero sini poi il des */
    stampaAlberoSimmetrica(albero->sin);
    stampaElemAlbero(albero->info);
    printf(" ");
    stampaAlberoSimmetrica(albero->des);
  }
return;
}




