#include <iostream>
#include <string>
using namespace std;

typedef struct s_info {
	int account;
	string name;
	int balance;
} t_info;

t_info infos[100];
int cnt = 0;

void showMenu() {
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void makeNewAccount() {
	int account;
	string name;
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	infos[cnt].account = account;
	infos[cnt].name = name;
	infos[cnt].balance = balance;
	cnt++;
}

void deposit() {
	int account;
	int input;
	
	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	cout << "입금액: ";
	cin >> input;
	for (int i = 0; i < cnt; i++) {
		if (account == infos[i].account) {
			infos[i].balance += input;
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "ID를 찾지 못했습니다." << endl;
}

void withdraw() {
	int account;
	int output;
	
	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	cout << "출금액: ";
	cin >> output;
	for (int i = 0; i < cnt; i++) {
		if (account == infos[i].account) {
			if (infos[i].balance >= output) {
				infos[i].balance -= output;
				cout << "출금완료" << endl;
			}
			else {
				cout << "잔액이 부족합니다." << endl;
			}
			return;
		}
	}
	cout << "ID를 찾지 못했습니다." << endl;
}

void print() {
	for (int i = 0; i < cnt; i++) {
		cout << "계좌ID: " << infos[i].account << endl;
		cout << "이름: " << infos[i].name << endl;
		cout << "잔액: " << infos[i].balance << endl << endl;
	}
}


int main() {
	int select;

	while (1) {
		showMenu();
		cout << "선택: ";
		cin >> select;
		cout << endl;
		switch (select) {
		case 1:
			makeNewAccount();
			break;
		case 2:
			deposit();
			break;	
		case 3:
			withdraw();
			break;
		case 4:
			print();
			break;
		case 5:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		cout << endl;
	}
	return 0;
}