connection(boston, new_york).

connection(new_york, philadelphia).

connection(philadelphia, washington).

connection(washington, atlanta).

connection(washington, new_york).

connection(washington, san_francisco).

path(X, Y) :- connection(X, Y).

path(X, Y) :- connection(X, Z), path(Z, Y).