#!/usr/bin/python
# coding: iso-8859-1
"""
editor ED
"""


def main():
    uscita = False
    righeInput = []
    righeTesto = []
    righeComando = []

    while not uscita:
        riga = input(">>")
        righeInput.append(riga)

        if isComando(riga):
            righeComando.append(riga)
            if riga == 'q':
                uscita = True
            else:
                doComando(riga, righeComando, righeTesto)
        else:
            righeTesto.append(riga)
            print(riga)

    print("---- fine editing ----")
    print(righeTesto)

    return 0


def isComando(r):
    """comandi riconosciuti:
        q """

    if r == 'q':
        return True

    return False


def doComando(r, righeComando, righeTesto):
    """ effettua le opportune modifiche alla lista di testo in base ai comandi """
    pass


if __name__ == '__main__':
    main()
