drawTree(S,L) :-
	S >= 10,
	A is S/2,
	H = [lt(90),fd(S)],
	TryLeft = [lt(30)],
	TryRight = [rt(60)],
	Goback = [lt(30),backward(S)],
	drawTree(A,Result,pass),
	append(H,TryLeft,S1),
	append(S1,Result,S2)	,
	append(S2,TryRight,S3),
	append(S3,Result,S4),
	append(S4,Goback,L).
drawTree(S,[],pass) :- S < 10.
drawTree(S,L,pass) :-
	S >= 10,
	A is S/2,
	H = [fd(S)],
	TryLeft = [lt(30)],
	TryRight = [rt(60)],
	Goback = [lt(30),backward(S)],
	drawTree(A,Result,pass),
	append(H,TryLeft,S1),
	append(S1,Result,S2)	,
	append(S2,TryRight,S3),
	append(S3,Result,S4),
	append(S4,Goback,L).

	

