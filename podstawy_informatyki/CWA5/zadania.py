#zadanie 1

def negacja(a):
    return not a

def koniunkcja(a, b):
    return (a and b)

def alternatywa(a, b):
    return (a or b)

def implikacja(a,b):
    if a == True and b == False:
        return False
    else:
        return True

def rownowaznosc(a,b):
    if a == b:
        return True
    else:
        return False

poprawne = True

a = input("Podaj wartosc a (0, 1): ")
match a:
    case "0":
        a = False
    case "1":
        a = True
    case _:
        print("to nie jest 0 albo 1")
        poprawne = False
b = input("Podaj wartosc b (0, 1): ")



match b:
    case "0":
        b = False
    case "1":
        b = True
    case _:
        print("to nie jest 0 albo 1")
        poprawne = False

if poprawne:
    print("negacja: ", negacja(a), negacja(b))
    print("koniunkcja: ", koniunkcja(a,b))
    print("alternatywa: ", alternatywa(a, b))
    print("implikacja: ", implikacja(a, b))
    print("równoważnosc: ", rownowaznosc(a, b))

# ZADANIE 2

p = True
q = True
r = False

print("1", koniunkcja(p, q))
print("2", alternatywa(p, q))
print("3", koniunkcja(negacja(p), alternatywa(p, q)))
print("4", implikacja(koniunkcja(p,r),q))
print("5", negacja(rownowaznosc(p, alternatywa(q, r))))
print("6", rownowaznosc(alternatywa(implikacja(p,r), negacja(q)),implikacja(p,koniunkcja(r, negacja(q)))))
print("7", implikacja(alternatywa(alternatywa(negacja(r),q),negacja(koniunkcja(q,r))), negacja(implikacja(q,p))))

#ZADANIE 3

lista = [0,1,2,3,4,56,7,8,9,19]
a = int(input("Podaj liczbe calkowita: "))
if a in lista:
    print("Nalezy do listy")
if a not in lista:
    print("nie nalezy do listy")

#ZADANIE 4

koszyk1 = ["chleb", "mleko", "jajka"]
koszyk2 = koszyk1
koszyk3 = ["chleb", "mleko", "jajka"]

print("koszyk1 == koszyk2", koszyk1 == koszyk2)
print("koszyk1 == koszyk3", koszyk1 == koszyk3)
print("koszyk2 == koszyk3", koszyk2 == koszyk3)
print("koszyk1 is koszyk2", koszyk1 is koszyk2)
print("koszyk1 is koszyk3", koszyk1 is koszyk3)
print("koszyk2 is koszyk3", koszyk2 is koszyk3)

koszyk2.append("woda")

print(koszyk1, koszyk2, koszyk3)

