rzymskie = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"]
arab = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
wynik = []

def odpowiednik(liczba):
    for i in range(len(arab) - 1,-1,-1):
        while liczba-arab[i]>=0:
            liczba-=arab[i]
            wynik.append(rzymskie[i])
    return wynik


odpowiednik(1994)
print("".join(wynik))
