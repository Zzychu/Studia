# zadanie 1

# rok = int(input("podaj rok: "))
#
# if (rok % 4 == 0 and rok % 100 != 0) or rok % 400 == 0:
#     print("rok jest przestepny")
# else:
#     print("rok nie jest przestepny")

# zadanie 2

# dzien = input("podaj numer dnia: ")
# match dzien:
#     case "1":
#         print("poniedzialek")
#     case "2":
#         print("wtorek")
#     case "3":
#         print("Sroda")
#     case "4":
#         print("Czwartek")
#     case "5":
#         print("Piatek")
#     case "6":
#         print("sobota")
#     case "7":
#         print("Niedziela")
#     case _:
#         print("To nie jest dzien tygodnia")

# Zadanie 3

# Petla wprowadzania
# lista = []
# while True:
#     liczba = int(input("wpisz liczbe calkowita: "))
#     if liczba == 0:
#         if len(lista) == 0:
#             print("nie podano zadnej liczby dodatniej")
#             break
#         # Dlugosc listy
#
#         print("ilosc liczb:", len(lista))
#
#         # suma i srednia
#
#         suma = 0
#         for i in lista:
#             suma += i
#         srednia = suma / len(lista)
#         print("Suma:", suma, "Srednia:", srednia)
#
#         # Liczenie parzystych
#
#         parzyste = 0
#         for i in lista:
#             if i % 2 == 0:
#                 parzyste += 1
#
#         print("ilosc liczb parzystych:", parzyste)
#
#         # sortowanie max min i roznica
#
#         lista.sort(reverse=True)
#         print("posortowana malejaco: ", lista)
#         print("Najwieksza:", max(lista))  # albo lista.sort(reverse=True)[0]
#         print("Najmniejsza", min(lista))  # albo lista.sort()[0]
#         print("Roznica najwiekszej od najmniejszej:", (max(lista) - min(lista)))
#         break
#     elif liczba > 0:
#         lista.append(liczba)
#     elif liczba < 0:
#         print("Liczba ujemna, nie dodano do listy")
#

# Zadanie 4

napis = input("Podaj napis")
if len(napis) < 3:
    print("Za krotki napis")
else:
    
