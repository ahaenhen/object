#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include"shuju.h"
using namespace std;

class Operator:public patient,public professor,public book {
public:
	map<string, patient>m1;
	map<string, professor>m2;
	map<string, book>m3;
	map<string, patient>::iterator it1;
	map<string, professor>::iterator it2;
	map<string, book>::iterator it3;
	void init();
	void readpatient();
	void readprofessor();
	void readbook();
	void save(string Num, string Name, int Age, int Gender);
	void save(string Num, string Name, string Direction, string Office, int Time);
	void save(string Panum, string Pronum, string Illness, string date);
	void del(char *Num, int x);
};

