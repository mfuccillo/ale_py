/* chiarimenti sui puntatori
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Riga {
    char* testo;        // attenzione che non punta a niente
    int tipo;           // qui ci scriverò se la riga è un comando oppure un testo, vedremo.
    struct Riga* next;  // ho in mente di fare una lista di questi elementi Riga
};

struct Riga * initRiga(char * testo){
    // vediamo di concentrare qui tutto il meccanismo di inizializzazione di un oggetto Riga

    struct Riga *p;

    // manca il controllo che malloc abbia allocato qualcosa
    // se malloc non ha allocato è perchè ha finito la memoria p==NULL
    p = (struct Riga *) malloc(sizeof(struct Riga));

    p->testo = strdup(testo);  //rileggere le specifiche di strdup()
    p->tipo = 0;
    p->next = NULL;

    return p;
}

struct Riga * appendRiga(struct Riga ** headrif, char * testo){
    // va in fondo alla lista e appende un nuovo elemento
    // headrif non è head ma l'indirizzo di head, infatti ci sono due asterischi
    // e quando richamerò la funzione la chiamata non sarà  appendRiga(head, ...   ma   appendRiga( & head, ...
    // tutto questo serve per gestire la situazione di lista vuota:
    // all'inizio del programma la lista è vuota cioè head punta a NULL (non ho ancora allocato nessun elemento di tipo Riga)
    // all'inserimento del primo elemento cosa succede:
    //     creo un elemento Riga e il puntatore a questo elemento è p
    //     devo fare in modo che head punti alla stessa memoria di p
    //     quindi devo modificare il contenuto, (in altre parole il valore) di head e quindi devo passare a appendRiga il parametro head "by reference" e non "by value"

    struct Riga *p;            // nuovo elemento da appendere alla lista
    struct Riga *curr = *headrif;  // mi serve un altro puntatore: puntatore all'elemento corrente, che all'inizio punta al primo elemento o a NULL se la lista è vuota

    p = initRiga(testo);       // ricordarsi di modificare initRiga in modo che ritorni NULL se la malloc non è andata bene
    printf("debug - append - creato nuovo elemento %s", testo);

    if (p != NULL) {          // cioè se la initRiga ha effettivamente creato un elemento...

        if (*headrif != NULL) {
            while (curr->next != NULL) {   // questo piccolo loop va in fondo alla lista
                curr = curr->next;
            }
        printf("debug - append - sono in fondo");
        curr->next = p;    // a quello che era l'ultimo elemento ne abbiamo appeso un altro
        }
        else {
            *headrif = p;
        }
        printf("debug - append - appeso", p->testo);
    }

    return p;   // magari ci farà comodo avere il puntatore all'ultimo elemento
}


int prova4(){
    // appendere

    struct Riga *head = NULL; // puntatore al primo elemento della lista

    struct Riga *p;           // puntatore all'ultimo elemento
    int r;

    p= appendRiga(&head, "ciao Alessia");

}


int main() {
    prova4();
}
