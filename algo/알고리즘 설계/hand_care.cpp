#include <iostream>
/*
	
	������
	1. ȿ������ ������ �Է¹��
	2. ������ �˰����� ������ ���ɿ� ������ ��ĥ�� �Һи�..?
	���ɿ� ������ ��ĥ��??

*/
int CalculCnt;
int CompareCnt;

using namespace std;

struct CheckOut
{
	int perTime;
};

static CheckOut* device;
static int N;

void CountMin(int M) {
	
	CalculCnt = 0; CompareCnt = 0;
	int t = 1;									//���� �ð�
	int maxT = 0;
	int totalMAX;								//�ο� ��� ���� �ִ�ð�
	int MIN = 0;
	int totalNum;
	int mid;

	for (int i = 0; i < N; i++) {				// 1. �˻�� �� ���� �˻簡 ���� �ɸ��� �ð��� ����Ž���� ���� search
		maxT = maxT < device[i].perTime ? device[i].perTime : maxT;
		CompareCnt++;
	}
	totalMAX = maxT * M;						// �� �ð��� ������ �ִ�ð��� MAX�� ����
	CalculCnt++;
	while (MIN < totalMAX) {
		mid = (MIN + totalMAX) / 2;			
		CalculCnt++; CompareCnt++;
		totalNum = 0;							//���� �ð��ȿ� �˻��� �� �ִ� ��� ���

		for (int i = 0; i < N; i++) {				// 2. �˻�� ���� ���� �ð��ȿ� ó���� �� �ִ�
			totalNum += mid / device[i].perTime;	//   ����� ����� ����Ͽ� �߰� 
			CalculCnt+=2;
		}

		if (totalNum > M)	totalMAX = mid;			
		else if (totalNum == M) break;
		else MIN = mid + 1;
		CompareCnt++;
	}

	cout << "�ּҽð�" << mid << endl;
	cout << "����Ƚ�� : " << CalculCnt<<endl;
	cout << "��Ƚ�� : " << CompareCnt << endl;
	
}

int main() {


	//1. �˻�� ���� �Է� �� �ҵ��� �ѹ� ��� �� �ɸ��� �ð� ����

	cout << "�˻�� ���� : "; cin >> N; if (N > 100) { return 0; }

//	N = 6;

	device = new CheckOut[N];
	
	for (int i = 0; i < N; i++) {
		cout << (char)('A' + i) << " : ";
		cin >> device[i].perTime; if (device[i].perTime > 30) { return 0; }
	}
	/*
	device[0].perTime = 5; device[1].perTime = 5;
	device[2].perTime = 6; device[3].perTime = 8;
	device[4].perTime = 8; device[5].perTime = 10;

	*/
	//2. ����� �� �Է�
	int M; cout << "����� �� : "; cin >> M;// if (M > 5000) { return 0; }



	// 3-1. �̺�Ž���� ����� �ִܽð�
	CountMin(M);


	return 0;

}