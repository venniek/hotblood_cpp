#include "BankingCommonDec1.hpp"
#include "Account.hpp"

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