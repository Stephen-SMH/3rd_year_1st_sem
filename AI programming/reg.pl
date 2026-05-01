% Facts

% student(Student, Year_of_study, Study_Program).
student(alice, 1, computer_science).
student(bob, 2, computer_science).
student(carol, 1, computer_science).
student(dave, 3, computer_science).
student(eve, 2, mathematics).

% course(Course, Year_of_study, Program).
course(intro_to_cs, 1, computer_science).
course(data_structures, 2, computer_science).
course(algorithms, 3, computer_science).
course(calculus, 1, mathematics).
course(linear_algebra, 2, mathematics).

% completed(Student, Course).
completed(alice, intro_to_cs).
completed(bob, intro_to_cs).
completed(bob, data_structures).
completed(dave, intro_to_cs).
completed(dave, data_structures).
completed(dave, algorithms).
completed(eve, calculus).

% requires(CourseA, CourseB).
requires(data_structures, intro_to_cs).
requires(algorithms, data_structures).


% rules

% X can take course Y if X is a student and Y is a course and X has not completed Y
can_enroll(Student, Course) :- 
      student(Student, Y, A), 
      course(Course, Y, A), 
      (
            requires(Course, B),
            completed(Student, B);
            not(requires(Course, _))
      ),
      not(completed(Student, Course)).

% X is a classmate of Y if X and Y are students and X is not Y
classmate(X, Y) :- 
      student(X, A, _), 
      student(Y, B, _), 
      A == B,
      X \= Y.