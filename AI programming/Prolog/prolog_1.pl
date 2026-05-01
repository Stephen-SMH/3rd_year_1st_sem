male(john).
male(oliver).
male(ali).
male(james).
male(jack).
male(harry).

female(helen).
female(sophie).
female(mary).
female(sue).

parent(john,mary).
parent(john,sue).
parent(helen,mary).
parent(helen,sue).
parent(oliver,james).
parent(sophie,james).
parent(mary,jack).
parent(ali,jack).
parent(sue,harry).
parent(james,harry).

father(X,Y) :- parent(X,Y), male(X).
mother(X,Y) :- parent(X,Y), female(X).
grandfather(X,Y) :- father(X,Z), parent(Z,Y).
grandmother(X,Y) :- mother(X,Z), parent(Z,Y).

sibling(X,Y) :- X\=Y, parent(Z,X), parent(Z,Y).
sister(X,Y) :- female(X), sibling(X,Y).
brother(X,Y) :- male(X), sibling(X,Y).
uncle(X,Y) :- brother(Z,X), parent(Z,Y).
aunt(X,Y) :- sister(Z,X), parent(Z,Y).



%father(john, mary).
%father(john, sue).
%mother(helen, mary).
%mother(helen, sue).
%father(oliver, james).
%mother(sophie, james).
%mother(mary, jack).
%father(ali, jack).
%mother(sue, harry).
%father(james, harry).

%grandfather(john, jack).
%grandmother(helen, jack).
%grandfather(oliver, harry).
%grandmother(sophie, harry).
