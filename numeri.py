#!python3.6
# coding: iso-8859-1

"""cose che riguardano l'estetica di un numero
cioè come rendere il numero più leggibile da parte di un essere umano

riferimenti della funzione format:
https://www.w3schools.com/python/ref_string_format.asp

https://docs.python.org/3.7/library/string.html#formatstrings

interessante articolo sulla formattazione
https://realpython.com/python-string-formatting/

"""

c1 = 3
c2 = 0.1
x = c1 * c2

# risultato senza manipolazioni
print("x: ", x)
print( "tipo di x: ", type(x))
# chissà cosa ci fa quel 4 lì in fondo... bisognerà approfondire i concetti di come funziona un float
# ma per il momento facciamo finta di nulla

# questo funziona ma sembra non succedere nulla
print("format boh:", format(x))

# ma format?
print("cosa ottengo da format:", type(format(x)))

# format è un metodo della classe str
# e la maniera giusta di usarlo assomiglia un po' alla printf del C

res = "il mio risultato e' {}"
print("una strana stringa con le graffe:", res)

# bella roba, non serve a nulla

# aspetta...
print("riproviamo:",  res.format(x))

# cioè le graffe sono state sostituite dal numero che volevo stampare
# allora vediamo di migliorare l'estetica
res = "il mio risultato e' {:.2f}"
print("solo 2 decimali:",  res.format(x))

# ma che cosa c'è nelle graffe?
# nelle graffe c'è un piccolo microcosmo di simboli che permettono di cambiare l'aspetto di un numero o di una stringa

# un piccolo esempio:

prezzo = 2499.99

print("prezzo di un macbook: {:_}".format(prezzo))
