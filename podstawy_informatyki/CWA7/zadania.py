#zadanie 1

# liczba = ord(input("podaj znak: "))
# if (liczba>=33 and liczba<=47) or (liczba>=58 and liczba<=64) or (liczba>=91 and liczba<=96) or (liczba>=123 and liczba<=126):
#     print("znak specjalny")
# if liczba>=48 and liczba<=57:
#     print("cyfra")
# if liczba>=65 and liczba<=90:
#     print("duza litera")
# if liczba>=97 and liczba<=122:
#     print("mala litera")

#zadanie 3

import math

def toBin(liczba, system):
    wynik = ''
    if system == "d":
        liczba=int(liczba)
        while(liczba>0):
            if liczba%2==0:
                wynik="0" +wynik
            else:
                wynik="1"+wynik
            liczba=liczba//2
    elif system == "o":
        wynik = ''
        for znak in liczba:
            for i in range(3 - len(toBin(znak, "d"))):
                wynik=wynik+"0"
            wynik = wynik+toBin(znak, "d")
    elif system == "h":
        wynik = ''
        for znak in liczba:
            match znak:
                case "A":
                    znak=10
                case "B":
                    znak=11
                case "C":
                    znak=12
                case "D":
                    znak=13
                case "E":
                    znak=14
                case "F":
                    znak=15
                case _:
                    znak=znak
            for i in range(4 - len(toBin(znak, "d"))):
                wynik = wynik + "0"
            wynik = wynik + toBin(znak, "d")
    return wynik
def toDec(liczba, system):
    wynik = 0
    potega = 0
    if system=="b":
        for i in range(len(liczba) - 1,-1,-1):
            wynik=wynik+(int(liczba[i])*int(math.pow(2, potega)))
            potega+=1
    if system=="o":
        wynik = toDec(toBin(liczba, "o"), "b")
    if system=="h":
        wynik = toDec(toBin(liczba, "h"), "b")
    return wynik
def toOct(liczba, system):
    wynik = ''
    if system=="b":
        tablica_trojek = []
        #pelne trojki od tylu
        counter = 0
        for i in range(len(liczba), 0, -3):
            tablica_trojek.append(liczba[i-3:i])
            counter+=1
        #usuniecie pustego elementu
        tablica_trojek.pop()
        counter-=1
        #resztki z poczatku
        resztka = ''
        for i in range(3 - (len(liczba) - 3*counter)):
            resztka = "0"+resztka
        for i in  range((len(liczba) - 3*counter)):
            resztka = resztka+liczba[i]
        tablica_trojek.append(resztka)
        for each in tablica_trojek:
            wynik=str(toDec(each, "b"))+wynik
    elif system == "d":
        wynik = toOct(toBin(liczba, "d"), "b")
    elif system == "h":
        wynik = toOct(toBin(liczba, "h"), "b")
    return wynik
def toHex(liczba, system):
    wynik = ''
    if system=="b":
        tablica_czw = []
        #pelne czworek od tylu
        counter = 0
        for i in range(len(liczba), 0, -4):
            tablica_czw.append(liczba[i-4:i])
            counter+=1
        #usuniecie pustego elementu
        tablica_czw.pop()
        counter-=1
        #resztki z poczatku
        resztka = ''
        for i in range(4 - (len(liczba) - 4*counter)):
            resztka = "0"+resztka
        for i in  range((len(liczba) - 4*counter)):
            resztka = resztka+liczba[i]
        tablica_czw.append(resztka)
        for each in tablica_czw:
            znak = toDec(each, "b")
            match znak:
                case 10:
                    znak="A"
                case 11:
                    znak="B"
                case 12:
                    znak="C"
                case 13:
                    znak="D"
                case 14:
                    znak="E"
                case 15:
                    znak="F"
                case _:
                    znak=znak
            wynik=str(znak)+wynik
    elif system == "d":
        wynik = toHex(toBin(liczba, "d"), "b")
    elif system == "o":
        wynik = toHex(toBin(liczba, "o"), "b")
    return wynik


system = input("podaj system liczby (b, o, d, h): ")
liczba = input("wpisz liczbe")
conv = input("podaj na co przekonwertowac (b, o, d, h): ")
if system == conv:
    print("liczba jest juz w tym systemie")
else:
    match conv:
        case "b":
            print(toBin(liczba, system))
        case "d":
            print(toDec(liczba, system))
        case "o":
            print(toOct(liczba, system))
        case "h":
            print(toHex(liczba, system))
