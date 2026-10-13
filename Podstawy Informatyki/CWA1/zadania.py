
# ZADANIE 1

print("kreator wizytówek")

imie = input("podaj imie: ")
nazwisko = input("podaj nazwisko: ")
#zapisanie dlugosci jednej linijki uwzgledniajac spacje pomiedzy slowami
len_i_n = len(imie) + len(nazwisko) + 1
nazwa_firmy = input("podaj nazwe firmy: ")
stanowisko = input("podaj stanowisko: ")
len_nf_s = len(nazwa_firmy) + len(stanowisko) + 1
tel = input("podaj numer telefonu: ")
email = input("podaj email: ")
len_t_e = len(tel) + len(email) + 1
maxlen = max(len_i_n, len_nf_s, len_t_e)
print(maxlen)


print("#" * (maxlen + 4))
print("# " + imie + " " + nazwisko + ((" ") * (maxlen - len_i_n)) + " #")
print("# " + nazwa_firmy + " " + stanowisko + ((" ") * (maxlen - len_nf_s)) + " #")
print("# " + tel + " " + email + ((" ") * (maxlen - len_t_e)) + " #")
print("#" * (maxlen + 4))

# ZADANIE 2

print("kreator hasel")
haslo = input("podaj nowe haslo: ")
if input("podaj hasło: ") == haslo:
   x = 18
   y = 21
   answ = x + y
   print("ile to", x, "+", y, "?")
   if int(input("odp: ")) == answ:
       print("Zalogowano pomyslnie")
   else:
       print("niepoprawna odpowiedz, bład logowania")
else:
   print("błędne hasło")


# ZADANIE 3

print("sprawdzanie wieku")
data = input("podaj date urodzenia (dd.mm.yyyy): ")
#rozdzielanie odpowiedzi na poszczegolne czesci daty i zamiana na int
day = int(data.split(".")[0])
month = int(data.split(".")[1])
year = int(data.split(".")[2])
#porownywanie daty uwzgledniajac kazdy z czlonow daty dla dnia 8.10.2026
if year < 2008:
    print("nie masz 18 lat")
elif (year == 2008) & (month < 10):
    print("nie masz 18 lat")
elif year == 2008 & month == 10 & day < 8:
    print("nie masz 18 lat")
else:
    print("Masz 18 lat")