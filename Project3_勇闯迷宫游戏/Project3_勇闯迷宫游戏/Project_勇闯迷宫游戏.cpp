#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*---�����м���̵�ջ----*/
struct flag{
	int X;    //������
	int Y;    //������

	struct flag* Next; //��һ��
};
/*---ȫ�ֱ���----*/
static char **map;       //��ͼָ��
static int row, col;     //�У� ��
static int en_X, en_Y;   //�������
static int out_X, out_Y; //��������
string commond;          //ָ��
flag *Head;              //�������

/*----չʾ����----*/
void display(){
	bool search(int x, int y);
	cout << "      ";
	for (int i = 0; i <= col; i++)
		cout << "��" << i << "��" << "    ";
	cout << endl;
	for (int i = 0; i <= row; i++){
		cout << "��" << i << "��     ";
		for (int k = 0; k <= col; k++){
			if (!search(i, k) || (i == out_X && k == out_Y))
				cout << "X" << "        ";
			else
				cout << map[i][k] << "        ";
		}
		cout << endl << endl;
	}
}
/*----���ĺ���----*/
void solve(){
	bool toNext(int x, int y);
	/*--������--*/
	if (en_X - 1 >= 0 && map[en_X - 1][en_Y] == '0'){
		//����̽�������������������ݹ�
		if (toNext(en_X - 1, en_Y))
			return;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag *p = Head->Next;
			delete p;
			Head->Next = NULL;
		}
	}
	/*--������--*/
	if (en_X + 1 <= row && map[en_X + 1][en_Y] == '0'){
		//����̽�������������������ݹ�
		if (toNext(en_X + 1, en_Y))
			return;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag *p = Head->Next;
			delete p;
			Head->Next = NULL;
		}
	}
	/*--������--*/
	if (en_Y - 1 >= 0 && map[en_X][en_Y - 1] == '0'){
		//����̽�������������������ݹ�
		if (toNext(en_X, en_Y - 1))
			return;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag *p = Head->Next;
			delete p;
			Head->Next = NULL;
		}
	}
	/*--������--*/
	if (en_Y + 1 <= col && map[en_X][en_Y + 1] == '0'){
		//����̽�������������������ݹ�
		if (toNext(en_X, en_Y + 1))
			return;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag *p = Head->Next;
			delete p;
			Head->Next = NULL;
		}
	}
}
/*----�ݹ麯��----*/
bool toNext(int x, int y){
	bool search(int x, int y);
	/*--�����½ڵ㣬����ջ--*/
	flag *newWay = new flag, *p = Head;
	newWay->X = x;
	newWay->Y = y;
	newWay->Next = NULL;
	while (p && p->Next)
		p = p->Next;
	p->Next = newWay;
	/*--�жϸõ��Ƿ�Ϊ�յ�--*/
	if (x == out_X && y == out_Y)
		return true;
	/*--������̽--*/
	if (x - 1 >= 0 && map[x - 1][y] == '0' && search(x - 1, y)){
		//�ݹ����̽�������������������ݹ�
		if (toNext(x - 1, y))
			return true;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag * temp = newWay->Next;
			delete temp;
			newWay->Next = NULL;
		}
	}
	/*--������̽--*/
	if (x + 1 <= row && map[x + 1][y] == '0' && search(x + 1, y)){
		//�ݹ����̽�������������������ݹ�
		if (toNext(x + 1, y))
			return true;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag * temp = newWay->Next;
			delete temp;
			newWay->Next = NULL;
		}
	}
	/*--������̽--*/
	if (y - 1 >= 0 && map[x][y - 1] == '0' && search(x, y - 1)){
		//�ݹ����̽�������������������ݹ�
		if (toNext(x, y - 1))
			return true;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag * temp = newWay->Next;
			delete temp;
			newWay->Next = NULL;
		}
	}
	/*--������̽--*/
	if (y + 1 <= col && map[x][y + 1] == '0' && search(x, y + 1)){
		//�ݹ����̽�������������������ݹ�
		if (toNext(x, y + 1))
			return true;
		//�÷��򲻿���ִ�г�ջ
		else{
			flag * temp = newWay->Next;
			delete temp;
			newWay->Next = NULL;
		}
	}
	return false;
}
/*--�����Ƿ��߹�����--*/
bool search(int x, int y){
	flag *p = Head;
	while (p && p->Next){
		if (p->X == x && p->Y == y)
			return false;
		p = p->Next;
	}
	return true;
}
/*--ģʽAѡ����--*/
void modeA(){
	int order;
	cout << "��ѡ���ͼ(1, 2, 3):";
	cin >> order;
	while (order != 1 && order != 2 && order != 3){
		cout << "����������������:";
		cin >> order;
	}

	ifstream inFile1, inFile2, inFile3;
	inFile1.open("maze1.txt");
	inFile2.open("maze2.txt");
	inFile3.open("maze3.txt");
	if (!inFile1){
		cout << "�ļ�1��ʧ��";
		return;
	}
	if (!inFile2){
		cout << "�ļ�2��ʧ��";
		return;
	}
	if (!inFile3){
		cout << "�ļ�3��ʧ��";
		return;
	}
	if (order == 1){
		map = new char*[3];
		for (int i = 0; i < 3; i++){
			map[i] = new char[3];
		}
		inFile1 >> en_X >> en_Y >> out_X >> out_Y;
		for (int i = 0; i < 3; i++){
			for (int k = 0; k < 3; k++)
				inFile1 >> map[i][k];
		}
		row = 2;
		col = 2;
	}
	if (order == 2){
		map = new char*[4];
		for (int i = 0; i < 4; i++){
			map[i] = new char[4];
		}
		inFile2 >> en_X >> en_Y >> out_X >> out_Y;
		for (int i = 0; i < 4; i++){
			for (int k = 0; k < 4; k++)
				inFile2 >> map[i][k];
		}
		row = 3;
		col = 3;
	}
	if (order == 3){
		map = new char*[5];
		for (int i = 0; i < 5; i++){
			map[i] = new char[5];
		}
		inFile3 >> en_X >> en_Y >> out_X >> out_Y;
		for (int i = 0; i < 5; i++){
			for (int k = 0; k < 5; k++)
				inFile3 >> map[i][k];
		}
		row = 4;
		col = 4;
	}
		Head = new flag;
		Head->X = en_X;
		Head->Y = en_Y;
		Head->Next = NULL;
		//���������
		map[en_X][en_Y] = '0';
		map[out_X][out_Y] = '0';
		/*----���ú��ĺ���Ѱ��·��----*/
		solve();
		/*----���----*/
		//�Թ��޽�
		if (Head->Next == NULL){
			cout << "���Թ��޽⣡" << endl;
			//�ͷ��ڴ�
			delete[] map;
			delete Head;
		}
		//�Թ��н�
		else{
			display();
			flag *p = Head;
			while (p){
				if (p->Next == NULL)
					cout << "(" << p->X << ", " << p->Y << ")";
				else
					cout << "(" << p->X << ", " << p->Y << ")->";
				p = p->Next;
			}
			cout << endl;
			//�ͷ��ڴ�
			delete[] map;
			delete Head;
		}
}
/*--ģʽBѡ����--*/
void modeB(){
	string commondB = "Yes";
	while (commondB == "Yes"){
		/*----�к��е�����----*/
		cout << "�������Թ��Ĵ�С������0�к�0�У��� ��:";
		cin >> row;
		cout << "�У�";
		cin >> col;
		//��������Ƿ�����
		while (row < 0 || col < 0){
			cout << "�����������б�����㣡�����������롣\n";
			cout << "�������Թ��Ĵ�С������0�к�0�У��� ��:";
			cin >> row;
			cout << "�У�";
			cin >> col;
		}
		/*----��ڵ�����----*/
		cout << "�������Թ���������꣨����0�к�0�У�, X:";
		cin >> en_X;
		cout << "Y:";
		cin >> en_Y;
		//��������Ƿ�����
		while (en_X < 0 || en_X > col || en_Y < 0 || en_Y > row){
			cout << "��������������󣡣�������Թ���С��ȷ���롣\n";
			cout << "�������Թ���������꣨����0�к�0�У�, X:";
			cin >> en_X;
			cout << "Y:";
			cin >> en_Y;
		}
		/*----���ڵ�����----*/
		cout << "�������Թ��ĳ������꣨����0�к�0�У�, X:";
		cin >> out_X;
		cout << "Y:";
		cin >> out_Y;
		//��������Ƿ�����
		while (out_X < 0 || out_X > col || out_Y < 0 || out_Y > row){
			cout << "���������������󣡣�������Թ���С��ȷ���롣\n";
			cout << "�������Թ��ĳ������꣨����0�к�0�У�, X:";
			cin >> out_X;
			cout << "Y:";
			cin >> out_Y;
		}
		/*----��ͼ�ͱ�ǵĳ�ʼ��----*/
		cout << "���������Զ�������ͼ������\"#\"�����ϰ��\"0\"����ͨ�ĵ�·����0�������Ƕ�����Ϊ�ϰ�����������ǽ�ǿ������Ϊ��ͨ\n";
		map = new char *[row + 1];
		for (int i = 0; i <= row; i++)
			map[i] = new char[col + 1];
		for (int i = 0; i <= row; i++)
			for (int k = 0; k <= col; k++)
				cin >> map[i][k];
		Head = new flag;
		Head->X = en_X;
		Head->Y = en_Y;
		Head->Next = NULL;
		//���������
		map[en_X][en_Y] = '0';
		map[out_X][out_Y] = '0';
		/*----���ú��ĺ���Ѱ��·��----*/
		solve();
		/*----���----*/
		//�Թ��޽�
		if (Head->Next == NULL){
			cout << "���Թ��޽⣡" << endl;
			//�ͷ��ڴ�
			delete[] map;
			delete Head;
		}
		//�Թ��н�
		else{
			display();
			flag *p = Head;
			while (p){
				if (p->Next == NULL)
					cout << "(" << p->X << ", " << p->Y << ")";
				else
					cout << "(" << p->X << ", " << p->Y << ")->";
				p = p->Next;
			}
			cout << endl;
			//�ͷ��ڴ�
			delete[] map;
			delete Head;
		}
		cout << "Do you want to play again? input��Yes��or ��No��:" << endl;
		cin >> commondB;
		while (commondB != "Yes" && commondB != "No"){
			cout << "��������" << endl;
			cout << "Do you want to play again? input��Yes��or ��No��:" << endl;
			cin >> commondB;
		}
	}
	return;
}

int main(){

	cout << "************************************************************************" << endl;
	cout << "                          ��ӭ�����´��Թ���Ϸ                          " << endl;
	cout << "                            A--ѡ���ͼģʽ                             " << endl;
	cout << "                            B--�Զ����ͼģʽ                           " << endl;
	cout << "                            E--�˳���Ϸ                                 " << endl;
	cout << "************************************************************************" << endl;

	cout << "������ָ�";
	cin >> commond;

	while (commond != "E"){
		if (commond == "A")
			modeA();
		if (commond == "B")
			modeB();
		cout << "������ָ�";
		cin >> commond;
	}
	return 0;
}