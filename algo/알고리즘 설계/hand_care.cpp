#include <iostream>
/*
	
	문제점
	1. 효율적인 데이터 입력방법
	2. 제시한 알고리즘이 실제로 성능에 영향을 미칠지 불분명..?
	성능에 영향을 미칠까??

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
	int t = 1;									//기준 시간
	int maxT = 0;
	int totalMAX;								//인원 대비 기준 최대시간
	int MIN = 0;
	int totalNum;
	int mid;

	for (int i = 0; i < N; i++) {				// 1. 검사대 중 가장 검사가 오래 걸리는 시간을 순차탐색을 통해 search
		maxT = maxT < device[i].perTime ? device[i].perTime : maxT;
		CompareCnt++;
	}
	totalMAX = maxT * M;						// 총 시간의 가능한 최대시간을 MAX로 기준
	CalculCnt++;
	while (MIN < totalMAX) {
		mid = (MIN + totalMAX) / 2;			
		CalculCnt++; CompareCnt++;
		totalNum = 0;							//기준 시간안에 검사할 수 있는 사람 명수

		for (int i = 0; i < N; i++) {				// 2. 검사대 별로 기준 시간안에 처리할 수 있는
			totalNum += mid / device[i].perTime;	//   사람의 명수를 계산하여 추가 
			CalculCnt+=2;
		}

		if (totalNum > M)	totalMAX = mid;			
		else if (totalNum == M) break;
		else MIN = mid + 1;
		CompareCnt++;
	}

	cout << "최소시간" << mid << endl;
	cout << "연산횟수 : " << CalculCnt<<endl;
	cout << "비교횟수 : " << CompareCnt << endl;
	
}

int main() {


	//1. 검사대 개수 입력 및 소독기 한번 사용 시 걸리는 시간 설정

	cout << "검사대 개수 : "; cin >> N; if (N > 100) { return 0; }

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
	//2. 사용자 수 입력
	int M; cout << "사용자 수 : "; cin >> M;// if (M > 5000) { return 0; }



	// 3-1. 이분탐색을 사용한 최단시간
	CountMin(M);


	return 0;

}