#!python3.6
# coding: iso-8859-1

"""
cose che riguardano i numeri in quanto tali

"""

c1 = 3
c2 = 3.14
c3 = 7

# queste funzioni lavorano direttamente sui numeri
# il risultato cioè è un numero

# le operazioni aritmetiche, ovvio
x = c1 * c2
y = c3 / c1

print("x:", x)
print("y:", y)

# e altre un po' più sofisticate

z = abs(-45)   # valore assoluto
k = int(c2)   # troncamento dei decimali
q = c3 // c1   # quoziente intero
r = c3 % c1   # resto della divisione intera

print(z, k, r)

# però possiamo anche stampare meglio
print("valore assoluto: {}   parte intera {}  quoziente intero {}    resto della divisione intera {}".format(z, k, q, r))

# per capire la divisione intera, utilissima in un mucchio di situazioni:
p = 15  # pizzette
be = 6  # bambini educati
print("pizzette mangiate da ogni bambino {}    pizzette avanzate {}".format(p // be, p % be))

# arrotondamento
y = round(c3/c1, 3)
print("arrotondamento a tre decimali: ", y)

y = round(c3/c1, 12)
print("arrotondamento a dodici decimali: ", y)

# infine un piccolo assaggio delle insidie che si nascondono nei numeri in virgola mobile
# non è colpa del python. lo stesso problema lo avresti con C, C++, VisualBasic, ...
# ha a che fare con il numero delle cifre significative della mantissa

print( 0.3 * 0.7)
print( 0.4 * 0.4)
print( 0.7 * 0.7)

