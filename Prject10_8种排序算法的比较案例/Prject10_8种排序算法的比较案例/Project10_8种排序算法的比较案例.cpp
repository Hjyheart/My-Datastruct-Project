#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <Windows.h>
#include <cmath>

using namespace std;

static int *testArr, testNum, Count = 0;

void print(int arr[]){
	for (int i = 0; i < testNum; i++)
		cout << arr[i] << endl; 
}

/*---ð������---*/
void bubble_sort(int arr[]){
	int temp, *test, count = 0;
	int stime, etime;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	for (int i = 0; i < testNum - 1; i++){
		for (int k = 0; k < testNum - 1 - i; k++){
			if (test[k] > test[k + 1]){
				temp = test[k];
				test[k] = test[k + 1];
				test[k + 1] = temp;
				Count++;
			}
		}
	}
	
	etime = GetTickCount();
	delete[] test;
	//print(arr);
	//print(testArr);
    cout << "ð����������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "ð�����򽻻�������      " << Count << endl;
	Count = 0;
}

/*---ѡ������---*/
void selection_sort(int arr[]){//wrong
	int temp, *test;
	int stime, etime;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	for (int i = 0; i < testNum - 1; i++){
		for (int k = i + 1; k < testNum; k++){
			if (test[i] > test[k]){
				temp = test[i];
				test[i] = test[k];
				test[k] = temp;
				Count++;
			}
		}
	}

	etime = GetTickCount();
	delete[] test;
	//print(arr);
	//print(testArr);
	cout << "ѡ����������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "ѡ�����򽻻�������      " << Count << endl;
	Count = 0;
}

/*---ֱ�Ӳ�������---*/
void insertion_sort(int arr[]){
	int temp, *test, j;
	int stime, etime;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	for (int i = 1; i < testNum; i++){
		if (test[i] < test[i - 1]){
			Count++;
			temp = test[i];
			j = i - 1;
			do{
				test[j + 1] = test[j];
				j--;
			} while (j >= 0 && temp < test[j]);
			test[j + 1] = temp;
		}
	}

	etime = GetTickCount();
	delete[] test;
	//print(test);
	cout << "ֱ�Ӳ�����������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "ֱ�Ӳ������򽻻�������      " << Count << endl;
	Count = 0;
}

/*---ϣ������---*/
void shell_sort(int arr[]){
	int temp, *test, j, gap, count = 0;
	int stime, etime;

	gap = testNum + 1;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	do{
		gap = (gap / 3) + 1;
		for (int i = gap; i < testNum; i++){
			if (test[i] < test[i - gap]){
				count++;
				temp = test[i];
				j = i - gap;
				do{
					test[j + gap] = test[j];
					j = j - gap;
				} while (j > 0 && temp < test[j]);
				test[j + gap] = temp;
			}
		}
	} while (gap > 1);

	etime = GetTickCount();
	delete[] test;
	//print(test);
	cout << "ϣ����������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "ϣ�����򽻻�������      " << count << endl;
}

/*---��������---*/
void quick_sort(int arr[]){
	void quick_sort_help(int arr[], const int left, const int right);

	int temp, *test, j;
	int stime, etime;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	quick_sort_help(test, 0, testNum - 1);

	etime = GetTickCount();
	delete[] test;
	//print(test);
	cout << "������������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "�������򽻻�������      " << Count << endl;
	Count = 0;
}

void quick_sort_help(int arr[], const int left, const int right){
	if (left >= right)
		return;
	int first = left;
	int last = right;
	int key = arr[first];
	Count++;
	while (first < last){
		while (first < last && arr[last] >= key)
			--last;
		arr[first] = arr[last];
		Count++;
		while (first < last && arr[first] <= key)
			++first;
		arr[last] = arr[first];
		Count++;
	}
	arr[first] = key;
	quick_sort_help(arr, left, first - 1);
	quick_sort_help(arr, first + 1, right);
}

/*---������---*/
void heap_sort(int arr[]){
	void HeapAdjust(int arr[], int i, int nLength);
	
	int temp, *test;
	int stime, etime;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	for (int i = testNum / 2 - 1; i >= 0; --i)
		HeapAdjust(test, i, testNum);
	for (int i = testNum - 1; i >= 0; i--){
		Count++;
		temp = test[i];
		test[i] = test[0];
		test[0] = temp;
		HeapAdjust(test, 0, i);
	}

	etime = GetTickCount();
	//print(test);
	delete[] test;
	cout << "����������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "�Ѷ����򽻻�������      " << Count << endl;
	Count = 0;
}

void HeapAdjust(int arr[], int i, int nLength){
	int nChild, nTemp;
	for (; 2 * i < nLength; i = nChild){
		nChild = 2 * i + 1;
		if (nChild < nLength - 1 && arr[nChild + 1] > arr[nChild])
			++nChild;
		if (arr[i] < arr[nChild]){
			Count++;
			nTemp = arr[i];
			arr[i] = arr[nChild];
			arr[nChild] = nTemp;
		}
		else
			break;
	}
}

/*---�鲢����---*/
void merge_sort(int arr[]){
	void merge_help1(int arr[], int temp[], int start, int end);
	void merge_help2(int arr[], int temp[], int start, int mid, int end);

	int temp, *test,*temparr;
	int stime, etime;

	temparr = new int[testNum];
	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	stime = GetTickCount();

	merge_help1(test, temparr, 0, testNum - 1);

	etime = GetTickCount();
	//print(test);
	delete[] test;
	cout << "�鲢��������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "�鲢���򽻻�������      " << Count << endl;
	Count = 0;

}

void merge_help2(int arr[], int temp[], int start, int mid, int end){
	int i = start, j = mid + 1, k = start;
	while (i != mid + 1 && j != end + 1){
		if (arr[i] > arr[j]){
			temp[k++] = arr[i++];
			Count++;
		}
		else{
			temp[k++] = arr[j++];
			Count++;
		}
	}
	while (i != mid + 1)
		temp[k++] = arr[i++];
	while (j != end + 1)
		temp[k++] = arr[j++];
	for (i = start; i <= end; i++)
		arr[i] = temp[i];
}

void merge_help1(int arr[], int temp[], int start, int end){
	int mid;
	if (start < end){
		mid = (start + end) / 2;
		merge_help1(arr, temp, start, mid);
		merge_help1(arr, temp, mid + 1, end);
		merge_help2(arr, temp, start, mid, end);
	}
}

/*---��������---*/
void radix_sort(int arr[]){
	int getPlaces(int num);
	int getMax(int arr[], int n);
	void radix_help(int arr[], int n, int place);

	int temp, *test, max, maxPlaces;
	int stime, etime;

	test = new int[testNum];
	memcpy(test, arr, sizeof(int) * testNum);

	max = getMax(test, testNum);
	maxPlaces = getPlaces(max);

	stime = GetTickCount();

	for (int i = 1; i <= maxPlaces; i++)
		radix_help(test, testNum, i);

	etime = GetTickCount();
	delete[] test;
	//print(test);
	cout << "������������ʱ�䣺      " << etime - stime << "ms" << endl;
	cout << "�������򽻻�������      " << Count << endl;
	Count = 0;
}

int getPlaces(int num){
	int count = 1;
	int temp = num / 10;
	while (temp != 0){
		count++;
		temp /= 10;
	}
	return count;
}

int getMax(int arr[], int n){
	int max = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void radix_help(int arr[], int n, int place){
	int buckets[10][100] = {NULL};
	int temp = (int)pow(10, place - 1);
	for (int i = 0; i < n; i++){
		int row = (arr[i] / temp) % 10;
		for (int j = 0; j < 100; j++){
			if (buckets[row][j] == NULL){
				Count++;
				buckets[row][j] = arr[i];
				break;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 20; j++){
			if (buckets[i][j] != NULL){
				arr[k] = buckets[i][j];
				buckets[i][j] = NULL;
				k++;
			}
		}
	}
}

int main(){
	cout << "**                               �����㷨�Ƚ�                               **" << endl;
	cout << "==============================================================================" << endl;
	cout << "**                              1 --- ð������                              **" << endl;
	cout << "**                              2 --- ѡ������                              **" << endl;
	cout << "**                              3 --- ֱ�Ӳ�������                          **" << endl;
	cout << "**                              4 --- ϣ������                              **" << endl;
	cout << "**                              5 --- ��������                              **" << endl;
	cout << "**                              6 --- ������                                **" << endl;
	cout << "**                              7 --- �鲢����                              **" << endl;
	cout << "**                              8 --- ��������                              **" << endl;
	cout << "**                              9 --- �˳�����                              **" << endl;
	cout << "==============================================================================" << endl;

	int order;

	srand((int)time(NULL));

	cout << "������Ҫ������������ĸ�����";
	cin >> testNum;
	testArr = new int[testNum];
	for (int i = 0; i < testNum; i++)
		testArr[i] = rand() % testNum;

	cout << endl << "��ѡ�������㷨:        ";
	cin >> order;
	while (order != 9){
		switch (order){
		case 1:
			bubble_sort(testArr);
			break;
		case 2:
			selection_sort(testArr);
			break;
		case 3:
			insertion_sort(testArr);
			break;
		case 4:
			shell_sort(testArr);
			break;
		case 5:
			quick_sort(testArr);
			break;
		case 6:
			heap_sort(testArr);
			break;
		case 7:
			merge_sort(testArr);
			break;
		case 8:
			radix_sort(testArr);
			break;
		default:
			cout << "��������!" << endl;
		}
		cout << endl << "��ѡ�������㷨:        ";
		cin >> order;
	}
	return 0;
}