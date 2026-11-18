#zadanie 1
import csv
# n = int(input("do jakiej liczby wypisac tabliczke: "))
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

# from random import randint
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
# n = int(input("podaj liczbe wierzcholkow: "))
# m = int(input("podaj liczbe krawedzi: "))
#
# tablica_sasiedztwa = []
#
# for i in range(n):
#     temp = []
#     for j in range(n):
#         temp.append(0)
#     tablica_sasiedztwa.append(temp)
#
# for line in tablica_sasiedztwa:
#     print(line)
#
# tablica_krawedzi = []
#
# for i in range(m):
#     print(f"krawedz e{i}")
#     tablica_krawedzi.append([int(input("podaj numer pierwszego wierzcholka: ")), int(input("podaj numer drugiego wierzholka: "))])
#
# for krawedz in tablica_krawedzi:
#     tablica_sasiedztwa[krawedz[0]][krawedz[1]]=1
#     tablica_sasiedztwa[krawedz[1]][krawedz[0]]=1
#
# for line in tablica_sasiedztwa:
#     print(line)


#zadanie 4

n = 0
m = 0
with open("rozmiar.txt", "r") as file:
    for line in file:
        if int(line.strip()[0]) == 1:
            n = int(line.strip()[-1])
        if int(line.strip()[0]) == 2:
            m = int(line.strip()[-1])

print(n, m)

tablica_sasiedztwa = []

for i in range(n):
    temp = []
    for j in range(n):
        temp.append(0)
    tablica_sasiedztwa.append(temp)

for line in tablica_sasiedztwa:
    print(line)

tablica_krawedzi = []

for i in range(m):
    print(f"krawedz e{i}")
    tablica_krawedzi.append([int(input("podaj numer pierwszego wierzcholka: ")), int(input("podaj numer drugiego wierzholka: "))])

for krawedz in tablica_krawedzi:
    tablica_sasiedztwa[krawedz[0]][krawedz[1]]=1
    tablica_sasiedztwa[krawedz[1]][krawedz[0]]=1

for line in tablica_sasiedztwa:
    print(line)

#zadanie domowe

#csv

# from csv import DictReader, DictWriter
#
# with open("kraje.csv", "r", encoding="utf8", newline='') as file, \
#     open('output.csv', 'w', encoding='utf-8', newline='') as output:
#     reader = DictReader(file)
#     writer = DictWriter(output, fieldnames=reader.fieldnames)
#     print(reader.fieldnames)
#     for row in reader:
#         print(row)
#     for row in reader:
#         writer.writerow(row)

#json

# from json import load, dump
#
# with open("programming.json", "r") as input_file:
#     content = load(input_file)
#     print(content)
#     for lan in content.get('languages', []):
#         print(lan)
#
# programmin_lan = str(input("podaj nazwe"))
# date = int(input("podaj rok"))
# para = input("podaj pardygmaty").split(",")
# pop = int(input("podaj popularnosc"))
# stars = int(input("podaj gwiazdki"))
# content['languages'].append({
#     "name": programmin_lan,
#     "year_created": date,
#     "paradigm": para,
#     "popularity_index": pop,
#     "github_stars": stars
# })
#
# with open("programming2.json", "w") as output_file:
#     dump(content, output_file)

