#ifndef ACCOUNT_H
#define ACCOUNT_H

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
	Account& operator=(const Account &origin);
	~Account();
};

#endif