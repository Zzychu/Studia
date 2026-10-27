#ZADANIE 1


pigs = int(input("podaj ilosc swin: "))
cows = int(input("podaj liczbe krow: "))
chickens = int(input("podaj liczbe kur: "))

def animals(pigs, chickens, cows):
    suma = (pigs * 4) + (chickens * 2) + (cows * 4)
    return suma

print(animals(pigs, chickens, cows))

#ZADANIE 2

far = lambda stopnie: (stopnie * 1.8) + 32
print(far(float(input("Podaj tempertature w celsjuszach: "))))

#ZADANIE 3

from math import sqrt

def dodawanie(a,b):
    return a + b

def odejmowanie(a,b):
    return a - b

def mnozenie(a,b):
    return a*b

def dzielenie(a,b):
    if b == 0:
        return "Nie mozna dzielic przez zero"
    else:
        return a/b

def dzielcal(a,b):
    if b == 0:
        return "Nie mozna dzielic przez zero"
    else:
        return a // b

def reszta(a,b):
    return a % b

def potegowanie(a,b):
    if b == 0:
        return 1
    wynik = 1
    for i in range(0, b):
        wynik*=a
    if b > 0:
        return wynik
    if b < 0:
        return 1/wynik

import math

def pierwsum(a,b):
    if a+b < 0:
        return "nie mozna pierwiastkowac liczb ujemnych"
    else:
        return sqrt(a+b)

while True:
    liczba1 = int(input("podaj pierwsza liczbe: "))
    liczba2 = int(input("podaj druga liczbe: "))
    print("Dostepne operacje:\n1 - dodawanie\n2 - odejmowanie\n3 - mnozenie\n4 - dzielenie\n5 - dzielenie calkowite\n6 - reszta z dzielenia\n7 - potegowanie a przez b\n8 - pierwiastek sumy a+b")
    operacja = int(input("wybierz operacje: "))
    match operacja:
        case 1:
            print(dodawanie(liczba1, liczba2))
            continue
        case 2:
            print(odejmowanie(liczba1, liczba2))
        case 3:
            print(mnozenie(liczba1, liczba2))
        case 4:
            print(dzielenie(liczba1, liczba2))
        case 5:
            print(dzielcal(liczba1, liczba2))
        case 6:
            print(reszta(liczba1, liczba2))
        case 7:
            print(potegowanie(liczba1, liczba2))
        case 8:
            print(pierwsum(liczba1, liczba2))
        case 0:
            break
        case _:
            print("niepoprawna operacja")


#ZADANIE 4

import random


def losowanie():
    rand = random.randint(1,3)
    match rand:
        case 1:
            return "papier"
        case 2:
            return "kamien"
        case 3:
            return "nozyce"

# 1 - papier 2 - kamien 3 - nozyce

wynik = [0,0]
while True:
    print("aktualny wynik:\nCPU",wynik[0],"Player",wynik[1])
    #logika rundy
    cpu = losowanie()
    gracz = input("Wybierz (papier, kamien, nozyce, 0 - zakoncz: ")
    #pokazanie co wybiera komputer
    print("CPU:", cpu)
    if cpu == gracz:
        print("REMIS")
    elif cpu == "papier" and gracz == "kamien":
        print("KOMPUTER WYGRYWA")
        wynik[0]+=1
    elif cpu == "papier" and gracz == "nozyce":
        print("GRACZ WYGRYWA")
        wynik[1]+=1
    elif cpu == "kamien" and gracz == "nozyce":
        print("KOMPUTER WYGRYWA")
        wynik[0]+=1
    elif cpu == "kamien" and gracz == "papier":
        print("GRACZ WYGRYWA")
        wynik[1]+=1
    elif cpu == "nozyce" and gracz == "papier":
        print("KOMPUTER WYGRYWA")
        wynik[0]+=1
    elif cpu == "nozyce" and gracz == "kamien":
        print("GRACZ WYGRYWA")
        wynik[0]+=1
    elif  gracz == "0":
        print("ostateczy wynik:\nCPU",wynik[0],"Player",wynik[1])
        break
    else:
        print("NIEPOPRAWNA OPERACJA")