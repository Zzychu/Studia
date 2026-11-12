#zadanie 1
from random import randint

#n = int(input("do jakiej liczby wypisac tabliczke: "))
#
# tabliczka = []
# for i in range(n):
#     wiersz = []
#     for j in range(n):
#         wiersz.append((i+1)*(j+1))
#     tabliczka.append(wiersz)
#
# for line in tabliczka:
#     print(line)
#
# with open("tabliczka.txt", "w") as file:
#     for line in tabliczka:
#         file.write(str(line) + "\n")

#zadanie 2


# tablica_losowa = []
# for i in range(3):
#     wiersz = []
#     for j in range(3):
#         wiersz.append(randint(0,100))
#     tablica_losowa.append(wiersz)
#
# for line in tablica_losowa:
#     print(line)
#
#
# suma = 0
# maks = 0
#
# for i in range(3):
#     for j in range(3):
#         if tablica_losowa[i][j] > maks:
#             maks = tablica_losowa[i][j]
#         suma = suma+tablica_losowa[i][j]
#
# print("maks", maks, "suma", suma)
#
# for i in range(3):
#     for j in range(3):
#         if j == i:
#             tablica_losowa[i][j] = 1
#         else:
#             tablica_losowa[i][j] = 0
#
# for line in tablica_losowa:
#     print(line)


#zadanie 3

n = int(input("podaj liczbe wierzcholkow: "))
m = int(input("podaj liczbe krawedzi: "))

tablica_sasiedztwa = [[0] * n] * n

print(tablica_sasiedztwa)

tablica_krawedzi = []

for i in range(m):
    print("krawedz e")
    tablica_krawedzi.append([int(input("podaj numer pierwszego wierzcholka: ")), int(input("podaj numer drugiego wierzholka: "))])