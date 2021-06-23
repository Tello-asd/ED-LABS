#include <iostream>
#include <string>
#include "Table.h"
#include "List.h"
#include "bitcoin_accounts.h"
using namespace std;


int main(){
	int numCases;

	cin >> numCases;
	for (int i = 0; i < numCases; i++){
		Bitcoin bitcoin = Bitcoin();
		int numOperations;
		cin >> numOperations;
		for (int j = 0; j < numOperations; j++){
			char operation;
			cin >> operation;

			if (operation == 'd'){
				string owner, owneraccount;
				int moneydeposit;
				cin >> owner >> owneraccount >> moneydeposit;
				bitcoin.deposit(owner,owneraccount,moneydeposit);
			}

			else if (operation == 't'){
				string accountreceiver, accountsender,receiver,sender;
				int money;
				cin >> sender >> accountsender >> receiver >> accountreceiver >> money;
				bitcoin.transfer(sender,accountsender,receiver,accountreceiver,money);
			}

			else if (operation == 'm'){
				string person;
				int result;
				cin >> person;
				result = bitcoin.money(person);
				cout << result << endl;
			}
		}

	}
	return 0;
}





