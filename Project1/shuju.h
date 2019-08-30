#include<graphics.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;

class patient{
private:
	string num, name;
	int age, gender;
public:
	patient() {
		num = "b";
		name = "a";
		age = 0;
		gender = 0;
	}
	patient(string s, string ss, int a, int g) {
		num = s;
		name = ss;
		age = a;
		gender = g;
	}

	string getnum() { return num; }
	string getname() { return name; }
	int getage() { return age; }
	int getgender() { return gender; }
	void save(string Num, string Name, int Age, int Gender){}
	
	friend istream &operator>>(istream &in, patient &x) {
		in >> x.num >> x.name >> x.age >> x.gender;
		return in;
	}
	
	friend ostream &operator<<(ostream &out, const patient &x)
	{
		out << x.num << " " << x.name << " " << x.age << " " << x.gender;
		return out;
	}
};

class professor {
private:
	string num, name, direction, office;
	int time;
public:
	professor() {
		name = "s";
		num = "ss";
		direction = "d";
		office = "o";
		time = 0;
	}
	professor(string s, string ss, string d, string o, int t) {
		name = s;
		num = ss;
		direction = d;
		office = o;
		time = t;
	}

	string getnum() { return num; }
	string getname() { return name; }
	string getdirection() { return direction; }
	string getoffice() { return office; }
	int gettime() { return time; }
	void save(string Num, string Name, string Direction, string Office, int Time){}

	friend istream &operator>>(istream &in, professor &x) {
		in >> x.num >> x.name >> x.direction >> x.office >> x.time;
		return in;
	}

	friend ostream &operator<<(ostream &output, const professor &x) {
		output << x.num << " " << x.name << " " << x.direction << ' ' << x.office << " " << x.time;
		return output;
	}
};
class book {
private:
	string panum, pronum, illness, date;
public:
	book() { panum = "s"; pronum = "ss"; illness = "sss"; }
	book(string s, string ss, string sss, string d) { panum = s; pronum = ss; illness = sss; date = d; }
	string getpanum() { return panum; }
	string getpronum() { return pronum; }
	string getillness() { return illness; }
	string getdate() { return date; }
	void save(string Panum, string Pronum, string Illness, string date){}
	friend istream &operator>>(istream &in, book &x) {
		in >> x.panum >> x.pronum >> x.illness >> x.date;
		return in;
	}

	friend ostream &operator<<(ostream &output, const book &x) {
		output << x.panum << " " << x.pronum << " " << x.illness << " " << x.date;
		return output;
	}
};
