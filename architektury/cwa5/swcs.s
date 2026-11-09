#################################################################
#
# Laboratorium 5.
# Switch-case-break, ABI, przekazanie argumentow,
# wywolanie funkcji z biblioteki standardowej jezyka C.
#
# Program ma wykonac wybrana operacje arytmetyczna oraz wyswietlic:
# jej nazwe, argumenty oraz wynik.
#
# Argumenty do programu nalezy przekazac jako parametry z linii komend:
#
# ./swcs arg1 arg2 nr_operacji

.globl	main

.section  .note.GNU-stack, "", @progbits

#################################################################
#
# Alokacja pamieci - zmienne statyczne z nadana wartoscia poczatkowa.

.data

str_add:	.asciz	"%u ADD %u = %u\n"
str_sub:	.asciz	"%u SUB %u = %u\n"
str_mul:	.asciz	"%u MUL %u = %lu\n"
str_div:	.asciz	"%u DIV %u = %u\n"
str_def:	.asciz	"DEFAULT\n"

arg_1:		.long	0
arg_2:		.long	0
result:		.long	0
case_no:	.long	0

# --- 2b ---
# Tablica skokow - adresow kolejnych sekcji switcha.
			#0	1	2	3
jump_table:	.quad	c_add,c_sub,c_mul,c_div

#################################################################
#
# program glowny

.text

main:

# W celu zachowania zgodnosci z ABI i funkcjami z GNU C Library
# wierzcholek stosu powinien byc wyrownany do granicy 16 bajtow
# (8-bajtowy adres powrotu + 8-bajtowa ramka stosu, ew. odkladanie
# na stos 16-bajtowych elementow).
# Ramki stosu nie tworzymy, wiec %rsp nalezy obnizyc o 8 bajtow.

sub	$8 , %rsp

# --- 1b --- Opcjonalnie:
#
# sprawdz, czy z linii komend przekazano trzy parametry,
# jesli nie - wyjdz (opcjonalnie zwracajac -1 w %eax).

# ...

#sprawdz czy argc (w edi) jest rowny 4:

cmp	$4, %edi
je	convert_argv


add	$8, %rsp 	#cofniecie wierzcholka stosu do dobrego miejsca
mov	$255, %eax	#zwroc wartosc wyjscia
ret



convert_argv:

# --- 1a --- Przekazywanie parametrow z linii komend.
#
# Konwertuj przekazane parametry (argv) z ciagu tekstowego na liczbe calkowita,
# np. jedna z funkcji biblioteki standardowej jezyka C (np. atoi, strtol).
mov	%rsi, %r14	#skopijuj rsi do rejestru ktory ma gwarancje zachowania danych
mov	8(%rsi) , %rdi
call	atoi
mov	%eax , arg_1

# Analogicznie konwersje kolejnych parametrow:

mov     16(%r14) , %rdi
call    atoi
mov     %eax , arg_2

mov     24(%r14) , %rdi
call    atoi

# --- 2a --- Switch - Case.
#
# Sprawdz, czy podany nr przypadku miesci sie w stablicowanym zakresie.

cmp	$3 , %eax
ja	c_def

# --- 2c ---
#
# Skok posredni - do adresu odczytanego z tablicy (do odpowiedniego przypadku).

jmp	*jump_table( , %eax, 8)


# W kazdym z przypadkow (oprocz default...) wykonaj odpowiednia operacje
# arytmetyczna oraz przekaz niezbedne argumenty do funkcji printf.

c_add:
mov	arg_1 , %esi
mov	arg_2 , %edx
mov	%edx , %ecx
add	%esi , %ecx
mov	$str_add , %rdi
jmp	brk

c_sub:
mov	arg_1 , %esi
mov	arg_2 , %edx
mov	%esi , %ecx
sub	%edx , %ecx
mov	$str_sub , %rdi
jmp	brk

c_mul:
mov	arg_1 , %eax
mov	%eax , %esi
mov	arg_2 , %ecx
mul	%ecx
shl	$32 , %rdx
or	%rax , %rdx
xchg	%rdx , %rcx
mov	$str_mul , %rdi
jmp	brk

c_div:
xor	%edx , %edx
mov	arg_1 , %eax
mov	%eax , %esi
mov	arg_2 , %ecx
or	%ecx , %ecx
jz	c_def
div	%ecx
mov	%eax , %edx
xchg	%edx , %ecx
mov	$str_div , %rdi
jmp	brk

c_def:
mov	$str_def , %rdi

brk:

# Czesc wspolna dla wszystkich przypadkow:
# wywolaj funkcje printf z uprzednio umieszczonymi w odpowiednich rejestrach (wg ABI):
# adresem ciagu, dwoma argumentami i wynikiem operacji.
# Nie sa uzywane typy zmiennoprzecinkowe i rejestry wektorowe (%xmm) wiec %eax=0.

xor	%eax , %eax
call	printf

# Przesun wskaznik stosu o 8 bajtow w gore aby "ret" prawidlowo sciagnal adres powrotu.

add	$8 , %rsp

# Powrot z main, zwroc w %eax kod bledu.
xor	%eax , %eax
ret

#################################################################

