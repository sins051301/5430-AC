#include<iostream>
#include<list>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);  //C 표준 입출력의 동기화를 끄는 코드로 C++에서 입출력 속도를 높이기 위함.
	cin.tie(0);
	cout.tie(0);
	list<long long int> List;
	list<long long int>::iterator iter;
	long long int testcase, i, num, j, Rn=0, currentNumber, errorcnt =0;
	string func, arrays, separator = ",", answer;
	cin >> testcase;
	for (i = 0; i < testcase; i++) {
		cin >> func;
		cin >> num;
		cin >> arrays;
		currentNumber = 0;

		// 문자열 순회하며 숫자만 <list>에 추가
		for (char c : arrays) {
			if (isdigit(c)) {
				// 현재 읽고 있는 숫자를 갱신
				currentNumber = currentNumber * 10 + static_cast<long long int>(c - '0');
			}
			else {
				// 숫자가 아닌 경우, 현재까지 읽은 숫자를 리스트에 추가하고 초기화
				if (currentNumber != 0) {
					List.push_back(currentNumber);
					currentNumber = 0;
				}
			}
		}
		for (j = 0; j < func.length(); j++) {
			if (func.substr(j, 1) == "R") {       
				Rn++;     //Rn카운트 증가
			}
			if (func.substr(j, 1) == "D") {  
				if (List.size() == 0) {
					cout << "error" << endl;
					errorcnt = 1;
					break;
				}
				if (Rn % 2 == 0) {    //Rn 카운트가 짝수이면 앞에서 삭제
					List.pop_front();
				}
				else {    //Rn 카운트가 홀수이면 앞에서 삭제
					List.pop_back();
				}
			}

		}
		answer = "";
		if (List.size() != 0) {         //완전히 비어있지 않다면
			if (Rn % 2 == 0) {
				answer += "[";
				for (iter = List.begin(); iter != List.end(); ++iter) {
					if (iter == prev(List.end())) {  //끝문자일때만 ]추가
						answer += to_string(*iter);
						answer += "]";
					}
					else {
						answer += to_string(*iter);
						answer += ",";
					}

				}
			}
			else {
				answer += "[";
				for (iter = prev(List.end()); iter != List.begin(); --iter) {
					answer += to_string(*iter);
					answer += ",";
				}
				answer += to_string(*iter);    //끝문자일때만 ]추가
				answer += "]";
			}

		}
		else {
			if (errorcnt == 0) {   //비어있고 error카운트가 0이면
				answer += "[";
				answer += "]";
			}
				
		}
		if(errorcnt ==0)    //error카운트가 0이면 출력
		    cout << answer << endl;
		List.clear();   //초기화
		Rn = 0;
		errorcnt = 0;
	}
	
}

/*
2
DRRDRDD
3
[43,97,100]
RD
3
[10,9,8]

error
[9,10]
*/