/* pasticci con le struct

come compilare:
gcc struct.c -o struct.exe

cose da ricordare:
puntatore: variabile che invece di contenere un valore di qualche genere, contiene un indirizzo di memoria.

un articolo su struct e malloc - che poi è il vero problema
http://www.cs.toronto.edu/~heap/270F02/node31.html

typedef o non typedef per la struct ?  leggere qui:
https://stackoverflow.com/questions/18806392/typedef-struct-declarations
https://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions/


variabile.attributo o puntatore->attributo ?  leggere qui:
https://stackoverflow.com/questions/10036381/arrow-operator-vs-dot-operator
https://stackoverflow.com/questions/13366083/why-does-the-arrow-operator-in-c-exist

cosa farei io al tuo posto:
per prima cosa mi definirei una struct che mi raccolga l'input dell'utente (tutto quanto, magari sbaglio, non so, poi vedremo)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Riga {
    char* testo;        // attenzione che non punta a niente
    int tipo;           // qui ci scriverò se la riga è un comando oppure un testo, vedremo.
    struct Riga* next;  // ho in mente di fare una lista di questi elementi Riga
};


int prova1(){
    // giusto per prendere dimestichezza con la sintassi che non mi ricordo piu niente
    struct Riga r;  // dichiaro una variabile di tipo Riga
    r.tipo = 1;     // assegno qualcosa di semplice

    printf("%d\n", r.tipo);

    char ciao[] = "ciao Ale";

    r.testo = ciao;     // se non ricordo male ciao è un puntatore a un array di caratteri quindi r.testo = ciao è l'assegnamento di una variabile di tipo puntatore
                        // in altre parole ciao e r.testo sono due puntatori che puntano alla stessa zona di memoria

    printf("%s\n", r.testo);

    // e se modifico ciao cosa succede?
    ciao[4] = 33;  // ascii del punto esclamativo
    printf("%s\n", r.testo); // che infatti risulta modificato anche r.testo

    // so far so good
}

int prova2(){
    // quella di prima era una allocazione statica di una struct
    // ora proviamo una allocazione dinamica

    struct Riga *pr;  // puntatore a oggetto Riga

    //        +------------- cast al corretto tipo di puntatore
    //       |                          +----------------------- quanta memoria va allocata? tanta quanto è grosso un oggetto Riga
    //       V                          v
    pr = (struct Riga *) malloc(sizeof(struct Riga));

    printf("??? %i\n", pr->tipo);  // malloc non azzera gli elementi della struct (questo me lo ricordavo bene)

    pr->tipo = 10;
    printf("!!! %i\n", pr->tipo);
}

struct Riga * initRiga(char * testo){
    // vediamo di concentrare qui tutto il meccanismo di inizializzazione di un oggetto Riga

    struct Riga *p;

    // manca il controllo che malloc abbia allocato qualcosa
    // se malloc non ha allocato perchè ha finito la memoria p==NULL
    p = (struct Riga *) malloc(sizeof(struct Riga));

    p->testo = strdup(testo);  //rileggere le specifiche di strdup()
    p->tipo = 0;
    p->next = NULL;

    return p;
}



int prova3(){
    // come utilizzare initRiga
    struct Riga *pr;
    char tx[] = "ciao Alessia";
    pr = initRiga(tx);
    printf("prova initriga %i %s\n", pr->tipo, pr->testo);

}


/*
struct Riga *head = NULL; // puntatore al primo elemento della lista
*/

// giusto per vedere se compila

int main() {
    prova1();
    prova2();
    prova3();
}
