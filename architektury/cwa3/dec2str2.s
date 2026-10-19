#################################################################
#
# Laboratorium 3. Konwersja liczby calkowitej bez znaku
# do postaci ciagu tekstowego (reprezentacja w systemie dziesietnym).

.globl _start

#################################################################
#
# Alokacja pamieci - zmienne statyczne, 8/16/32/64-bitowe,
# z nadana wartoscia poczatkowa.

.data

var8:	.byte	0b01011101
var16:	.word	0x6300
var32:	.long	0xFFFFFFFF
var64:	.quad	0xAB54A98EEE391EEA

#		"qqqqqqqqqqqqqqqqqqqq"
#		"..........llllllllll"
#		"...............wwwww"
#		".................bbb"
str:	.ascii	"...................."

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
# w %rdi (%edi) adres bufora (pozycji zapisu cyfry jednosci),
# opcjonalnie w %rcx (%ecx) liczbe konwertowanych cyfr (zaleznie od typu danych).

	mov 	var64, %rax
	mov	$newline-1, %rdi

# Wywolaj funkcje konwertujaca.

	call	convert_dec

# Wyswietl wynik (system_call nr 1).

	mov	$1 , %eax
	mov	$1 , %edi
	mov	$str , %rsi
	mov	$strlen , %edx
	syscall

# Zakoncz program (system_call nr 60).

	mov	$60 , %eax
	xor	%edi , %edi
	syscall

#################################################################
#
# Konwertuj wielobajtowy typ danych na ciag tekstowy
# (reprezentacja liczby w systemie dziesietnym).
# Argumenty: liczba w rejestrze %rax (ew. w jego czesci), adres zapisu w %rdi (%edi),
# ew. liczba bajtow do konwersji w %ecx.
#
# Zwracana wartosc: - (zapis w pamieci).
# Nadpisywane rejestry: ustalic.

convert_dec:
	mov	$10, %rbx	#dzielnik = 10
convert_loop:
	xor	%rdx, %rdx	# wyzeruj strsza polowe dzilenej mkod
	div	%rbx		# podaj dzielnik rax / rbx iloraz rax modulo rdx
	add	$48, %dl	# dodaj stala do najmlodszego byta dl
	mov	%dl, (%rdi)	# zapisz znak ascii do pamieci w adres trzymany w rdi
	dec	%rdi		# przesun adres miejsca zapisu na kolejna pozycje
	or	
	jnz	convert_loop
	ret

#################################################################
