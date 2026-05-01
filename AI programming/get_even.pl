% Base case: if the input list L1 is empty, the result list L2 is also empty.
get_even([], []).

% Recursive case: if the head of the list is an even number, keep it in the result list.
get_even([H|T], [H|L2]) :- 
    H mod 2 =:= 0,     % Check if H is even (H mod 2 equals 0).
    get_even(T, L2).   % Recursively process the tail.

% Recursive case: if the head of the list is not an even number, skip it.
get_even([H|T], L2) :- 
    H mod 2 =\= 0,     % Check if H is not even (H mod 2 is not equal to 0).
    get_even(T, L2).   % Recursively process the tail.
