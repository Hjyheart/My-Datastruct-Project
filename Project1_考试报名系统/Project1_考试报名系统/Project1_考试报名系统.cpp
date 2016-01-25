/*���ƣ����Ա���ϵͳ
*��Ҫ����дһ�����Ա���ϵͳ��ʵ�ֻ�������
*���ߣ������
*ѧ�ţ�1452822
*���ڣ�2015.10.8
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define  INFORMATION "��ѡ����Ҫ���еĲ�����1Ϊ���룬 2Ϊɾ���� 3Ϊ���ң� 4Ϊ�޸ģ� 5Ϊͳ�ƣ� 0Ϊȡ��������" 
#define  ORDER_INSERT 1
#define  ORDER_DELETE 2
#define  ORDER_FIND   3
#define  ORDER_EDIT   4
#define  ORDER_COUNT  5
#define  ORDER_CANCEL 6

using namespace std;
/*----������----*/
struct Student{

	string name;      //����
	string category;  //���
	string sex;       //�Ա�
	int test_Number;  //����
	int age;          //����

	Student *Pre;     //ǰָ��
	Student *Next;    //��ָ��
};

/*----������----*/
class List{
private:
	Student *Head, *End;    //ͷָ�� & βָ��                      
	int List_Size;          //��������
public:
	List();
	~List();

	void add(const Student & stu);                  //��ӿ���
	void Insert();                                  //���뿼��
	void Delete();                                  //ɾ������
	void Edit();                                    //�༭����
	void Count();                                   //ͳ�ƿ���
	void show();                                    //���û�չʾĿǰ���п����������
	void copy(Student * stu1, const Student & stu2);//��������

	Student * Find();                               //���Һ������޲Σ�
	Student * Find(int pos);                        //���Һ������вΣ�
	Student * find(int pos);                        //���Һ������вΣ�
};
/*----��������----*/
void List::copy(Student * stu1, const Student & stu2){
	stu1->name = stu2.name;
	stu1->age = stu2.age;
	stu1->category = stu2.category;
	stu1->sex = stu2.sex;
	stu1->Pre = stu2.Pre;
	stu1->Next = stu2.Next;
	stu1->test_Number = stu2.test_Number;
}
/*----���캯��----*/
List::List(){
	Head = NULL;
	End = NULL;
	List_Size = 0;
}
/*----��������----*/
List::~List(){
	Student * p = Head;
	for (int i = 0; i < List_Size - 2; i++){
		p = p->Next;
	}
	for (int i = 0; i < List_Size - 2; i++){
		delete p->Next;
		p = p->Pre;
	}
	if (p->Next)
	    delete p->Next;
	delete p;
}
/*----չʾ����----*/
void List::show(){
	Student *p = Head;

	cout << "����    ����    �Ա�    ����      ���" << endl;

	for (int i = 0; i < List_Size; i++){
		cout << p->test_Number << "       " << p->name << "     " << p->sex << "     " << p->age << "         "
			<< p->category << endl;
		if (p->Next)
		    p = p->Next;
	}
	cout << endl;
}
/*----��Ӻ���----*/
void List::add(const Student & stu){
	Student *item = new Student;
	if (!item){
		cout << "fail" << endl;
		return;
	}
	copy(item, stu);

	List_Size++;
	//�������Ϊ��
	if (!Head){
		Head = item;
		End = item;
	}
	//�������Ϊ��
	else{
		End->Next = item;
		item->Pre = End;
		item->Next = NULL;
		End = item;
	}
}
/*----���뺯��----*/
void List::Insert(){
	Student *item = new Student;
	if (!item){
		cout << "fail" << endl;
		return;
	}
	int pos;

	cout << "������Ҫ����Ŀ���λ�ã�";
	cin >> pos;
	//��������ڶ�β����
	if (pos != List_Size + 1){
		Student *temp = find(pos);
		//�ݴ����
		while (!temp){
			cout << "�Բ���û���ҵ�����Ҫ������λ�ã�����������λ��, ���߰�0ȡ����";
			int pos2;
			cin >> pos2;
			if (pos2 == 0)
				return;
			temp = Find(pos2);
		}
		cout << "���������뿼���Ŀ��š��������Ա����估�������" << endl;
		cin >> item->test_Number >> item->name >> item->sex >> item->age >> item->category;
		//���ǰָ�벻Ϊ��
		if (temp->Pre != NULL){
			temp->Pre->Next = item;
			item->Pre = temp->Pre;
			item->Next = temp;
			temp->Pre = item;
		}
		//���ǰָ��Ϊ��
		else{
			item->Next = temp;
			item->Pre = NULL;
			temp->Pre = item;
			Head = item;
		}
	}
	else{
		cout << "���������뿼���Ŀ��š��������Ա����估�������" << endl;
		cin >> item->test_Number >> item->name >> item->sex >> item->age >> item->category;
		//ͷָ��Ϊ��
		if (!Head){
			Head = item;
			End = item;
		}
		//ͷָ�벻Ϊ��
		else{
			End->Next = item;
			item->Pre = End;
			item->Next = NULL;
			End = item;
		}
	}
	List_Size++;
}
/*----���Һ������޲Σ�----*/
Student * List::Find(){
	int pos;
	Student *p = Head;

	cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
	cin >> pos;
	for (int i = 0; i < List_Size; i++){
		if (p->test_Number == pos)
			return p;
		if (p->Next)
			p = p->Next;
	}
	return NULL;
}
/*----���Һ������вΣ�----*/
Student * List::Find(int pos){
	Student *p = Head;

	for (int i = 0; i < List_Size; i++){
		if (p->test_Number == pos)
			return p;
		if (p->Next)
			p = p->Next;
	}
	return NULL;
}
Student * List::find(int pos){
	Student *p = Head;

	for (int i = 0; i < pos; i++){
		if (p->Next)
			p = p->Next;
	}
	return p;
}
/*----ɾ������----*/
void List::Delete(){
	Student *temp;
	int pos;

	cout << "������Ҫɾ���Ŀ�������:";
	cin >> pos;

	temp = Find(pos);
	//�ݴ����
	while (!temp){
		cout << "��������������������߰�0ȡ����";
		int pos2;
		cin >> pos2;
		if (pos2 == 0)
			return;
		temp = Find(pos2);
	}
	cout << "��Ҫɾ���Ŀ�����ϢΪ��" << "���ţ�" << temp->test_Number << "  ����:" << temp->name
		<< "  �Ա�:" << temp->sex << "  ����:" << temp->age << "  ���:" << temp->category << endl;
	//ɾ������λ�ڶ����м�
	if (temp->Pre != NULL && temp->Next != NULL){
		temp->Pre->Next = temp->Next;
		temp->Next->Pre = temp->Pre;
		delete temp;
	}
	//ɾ������λ�ڶ���
	if (temp->Pre == NULL && temp->Next != NULL){
		temp->Next->Pre = NULL;
		Head = temp->Next;
		delete temp;
	}
	//ɾ������λ�ڶ�β
	if (temp->Pre != NULL && temp->Next == NULL){
		temp->Pre->Next = NULL;
		End = temp->Pre;
		delete temp;
	}
	List_Size--;
}
/*----�༭����----*/
void List::Edit(){
	Student *temp;
	int pos;

	cout << "������Ҫ�޸ĵĿ����Ŀ��ţ�";
	cin >> pos;

	temp = Find(pos);
	//�ݴ����
	while (!temp){
		cout << "������������߰�0ȡ����";
		int pos2;
		cin >> pos2;
		if (pos2 == 0)
			return;
		temp = Find(pos2);
	}

	int chose;
	cout << "������Ӧ���ֽ��б༭,1:���Ŀ��� 2���������� 3�������Ա� 4���������� 5:�������";
	cin >> chose;
	while (chose > 5 || chose < 1){
		cout << "������󣬰�0ȡ����������Ӧ���ֽ��б༭,1:���Ŀ��� 2���������� 3�������Ա� 4���������� 5:�������";
		cin >> chose;
		if (chose == 0)
			return;
	}
	//����Ϣ
	int new_Age;
	int new_Test_Number;
	string new_Name;
	string new_Sex;
	string new_Kind;
	//��Ӧ����
	switch (chose){
	case 1:
		cout << "�������¿��ţ�";
		cin >> new_Test_Number;
		temp->test_Number = new_Test_Number;
		break;
	case 2:
		cout << "������������:";
		cin >> new_Name;
		temp->name = new_Name;
		break;
	case 3:
		cout << "���������Ա�";
		cin >> new_Sex;
		temp->sex = new_Sex;
		break;
	case 4:
		cout << "������������:";
		cin >> new_Age;
		temp->age = new_Age;
		break;
	case 5:
		cout << "�����������:";
		cin >> new_Kind;
		temp->category = new_Kind;
		break;
	default:
		break;
	}
}
/*----ͳ�ƺ���----*/
void List::Count(){
	cout << "�ܹ�" << List_Size << "����" << endl;
	int boy_Num = 0, gir_Num = 0;      //��Ů��ͳ��
	Student *p = Head;                 //��ʱָ��
	vector <pair<string, int> > kind;  //���ͳ������
	vector <pair<int, int> > Age;      //����ͳ������
	//ɨ��ͳ��
	for (int i = 0; i < List_Size; i++){
		if (p->sex == "��")
			boy_Num++;
		else
			gir_Num++;
		if (kind.empty())
			kind.push_back(make_pair(p->category, 1));
		else{
			for (int k = 0; k < kind.size(); k++){
				if (kind[k].first == p->category){
					kind[k].second++;
					break;
				}
				if (k == kind.size() - 1){
					kind.push_back(make_pair(p->category, 1));
					break;
				}
			}
		}

		if (Age.empty())
			Age.push_back(make_pair(p->age, 1));
		else{
			for (int k = 0; k < Age.size(); k++){
				if (Age[k].first == p->age){
					Age[k].second++;
					break;
				}
				if (k == Age.size() - 1){
					Age.push_back(make_pair(p->age, 1));
					break;
				}
			}
		}

		if (p->Next != NULL)
			p = p->Next;
	}
	//���
	cout << "��" << boy_Num << "������, ��" << gir_Num << "��Ů��" << endl;
	cout << "�����¼������" << endl;

	for (int i = 0; i < kind.size(); i++)
		cout << kind[i].first << ":" << kind[i].second << "��" << endl;

	cout << endl;

	cout << "�м��������:" << endl;
	for (int i = 0; i < Age.size(); i++)
		cout << Age[i].first << ":" << Age[i].second << "��" << endl;
}

int main(){
	int amount, order;
	Student temp = { "", "", "", 0, 0, NULL, NULL };
	Student *p = NULL;
	List Test_System;

	cout << "�����뽨��������Ϣϵͳ!" << endl << "�����뿼��������";
	cin >> amount;
	//������Ϣ
	cout << "���������뿼���Ŀ��š��������Ա����估�������" << endl;

	for (int i = 0; i < amount; i++){
		cin >> temp.test_Number >> temp.name >> temp.sex
			>> temp.age >> temp.category;
		//�Ա��ݴ�
		while (temp.sex != "��" && temp.sex != "Ů"){
			cout << endl << "�Ա���� ���������Ա�(�� or Ů):";
			cin >> temp.sex;
		}
		Test_System.add(temp);
	}
	//չʾ��Ϣ
	cout << "�������Ϊ��" << endl;
	Test_System.show();
	//ѡ�����
	cout << INFORMATION << endl
		<< "��ѡ����Ҫ���еĲ�����";
	cin >> order;
	//ѭ������
	while (order != ORDER_CANCEL){
		//���ݲ���orderѡ�����
		switch (order){
		case ORDER_INSERT:
			Test_System.Insert(); break;
		case ORDER_DELETE:
			Test_System.Delete(); break;
		case ORDER_FIND:
			p = Test_System.Find();
			if (p){
				cout << "����    ����    �Ա�    ����      ���" << endl;
				cout << p->test_Number << "       " << p->name << "     " << p->sex << "     " << p->age << "         "
					<< p->category << endl;
			}
			else
				cout << "���޴��ˣ�" << endl;
			break;
		case ORDER_EDIT:
			Test_System.Edit(); break;
		case ORDER_COUNT:
			Test_System.Count();
			break;
		default:
			break;
		}
		cout << "������������Ϊ��" << endl;
		Test_System.show();
		cin.get();
		//ѭ��
		cout << INFORMATION << endl
			<< "��ѡ����Ҫ���еĲ�����";
		cin >> order;
	}
	return 0;
}