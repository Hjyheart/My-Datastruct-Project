#include <iostream>
#include <vector>

using namespace std;

struct Node{ 
	int data;               //���������
	Node * leftChild;       //������
	Node * rightChild;      //������
};

class Tree{
private:
	Node * root;                          //���ڵ�
public:
	Tree() :root(NULL){};                 //Ĭ�Ϲ��캯��
	~Tree();                              //��������

	void one_BuildTree();                 //���ɶ���������
	void two_Insert();                    //����ڵ�
	void three_Find();                    //���ҽڵ�

	void destroy(Node *p);                //�ݻٽڵ�
	void build(Node *p, Node *current);   //���ɶ�����������������
	void Print(Node *node);               //��ӡ
	void search(int number, Node *node);  //���Ҹ�������

	Node * create();                      //�����սڵ�
};

/*---��������---*/
Tree::~Tree(){
	destroy(root);
}
/*---�ݻٽڵ�---*/
void Tree::destroy(Node *p){
	if (p->leftChild)
		destroy(p->leftChild);
	if (p->rightChild)
		destroy(p->rightChild);
	delete p;
}
/*---�����սڵ�---*/
Node * Tree::create(){
	Node *p = new Node();

	p->data = 0;
	p->leftChild = NULL;
	p->rightChild = NULL;

	return p;
}
/*---���ɶ���������---*/
void Tree::one_BuildTree(){
	vector <int> que;
	int key, flag = 0;
	cout << "Please input key to create Bsort_Tree(end with 0):" << endl;
	cin >> key;
	while (key != 0){
		for (int i = 0; i < que.size(); i++){
			if (que[i] == key){
				cout << "The input key<" << key << "> is have in!" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			que.push_back(key);
		flag = 0;
		cin >> key;
	}

	root = create();
	if (!root){
		cout << "�ڴ����ʧ�ܣ�" << endl;
		return;
	}
	root->data = que[0];

	for (int i = 1; i < que.size(); i++){
		Node *p = create();
		if (!p){
			cout << "�ڴ����ʧ��" << endl;
			return;
		}
		p->data = que[i];
		build(p, root);
	}

	cout << "Bsort_Tree is:" << endl;
	Print(root);
	cout << endl << endl;
}
/*---����ڵ�---*/
void Tree::two_Insert(){
	int num;
	cout << "Please input  key which inserted: ";
	cin >> num;

	Node *p = create();
	if (!p){
		cout << "�ڴ����ʧ�ܣ�" << endl;
		return;
	}
	p->data = num;

	build(p, root);

	cout << "Bsort_Tree is:" << endl;
	Print(root);
	cout << endl << endl;
}
/*---���ҽڵ�---*/
void Tree::three_Find(){
	int num;
	cout << "Please input key which searched: ";
	cin >> num;

	search(num, root);
}
/*---���ɶ�������������---*/
void Tree::build(Node *p, Node *current){
	if (p->data > current->data){
		if (!current->rightChild){
			current->rightChild = p;
			return;
		}
		build(p, current->rightChild);
	}
	if (p->data < current->data){
		if (!current->leftChild){
			current->leftChild = p;
			return;
		}
		build(p, current->leftChild);
	}
	if (p->data == current->data)
		cout << p->data << " have in��";
}
/*---��ӡ---*/
void Tree::Print(Node *node){
	Node *p = node;
	if (p->leftChild)
		Print(p->leftChild);
	cout << p->data << " -> ";
	if (p->rightChild)
		Print(p->rightChild);
}
/*---���Ҹ�������---*/
void Tree::search(int number, Node *node){

	if (number < node->data){
		if (!node->leftChild){
			cout << number << " is not exist!" << endl;
			return;
		}
		search(number, node->leftChild);
	}
	if (number > node->data){
		if (!node->rightChild){
			cout << number << " is not exist!" << endl;
			return;
		}
		search(number, node->rightChild);
	}
	if (number == node->data){
		cout << number << " is exist." << endl;
		if (node->leftChild)
			cout << "It's leftChild is " << node->leftChild->data << endl;
		if (node->rightChild)
			cout << "It's rightChild is " << node->rightChild->data << endl;
	}
}

int main(){
	cout << "**                           ����������                           **" << endl;
	cout << "====================================================================" << endl;
	cout << "**                         1 --- ��������������                   **" << endl;
	cout << "**                         2 --- ����Ԫ��                         **" << endl;
	cout << "**                         3 --- ��ѯԪ��                         **" << endl;
	cout << "**                         4 --- �˳�����                         **" << endl;
	cout << "====================================================================" << endl;
	
	int order;
	Tree tree;

	cout << "Please select: ";
	cin >> order;
	while (order != 4){
		switch (order){
		case 1:
			tree.one_BuildTree();
			break;
		case 2:
			tree.two_Insert();
			break;
		case 3:
			tree.three_Find();
			break;
		default:
			cout << "��������" << endl;
		}
		cout << "Please select: ";
		cin >> order;
	}
	return 0;
}