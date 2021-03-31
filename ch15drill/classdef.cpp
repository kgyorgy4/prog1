/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "std_lib_facilities.h"

struct Person
{
	
private:
		string first_name;
		string second_name;
		int o_age;
public:
		Person(string firstname,string secondname,int age);
		Person(){};

		string get_firstname() const {return first_name;}
		string get_secondname()const {return second_name;}
		int get_age() const {return o_age;}
		
		void set_firstname(string firstname)
		{
			for(int i=0;i<firstname.length();i++)
			{
				if(!isalpha(firstname.at(i))) error("this name dosen't exist");
			}
			first_name=firstname;
		}
		void set_secondname(string secondname)
		{
			for(int i=0;i<secondname.length();i++)
			{
				if(!isalpha(secondname.at(i))) error("this name dosen't exist");
			}
			second_name=secondname;
		}
		void set_age(int age)
		{
			if (age<0 || age>150) error("unbelieveble age");
			else o_age=age;
		}
};

Person::Person(string firstname,string secondname,int age)
{
	set_firstname(firstname);
	set_secondname(secondname);
	set_age(age);
}

ostream& operator<<(ostream &o,Person p)
{
	return o<<p.get_firstname()<<" "<<p.get_secondname()<<": "<<p.get_age();
}

istream& operator>>(istream &i, Person &p)
{
	string tmp_firstname;
	string tmp_secondname;
	int tmp_age;
	i>>tmp_firstname>>tmp_secondname>>tmp_age;
	p.set_firstname(tmp_firstname);
	p.set_secondname(tmp_secondname);
	p.set_age(tmp_age);
	return i;
}

int main()
{
	
	Person Goofy;
	Goofy.set_firstname("Goofy");
	Goofy.set_age(63);

	cout<<Goofy<<endl;
	vector<Person> v;
	char quit;
	Person p;
	cout<<"input q to quit"<<endl;
	while(true)
	{
		cin>>quit;
		if(quit=='q') break;
		else
		{
			cin.putback(quit);
			cin>>p;
			v.push_back(p);
		}
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v.at(i)<<endl;
	}
}
