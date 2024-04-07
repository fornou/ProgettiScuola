from random import randint

def indovina_numero():
    rand, find = randint(1, 100), False

    for i in range(10) and find==True:

        a = int(input("prova a indovinare"))

        if a ==rand:
            print("bravo hai indovinato in {}".format(i))
            find = True
        elif a>rand:
            print("troppo grande\n")
        else:
            print("Troppo piccolo\n")
    
    print("non hai indovinato il numero era {}".format(rand))

indovina_numero()

    