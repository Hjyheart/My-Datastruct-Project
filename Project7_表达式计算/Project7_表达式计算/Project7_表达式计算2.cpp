#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*----�ڵ�ṹ�������----*/
struct Node{
	char data;
	Node * leftChild;
	Node * rightChild;
};

class Tree{
private:
	Node * root;
	static int count;
public:
	Tree() :root(NULL){}
	Tree(const string s){ root = buildTree(s); }
	Node* buildTree(const string s);
	Node* create();
	Node* getRoot();

	void PostOrder(Node* node);
	void Inorder(Node* node);
};

int Tree::count = 0;

/*----�������Ľڵ�----*/
Node* Tree::create(){
	Node* p = new Node();
	p->data = ' ';
	p->leftChild = NULL;
	p->rightChild = NULL;
	return p;
}

/*----��ȡ����----*/
Node* Tree::getRoot(){
	return root;
}

/*----������----*/
Node* Tree::buildTree(const string s){
	stack <char> operate;
	stack <Node *> node;
	stack <char> operate2;
	stack <Node *> node2;
	string p = "";
	Node * treeNode;
	char ch;

	for (int k = 0; k < s.length(); k++){
		//������������ݵ�����Ϊһ�����ʽ��������ȥ����
		if (s[k] == '('){
			k++;
			while (s[k] != ')'){
				p = p + s[k];
				k++;
			}
			node.push(buildTree(p));
			p.clear();
			continue;
		}
		//����ֱ����Ҷ�ӽڵ�
		else{
			if (s[k] - '0' >= 0 && s[k] - '0' <= 9){
				treeNode = create();
				treeNode->data = s[k];

				node.push(treeNode);
			}
			//���������
			else if (s[k] == '*' || s[k] == '/' || s[k] == '+' || s[k] == '-'){
				if (!operate.empty() && (s[k] == '+' || s[k] == '-')){
					if (operate.top() == '+' || operate.top() == '-'){
						treeNode = create();
						treeNode->data = operate.top();
						treeNode->rightChild = node.top();
						node.pop();
						treeNode->leftChild = node.top();
						node.pop();

						node.push(treeNode);

						operate.pop();
						operate.push(s[k]);
					}
					else{
						//�����������Ĵ���
						while (!operate.empty() && (operate.top() == '*' || operate.top() == '/')){
							node2.push(node.top());
							node.pop();
							operate2.push(operate.top());
							operate.pop();
						}
						node2.push(node.top());
						node.pop();
						while (!operate2.empty())
						{
							treeNode = create();
							treeNode->data = operate2.top();
							operate2.pop();
							treeNode->leftChild = node2.top();
							node2.pop();
							treeNode->rightChild = node2.top();
							node2.pop();

							node2.push(treeNode);
						}
						node.push(node2.top());
						operate.push(s[k]);
						node2.pop();
					}
				}
				else
					operate.push(s[k]);
			}
		}
	}


	while (!operate.empty() && (operate.top() == '*' || operate.top() == '/')){
		node2.push(node.top());
		node.pop();
		operate2.push(operate.top());
		operate.pop();
	}
	node2.push(node.top());
	node.pop();
	while (!operate2.empty())
	{
		treeNode = create();
		treeNode->data = operate2.top();
		operate2.pop();
		treeNode->leftChild = node2.top();
		node2.pop();
		treeNode->rightChild = node2.top();
		node2.pop();

		node2.push(treeNode);
	}
	node.push(node2.top());
	node2.pop();

	while (!operate.empty())
	{

		node2.push(node.top());
		node.pop();
		operate2.push(operate.top());
		operate.pop();
	}
	node2.push(node.top());
	node.pop();
	while (!operate2.empty())
	{
		treeNode = create();
		treeNode->data = operate2.top();
		operate2.pop();
		treeNode->leftChild = node2.top();
		node2.pop();
		treeNode->rightChild = node2.top();
		node2.pop();

		node2.push(treeNode);
	}
	node.push(node2.top());
	node2.pop();

	return node.top();
}

/*---��������----*/
void Tree::PostOrder(Node* node){
	if (node != NULL){
		PostOrder(node->leftChild);
		PostOrder(node->rightChild);
		cout << node->data;
	}
}

/*----ǰ�����----*/
void Tree::Inorder(Node* node){
	if (node != NULL){
		cout << node->data;
		Inorder(node->leftChild);
		Inorder(node->rightChild);
	}
}

int main(){
	string centerString;

	cout << "��������ʽ��";
	cin >> centerString;

	Tree tree(centerString);

	cout << "�������ʽ��";
	tree.Inorder(tree.getRoot());
	cout << endl;

	cout << "��׺���ʽ��";
	cout << centerString << endl;

	cout << "�沨�����ʽ��";
	tree.PostOrder(tree.getRoot());
	cout << endl;
	return 0;
}