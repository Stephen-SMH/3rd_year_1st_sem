% Facts
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

parent(john, mary).
parent(john, sue).
parent(helen, mary).
parent(helen, sue).
parent(oliver, james).
parent(sophie, james).
parent(mary, jack).
parent(ali, jack).
parent(sue, harry).
parent(james, harry).

% Rules

% X is the father of Y if X is male and parent of Y
father(X, Y) :- male(X), parent(X, Y).

% X is the mother of Y if X is female and parent of Y
mother(X, Y) :- female(X), parent(X, Y).

% X is grandparent of Y if X is parent of Z and Z is parent of Y
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% X is a grandfather of Y if X is male and grandparent of Y
grandfather(X, Y) :- male(X), grandparent(X, Y).

% X is a grandmother of Y if X is female and grandparent of Y
grandmother(X, Y) :- female(X), grandparent(X, Y).

% X is a sister of Y if X is female and X and Y are siblings
sister(X, Y)      :- female(X), sibling(X, Y).

% X is a brother of Y if X is male and X and Y are siblings
brother(X, Y)     :- male(X), sibling(X, Y).

% X and Y are siblings if they share at least one parent
sibling(X, Y) :- parent(P, X), parent(P, Y), X \= Y.

% X is a uncle of Y if X is a male and X is a sibling of Z and Z is a parent of Y
uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).

% X is a aunt of Y if X is a female and X is a sibling of Z and Z is a parent
aunt(X, Y)  :- female(X), sibling(X, Z), parent(Z, Y).

% Test Queries
% ?- father(john, mary).
% ?- mother(helen, sue).
% ?- sibling(mary, sue).
% ?- grandparent(helen, jack).
