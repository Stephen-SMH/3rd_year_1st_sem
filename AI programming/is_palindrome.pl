is_palindrome([]).
is_palindrome([_]).
is_palindrome(L) :- reverse(L,R).
reverse(L,R):- 
      reverse(L,[],R).
reverse(L,R):- 
      reverse([],A,A).
reverse([H|T],A,R):-
      reverse(T,[H|A],R).