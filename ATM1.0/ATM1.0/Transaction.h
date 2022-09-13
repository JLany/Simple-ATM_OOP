#ifndef TRANSACTION_H
#define TRANSACTION_H

// forward declarations
class Screen;
class BankDatabase;

// abstract class Transaction
class Transaction {
public:
	Transaction(int, Screen*, BankDatabase*); // constructor
	virtual ~Transaction() = default; // virtual destructor set to default

	// NOTE the difference here between a default constructor, and 
	// a constructor set to default. default means it takes no arguments
	// while "set to default" means a compiler generated constructor

	virtual void execute() = 0; // perform transaction, pure virtual

	// for derived classes to access base class members
	int getAccountNumber() const;
	Screen* getScreen() const;
	BankDatabase* getBankDatabase() const;
private:
	Screen* screen;
	BankDatabase* bankDatabase;
	int accountNumber; // account to which apply transaction
}; // end class Transaction

#endif // TRANSACTION_H
