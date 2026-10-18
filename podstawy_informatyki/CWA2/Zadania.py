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

# # Petla wprowadzania
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

# Zadanie 4

# napis = input("Podaj napis: ").lower()
# if len(napis) < 3:
#     print("Za krotki napis")
# else:
#     dlugosc = len(napis)
#     print("dlugość:", dlugosc)
#     print("pierwszy znak:", napis[0])
#     print("ostatni znak:", napis[dlugosc - 1])
#     for i in range(0, dlugosc):
#         print(i, napis[i])
#     odwrot = ""
#     poprawne = 0
#     for i in range(dlugosc - 1, -1, -1):
#         odwrot = odwrot + napis[i]
#         if napis[i] == napis[dlugosc - 1 - i]:
#             poprawne += 1
#     print(odwrot)
#     if poprawne == dlugosc:
#         print("Słowo jest palindromem")
#     else:
#         print("Słowo nie jest palindromem")
#
#     samogloski = ('a', 'e', 'i', 'o', 'u', 'y', 'ą', 'ę', 'ó')
#     samogloski_liczba = 0
#     for i in napis:
#         for j in samogloski:
#             if i == j:
#                 samogloski_liczba += 1
#     print("Ilość samogłosek:", samogloski_liczba)

# ZADANIE 5 A

# poniedzialek = {"Anna", "Piotr", "Marta", "Jan", "Ewa"}
# sroda = {"Piotr", "Kasia", "Jan", "Tomek"}
#
# print("Wszyscy studenci:", poniedzialek | sroda)
# print("Tylko w poniedziałek:", poniedzialek.difference(sroda))  # poniedzialek - sroda
# print("w obu dniach:", poniedzialek.intersection(sroda))  # poniedzialek & sroda
# print("Tylko w jednym z dni:", (poniedzialek | sroda) - (poniedzialek & sroda))
#
# poniedzialek.add("Martyna")
# spoznieni = poniedzialek.copy()
# poniedzialek.discard("Piotr")
# print("Czy zbiory są rozłączne:", poniedzialek.isdisjoint(spoznieni))

# ZADANIE 5 B

oceny = {"Anna": 5, "Piotr": 3, "Marta": 4}
oceny.update({"Martyna": 5})
oceny.update({"Piotr": 2})

suma_ocen = 0
for i in oceny:
    print(i, oceny.get(i))
    suma_ocen += oceny.get(i)
print("Srednia ocen", suma_ocen / len(oceny))
imie = input("Podaj imie: ")
if oceny.get(imie) == None:
    print("Nie ma takiego studena")
else:
    print("Ocena:", oceny.get(imie))
