#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char arr[80]; //OX 들어갈 문자열
	int score = 0;
	int sum = 0;
	int N; // 테스트 케이스 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr;// 배열에 문자열 입력

		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == 'O') {
				score++; // 점수 증가
				sum += score; // 점수 누적

			}
			if (arr[j] == 'X') {
				score = 0; // 점수 초기화
			}
		}
		cout << sum << endl;
		sum = 0; // sum 초기화
		score = 0; // 점수 증가량 초기화

	}
	return 0;
}