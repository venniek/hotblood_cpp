#include "BankingCommonDec1.hpp"
#include "AccountHandler.hpp"

int main() {
	int select;
	AccountHandler infos;

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