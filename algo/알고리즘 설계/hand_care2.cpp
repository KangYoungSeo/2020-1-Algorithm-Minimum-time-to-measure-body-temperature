#include <iostream>
/*
	탐색 관련 문제임
	해당 제한시간을 가진 모든 탐색 대에 해당 인원이 최단 시간 안에 출력 할 수 있는 방법은??

*/

using namespace std;

int CalculCnt;
int CompareCnt;

struct CheckOut								//소독기 별 정보 저장 구조체
{
	int perTime;								// 해당 소독기 1번 사용시 걸리는 시간
	int Total;								// 소독기를 실제로 사용한 시간
	int FutureTotal;							// 
};

static CheckOut* device;
static int N;

void swap(CheckOut a[], int i, int j) {		//i j 인덱스 값들을 swap
	CheckOut temp;
	temp = a[j]; a[j] = a[i]; a[i] = temp;
}

void MakeHeap(CheckOut a[], int Root, int LastNode) {

	int Parent, LeftSon, RightSon, Son;		// 자식 값

	CheckOut RootValue;

	Parent = Root;							// 부모 정함
	RootValue = a[Root];					// 부모노드에 존재하는 값을 저장먼저 해두기
	LeftSon = 2 * Parent + 1;				// 리스트의 왼쪽 오른쪽 son을 정해두기
	RightSon = LeftSon + 1;

	while (LeftSon < LastNode) {			// LastNode가 LeftSon보다 클경우
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

	while (PeopleCnt < M) {					//인원 수 별로 정렬을 수행
		CompareCnt++;
		PeopleCnt++;
		device[0].FutureTotal += device[0].perTime; CalculCnt+=2;
		device[0].Total += device[0].perTime;
		heapsort();							//미래 시간을 기준으로 sort
	}

	int totalTime = 0;						//검사대 중 가장 검사가 오래 걸리는 시간을 구해 출력
	for (int i = 0; i < N; i++) {
		totalTime = totalTime < device[i].Total ? device[i].Total : totalTime;
		CompareCnt++;
	}

	cout << "최소시간" << totalTime << endl;
	cout << "연산횟수 : " << CalculCnt << endl;
	cout << "비교횟수 : " << CompareCnt << endl;
}

int main() {


	//1. 검사대 개수 입력 및 소독기 한번 사용 시 걸리는 시간 설정

	cout << "검사대 개수 : "; cin >> N; if (N > 100) { return 0; }
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
	//2. 사용자 수 입력
	int M; cout << "사용자 수 : "; cin >> M; //if (M > 5000) { return 0; }

	// 3-2. 순차탐색 후 정렬, 비교를 통한 최소 값 출력
	CountTravel(M);


	return 0;

}