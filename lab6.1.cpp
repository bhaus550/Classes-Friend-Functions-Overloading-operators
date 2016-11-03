//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iomanip>
using namespace std;
void exercise1();
void exercise2();
class resource {
private:
	int status;
	int writeTo;
public:
	resource();
	resource(int);
	int getwriteTo();
	int getstatus();
	void setstatus(int);
	void setwriteTo(int);
	void output(ostream& out_stream);
	friend bool check_status(const resource& res1, const resource& res2);
};
class rational {
public:
	rational();
	rational (int n, int d);
	void input(istream& in);
	void output(ostream& out);
	void simplify();
	friend rational add(rational& r1, rational& r2);
	friend rational subtract(rational& r1, rational& r2);
	friend rational multiply(rational& r1, rational& r2);
	friend rational divide(rational& r1, rational& r2);
	friend bool equal(const rational& r1, const rational& r2);
	friend bool less_than(const rational& r1, const rational& r2);
private:
	int numerator;
	int denominator;
};
int gcd(int n1, int n2);

int main() {
	exercise1();
	exercise2();
	return 0;
}
void exercise1() {
	resource res1, res2, res3;
	cout << "res1\n";
	res1.output(cout);
	cout << "res2\n";
	res2.output(cout);
	cout << "res3\n";
	res3.output(cout);
	int i = 1, j = 1;
	cout << "change res2 and res3" << endl;
	res2.setstatus(i);
	res2.setwriteTo(i);
	res3.setstatus(j);
	res3.setwriteTo(j);
	cout << "new res2\n";
	res2.output(cout);
	cout << "new res3\n";
	res3.output(cout);
	cout << "check availability of res1 and res2\n";
	check_status(res1, res2);
	cout << "Check availability of res2 and res3\n";
	check_status(res2, res3);
}
resource::resource() :
		status(0), writeTo(0) {
}
int resource::getwriteTo() {
	return writeTo;
}
int resource::getstatus() {
	return status;
}
void resource::setstatus(int i) {
	status = i;
}
void resource::setwriteTo(int i) {
	writeTo = i;
}
void resource::output(ostream& out_stream) {
	cout << "status: " << status << ", writeTo: " << writeTo << endl;
}
bool check_status(const resource& res1, const resource& res2) {
	if (res1.status == 1 && res2.status == 1) {
		cout << "Resource available" << endl;
		return true;
	} else {
		cout << "Both resources are unavailable" << endl;
		return false;
	}
}
resource::resource(int i) {
	if (i > 1 || i < 0) {
		writeTo = 0;
	} else {
		writeTo = i;
	}
}
void exercise2() {
	rational r1, r2;
	r1.input(cin);
	r2.input(cin);
	cout << "r1 is ";
	r1.output(cout);
	cout<<endl;
	cout << "r2 is ";
	r2.output(cout);
		cout<<endl;
	cout << "The sum of the rational fractions is:\t";
	add(r1, r2).output(cout);
	cout << "\nThe difference between them is:\t";
	subtract(r1, r2).output(cout);
	cout << "\nThe product of them is:\t";
	multiply(r1, r2).output(cout);
	cout << "\nThe quotient of them is:\t";
	divide(r1, r2).output(cout);
	if (equal(r1, r2)) {
		cout << "\nThey are equal" << endl;
	} else {
		less_than(r1, r2);
	}
}
int gcd(int n1, int n2) { //gets the greatest common divisor of the numerator and denominator
	int temp;
	while (n2 != 0) {
		temp = n1;
		n1 = n2;
		n2 = temp % n2;
	}
	return abs(n1);
}
void rational::simplify() {
	int divisor = gcd(numerator, denominator);
	numerator = abs(numerator / divisor);
	denominator = abs(denominator / divisor);
}
void rational::input(istream& in) {
	int num, dom;
	cout << "Enter in the numerator followed by the denominator" << endl;
	cin >> num >> dom;
	numerator = num;
	if (dom == 0) {
		cout << "denominator cannot equal zero" << endl;
	} else {
		denominator = dom;
		simplify();
	}
}
void rational::output(ostream& out) {
	if (numerator == 0) {
		cout << 0 << endl;
	} else if (numerator == denominator) {
		cout <<1<< endl;
	} else {
		cout << numerator << "/" << denominator << endl;
	}
}
rational add(rational& r1, rational& r2) {
	int n = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
	int d = r1.denominator * r2.denominator;
	rational result(n, d);
	result.simplify();
	return result;
}
rational subtract(rational& r1, rational& r2) {
	int n = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
	int d = r1.denominator * r2.denominator;
	rational result(n, d);
	result.simplify();
	return result;
}

rational divide(rational& r1, rational& r2) {
	int n = r1.numerator * r2.denominator;
	int d = r1.denominator * r2.numerator;
	rational result(n, d);
	result.simplify();
	return result;
}
rational multiply(rational& r1, rational& r2) {
	int n = r1.numerator * r2.numerator;
	int d = r1.denominator * r2.denominator;
	rational result(n, d);
	result.simplify();
	return result;
}
bool equal(const rational& r1, const rational& r2) {
	int first = r1.numerator / r1.denominator;
	int second = r2.numerator / r2.denominator;
	if (first == second) {
		return true;
	} else {
		return false;
	}
}
bool less_than(const rational& r1, const rational& r2) {
	int first = r1.numerator / r1.denominator;
	int second = r2.numerator / r2.denominator;
	if (first < second) {
		cout << "r1 is less than r2" << endl;
	} else {
		cout << "r2 is less than r1" << endl;
	}
	return true;
}
rational::rational(int n, int d) {
	numerator = n;
	if (d == 0) {
		cout << "Denominator can't equal 0, please restart" << endl;
		exit(1);
	} else {
		denominator = d;
	}
}
rational::rational(): numerator(1), denominator(1){

}
/*
res1
status: 0, writeTo: 0
res2
status: 0, writeTo: 0
res3
status: 0, writeTo: 0
change res2 and res3
new res2
status: 1, writeTo: 1
new res3
status: 1, writeTo: 1
check availability of res1 and res2
Both resources are unavailable
Check availability of res2 and res3
Resource available
Enter in the numerator followed by the denominator
2
3
Enter in the numerator followed by the denominator
4
3
r1 is 2/3

r2 is 4/3

The sum of the rational fractions is:	2/1

The difference between them is:	2/3

The product of them is:	8/9

The quotient of them is:	1/2
r1 is less than r2*/
