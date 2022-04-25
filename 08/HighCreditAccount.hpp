#ifndef HIGHCREDITACCOUNT_H
#define HIGHCREDITACCOUNT_H

# include "NormalAccount.hpp"

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

#endif