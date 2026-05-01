% Base case: if the list is empty, return an empty list.
delete_all(_, [], []).

% If the head of the list is the element X, skip it and continue with the rest of the list.
delete_all(X, [X|T], L2) :- 
    !, delete_all(X, T, L2).

% If the head of the list is not X, keep it in the result and process the tail.
delete_all(X, [H|T], [H|L2]) :- 
    delete_all(X, T, L2).



