
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

/* aggiunte rispetto al fileprecedente */

int eliminaVolo(TipoTabella *t, char cod[]);
/* elimina il volo di codice cod dalla tabella *t 
(cambiano arrayVoli e quantiVoli) 
restituisce 0 o 1 a seconda del successo dell'operazione */


/* Questa e' ancora una versione limitata */


int main() {
  TipoTabella tabVoli;
  TipoVolo unVolo;
  int riuscita,
      scelta;  /* scelta nel menu' */
  char buffer[40];

   tabVoli.quantiVoli=0;   /* inizializzazione del numero di  voli */

   do {
     printf(" -      scegli                         -\n");
     printf(" - stampa dei voli                 (1) -\n");
     printf(" - stampa di un certo volo         (2) -\n");
     printf(" - aggiunta di un volo             (3) -\n");
     printf(" - eliminazione di un volo         (4) -\n");
     printf(" - fine                            (0) -\n");

     scanf("%d", &scelta);

     switch (scelta) {
       case 1:
          printf(" - %d voli in tabella:\n", tabVoli.quantiVoli);
          stampaTabella(tabVoli);
          break;
       case 2:
          printf(" - codice volo? ");
          scanf("%s", buffer);
          stampaQuelVolo(tabVoli, buffer);
          putchar('\n');
          break;
       case 3:
          riuscita=aggiungiVolo(&tabVoli);
          if(!riuscita)
            printf(" - aggiunta non effettuata -\n");
          else
            printf(" - fatto -\n");
          break;
       case 4:
          printf(" - codice volo da eliminare? ");
          scanf("%s", buffer);
          
          riuscita=eliminaVolo(&tabVoli, buffer);
          if(!riuscita)
            printf(" - eliminazione non effettuata -\n");
          else
            printf(" - fatto -\n");
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


/* elimina il volo di codice cod dalla tabella *t 
restituisce 0 o 1 a seconda del successo dell'operazione 
Si cerca l'elemento da eliminare e lo si ricopre
copiandoci sopra l'ultimo elemento della tabella;
poi si decrementa quantiVoli*/
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
