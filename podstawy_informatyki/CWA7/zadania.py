#zadanie 1

liczba = ord(input("podaj znak: "))
if (liczba>=33 and liczba<=47) or (liczba>=58 and liczba<=64) or (liczba>=91 and liczba<=96) or (liczba>=123 and liczba<=126):
    print("znak specjalny")
if liczba>=48 and liczba<=57:
    print("cyfra")
if liczba>=65 and liczba<=90:
    print("duza litera")
if liczba>=97 and liczba<=122:
    print("mala litera")

#zadanie 3

system = input("podaj system liczby (b, o, d, h): ")
liczba = input("wpisz liczbe")
conv = input("podaj na co przekonwertowac (b, o, d, h): ")
match liczba:
    case "b":
        print(toBin(liczba))
    case "d":
        print(toBin(liczba))
    case "b":
        print(toBin(liczba))
    case "b":
        print(toBin(liczba))
