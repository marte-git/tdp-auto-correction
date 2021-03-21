# lweb-repo title

$ - a repo for people that like :tangerine: and :lemon:

> Per Aspera ad Astra

~~this text is canceled; it is here only because I'm a fan of **~**~~

# Welcome to GitHub Desktop!

A parte gli scherzi, il README(.md perche' e' scritto in markdown)
e' il documento che contiene spiegazioni sul progetto e che viene consultato per primo da chi e' interessato al progetto.


# dummy repository `readme` file 

lista:
- a project for people that like only :watermelon: and :grapes:
- yes, this is a _readme_ file
- no

sottosezione:
## what can I put here
the `emoji-cheat-sheet` is [here](https://github.com/ikatyang/emoji-cheat-sheet/blob/master/README.md)

- no

quotation:
> SI sta come le foglie
> sugli alberi
> > d'autunno
> > 

######sottosottosezione
```c
/* n dimensione array, v valore intero */
int eser (int arr[], int n, int v) {
  int i, dist, distMin, indMin=0;

  distMin = (arr[0]<v) ? v-arr[0] : arr[0]-v;
  for(i=1; i<n; i++) {
     dist = (arr[i]<v) ? v-arr[i] : arr[i]-v;
     if (dist<distMin) {
        distMin = dist;
        indMin=i;
     }
  }
return indMin;
}
```


