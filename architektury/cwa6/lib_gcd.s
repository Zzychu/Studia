.section  .note.GNU-stack, "", @progbits

.globl gcd

.text

.type	gcd,@function

gcd:
sub	$8 , %rsp

# Zabezpiecz odpowiednie rejestry przed nadpisaniem
# i wywolaj print_call.

push	%rsi
push	%rdi
call	print_call
pop	%rdi
pop	%rsi

# Algorytm Euklidesa:
#	a = esi 
# unsigned int GCD(unsigned int a, unsigned int b) 
# { 
#   if (b==0) return a; 
#   else GCD(b, a % b); 
# } 

# ...

# a = edi	b = esi 	wybik eax

or	%esi, %esi	#czy b = 0?
#jz	return_gcd

xor	%edx, %edx
mov	%edi, %eax
#div	%esi
mov	%esi,%edi
mov	%edx,%esi

call	gcd

return_gcd:

# Zabezpiecz odpowiednie rejestry przed nadpisaniem
# i wywolaj print_ret.

push	%rsi
push	%rdi
call 	print_ret
pop	%rdi
pop	%rsi

# Zwroc obliczona wartosc w %eax.

mov	%edi, %eax	#zwroc a w eax

add	$8 , %rsp
ret

