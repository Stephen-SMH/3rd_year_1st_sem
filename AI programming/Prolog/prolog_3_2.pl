has_factor(N,K) :-
	K * K =< N,
	V is N mod K,
	0  == V.
has_factor(N,K) :-
	K * K =< N,
	K1 is K + 1,
	has_factor(N,K1).
is_prime(2).
is_prime(N) :-
	N > 2,
	\+ has_factor(N,2).