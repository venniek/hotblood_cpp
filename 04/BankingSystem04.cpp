#include <iostream>
#include <cstring>
using namespace std;

class Account {
private:
	int ID;
	int balance;
	char *name;
public:
	int getID() const { return ID; }
	int getBalance() const { return balance; }
	char *getName() const { return name; }
	void setID(int id) { this->ID = id; }
	void setBalance(int balance) { this->balance = balance; }
	void setName(char *name) { strcpy(this->name, name); }

	void depositMoney(int add) {
		balance += add;
		cout << "입금이 끝났습니다. 잔액은 " << balance << "원입니다." << endl;
	}
	void withdrawMoney(int withdraw) {
		if (balance < withdraw)
			cout << "잔액이 부족합니다." << endl;
		else {
			balance -= withdraw;
			cout << "출금이 끝났습니다. 잔액은 " << balance << "원입니다." << endl;
		}
	}
	void showInfo() const {
		cout << "계좌ID: " << ID << endl;
		cout << "이름: " << name << endl;
		cout << "잔액: " << balance << endl;
	}

	Account() {
		this->name = new char[100];
	}
	Account(int id, int balance, char *name) : ID(id), balance(balance) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		if (balance < 0) {
			cout << "잔액이 음수일 수 없습니다. 0으로 초기화합니다." << endl;
			balance = 0;
		}
	}
	Account(const Account &copy) {
		ID = copy.getID();
		balance = copy.getBalance();
		this->name = new char[strlen(copy.name) + 1];
		strcpy(this->name, copy.name);
	}
	~Account() {
		delete []name;
	}
};

Account *infos[100];
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
	char *name = new char[100];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;

	infos[cnt] = new Account(account, balance, name);
	cnt++;
	delete[] name;
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
		if (account == infos[i]->getID()) {
			infos[i]->depositMoney(input);
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
		if (account == infos[i]->getID()) {
			infos[i]->withdrawMoney(output);
			return;
		}
	}
	cout << "ID를 찾지 못했습니다." << endl;
}

void print() {
	cout << "==Accounts Info===========" << endl << endl;
	for (int i = 0; i < cnt; i++) {
		infos[i]->showInfo();
		cout << endl;
	}
	cout << "==========================" << endl;
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