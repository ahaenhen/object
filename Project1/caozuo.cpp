#include"caozuo.h"

void Operator::init(){ m1.clear(); m2.clear(); m3.clear(); }
void Operator::readpatient() {
	ifstream infile;
	infile.open("E:\\vs\\c++\\homework\\Project1\\Project1\\patient.txt", ios::in);
	patient temp;
	if (!infile) { cout << "Error!读取文件失败！\n"; }
	else {
		while (infile >> temp) {
			m1.insert(make_pair(temp.getnum(), temp));
		}
	}
	infile.close();
}

void Operator::save(string Num, string Name, int Age, int Gender) {
	patient t(Num, Name, Age, Gender);
	m1.insert(make_pair(Num, t));
	ofstream outfile;
	outfile.open("E:\\vs\\c++\\homework\\Project1\\Project1\\patient.txt", ios::app);
	if (!outfile) { cout << "Error!保存文件失败！\n"; }
	else {
		outfile << t.getnum() << " " << t.getname() << " " << t.getage() << ' ' << t.getgender() << endl;
	}
	outfile.close();
}

void Operator::readprofessor() {
	ifstream infile;
	infile.open("E:\\vs\\c++\\homework\\Project1\\Project1\\professor.txt", ios::in);
	professor temp;
	if (!infile) { cout << "Error!读取文件失败！\n"; }
	else {
		while (infile >> temp) {
			m2.insert(make_pair(temp.getnum(), temp));
		}
	}
	infile.close();
}

void Operator::save(string Num, string Name, string Direction, string Office, int Time) {
	professor t(Name, Num, Direction, Office, Time);
	m2.insert(make_pair(Num, t));
	ofstream outfile;
	outfile.open("E:\\vs\\c++\\homework\\Project1\\Project1\\professor.txt", ios::app);
	if (!outfile) { cout << "Error!保存文件失败！\n"; }
	else {
		outfile << t.getnum() << " " << t.getname() << " " << t.getdirection() << ' ' << t.getoffice() << ' ' << t.gettime() << endl;
	}
	outfile.close();
}

void Operator::readbook() {
	ifstream infile;
	infile.open("E:\\vs\\c++\\homework\\Project1\\Project1\\book.txt", ios::in);
	book temp;
	if (!infile) { cout << "Error!读取文件失败！\n"; }
	else {
		while (infile >> temp) {
			m3.insert(make_pair(temp.getpanum(), temp));
		}
	}
	infile.close();
}

void Operator::save(string Panum, string Pronum, string Illness, string date) {
	book t(Panum, Pronum, Illness, date);
	m3.insert(make_pair(Panum, t));
	ofstream outfile;
	outfile.open("E:\\vs\\c++\\homework\\Project1\\Project1\\book.txt", ios::app);
	if (!outfile) { cout << "Error!保存文件失败！\n"; }
	else {
		outfile << Panum << " " << Pronum << " " << Illness << ' ' << date << endl;
	}
	outfile.close();
}

void Operator::del(char *Num, int x) {
	int id = atoi(Num);
	ifstream in;
	if (x == 1)in.open("E:\\vs\\c++\\homework\\Project1\\Project1\\patient.txt", ios::in);
	else if (x == 2)in.open("E:\\vs\\c++\\homework\\Project1\\Project1\\professor.txt", ios::in);
	else if (x == 3)in.open("E:\\vs\\c++\\homework\\Project1\\Project1\\book.txt", ios::in);
	if (!in.is_open())cout << "file open error" << endl;
	else {
		string temp;
		stringstream ss;
		int curId;;
		while (in.peek() != EOF) {
			string line;
			getline(in, line);
			ss << line; ss >> curId;
			if (curId != id)temp += line + "\n";
			ss.str(""); ss.clear();
		}
		in.close();
		ofstream out;
		if (x == 1)out.open("E:\\vs\\c++\\homework\\Project1\\Project1\\patient.txt", ios::out);
		else if (x == 2)out.open("E:\\vs\\c++\\homework\\Project1\\Project1\\professor.txt", ios::out);
		else if (x == 3)out.open("E:\\vs\\c++\\homework\\Project1\\Project1\\book.txt", ios::out);
		if (!out.is_open())cout << "file open error" << endl;
		else {
			out << temp;
			out.close();
		}
	}

}