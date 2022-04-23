#include "BankingCommonDec1.hpp"
#include "AccountHandler.hpp"
#include "HighCreditAccount.hpp"

void AccountHandler::showMenu() const {
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::makeNewAccount() {
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

void AccountHandler::deposit() {
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

void AccountHandler::withdraw() {
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

void AccountHandler::print() {
	cout << "==Accounts Info===========" << endl << endl;
	for (int i = 0; i < cnt; i++) {
		infos[i]->showInfo();
		cout << endl;
	}
	cout << "==========================" << endl;
}

AccountHandler::AccountHandler(): cnt(0) { }

AccountHandler::~AccountHandler() {
	for (int i = 0; i < cnt; i++)
		delete infos[i];
}