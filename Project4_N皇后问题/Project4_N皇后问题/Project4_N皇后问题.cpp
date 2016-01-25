/*���ƣ�N�ʺ�����
*��Ҫ����дһ���������N�ʺ������
*���ߣ������
*���ڣ�2015.10.10
*/
#include <iostream>
#include <string>

#define INFORMATION "����N * N �����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�У��к�ͬһб���ϣ�"
#define INPUT "������ʺ�ĸ��������롰0���˳����򣩣�"

using namespace std;
/*----ȫ�ֱ���----*/
static int N;                   //�ʺ�����
static int solutionCount = 0;   //�������������
static int flag = 0;            //������ʶ
static int *nextLine;           //��һ�п���λ�ö���
static int *queenPos;           //�ʺ�λ�ü�¼����

/*----��ӡ����----*/
void Print(){
	for (int i = 0; i < N; i++){
		for (int k = 0; k < N; k++){
			//�ڻʺ��Ӧλ�������X��
			if (k == queenPos[i])
				cout << "X  ";
			else
				cout << "0  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

/*----���ݴ浵����----*/
void copy(int * Line){
	for (int i = 0; i < N; i++)
		Line[i] = nextLine[i];
}

/*----���ݻ��ݺ���----*/
void recopy(int *Line){
	for (int i = 0; i < N; i++)
		nextLine[i] = Line[i];
}

/*----������һ�к���----*/
void setNextLine(int row){
	/*--�ж��Ƿ��Ѿ��������һ��--*/
	if (row == N)
		return;

	int dis;        //�о�         
	memset(nextLine, 0, N * sizeof(int));
	/*--��һ�е�����--*/
	for (int i = 0; i < row; i++){
		dis = row - i;
		//����������һ��
		nextLine[queenPos[i]] = 1;
		//��б�·�������һ��
		if (queenPos[i] - dis >= 0)
			nextLine[queenPos[i] - dis] = 1;
		//��б�·�������һ��
		if (queenPos[i] + dis < N)
			nextLine[queenPos[i] + dis] = 1;
	}
}

/*----���ĵݹ麯��----*/
void solve(int row){
	/*--���õ�ǰ�ж���--*/
	int *currentLine = new int[N];
	memset(currentLine, 0, N * sizeof(int));
	//���ݱ���
	copy(currentLine);
	/*--�����ж�--*/
	if (row == N){
		//���н���ô�ӡ����
		Print();
		//���н��ʶ����Ϊ��1��
		flag = 1;
		//���������һ
		solutionCount++;
		//������һ��
		return;
	}
	/*--���ĵݹ鲿��--*/
	for (int i = 0; i < N; i++){
		//�ж϶�Ӧλ���Ƿ����
		if (currentLine[i] == 0){
			//��¼�ʺ�λ��
			queenPos[row] = i;
			//������һ�п���λ��
			setNextLine(row + 1);
			//����һ�н��еݹ�
			solve(row + 1);
			//�ݹ鷵��֮�󣬱���������ݻ���
			recopy(currentLine);
		}
	}
	/*--�ڴ��ͷ�--*/
	delete[] currentLine;
}

int main(){
	/*--�û�����--*/
	cout << INFORMATION << endl
		<< INPUT;
	cin >> N;
	//�ݴ����
	while (N < 0){
		cout << "N������С���㣡�����������룺";
		cin >> N;
	}
	/*--ѭ������--*/
	while (N != 0){
		//Ϊָ�����N���ռ䲢���ó�ʼ����
		queenPos = new int[N];
		nextLine = new int[N];
		memset(nextLine, 0, N * sizeof(int));
		memset(queenPos, -1, N * sizeof(int));
		//�Ե�һ�н��е�����������һ��Ϊ�����������Ϊ�κ�λ�ö����У�
		for (int i = 0; i < N; i++){
			//��¼�ʺ�λ��
			queenPos[0] = i;
			//������һ��
			setNextLine(1);
			//����ݹ�
			solve(1);
			//��ʼ��nextLine��Ϊ��һ��������׼��
			memset(nextLine, 0, N * sizeof(int));
		}
		/*--�������--*/
		//�޽����
		if (!flag){
			cout << "û�н�!" << endl;
		}
		//�н����
		else{
			//����ⷨ����
			cout << "��" << solutionCount << "�ֽⷨ!" << endl;
			//���ݳ�ʼ��
			solutionCount = 0;
			flag = 0;
		}
		cout << INFORMATION << endl
			<< INPUT;
		cin >> N;
	}
	/*--�ڴ��ͷ�--*/
	delete [] queenPos;
	delete [] nextLine;

	return 0;
}