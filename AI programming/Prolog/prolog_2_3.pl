connection(boston,new_york).
connection(new_york,philadelphia).
connection(philadelphia,washington).
connection(washington,atlanta).
connection(washington,new_york).

path(X,Y) :- path(X,Y,[]).

path(X,Y,Visited) :- 
    connection(X,Y), 
    \+ member(Y, Visited).

path(X,Y,Visited) :- 
    connection(X,Z), 
    Z \= Y, 
    \+ member(Z, Visited), 
    path(Z,Y,[X|Visited]).