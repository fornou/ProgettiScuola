from math import sqrt


def es1():
    verifica=True
    somma = 0

    while verifica==True:
        a = int(input("valore a\n"))

        somma += a
        
        if somma >= 100:
            verifica = False

def es2():
    scelta = input("valore scelta\n")

    match scelta:

        case "first" :
            a = int(input("valore altezza iniziale\n"))
            b = int(input("valore distanza in km\n"))

            while b>0:
                
                a/=2
                print(a +" è l'altezza al km "+b+" dell'onda\n")
                b-=1

            print(a +" è l'altezza finale dell'onda\n")
        case "second":

            a = int(input("valore altezza iniziale\n"))
            while a>1:
                a/=2
                cont+=1
            print(cont +" è il numero di km fatti dall'onda\n")

        case  "exit":
            return 0
        case _ :
            print("Undefined value\n")

   

def es3():
    a = int(input("valore massa\n"))
    b = int(input("valore millenni\n"))

    for i in range(b):
                
        a/=2
        print(a +" è la massa al millennio {}\n".format(i))     

    print(a +" è la massa finale del materiale\n")

def es4():
    verifica=True
    k = input("valore k\n")

    while verifica==True:
        a = int(input("valore a\n"))
        b = int(input("valore b\n"))

        if a*b==k: 
            verifica = False

def es5():


    a = int(input("lato a\n"))
    b = int(input("lato b\n"))
    c = int(input("lato c\n"))

    if a<(b+c) and a>(b-c) or b<(a+c) and b>(a-c) or c<(b+a) and c>(b-a):
        print("è un triangolo e ")

        p = a + b + c
        s = p*(p-a)(p-b)*(p-c)
        s = sqrt(s)
    
    print("l'area è "+s)




def scelta():

    inizia = "si"

    while inizia == "si":

        scelta = input("valore scelta\nfirst\nsecond\nthird\nfourth\nfifth\nexit\n")

        match scelta:

            case "first" :
                es1()
            case "second":
                es2()
            case "third":
                es3()
            case "fourth":
                es4()
            case "fifth":
                es5()
            case  "exit":
                return 0
            case _ :
                print("Undefined value")
            


scelta()