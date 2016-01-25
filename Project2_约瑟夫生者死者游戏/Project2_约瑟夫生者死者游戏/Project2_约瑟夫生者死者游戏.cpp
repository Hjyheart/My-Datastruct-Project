/*���ƣ�Լɪ������������Ϸ
*��Ҫ����дһ��Լɪ����������Ϸ��ģ�����
*���ߣ������
*ѧ�ţ�1452822
*���ڣ�2015.10.9
*/
#include <iostream>

using namespace std;
/*----��ҽṹ��----*/
struct Player{
	int pos;               //���������ʼλ��
	struct Player * Next;  //βָ��
};
/*----���ĺ���----*/
Player * solve(int n, int s, int m, int k){
	Player *p;                         //��ʱָ��
	Player *Josephus = new Player[n];  //����Լɪ��ѭ������
	int count = 1;                     //������
	//Լɪ�򻷵ĳ�ʼ��
	for (int i = 0; i < n; i++){
		Josephus[i].pos = i + 1;
		if (i != n - 1)
			Josephus[i].Next = &Josephus[i + 1];
		else
			Josephus[i].Next = &Josephus[0];
	}
	//Ѱ�ҵ�һ��λ�ã���s = 1�������⴦��
	s--;
	if (s - 1 >= 0)
		p = &Josephus[s - 1];
	else
		p = &Josephus[n - 1];
	//������ɾ���������ۼ�λ�ã�ֱ���ﵽ����Ҫ��
	while (n > k){
		for (int i = 0; i < m - 1; i++)
			p = p->Next;
		cout << "��" << count << "�����ߵ�λ����:    " << p->Next->pos << endl;
		n--;
		count++;
		p->Next = p->Next->Next;
	}
	//Ϊ�ﵽ��С����������ƶ�ָ��
	while (p->pos < p->Next->pos)
		p = p->Next;
	p = p->Next;
	return p;
}

int main(){
	int N, S, M, K;
	Player *p;

	cout << "����N��Χ��һȦ�� �ӵ�S���˿�ʼ���α�������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ" << endl;

	cout << "������������Ϸ��������N: ";
	cin >> N;
	//�ݴ����
	while (N < 2){
		cout << "������Ҫ�����ˣ�����������:";
		cin >> N;
	}

	cout << "��������Ϸ��ʼ��λ��:    ";
	cin >> S;
	//�ݴ����
	while (S > N){
		cout << "�����λ�ã�����������:";
		cin >> S;
	}

	cout << "��������������M:         ";
	cin >> M;

	cout << "������ʣ�����������K:   ";
	cin >> K;
	//�ݴ����
	while (K > N){
		cout << "��������룬����������:";
		cin >> K;
	}
	//���ú��ĺ���
	p = solve(N, S, M, K);
	//���
	cout << "���ʣ��:    " << K << "��" << endl;
	cout << "ʣ�������λ��Ϊ:    ";

	for (int i = 0; i < K; i++){
		cout << p->pos << "    ";
		p = p->Next;
	}
	return 0;
}