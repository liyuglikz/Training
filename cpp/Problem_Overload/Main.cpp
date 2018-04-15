#include <bits/stdc++.h>

class Student
{
	public:
		Student(const char *s = "stu");
		Student( const Student &k);
		Student operator = ( const Student &k);
		char name[32];
};

Student::Student(const char *s)
{
	if( s )
		strcpy( this->name, s );
	std::cout << "0. Constuctor " << this->name << std::endl;
}

Student::Student( const Student &k)
{
	strcpy( this->name, k.name);
	strcat( this->name, " copied");
	std::cout << "0.1 Member copy function " << this->name << std::endl;
}

Student Student::operator = ( const Student &k)
{
	std::cout << "0.2 overload operator " << this->name << std::endl;
}

int main()
{
	Student a("Alpha"), b("Bravo");

	Student c = a;	//
	Student d(b) ;

	b = a;	//

	return 0;
}
