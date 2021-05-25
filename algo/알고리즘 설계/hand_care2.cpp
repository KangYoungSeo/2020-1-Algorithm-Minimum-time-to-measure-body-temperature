#include <iostream>
/*
	Ž�� ���� ������
	�ش� ���ѽð��� ���� ��� Ž�� �뿡 �ش� �ο��� �ִ� �ð� �ȿ� ��� �� �� �ִ� �����??

*/

using namespace std;

int CalculCnt;
int CompareCnt;

struct CheckOut								//�ҵ��� �� ���� ���� ����ü
{
	int perTime;								// �ش� �ҵ��� 1�� ���� �ɸ��� �ð�
	int Total;								// �ҵ��⸦ ������ ����� �ð�
	int FutureTotal;							// 
};

static CheckOut* device;
static int N;

void swap(CheckOut a[], int i, int j) {		//i j �ε��� ������ swap
	CheckOut temp;
	temp = a[j]; a[j] = a[i]; a[i] = temp;
}

void MakeHeap(CheckOut a[], int Root, int LastNode) {

	int Parent, LeftSon, RightSon, Son;		// �ڽ� ��

	CheckOut RootValue;

	Parent = Root;							// �θ� ����
	RootValue = a[Root];					// �θ��忡 �����ϴ� ���� ������� �صα�
	LeftSon = 2 * Parent + 1;				// ����Ʈ�� ���� ������ son�� ���صα�
	RightSon = LeftSon + 1;

	while (LeftSon < LastNode) {			// LastNode�� LeftSon���� Ŭ���
		CompareCnt+=3;
		if (RightSon <= LastNode && a[LeftSon].FutureTotal < a[RightSon].FutureTotal) {	
			Son = RightSon;
		}


		else Son = LeftSon;
		if (RootValue.FutureTotal < a[Son].FutureTotal) {
			a[Parent] = a[Son];
			Parent = Son;
			LeftSon = Parent * 2 + 1;
			RightSon = LeftSon + 1;

		}
		else break;

	}
	a[Parent] = RootValue;
}
void heapsort() {
	int i;
	for (i = N / 2; i > 0; i--)  MakeHeap(device, i - 1, N - 1);
	for (i = N - 1; i > 0; i--) { swap(device, 0, i); MakeHeap(device, 0, i - 1); }

}



void CountTravel(int M) {

	CalculCnt = 0; CompareCnt = 0;
	int PeopleCnt = 0;

	while (PeopleCnt < M) {					//�ο� �� ���� ������ ����
		CompareCnt++;
		PeopleCnt++;
		device[0].FutureTotal += device[0].perTime; CalculCnt+=2;
		device[0].Total += device[0].perTime;
		heapsort();							//�̷� �ð��� �������� sort
	}

	int totalTime = 0;						//�˻�� �� ���� �˻簡 ���� �ɸ��� �ð��� ���� ���
	for (int i = 0; i < N; i++) {
		totalTime = totalTime < device[i].Total ? device[i].Total : totalTime;
		CompareCnt++;
	}

	cout << "�ּҽð�" << totalTime << endl;
	cout << "����Ƚ�� : " << CalculCnt << endl;
	cout << "��Ƚ�� : " << CompareCnt << endl;
}

int main() {


	//1. �˻�� ���� �Է� �� �ҵ��� �ѹ� ��� �� �ɸ��� �ð� ����

	cout << "�˻�� ���� : "; cin >> N; if (N > 100) { return 0; }
//	N = 6;

	device = new CheckOut[N];
	for (int i = 0; i < N; i++) {
		cout << (char)('A' + i) << " : ";
		cin >> device[i].perTime;
		device[i].Total = 0;
		device[i].FutureTotal = device[i].perTime;
	}


	/*
	device[0].perTime = 5; device[1].perTime = 5;
	device[2].perTime = 6; device[3].perTime = 8;
	device[4].perTime = 8; device[5].perTime = 10;
	for (int i = 0; i < N; i++) {
		device[i].Total = 0;
		device[i].FutureTotal = device[i].perTime;
	}
*/
	//2. ����� �� �Է�
	int M; cout << "����� �� : "; cin >> M; //if (M > 5000) { return 0; }

	// 3-2. ����Ž�� �� ����, �񱳸� ���� �ּ� �� ���
	CountTravel(M);


	return 0;

}