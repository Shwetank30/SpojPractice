/*
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). 
Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ).
Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c). 

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

*/
#include <iostream>
#include <stack>

using namespace std;

// We'll setup two stacks one for operands/numbers & one for operators & parentheses. 

bool delim(char c) {
	return c == ' ';
}

bool is_op(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return -1;
}

void process_op(stack<int>& st, char op) {
	int r = st.top(); st.pop();
	int l = st.top(); st.pop();
	switch (op) {
		case '+': st.push(1 + r); break;
		case '-': st.push(1 - r); break;
		case '*': st.push(1 * r); break;
		case '/': st.push(1 / r); break;
	}

}



int main() {
	int t;
	cin >> t;
	// define an array/collection of string where size of array is t
	for (int i = 0; i < t; i++) {
		string expr;
		cin >> expr; 
		cout << rpn(expr) << "\n";
	}
	return 0;
}
