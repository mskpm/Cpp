#include <iostream>
#include "point.hpp"
#include "segment.hpp"
#include "vector.hpp"

using namespace std;

void show_counter(point &);

void test_point();
void test_segment();
void test_vector();
void test_virtual_functions();

int main(int argc, char *argv[])
{
	ignore=argc;
	ignore=argv;

	// test_point();
	//test_segment();
	 test_vector();
	//test_virtual_functions();

	return 0;
}

void show_counter(point &obj)
{
	cout << obj.get_id() << "\n";
}

///////////////////////////////////////////////////////////////////////////
// Test functions
///////////////////////////////////////////////////////////////////////////


void test_point()
{
	cout << "Test of points" << endl;

	cout << "Konstruktor point(double,double)" << endl;
	point punkt1{1.1, 1.1};
	point punkt2{2.2, 2.2};
	cout << "punkt1: " << punkt1 << endl;
	cout << "punkt2: " << punkt2 << endl;

	cout << "Konstruktor kopiujacy point(punkt2)" << endl;
	point punkt3{punkt2};
	cout << "punkt3" << punkt3 << endl;


	cout << "unique_ptr punkt3 = punkt1 + punkt2" << endl;
	unique_ptr<point> punkt4(punkt1 + punkt2);
	cout << "punkt4 = punkt1+punkt2: " << *punkt4 << endl;

	cout << "Operator= punkt2=punkt1" << endl;
	punkt2 = punkt1;
	cout << punkt1 << endl;
	cout << punkt2 << endl;
	cout << *punkt4 << endl;

	cout << "Kontruktor point(double, double)" << endl;

	point punkt5{5.5, 5.5};
	cout << punkt5 << endl;
}

void test_segment()
{
	cout << "Test of segments" << endl;

	point punkt1{1.1, 1.1};
	point punkt2{2.2, 2.2};
	cout << punkt1 << punkt2 << endl;

	segment ab(punkt1, punkt2);
	cout << "segment ab" << ab << endl;
	segment cd = ab;
	cout << "segment cd=ab: " << cd << endl;

	cout << "ab dim: " << ab.dim() << endl;
}

void test_vector()
{
	cout << "Test of vectors" << endl;

	point punkt1{1.1, 1.1};
	point punkt3{3.3, 3.3};
	cout << punkt1 << endl;
	cout << punkt3 << endl;

	vector u{punkt1, punkt3};
	cout << "vector u [punkt1, punkt3]: ";
	u.show();

	vector *u_ptr = &u;
	cout << "u_ptr: ";
	vector::show(u_ptr);

	cout << "Test vector functions" << endl;

	cout << "u angle (rad): " << u.getAngleRad() << "\n";
	cout << "u angle (deg): " << u.getAngleDeg() << "\n";
	cout << "u magnitude: " << u.getMagnitude() << "\n";

	vector v{1, 0};
	vector z{-2, 2};

	cout << v << endl;
	cout << z << endl;

	cout << v.getMagnitude() << endl;
	cout << z.getMagnitude() << endl;

	cout << "angle between u,v: ";
	cout << v.getAngle2vectors(z) << endl;

	cout <<"(unique_ptr) vector x = v + z" << endl;
	unique_ptr<vector> x{v + z};
	cout << *x << endl;
	vector s{*x};
	cout << "vector from unique_ptr: s{*x}" << endl;
	cout << s << endl;
}

void test_virtual_functions()
{
	cout << "Test of virtual functions -> show_counter()" << endl;
	point punkt3{3.0,3.0};
	cout << punkt3 << ": ";
	show_counter(punkt3);
	
	segment ab{5.0,5.0};
	cout << ab << ": ";
	show_counter(ab);

	vector z{-2.0, 2.0};
	vector u{-2.0, 2.0};

	cout << z << endl;
	cout << u << endl;
	
	show_counter(z);
	show_counter(u);
}