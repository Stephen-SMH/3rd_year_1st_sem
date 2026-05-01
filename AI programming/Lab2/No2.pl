child(Mary, John).
child(Lisa, Mary).
child(Kevin, Lisa).

descendant(X, Y) :- child(X, Y).
descendant(X, Z) :- child(X, Y), descendant(Y, Z).