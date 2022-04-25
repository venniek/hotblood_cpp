#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include "Account.hpp"
#include "AccountArray.hpp"

class AccountHandler {
private:
	BoundCheckAccountPtrArray infos;
	int cnt;
public:
	void showMenu() const;
	void makeNewAccount();
	void deposit();
	void withdraw();
	void print();

	AccountHandler(int cnt);
	~AccountHandler();
};

#endif