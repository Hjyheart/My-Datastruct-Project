/*���ƣ��ؼ��ּ���ϵͳ
*��Ҫ������һ���ı��ļ����ļ������û��ü������룬����һ������
�ո�Ĺؼ��֣�ͳ������ؼ������ı��еĳ��ִ���
*���ߣ������
*���ڣ�2015.10.12
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <utility>

using namespace std;

vector <pair<string, int> > Search;

/*----ͳ�ƺ���----*/
void Count(const string & temp){
	string word;
	char ch;
	/*--����ͳ��--*/
	for (int i = 0; i < temp.length(); i++){
		//������ַ��ͷ���word
		if (isalpha(temp[i])){
			ch = temp[i];
			//��ת��ΪСд
			ch = tolower(ch);
			word.push_back(ch);
			continue;
		}
		//����Ϊ�յ����
		if (Search.empty()){
			Search.push_back(make_pair(word, 1));
			word.clear();
			continue;
		}
		else{
			//���������ҵ���ͬ�ַ���
			for (int k = 0; k < Search.size(); k++){
				if (Search[k].first == word){
					Search[k].second++;
					word.clear();
					break;
				}
				//���������Ҳ�����ͬ�ַ���
				if (k == Search.size() - 1){
					Search.push_back(make_pair(word, 1));
					word.clear();
					break;
				}
			}
		}
	}
}

int main(){
	ofstream outFile;
	string fileName, temp, keyValue, originalValue;

	/*--����--*/
	cout << "�ؼ��ּ���ϵͳ" << endl << "�������ļ�����";
	cin >> fileName;
	outFile.open(fileName);
	cout << endl << "������һ��Ӣ�ģ�" << endl;
	//д��
	while (getline(cin, temp)){
		outFile << temp;
		Count(temp);
	}
	if (outFile.good())
		cout << "�����ı��Ѿ��������ı��ļ�\"" << fileName << "\"�С�" << endl;
	outFile.close();

	/*--���--*/
	ifstream inFile;
	inFile.open(fileName);

	cin.clear();
	cout << "������Ҫ�����Ĺؼ���(����0�˳�����):";
	cin >> keyValue;
	while (keyValue != "0"){
		originalValue = keyValue;
		cout << "��ʾԴ�ļ�\"" << fileName << "\":" << endl;
		inFile.seekg(0);
		//����
		while (inFile.good()){
			inFile >> temp;
			cout << temp << " ";
		}
		cout << endl;

		//��Сдת��
		for (int i = 0; i < keyValue.length(); i++)
			keyValue[i] = tolower(keyValue[i]);
		//����
		for (int i = 0; i < Search.size(); i++){
			//�ҵ���Ӧ�ַ���
			if (Search[i].first == keyValue){
				cout << "��Դ�ļ��й���������" << Search[i].second << "���ؼ���"
					<< "\"" << originalValue << "\"" << endl;
				break;
			}
				//δ�ҵ���Ӧ�ַ���
				if (i == Search.size() - 1)
					cout << "Դ�ļ���δ�ҵ�Ҫ���ֶΡ�" << endl;
		}
		cout << "������Ҫ�����Ĺؼ��֣�";
		cin >> keyValue;
	}
	inFile.close();
	return 0;
}