/*    Gestione di una tabella di voli

un volo e' caratterizzato da
- codice (5 caratteri alfanumerici)
- destinazione (stringa di caratteri)
- ora di partenza (ore, minuti: due interi)
- numero di posti attualmente liberi

la gestione di una tabella di voli consiste nella possibilita' di
- stampare un volo della tabella, caratterizzato da un certo codice
- stampare i voli della tabella
- aggiungere un volo alla tabella,
- eliminare un volo avente caratterizzato da un certo codice
- modificare l'ora di partenza di un volo caratterizzato
  da un certo codice
- prenotare posti in un volo caratterizzato da un
  certo codice (cioe' modificarne il numero di posti liberi)
- memorizzare i dati di una tabella di voli in un file di voli
- caricare nella tabella dati da un file di voli

Si vede che in questa tabella il campo codice e' la
"chiave di ricerca" per i voli memorizzati.
*/

#include <stdio.h>
#define MAXVOLI 10   /* usiamo tabelle di 10 voli, per scrivere e testare
                     il programma. Dopo potremo cambiar questa dimensione */

/* definizione delle strutture dati */

/* il tipo struct per rappresentare un volo contiene un campo
   oraPartenza. L'ora e' ben rappresentabile con un'altra struct */

struct ora {
   int ore, minuti;
};

struct volo {
   char codice[6];
   char * destinazione;
   struct ora oraPartenza;
   int postiLiberi;
};

/* per i voli, decidiamo di definire un sinonimo di tipo */
typedef struct volo TipoVolo;

/* la tabella di voli consiste di un array di MAXVOLI voli,
ma anche di un intero quantiVoli che in ogni momento
specifica quanti sono i voli effettivamente presenti in tabella.
Faremo in modo che, se in un dato momento ci sono k voli in tabella,
essi siano i primi k elementi dell'array e quantiVoli sia uguale a k.
Ogni scansione della tabella si limitera' agli elementi
di indice da 0 a quantiVoli-1.

Quindi una tabella di voli e' una struttura a due campi.
*/
typedef
   struct {
     TipoVolo arrayVoli[MAXVOLI]; /* sostegno di memoria */
     int quantiVoli; /* quanti voli presenti nel sostegno */
   }
   TipoTabella;


/* ipotesi su alcune funzioni che useremo
(scriviamo solo le intestazioni, per ragionare su quel che
ci si aspetta che facciano le funzioni e come verranno chiamate)
*/

void stampaQuelVolo(TipoTabella t, char cod[6]);
/* stampa il volo avente codice cod nella tabella t */

void stampaTabella(TipoTabella t);
/* stampa tutti i voli della tabella */

/* !!! */
/* per entrambe le precedenti funzioni sara' comodo
usare una funzione come la seguente ... */
void stampaVolo(TipoVolo v);
/* stampa il volo v */

int aggiungiVolo(TipoTabella *t);
/* aggiunge un nuovo volo nella tabella t,
chiedendo e leggendo opportunamente i dati relativi

Restituisce 1 o 0 a seconda della riuscita dell'ahggiunta.

Sia t.arrayVoli (nell'elemento di indice dipendente da quantiVoli).
che t.quantiVoli saranno modificati.
Visto che tutte queste modifiche devono
sopravvivere nella tabella passata alla funzione come
parametro attuale, il passaggio avviene tramite
indirizzo, cioe' la funzione riceve l'indirizzo della
tabella */


/* per il momento basta con la definizione delle funzioni;
potendo aggiungere e stampare, siamo in grado di testare
subito se la strada e' quella giusta;
quindi qui aggiungiamo solo un'implementazione provvisoria
della main() e delle funzioni definite sopra.
Per fare un primo test.
E poi proseguiamo in voli2.c */


int main() {
  TipoTabella tabVoli;
  int riuscita,
      scelta;  /* scelta nel menu' */
  char buffer[40];

   tabVoli.quantiVoli=0;   /* inizializzazione del numero di  voli
                  presenti in tabella (cosa ci sia
                  effettivamente in tabVoli.arrayVoli e' di
                  poco interesse. Tanto le scansioni che faremo
                  saranno sempre limitate da quantiVoli*/
   do {
     printf(" -      scegli                   -\n");
     printf(" - stampa dei voli           (1) -\n");
     printf(" - stampa di un certo volo   (2) -\n");
     printf(" - aggiunta di un volo       (3) -\n");
     printf(" - fine                      (0) -\n");

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
          break;
       case 3:
          riuscita=aggiungiVolo(&tabVoli);
          if(!riuscita)
        printf(" - aggiunta non effettuata -\n");
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


int aggiungiVolo(TipoTabella *t) {
  printf("\nchiamata aggiungiVolo\n");
return 1;
}

void stampaQuelVolo(TipoTabella t, char cod[6]) {
/* qui sara' necessario "cercare" l'indice del volo in t.arrayVoli
   e poi eseguire stampaVolo (t.arrayVolo[k]);
*/

  printf("\nchiamata stampaQuelVolo\n");
return;
}

void stampaTabella(TipoTabella t) {
  printf("\nchiamata stampaTabella\n");
return;
}

void stampaVolo(TipoVolo v) {
  printf("...VOLO %s (%d disponibili), partenza alle %2d:%2d per %s",
  v.codice, v.postiLiberi, v.oraPartenza.ore, v.oraPartenza.minuti, v.destinazione);
return;
}
