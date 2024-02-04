#include<iostream>
#include<list>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);  //C ǥ�� ������� ����ȭ�� ���� �ڵ�� C++���� ����� �ӵ��� ���̱� ����.
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

		// ���ڿ� ��ȸ�ϸ� ���ڸ� <list>�� �߰�
		for (char c : arrays) {
			if (isdigit(c)) {
				// ���� �а� �ִ� ���ڸ� ����
				currentNumber = currentNumber * 10 + static_cast<long long int>(c - '0');
			}
			else {
				// ���ڰ� �ƴ� ���, ������� ���� ���ڸ� ����Ʈ�� �߰��ϰ� �ʱ�ȭ
				if (currentNumber != 0) {
					List.push_back(currentNumber);
					currentNumber = 0;
				}
			}
		}
		for (j = 0; j < func.length(); j++) {
			if (func.substr(j, 1) == "R") {       
				Rn++;     //Rnī��Ʈ ����
			}
			if (func.substr(j, 1) == "D") {  
				if (List.size() == 0) {
					cout << "error" << endl;
					errorcnt = 1;
					break;
				}
				if (Rn % 2 == 0) {    //Rn ī��Ʈ�� ¦���̸� �տ��� ����
					List.pop_front();
				}
				else {    //Rn ī��Ʈ�� Ȧ���̸� �տ��� ����
					List.pop_back();
				}
			}

		}
		answer = "";
		if (List.size() != 0) {         //������ ������� �ʴٸ�
			if (Rn % 2 == 0) {
				answer += "[";
				for (iter = List.begin(); iter != List.end(); ++iter) {
					if (iter == prev(List.end())) {  //�������϶��� ]�߰�
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
				answer += to_string(*iter);    //�������϶��� ]�߰�
				answer += "]";
			}

		}
		else {
			if (errorcnt == 0) {   //����ְ� errorī��Ʈ�� 0�̸�
				answer += "[";
				answer += "]";
			}
				
		}
		if(errorcnt ==0)    //errorī��Ʈ�� 0�̸� ���
		    cout << answer << endl;
		List.clear();   //�ʱ�ȭ
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