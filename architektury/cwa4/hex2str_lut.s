#################################################################
#
# Laboratorium 4. Konwersja liczby calkowitej bez znaku
# do postaci ciagu tekstowego (reprezentacja w systemie szesnastkowym).

.globl _start

#################################################################
#
# Alokacja pamieci - zmienne statyczne, 8/16/32/64-bitowe,
# z nadana wartoscia poczatkowa.

.data

# en.wikipedia.org/wiki/Hexspeak
# en.wikipedia.org/wiki/Magic_number_(programming)

var8:	.byte	237
var16:	.word	11181
var32:	.long	3735929054
var64:	.quad	18369614221190020847

#		"qqqqqqqqqqqqqqqqh"
#		"........llllllllh"
#		"............wwwwh"
#		"..............bbh"
str:	.ascii	"................h"

newline:.byte	0x0A

.equ	strlen, newline+1 - str

#################################################################
#
# Program glowny.

 .text

_start:

	xor	%eax , %eax	# %rax = 0

# Przekaz tylko niezbedne argumenty do funkcji konwertujacej,
# przykladowo:
# w %rax (ew. w jego czesci) liczbe podlegajaca konwersji,
# w %rdi (%edi) adres bufora - pozycji zapisu reprezentacji pierwszego bajtu,
# opcjonalnie w %rcx (%ecx) rozmiar konwertowanego typu danych w bajtach: (1),2,4,8.


mov  var64, %rax
mov $newline-3, %rdi #nie wiem czemu -3 ale chyba dlatego ze -1 dla new line poprostu i -2 dla 1 znaku czyli 2 bajtow
#mov $8, %rcx


#	...

# Wywolaj funkcje konwertujaca.

	call	convert	

# Wyswietl wynik (system_call nr 1).

	mov	$1 , %eax
	mov	%eax , %edi
	mov	$str , %rsi
	mov	$strlen,%edx
	syscall

# Zakoncz program (system_call nr 60).

	mov	$60,%eax
	xor	%edi,%edi
	syscall

#################################################################
#
# Zadanie --- 3 ---
#
# Konwertuj wielobajtowy typ danych w oparciu o Lookup Table
# (plik lut16bit.s).
#
# Argumenty:
# liczba w rejestrze %rax (ew. w jego czesci),
# adres zapisu w %rdi (%edi),
# ew. liczba bajtow do konwersji w %ecx.
#
# Zwracana wartosc: - (zapis w pamieci).
# Nadpisywane rejestry: ustalic.

convert:

	mov %rax, %rdx # kopia rax w rdx
	and $0xff, %rdx # and bitwise zeby wyciagnac tylko najmlodszy bajt z 64 (zerujemy pierwsze 56 bity) (0xff maska)
	mov lut16bit(, %rdx, 2), %dx	#pobranie 2 znaki ASCII z adresu lutbit16 + 2*rdx i zapisz w 16 bitowym rejestrze dx
	#teraz zapisz z dx w adress w rdi
	mov	%dx, (%rdi)
	sub	$2, %rdi # rdi = rdi - 2 miejsce adress kolejnego zapisu
	shr	$8, %rax # przesuniecie o 8 bitow w prawo ciagu rax
	jnz	convert


	ret

#################################################################
