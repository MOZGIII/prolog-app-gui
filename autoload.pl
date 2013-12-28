% Load prolog code
external_app_call(X, D, Y) :-
	write_to_codes(X, XAsString),
	write_to_codes(D, DAsString),
	append(" d ", DAsString, E1),
	append(XAsString, E1, E),
	append("Called with: ", E, L),
	log(L),
	append(E, "</font></b>", P1),
	append("<hr><b><font color=\"blue\">", P1, P),
	payload(P),
	integrate(X, d(D), Y).

% Load prolog code
:- consult(integration/integration).
