#include"caozuo.h"
using namespace std;
IMAGE beijing,bingren;
MOUSEMSG msg;

class Menu {
public:
	Operator op;
	int flag = 0;
	void welcome() {
		initgraph(700, 700);
		cleardevice();
		settextcolor(RGB(255, 255, 255));
		settextstyle(100, 0, "Taco Salad");
		setbkmode(TRANSPARENT);
		settextcolor(RGB(0, 0, 255)); 
		loadimage(&beijing, "E:\\vs\\c++\\homework\\Project1\\Project1\\yiyuanpicture\\beijing.jpg", 700, 700);
		putimage(0, 0, &beijing);
		outtextxy(100, 200, "ҽԺ����ϵͳ");
		while (1) {
			msg = GetMouseMsg();
			if (msg.x >= 490 && msg.x <= 650 && msg.y >= 500 && msg.y <= 550) {
				settextcolor(RGB(47, 10, 227));
				outtextxy(490, 500, "�������롷");
			}
			else {
				settextcolor(RGB(47, 169, 227));
				settextstyle(30, 0, "Tacao Salad");
				outtextxy(490, 500, "�������롷");
			}
			switch (msg.uMsg) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 490 && msg.x <= 650 && msg.y >= 500 && msg.y <= 550) {
					return;
				}break;
			default:break;
			}
		}
	}
	void selectmenu(){
		op.readpatient();
		op.readprofessor();
		op.readbook();
	umenu:
		setbkcolor(RGB(255, 255, 255));
		cleardevice();
		settextstyle(40, 0, "Taco Salad");
		while (1) {
			msg = GetMouseMsg();
			if (msg.x >= 250 && msg.x <= 450 && msg.y >= 100 && msg.y <= 150){
				settextcolor(RGB(47, 10, 227));
				outtextxy(280, 100, "�˳�ϵͳ");
			}
			else if (msg.x >= 250 && msg.x <= 450 && msg.y >= 200 && msg.y <= 250) {
				settextcolor(RGB(47, 10, 227));
				outtextxy(250, 200, "������Ϣ����");
			}
			else if (msg.x >= 250 && msg.x <= 450 && msg.y >= 300 && msg.y <= 350) {
				settextcolor(RGB(47, 10, 227));
				outtextxy(250, 300, "ר����Ϣ����");
			}
			else if (msg.x >= 250 && msg.x <= 450 && msg.y >= 400 && msg.y <= 450) {
				settextcolor(RGB(47, 10, 227));
				outtextxy(250, 400, "ԤԼ��Ϣ����");
			}
			else {
				settextcolor(RGB(47, 169, 227));
				outtextxy(280, 100, "�˳�ϵͳ");
				outtextxy(250, 200, "������Ϣ����");
				outtextxy(250, 300, "ר����Ϣ����");
				outtextxy(250, 400, "ԤԼ��Ϣ����");
			}
			switch (msg.uMsg) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 280 && msg.x <= 430 && msg.y >= 100 && msg.y <= 150)exit(0);
				else if (msg.x >= 250 && msg.x <= 450 && msg.y >= 200 && msg.y <= 250) {
					patientmsg();
					if (flag)goto umenu;
				}
				else if (msg.x >= 250 && msg.x <= 450 && msg.y >= 300 && msg.y <= 350) {
					professormsg();
					if (flag)goto umenu;
				}
				else if (msg.x >= 250 && msg.x <=450 && msg.y >= 400 && msg.y <= 450) {
					bookmsg();
					if (flag)goto umenu;
				}
				break;
			default: break;
			}
		}
	}
	void patientmsg() {
		pmsg:
		setbkcolor(RGB(255, 255, 255));
		cleardevice();
		settextcolor(RGB(47, 169, 227));
		settextstyle(100, 0, "Taco Salad");
		outtextxy(150, 100, "������Ϣ����");
		loadimage(&beijing, "E:\\vs\\c++\\homework\\Project1\\Project1\\yiyuanpicture\\bingren.jpg",700,700);
		while (1) {
			settextstyle(50, 0, "Taco Salad");
			msg = GetMouseMsg();
			if (msg.x >= 270 && msg.x <= 430 && msg.y >= 300 && msg.y <= 350){
				settextcolor(RGB(47, 10, 227));
				outtextxy(270, 300, "��Ϣ��ѯ");
			}
			else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 400 && msg.y <= 450) {
				settextcolor(RGB(47, 10, 227));
				outtextxy(270, 400, "��Ϣ���");
			}
			else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 500 && msg.y <= 550) {
				settextcolor(RGB(47, 10, 227));
				outtextxy(270, 500, "��Ϣɾ��");
			}
			else if (msg.x >= 1 && msg.x <= 80 && msg.y >= 1 && msg.y <= 51) {
				settextcolor(RGB(47, 10, 227));
				settextstyle(30, 0, "Taco Salad");
				outtextxy(1, 1, "�� ����");
			}
			else {
				settextcolor(RGB(47, 169, 227));
				settextstyle(30, 0, "Taco Salad");
				outtextxy(1, 1, "�� ����");
				settextstyle(50, 0, "Taco Salad");
				outtextxy(270, 300, "��Ϣ��ѯ");
				outtextxy(270, 400, "��Ϣ���");
				outtextxy(270, 500, "��Ϣɾ��");
			}
			switch (msg.uMsg) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 270 && msg.x <= 430 && msg.y >= 300 && msg.y <= 350) {
					char s[10];
				shuru:
					InputBox(s, 10, "�����벡�˱��");
					for (int i = 0; i < strlen(s); i++) {
						if ((s[i] - '0') > 9 || s[i] < '0'){
							cleardevice();
							outtextxy(100, 1, "�����ʽ�������ٴ����룡");
							goto shuru;
						}
					}
					cleardevice();
					map<string, patient>::iterator it = op.m1.find(s);
					if (it == op.m1.end())outtextxy(300, 200, "���޴��ˣ�");
					else{
						char num[10] = { '\0' }, name[10] = { '\0' }, age[10], gender[10];
						patient t = it->second;
						string s = t.getnum(), ss = t.getname();
						int a = t.getage(), g = t.getgender();
						_stprintf_s(age, _T("%d"), a);
						_stprintf_s(gender, _T("%d"), g);
						for (int i = 0;s[i]!='\0'; i++)num[i] = s[i];
						for (int i = 0; ss[i] != '\0'; i++)name[i] = ss[i];
						putimage(0, 0, &beijing);
						settextstyle(40, 0, "����");
						outtextxy(400, 200, num); outtextxy(400, 325, name);
						outtextxy(400, 450, age); outtextxy(400, 575, gender);
						while (1) {
							msg = GetMouseMsg();
							if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
								settextcolor(RGB(47, 10, 227));
								outtextxy(1, 1, "�� ����");
							}
							else { settextstyle(30, 0, "Taco Salad"); settextcolor(RGB(47, 169, 227)); outtextxy(1, 1, "�� ����"); }
							switch (msg.uMsg) {
							case WM_LBUTTONDOWN:
								if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
									goto pmsg;
								}
								break;
							default: break;
							}
						}
					}
				}
				else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 400 && msg.y <= 450) {
					char s[10]; string num, name; int age, gender;
				shuru2:
					InputBox(s, 10, "������Ԥ��ӵĲ��˱��");
					for (int i = 0; i < strlen(s); i++) {
						if ((s[i] - '0') > 9 || s[i] < '0') {
							cleardevice();
							outtextxy(100, 1, "�����ʽ�������ٴ����룡");
							goto shuru2;
						}
					}
					if (op.m1.find(s) != op.m1.end()) { 
						cleardevice();
						outtextxy(100, 1, "�ñ���Ѵ���,���������룡");
						goto shuru2;
					}
					num = s;
					cleardevice();
				shuru3:
					InputBox(s, 10, "������Ԥ��ӵĲ�������(���ģ�");
					for (int i = 0; i < strlen(s); i++) {
						if (!((s[i - 1] & 0x80) && (s[i] & 0x80))) {
							cleardevice();
							outtextxy(100, 1, "�����ʽ�������ٴ����룡");
							goto shuru3;
						}
					}
					name = s;
					cleardevice();
				shuru4:
					InputBox(s, 10, "������Ԥ��ӵĲ�������");
					for (int i = 0; i < strlen(s); i++) {
						if ((s[i] - '0') > 9 || s[i] < '0') {
							cleardevice();
							outtextxy(100, 1, "�����ʽ�������ٴ����룡");
							goto shuru4;
						}
					}
					age = atoi(s);
					cleardevice();
				shuru5:
					InputBox(s, 10, "������Ԥ��ӵĲ����Ա�Ů1��2");
					if ((s[0] != '1' || s[0] != '2') && s[1] != '\0') {
						cleardevice();
						outtextxy(100, 1, "�����ʽ�������ٴ����룡");
						goto shuru5;
					}
					gender = atoi(s);
					cleardevice();
					op.save(num, name, age, gender);
					outtextxy(200, 200, "�ѳɹ�¼��");
					Sleep(600);
					goto pmsg;
				}
				else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 500 && msg.y <= 550) {
					char s[10];
					InputBox(s, 10, "������ɾ���Ĳ��˱��!");
					for (int i = 0; i < strlen(s); i++) {
						if ((s[i] - '0') > 9 || s[i] < '0'){
							cleardevice();
							outtextxy(100, 1, "�����ʽ�������ٴ����룡");
							goto shuru;
						}
					}
					cleardevice();
					if(op.m1.find(s)==op.m1.end())outtextxy(200, 200, "�޴����޷�����");
					else {
						op.m1.erase(s);
						op.del(s,1);
						outtextxy(200, 200, "�ѳɹ�ɾ��");
					}
					Sleep(600);
					goto pmsg;
				}
				else if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
					flag = 1; return;
				}
				break;
			default: break;
				}
			}
		}
		void professormsg() {
		pmsg:
			setbkcolor(RGB(255, 255, 255));
			cleardevice();
			settextcolor(RGB(47, 169, 227));
			settextstyle(100, 0, "Taco Salad");
			outtextxy(150, 100, "ר����Ϣ����");
			loadimage(&beijing, "E:\\vs\\c++\\homework\\Project1\\Project1\\yiyuanpicture\\zhuanjia.jpg", 700, 700);
			while (1) {
				settextstyle(50, 0, "Taco Salad");
				MOUSEMSG msg = GetMouseMsg();
				if (msg.x >= 270 && msg.x <= 430 && msg.y >= 300 && msg.y <= 350) {
					settextcolor(RGB(47, 10, 227));
					outtextxy(270, 300, "��Ϣ��ѯ");
				}
				else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 400 && msg.y <= 450) {
					settextcolor(RGB(47, 10, 227));
					outtextxy(270, 400, "��Ϣ���");
				}
				else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 500 && msg.y <= 550) {
					settextcolor(RGB(47, 10, 227));
					outtextxy(270, 500, "��Ϣɾ��");
				}
				else if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
					settextcolor(RGB(47, 10, 227));
					settextstyle(30, 0, "Taco Salad");
					outtextxy(1, 1, "�� ����");
				}
				else {
					settextcolor(RGB(47, 169, 227));
					settextstyle(30, 0, "Taco Salad");
					outtextxy(1, 1, "�� ����");
					settextstyle(50, 0, "Taco Salad");
					outtextxy(270, 300, "��Ϣ��ѯ");
					outtextxy(270, 400, "��Ϣ���");
					outtextxy(270, 500, "��Ϣɾ��");
				}
				switch (msg.uMsg){
				case WM_LBUTTONDOWN:
					if (msg.x >= 270 && msg.x <= 430 && msg.y >= 300 && msg.y <= 350) {
						char s[10];
					shuru:
						InputBox(s, 10, "������ר�ұ��!");
						for (int i = 0; i < strlen(s); i++) {
							if ((s[i] - '0') > 9 || s[i] < '0') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru;
							}
						}
						cleardevice();
						op.readprofessor();
						map<string, professor>::iterator it = op.m2.find(s);
						if (it == op.m2.end())outtextxy(300, 200, "���޴��ˣ�");
						else {
							char num[10] = { '\0' }, name[10] = { '\0' }, dir[20] = { '\0' }, o[20] = { '\0' },g[10];
							professor t = it->second;
							string s = t.getnum(), ss = t.getname(), sss = t.getdirection(), ssss = t.getoffice();
							int gender= t.gettime();
							_stprintf_s(g, _T("%d"), gender);
							for (int i = 0; s[i] != '\0'; i++)num[i] = s[i];
							for (int i = 0; ss[i] != '\0'; i++)name[i] = ss[i];
							for (int i = 0; sss[i] != '\0'; i++)dir[i] = sss[i];
							for (int i = 0; ssss[i] != '\0'; i++)o[i] = ssss[i];
							putimage(0, 0, &beijing);
							settextstyle(30, 0, "����");
							outtextxy(400, 200, num); outtextxy(400, 300, name);
							outtextxy(400, 400, dir); outtextxy(400, 500, o); outtextxy(400, 600, g);
							while (1) {
								msg = GetMouseMsg();
								if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
									settextcolor(RGB(47, 10, 227));
									outtextxy(1, 1, "�� ����");
								}
								else { settextstyle(30, 0, "Taco Salad"); settextcolor(RGB(47, 169, 227)); outtextxy(1, 1, "�� ����"); }
								switch (msg.uMsg) {
								case WM_LBUTTONDOWN:
									if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
										goto pmsg;
									}
									break;
								default: break;
								}
							}
						}
					}
					else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 400 && msg.y <= 450) {
						char s[10]; string num, name,dir,office; int time;
					shuru2:
						InputBox(s, 10, "������Ԥ��ӵ�ר�ұ��");
						for (int i = 0; i < strlen(s); i++) {
							if ((s[i] - '0') > 9 || s[i] < '0') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru2;
							}
						}
						if (op.m2.find(s) != op.m2.end()) {
							cleardevice();
							outtextxy(100, 1, "�ñ���Ѵ���,���������룡");
							goto shuru2;
						}
						num = s;
						cleardevice();
					shuru3:
						InputBox(s, 10, "������Ԥ��ӵ�ר������(���ģ�");
						for (int i = 0; i < strlen(s); i++) {
							if (!((s[i - 1] & 0x80) && (s[i] & 0x80))) {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru3;
							}
						}
						name = s;
						cleardevice();
					shuru4:
						InputBox(s, 10, "������Ԥ��ӵ�ר����������");
						for (int i = 0; i < strlen(s); i++) {
							if (!((s[i - 1] & 0x80) && (s[i] & 0x80))) {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru4;
							}
						}
						dir = s;
						cleardevice();
					shuru5:
						InputBox(s, 10, "������Ԥ��ӵ�ר�ҿ���");
						for (int i = 0; i < strlen(s); i++) {
							if (!((s[i - 1] & 0x80) && (s[i] & 0x80))) {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru5;
							}
						}
						office = s;
						cleardevice();
					shuru6:
						InputBox(s, 10, "������Ԥ��ӵ�ר�ҹ���");
						for (int i = 0; i < strlen(s); i++) {
							if ((s[i] - '0') > 9 || s[i] < '0') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru6;
							}
						}
						time = atoi(s);
						cleardevice();
						op.save(num,name,dir,office,time);
						outtextxy(200, 200, "�ѳɹ�¼��");
						Sleep(600);
						goto pmsg;
					}
					else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 500 && msg.y <= 550) {
						char s[10];
						InputBox(s, 10, "������ɾ����ר�ұ��!");
						for (int i = 0; i < strlen(s); i++) {
							if ((s[i] - '0') > 9 || s[i] < '0') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru;
							}
						}
						cleardevice();
						if (op.m2.find(s) == op.m2.end())outtextxy(200, 200, "�޴����޷�����");
						else {
							op.m2.erase(s);
							op.del(s,2);
							outtextxy(200, 200, "�ѳɹ�ɾ��");
						}
						Sleep(600);
						goto pmsg;
					}
					else if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51){
						flag = 1; return;
					}
					break;
				default: break;
				}
			}
		}
		void bookmsg() {
		bmsg:
			setbkcolor(RGB(255, 255, 255));
			cleardevice();
			settextcolor(RGB(47, 169, 227));
			settextstyle(100, 0, "Taco Salad");
			outtextxy(150, 100, "ԤԼ��Ϣ����");
			loadimage(&beijing, "E:\\vs\\c++\\homework\\Project1\\Project1\\yiyuanpicture\\yuyue.jpg", 700, 700);
			while (1){
				settextstyle(50, 0, "Taco Salad");
				MOUSEMSG msg = GetMouseMsg();
				if (msg.x >= 270 && msg.x <= 430 && msg.y >= 300 && msg.y <= 350) {
					settextcolor(RGB(47, 10, 227));
					outtextxy(270, 300, "��Ϣ��ѯ");
				}
				else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 400 && msg.y <= 450) {
					settextcolor(RGB(47, 10, 227));
					outtextxy(270, 400, "��Ϣ���");
				}
				else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 500 && msg.y <= 550) {
					settextcolor(RGB(47, 10, 227));
					outtextxy(270, 500, "��Ϣɾ��");
				}
				else if (msg.x >= 1 && msg.x <= 50 && msg.y >= 1 && msg.y <= 51) {
					settextcolor(RGB(47, 10, 227));
					settextstyle(30, 0, "Taco Salad");
					outtextxy(1, 1, "�� ����");
				}
				else {
					settextcolor(RGB(47, 169, 227));
					settextstyle(30, 0, "Taco Salad");
					outtextxy(1, 1, "�� ����");
					settextstyle(50, 0, "Taco Salad");
					outtextxy(270, 300, "��Ϣ��ѯ");
					outtextxy(270, 400, "��Ϣ���");
					outtextxy(270, 500, "��Ϣɾ��");
				}
				switch (msg.uMsg) {
				case WM_LBUTTONDOWN:
					if (msg.x >= 270 && msg.x <= 430 && msg.y >= 300 && msg.y <= 350) {
						char s[10];
					shuru:
						InputBox(s, 10, "�����벡�˱��!");
						for (int i = 0; i < strlen(s); i++) {
							if ((s[i] - '0') > 9 || s[i] < '0') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru;
							}
						}
						cleardevice();
						op.readbook();
						map<string, book>::iterator it = op.m3.find(s);
						if (it == op.m3.end())outtextxy(200, 200, "�޴�ԤԼ��");
						else {
							char panum[10] = { '\0' }, pronum[10] = { '\0' }, illness[20] = { '\0' }, d[20] = { '\0' };
							book t = it->second;
							string s = t.getpanum(), ss = t.getpronum(), sss = t.getillness(),ssss = t.getdate();
							for (int i = 0; s[i] != '\0'; i++)panum[i] = s[i];
							for (int i = 0; ss[i] != '\0'; i++)pronum[i] = ss[i];
							for (int i = 0; sss[i] != '\0'; i++)illness[i] = sss[i];
							for (int i = 0; ssss[i] != '\0'; i++)d[i] = ssss[i];
							putimage(0, 0, &beijing);
							settextstyle(30, 0, "����");
							outtextxy(400, 250, panum); outtextxy(400, 370, pronum);
							outtextxy(400, 480, illness); outtextxy(400, 600, d);
							while (1) {
								msg = GetMouseMsg();
								if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
									settextcolor(RGB(47, 10, 227));
									outtextxy(1, 1, "�� ����");
								}
								else { settextstyle(30, 0, "Taco Salad"); settextcolor(RGB(47, 169, 227)); outtextxy(1, 1, "�� ����"); }
								switch (msg.uMsg) {
								case WM_LBUTTONDOWN:
									if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
										goto bmsg;
									}
									break;
								default: break;
								}
							}
						}
					}
					else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 400 && msg.y <= 450) {
						char s[10]; string panum,pronum,illness,date;
					shuru2:
						InputBox(s, 10, "������ԤԼ�Ĳ��˱��");
						for (int i = 0; i < strlen(s); i++){
							if (!(s[i]>='0'&&s[i]<='9')) {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru2;
							}
						}
						if (op.m1.find(s) == op.m1.end()){
							cleardevice();
							outtextxy(300, 1, "�޴˲���");
							outtextxy(100, 100, "��ȷ��������ٴ�����");
							goto shuru2;
						}
						panum = s;
						cleardevice();
					shuru3:
						InputBox(s, 10, "������ԤԼ��ר�ұ��");
						for (int i = 0; i < strlen(s); i++){
							if (!(s[i] >= '0'&&s[i] <= '9')){
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru3;
							}
						}
						if (op.m2.find(s) == op.m2.end()) {
							cleardevice();
							outtextxy(300, 1, "�޴�ר��");
							outtextxy(100, 100, "��ȷ��������ٴ�����");
							goto shuru3;
						}
						pronum = s;
						cleardevice();
					shuru4:
						InputBox(s, 10, "�����벡�˵Ĳ���");
						for (int i = 0; i < strlen(s); i++) {
							if (!((s[i - 1] & 0x80) && (s[i] & 0x80))) {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru4;
							}
						}
						 illness= s;
						cleardevice();
					shuru5:
						InputBox(s, 10, "������ԤԼʱ��(��/��/��");
						for (int i = 0; i < strlen(s); i++) {
							if ((s[i]>'9'||s[i]<'0')&&s[i]!='/') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru5;
							}
						}
						date = s;
						cleardevice();
						if (op.m3.find(s) != op.m3.end()) {
							book t = op.m3.find(s)->second;
							if (t.getpronum() == pronum && t.getillness() == illness && t.getdate() == date) {
								cleardevice();
								outtextxy(200, 1, "��ԤԼ�Ѵ��ڣ�");
								goto bmsg;
							}
						}
						op.save(panum, pronum, illness, date);
						outtextxy(300, 200, "�ѳɹ�¼��");
						Sleep(600);
						goto bmsg;
					}
					else if (msg.x >= 270 && msg.x <= 430 && msg.y >= 500 && msg.y <= 550){
						char s[10];
						shuru6:
						InputBox(s, 10, "������ɾ��ԤԼ�Ĳ��˱��!");
						for (int i = 0; i < strlen(s); i++){
							if ((s[i] - '0') > 9 || s[i] < '0') {
								cleardevice();
								outtextxy(100, 1, "�����ʽ�������ٴ����룡");
								goto shuru;
							}
						}
						cleardevice();
						if (op.m3.find(s) == op.m3.end())outtextxy(200, 200, "�޴�ԤԼ�޷�����");
						else {
							op.m3.erase(s);
							op.del(s,3);
							outtextxy(200, 200, "�ѳɹ�ɾ��");
						}
						Sleep(600);
						goto bmsg;
					}
					else if (msg.x >= 1 && msg.x <= 100 && msg.y >= 1 && msg.y <= 51) {
						flag = 1; return;
					}
					break;
				default: break;
				}
			}
		}
};
int main() {
	Menu m;
	m.welcome();
	m.selectmenu();
	return 0;
}