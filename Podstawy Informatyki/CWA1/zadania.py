
# ZADANIE 1

print("kreator wizytówek")

#imie = input("podaj imie: ")
#nazwisko = input("podaj nazwisko: ")
#nazwa_firmy = input("podaj nazwe firmy: ")
#stanowisko = input("podaj stanowisko: ")
#tel = input("podaj numer telefonu: ")
#email = input("podaj email: ")

#print("=================================================================")
#print(imie, nazwisko)
#print(nazwa_firmy, stanowisko)
#print(tel, email)
#print("=================================================================")

# ZADANIE 2

#print("kreator hasel")
#haslo = input("podaj nowe haslo: ")
#if input("podaj hasło: ") == haslo:
#    x = 10
#    y = 21
#    answ = x + y
#    print("ile to", x, "+", y, "?")
#    if int(input("odp: ")) == answ:
#        print("Zalogowano pomyslnie")
#    else:
#        print("niepoprawna odpowiedz, bład logowania")
#else:
#    print("błędne hasło")


# ZADANIE 3

print("sprawdzanie wieku")
data = input("podaj date urodzenia (dd.mm.yyyy): ")
print(data.split("."))
#print(data.contains("/"))
day = int(data.split(".")[0])
month = int(data.split(".")[1])
year = int(data.split(".")[2])
if year < 2008:
    print("nie masz 18 lat")
elif (year == 2008) & (month < 10):
    print("nie masz 18 lat")
elif year == 2008 & month == 10 & day < 8:
    print("nie masz 18 lat")
else:
    print("Masz 18 lat")