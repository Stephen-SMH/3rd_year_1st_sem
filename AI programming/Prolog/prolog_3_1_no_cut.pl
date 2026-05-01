fib2(0, 0).
fib2(1, 1).

fib2(N,R):-
	N > 1,
	N1 is N-1, 
	fib2(N1,R1),
	N2 is N-2,
	fib2(N2,R2),
	R is R1+R2.