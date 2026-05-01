matches([
    match('TeamA', 'TeamB', 2, 1),
    match('TeamC', 'TeamD', 1, 1),
    match('TeamA', 'TeamC', 0, 2),
    match('TeamB', 'TeamD', 3, 3)
]).

points(Team1, Team2, Score1, Score2, Points1, Points2) :-
    (Score1 > Score2 -> Points1 = 3, Points2 = 0;
     Score1 < Score2 -> Points1 = 0, Points2 = 3;
     Score1 =:= Score2 -> Points1 = 1, Points2 = 1).

update_team_score(Team, Points, [], [(Team, Points)]).
update_team_score(Team, Points, [(Team, CurrentPoints)|Rest], [(Team, NewPoints)|Rest]) :-
    NewPoints is CurrentPoints + Points.
update_team_score(Team, Points, [OtherTeamScore|Rest], [OtherTeamScore|UpdatedRest]) :-
    OtherTeamScore = (OtherTeam, _),
    Team \= OtherTeam,
    update_team_score(Team, Points, Rest, UpdatedRest).

calculate_points([], AccumulatedScores, AccumulatedScores).
calculate_points([match(Team1, Team2, Score1, Score2)|Rest], AccumulatedScores, FinalScores) :-
    points(Team1, Team2, Score1, Score2, Points1, Points2),
    update_team_score(Team1, Points1, AccumulatedScores, UpdatedScores1),
    update_team_score(Team2, Points2, UpdatedScores1, UpdatedScores2),
    calculate_points(Rest, UpdatedScores2, FinalScores).

calculate_points(Matches, TeamsWithPoints):-
	calculate_points(Matches, [], TeamsWithPoints).
		

sort_teams(TeamwithPoints, SortedTeams) :-
	sort(2, @>=, TeamsWithPoints, SortedTeams).

main(SortedTeams, TeamsWithPoints):- 
	matches(Matches),
	calculate_points(Match, TeamsWithPoints).
	sort_teams(TeamsWithPoints,SortedTeams).