is_palindrome([]).
is_palindrome([_]).
is_palindrome(L) :-
    reverse(L, L).

reverse(L, R) :-
    reverse_helper(L, [], R).


reverse_helper([], A, A).     % base case for reverse_helper - when the list is empty, the accumulator is the reverse list 
reverse_helper([H|T], A, R) :-
    reverse_helper(T, [H|A], R). % recursive case for reverse_helper - add the head of the list to the accumulator and call reverse_helper with the tail of the list
