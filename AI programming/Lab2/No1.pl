% Base case: The sum of an empty list is 0.
sum_list([], 0).

% Recursive case: Sum the head of the list with the sum of the tail.
sum_list([Head|Tail], Sum) :-
    sum_list(Tail, SumTail),     % Recursively sum the tail of the list
    Sum is Head + SumTail.       % Add the head to the sum of the tail
