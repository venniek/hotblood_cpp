#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

# include "Account.hpp"

class AccountHandler {
private:
	Account *infos[100];
	int cnt;
public:
	void showMenu() const;
	void makeNewAccount();
	void deposit();
	void withdraw();
	void print();

	AccountHandler();
	~AccountHandler();
};

#endif