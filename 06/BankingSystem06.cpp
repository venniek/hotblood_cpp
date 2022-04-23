#include <iostream>
#include <cstring>
using namespace std;

class Account {
private:
	int ID;
	int balance;
	char *name;
public:
	int getID() const;
	int getBalance() const;
	char *getName() const;

	virtual void depositMoney(int add);
	void withdrawMoney(int withdraw);
	void showInfo() const;

	Account(int id, int balance, char *name);
	Account(const Account &copy);
	~Account();
};

int Account::getID() const {
	return ID;
}

int Account::getBalance() const {
	return balance;
}

char *Account::getName() const {
	return name;
}

void Account::depositMoney(int add) {
	balance += add;
}

void Account::withdrawMoney(int withdraw) {
	if (balance < withdraw)
		cout << "잔액이 부족합니다." << endl;
	else
		balance -= withdraw;
}
void Account::showInfo() const {
	cout << "계좌ID: " << ID << endl;
	cout << "이름: " << name << endl;
	cout << "잔액: " << balance << endl;
}

Account::Account(int id, int balance, char *name) : ID(id), balance(balance) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	if (balance < 0) {
		cout << "잔액이 음수일 수 없습니다. 0으로 초기화합니다." << endl;
		balance = 0;
	}
}

Account::Account(const Account &copy) {
	ID = copy.getID();
	balance = copy.getBalance();
	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);
}

Account::~Account() {
	delete []name;
}

class NormalAccount: public Account {
private:
	int interest;
public:
	int getInterest() const;
	virtual void depositMoney(int add);

	NormalAccount(int id, int balance, char *name, int interest);
	~NormalAccount();
};

int NormalAccount::getInterest() const {
	return interest;
}

void NormalAccount::depositMoney(int add) {
	Account::depositMoney(add);
	Account::depositMoney(add * interest / 100);
}

NormalAccount::NormalAccount(int id, int balance, char *name, int interest): Account(id, balance, name), interest(interest) { }

NormalAccount::~NormalAccount() {}

class HighCreditAccount: public NormalAccount {
private:
	int special;
	char rank;
public:
	char getRank() const;
	virtual void depositMoney(int add);

	HighCreditAccount(int id, int balance, char *name, int interest, char rank);
	~HighCreditAccount();
};

char HighCreditAccount::getRank() const {
	return rank;
}

void HighCreditAccount::depositMoney(int add) {
	NormalAccount::depositMoney(add);
	Account::depositMoney(add * special / 100);
}

HighCreditAccount::HighCreditAccount(int id, int balance, char *name, int interest, char rank): NormalAccount(id, balance, name, interest), rank(rank) {
	if (rank == 'A')
		special = 7;
	else if (rank == 'B')
		special = 4;
	else if (rank == 'C')
		special = 2;
	else {
		cout << "잘못된 등급입니다. C등급으로 설정합니다." << endl;
		rank = 'C';
		special = 2;
	}
};

HighCreditAccount::~HighCreditAccount() {};

class Info {
private:
	Account *infos[100];
	int cnt;
public:
	void showMenu();
	void makeNewAccount();
	void deposit();
	void withdraw();
	void print();

	Info();
	~Info();
};

void Info::showMenu() {
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void Info::makeNewAccount() {
	int account;
	char *name = new char[100];
	int balance;
	int type;
	int interest;
	char rank;

	cout << "[계좌 종류 선택]" << endl << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> type;
	cout << (type == 1 ? "[보통예금계좌" : "[신용신뢰계좌") << " 개설]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> interest;
	if (type == 2) {
		cout << "신용 등급(A, B, C): ";
		cin >> rank;
		infos[cnt] = new HighCreditAccount(account, balance, name, interest, rank);
	}
	else
		infos[cnt] = new NormalAccount(account, balance, name, interest);
	cnt++;
	delete[] name;
}

void Info::deposit() {
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
			cout << "입금이 끝났습니다. 잔액은 " << infos[i]->getBalance() << "원입니다." << endl;
			return;
		}
	}
	cout << "ID를 찾지 못했습니다." << endl;
}

void Info::withdraw() {
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
			cout << "출금이 끝났습니다. 잔액은 " << infos[i]->getBalance() << "원입니다." << endl;
			return;
		}
	}
	cout << "ID를 찾지 못했습니다." << endl;
}

void Info::print() {
	cout << "==Accounts Info===========" << endl << endl;
	for (int i = 0; i < cnt; i++) {
		infos[i]->showInfo();
		cout << endl;
	}
	cout << "==========================" << endl;
}

Info::Info(): cnt(0) { }

Info::~Info() {
	for (int i = 0; i < cnt; i++)
		delete infos[i];
}

int main() {
	int select;
	Info infos;

	while (1) {
		infos.showMenu();
		cout << "선택: ";
		cin >> select;
		cout << endl;
		switch (select) {
		case 1:
			infos.makeNewAccount();
			break;
		case 2:
			infos.deposit();
			break;	
		case 3:
			infos.withdraw();
			break;
		case 4:
			infos.print();
			break;
		case 5:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		cout << endl;
	}
	return 0;
}