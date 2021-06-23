#ifndef BITCOIN_H_
#define BITCOIN_H_
#include "Table.h"
#include <string>
#include "List.h"
#include <iostream>
using namespace std;

class Bitcoin{

	typedef string person;
	typedef string account;

private:

    Table<person,Table<account,int>> bitcoin;

public:


    void deposit(const person& owner, const account& acc, int money){
    	//If owner exists...
    	if(this->bitcoin.exists(owner)){
    		//if account exists...
    		if (this->bitcoin.get(owner).exists(acc)){
    				this->bitcoin.get(owner).insert(acc,money);

    		}
    		else{ //If account doesn't exist...
    			this->bitcoin.get(owner).insert(acc,money);
    		}

    	}
    	//If owner doesn't exist...
    	else{
    		this->bitcoin.insert(owner,Table<account,int>());
    		this->bitcoin.get(owner).insert(acc,money);
    	}
    }

    void transfer(const person& sender, const account& accsender, const person receiver, const account accreceiver, int money){
    	//Check that the sender exists...
    	if (this->bitcoin.exists(sender)){
    		//Check that the sender account exists...
    		if(this->bitcoin.get(sender).exists(accsender)){
    			//Check that the sender account has enough money to give...
    			if (this->bitcoin.get(sender).get(accsender) >= money){
    					this->bitcoin.get(sender).get(accsender) = this->bitcoin.get(sender).get(accsender) - money;
    						//If the receiver doesn't exist...
    					if (!this->bitcoin.exists(receiver)){
    						this->bitcoin.insert(receiver,Table<account,int>());
    						//We insert the account and the money to the receiver...
    						this->bitcoin.get(receiver).insert(accreceiver,money);
    					}
    					else{ //If the account of the receiver doesn't exist...
    						if(!this->bitcoin.get(receiver).exists(accreceiver)){
    							this->bitcoin.get(receiver).insert(accreceiver,money);
    						}
    						else{
    							//If the account exists, then we do the deposit.
    							this->bitcoin.get(receiver).get(accreceiver) = this->bitcoin.get(receiver).get(accreceiver) + money;
    						}
    					}
    			}

    		}
    		//ELSE: If the sender account doesn't exist, the money can't be sent.
    	}
    	//ELSE: If the sender doesn't exist, the money can't be sent.
    }

    int money(person p){
    	int sum_bitcoins = 0;

    	if (this->bitcoin.exists(p)){
    		Table<account,int>::Iterator it = this->bitcoin.get(p).begin(); 
    		
    		while (it != this->bitcoin.get(p).end()){
    			sum_bitcoins = sum_bitcoins + it.value();
    			it.next();
    		}
    	}

    	return sum_bitcoins;
    }

};




#endif 
