child(mary,john).
child(lisa,mary).
child(kevin,lisa).

descendant(X,Y):- child(X,Y).
descendant(X,Y) :- child(X,Z),descendant(Z,Y).