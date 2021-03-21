/*
    Gestione di una tabella di voli
vedi cose scritte in voli1.c e voli2.c

qui l'implementazione parziale cresce,
con l'aggiunta di alcune funzioni necessarie 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXVOLI 10   /* usiamo tabelle di 10 voli, per scrivere e testare
                     il programma. Dopo potremo cambiar questa dimensione */

/* definizione delle strutture dati */

struct ora {
   int ore, minuti;
};

struct volo {
   char codice[6];
   char * destinazione;
   struct ora oraPartenza;
   int postiLiberi;
};

typedef struct volo TipoVolo;

typedef
   struct {
     TipoVolo arrayVoli[MAXVOLI]; /* sostegno di memoria */
     int quantiVoli; /* quanti voli presenti nel sostegno */
   }
   TipoTabella;


/* prototipi di funzioni */

int indiceVolo(TipoTabella t, char cod[]);
void stampaQuelVolo(TipoTabella t, char cod[]);
void stampaTabella(TipoTabella t);
void stampaVolo(TipoVolo v);
int aggiungiVolo(TipoTabella *t);
int eliminaVolo(TipoTabella *t, char cod[]);

/* aggiunte rispetto al fileprecedente */

int cambiaOraPartenza(TipoTabella *t, char cod[], int nuovaOra, int nuoviMinuti);
/* restituisce 0 o 1 a seconda del successo dell'operazione */

int cambiaPostiLiberi(TipoTabella *t, char cod[], int k);
/* diminuisce di k i posti liberi (quindi li aumenta se k e' negativo);
restituisce 0 o 1 a seconda del successo dell'operazione */



/* Questa e' ancora una versione limitata;
Il resto delle funzioni in voli5.c */


int main() {
  TipoTabella tabVoli;
  TipoVolo unVolo;
  int riuscita,o,m,pl,
      scelta;  /* scelta nel menu' */
  char buffer[40];

   tabVoli.quantiVoli=0;   /* inizializzazione del numero di  voli */

   do {
     printf(" -      scegli                         -\n");
     printf(" - stampa dei voli                 (1) -\n");
     printf(" - stampa di un certo volo         (2) -\n");
     printf(" - aggiunta di un volo             (3) -\n");
     printf(" - eliminazione di un volo         (4) -\n");
     printf(" - modifica ora partenza           (5) -\n");
     printf(" - prenotazione posti              (6) -\n");
     printf(" - fine                            (0) -\n");

     scanf("%d", &scelta);

     switch (scelta) {
       case 1:
      printf(" --- %d voli in tabella:\n", tabVoli.quantiVoli);
      stampaTabella(tabVoli);
      break;
       case 2:
      printf(" --- codice volo? ");
      scanf("%s", buffer);
      stampaQuelVolo(tabVoli, buffer);
      putchar('\n');
      break;
       case 3:
      riuscita=aggiungiVolo(&tabVoli);
      if(!riuscita)
        printf(" --- aggiunta non effettuata -\n");
      else
        printf(" --- fatto -\n");
      break;
       case 4:
      printf(" --- codice volo da eliminare? ");
      scanf("%s", buffer);

      riuscita=eliminaVolo(&tabVoli, buffer);
      if(!riuscita)
        printf(" --- eliminazione non effettuata -\n");
      else
        printf(" --- fatto -\n");
      break;
       case 5:
      printf(" --- codice e nuova ora (scrivi ore e minuti) ");
      scanf("%s %d %d", buffer, &o, &m);

      riuscita=cambiaOraPartenza(&tabVoli, buffer,o,m);
      if(!riuscita)
        printf(" --- modifica non effettuata -\n");
      else
        printf(" --- fatto -\n");
      break;
       case 6:
      printf(" --- codice e quanti posti ");
      scanf("%s %d", buffer, &pl);

      riuscita=cambiaPostiLiberi(&tabVoli, buffer, pl);
      if(!riuscita)
        printf(" --- modifica non effettuata -\n");
      else
        printf(" --- fatto -\n");
      break;
       case 0:
      printf(" - USCITA DAL PROGRAMMA\n");
      break;
       default:
      printf(" - opzione sballata\n");
     } /* fine switch */
   } while (scelta!=0);       /* fine do_while*/

  printf("\nFINE\n");
  return 0;
  }


int indiceVolo(TipoTabella t, char cod[]) {
  int trovato=0, i=0;
  while (!trovato && (i<t.quantiVoli))
    if (strcmp(t.arrayVoli[i].codice, cod)==0)
      trovato=1;
    else i++;
  /* all'uscita dal ciclo, se abbiamo trovato il volo i
  ne contiene l'indice */

  if (trovato)
    return i;
  else return -1;
}

void stampaVolo(TipoVolo v) {
  printf("...VOLO %s (%d disponibili), partenza alle %2d:%2d per %s",
  v.codice, v.postiLiberi, v.oraPartenza.ore, v.oraPartenza.minuti, v.destinazione);
return;
}

void stampaQuelVolo(TipoTabella t, char cod[]) {
  int k=indiceVolo(t, cod);

  if (k==-1)
    printf("\n volo %s non in tabella -\n", cod);
  else stampaVolo(t.arrayVoli[k]);
return;
}

void stampaTabella(TipoTabella t) {
  int i;
  printf("\nStampa intera tabella voli\n");

  for (i=0; i<t.quantiVoli; i++) {
    stampaVolo(t.arrayVoli[i]);
    printf("\n");
  }
return;
}

int aggiungiVolo(TipoTabella *t) {
  char buffer[50], *aux;
  int o,m,pl;


  if (t->quantiVoli==MAXVOLI) {
    printf("\n spazio insufficiente \n");
    return 0;
  }
  else {
    printf(" - codice? ");
    scanf("%s", t->arrayVoli[t->quantiVoli].codice);

    printf(" - destinazione? ");
    scanf("%s", buffer);
    aux=malloc(strlen(buffer)+1);
    if (aux==NULL) {
      printf ("\nPROBLEMI IN ALLOCAZIONE\n");
      return 0;
    }
    else {
      strcpy(aux, buffer);
      t->arrayVoli[t->quantiVoli].destinazione=aux;
    }

    printf(" - ora della partenza (scrivi ore e minuti)? ");
    scanf("%d %d", &o, &m);
    t->arrayVoli[t->quantiVoli].oraPartenza.ore=o;
    t->arrayVoli[t->quantiVoli].oraPartenza.minuti=m;

    printf(" - posti disponibili? ");
    scanf("%d", &pl);
    t->arrayVoli[t->quantiVoli].postiLiberi=pl;

    /* l'aggiunta ha avuto successo */
    (t->quantiVoli)+=1;

  }
return 1;
}


int eliminaVolo(TipoTabella *t, char cod[]) {
  int k, ultimo;
  
  k=indiceVolo(*t, cod);   /* indice elemento da eliminare (o -1) */
  ultimo=t->quantiVoli-1;  /* indice ultimo elemento in tabella */

  if (k==-1) {
    printf("\n volo %s non in tabella -\n", cod);
    return 0;
  }
  else {
    t->arrayVoli[k] = t->arrayVoli[ultimo];
    t->quantiVoli-=1;
    return 1;
  }
}


/* cambia un dato nel volo di codice cod della tabella *t 
restituisce 0 o 1 a seconda del successo dell'operazione 
Si cerca l'elemento da eliminare e lo si modifica ...  */
int cambiaOraPartenza(TipoTabella *t, char cod[], int nuovaOra, int nuoviMinuti) {
  int k;
  
  k=indiceVolo(*t, cod);   /* indice elemento da eliminare (o -1) */

  if (k==-1) {
    printf("\n volo %s non in tabella -\n", cod);
    return 0;
  }
  else {
    t->arrayVoli[k].oraPartenza.ore = nuovaOra;
    t->arrayVoli[k].oraPartenza.minuti = nuoviMinuti;
    return 1;
  }
}

/* cambia un dato nel volo di codice cod della tabella *t 
restituisce 0 o 1 a seconda del successo dell'operazione 
Si cerca l'elemento da eliminare e lo si modifica ...  

diminuisce di k i posti liberi (quindi li aumenta se k e' negativo);
restituisce 0 o 1 a seconda del successo dell'operazione */
int cambiaPostiLiberi(TipoTabella *t, char cod[], int num) {
  int h;

  h=indiceVolo(*t, cod);   /* indice elemento da eliminare (o -1) */

  if (h==-1) {
    printf("\n volo %s non in tabella -\n", cod);
    return 0;
  }
  else
    if(num<=t->arrayVoli[h].postiLiberi) {
      t->arrayVoli[h].postiLiberi -= num;
      return 1;
    }
    else  {
      printf("\n posti insufficienti -\n");
      return 0;
    }
}
