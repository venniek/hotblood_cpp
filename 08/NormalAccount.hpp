#ifndef NORMALACCOUNT_H
#define NORMALACCOUNT_H

# include "Account.hpp"

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

#endif