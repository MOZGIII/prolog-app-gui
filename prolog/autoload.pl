% This is an example autoload.pl file

% Example of function suitable for external app call
external_app_call(X, Y) :-
	write_to_codes(X, XAsString),           % convert X term to string
	append("Called with: ", XAsString, L),  % concatenate strings for log
	log(L),                                 % log the string we've made
	sum_if_string(X, Y).                    % and call our function

% Implementation of the user function
sum_if_string(X, Y) :- number(X), Y is X + X, !.
sum_if_string(_, "not a  number").

% You could've load another file here with consult/1
% :- consult(filename).
