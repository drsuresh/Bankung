//This program is pretty much the system of how banks operate

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int max = 1000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//customer interface
//basic add/subtract money from balance (total), transfering to different balance
struct customertype
{
	int counterN = 0;
	double checking[max];
	double saving[max];
	string identity;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//bankteller and employee interface bank1 + bank2
//must be able to add/delete users, search users
struct employeetype
{
	string name[max];
	int found = 0;
	int search = 0;

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// bank supervisor/manager interface bank1+bank2+bank3
//displays: total number of users, total balances, total deposits, total withdraws, detailed LOG (big challenge)
struct managertype
{
	double withdraw;
	double deposit;
	double total;
	fstream log;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readFile(customertype &customer, employeetype &employee, managertype &manager);
//Menu display functions
void mainMenu(char input, customertype &customer, employeetype &employee, managertype &manager);
void customerUI();
void tellerUI();
void managerUI();
//The menu actions
void customerActions(char input, customertype &customer, employeetype &employee, managertype &manager);
void tellerActions(char input, customertype &customer, employeetype &employee, managertype &manager);
void managerActions(char input, customertype &customer, employeetype &employee, managertype &manager);
//Identifying the person
void identify();
//Menu functions
void balanceInquiry(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void depositMoney(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void withdrawMoney(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void transferMoney(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void addCustomer(customertype &customer, employeetype &employee, managertype &manager);
void delCustomer(customertype &customer, employeetype &employee, managertype &manager);
void searchRecord(char input, customertype &customer, employeetype &employee, managertype &manager);
void totalCustomers(char input, customertype &customer, employeetype &employee, managertype &manager);
void totalMoney(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void totalDeposits(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void totalWithdrawals(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void logger(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work
void identify(char input, customertype &customer, employeetype &employee, managertype &manager);//needs work

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void identify(char input, customertype &customer, employeetype &employee, managertype &manager)
{

}
void searchRecord(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	string searchInput;
	cout << "What is the person's name?: ";
	cin >> searchInput;
	while (employee.found < customer.counterN)
	{
		if (employee.name[employee.found] == searchInput)
		{
			cout << "The person is in the database!" << endl << endl;
			break;
		}
		else
		{
			employee.found++;
		}
	}
	cout << "Would you like to continue? Y/N" << endl;
	cin >> input;
	if (tolower(input) == 'y')
	{
		searchRecord(input, customer, employee, manager);
	}
	else if (tolower(input) == 'n')
	{
		mainMenu(input, customer, employee, manager);
	}
}
void customerUI()
{
	cout << endl;
	cout << "Welcome to Austen's House of Surprise!, please choose an action." << endl;
	cout << "a.	Functions: Balance Inquiry" << endl;
	cout << "b.	Deposit Funds" << endl;
	cout << "c.	Withdraw funds" << endl;
	cout << "d.	Transfer Funds to another account (like from Checking to Savings or to Credit Card)" << endl;
}
void customerActions(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	if (input == 'a')
	{
		balanceInquiry(input, customer, employee, manager);
	}
	else if (input == 'b')
	{
		
	}
	else if (input == 'c')
	{
		
	}
	else if (input == 'd')
	{
		
	}
	else if (tolower(input) == 'x')
	{
		exit(1);
	}
}
void tellerUI()
{
	customerUI();
	cout << "e. ADD a new Customer to the Bank" << endl;
	cout << "f. DELETE a  Customer from the Bank" << endl;
	cout << "g. Search for a Record based on a “Name of a Customer" << endl;

}
void tellerActions(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	if (input == 'a')
	{
		balanceInquiry(input, customer, employee, manager);
	}
	else if (input == 'b')
	{
		
	}
	else if (input == 'c')
	{
		
	}
	else if (input == 'd')
	{
		
	}
	else if (input == 'e')
	{
		addCustomer(customer, employee, manager);
	}
	else if (input == 'f')
	{
		delCustomer(customer, employee, manager);
	}
	else if (input == 'g')
	{
		searchRecord(input, customer, employee, manager);
	}
	else if (tolower(input) == 'x')
	{
		exit(1);
	}
}
void managerUI()
{
	customerUI();
	tellerUI();
	cout << "1. List Total Number of Customers in Bank" << endl;
	cout << "2. List Total Amount of Money in the Bank" << endl;
	cout << "3. List Total Deposits in a Day" << endl;
	cout << "4. List Total Withdrawals in a Day" << endl;
	cout << "5. see/query detailed LOG of all transactions" << endl;
}
void managerActions(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	if (input == 'a')
	{
		balanceInquiry(input, customer, employee, manager);
	}
	else if (input == 'b')
	{
		
	}
	else if (input == 'c')
	{
		
	}
	else if (input == 'd')
	{
		
	}
	else if (input == 'e')
	{
		addCustomer(customer, employee, manager);
	}
	else if (input == 'f')
	{
		delCustomer(customer, employee, manager);
	}
	else if (input == 'g')
	{
		searchRecord(input, customer, employee, manager);
	}
	else if (input == '1')
	{
		totalCustomers(input, customer, employee, manager);

	}
	else if (input == '2')
	{
		totalMoney(input, customer, employee, manager);
	}
	else if (input == '3')
	{
		totalDeposits(input, customer, employee, manager);
	}
	else if (input == '4')
	{
		totalWithdrawals(input, customer, employee, manager);
	}
	else if (input == '5')
	{
		
	}
	else if (tolower(input) == 'x')
	{
		exit(1);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void balanceInquiry(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	cout << "Hello " << employee.name[customer.counterN] << ", your balance is ";
	cout << "Is there anything else you would like to do from the menu?" << endl;
	customerActions(input, customer, employee, manager);
}
void depositMoney(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	
}
void withdrawMoney(char input, customertype &customer, employeetype &employee, managertype &manager)
{

}
void transferMoney(char input, customertype &customer, employeetype &employee, managertype &manager)
{

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readFile(customertype &customer, employeetype &employee, managertype &manager)
{
	ifstream inFile;
	inFile.open("bank.txt");
	inFile >> employee.name[customer.counterN] >> customer.checking[customer.counterN];
	cout << "name: " << employee.name[customer.counterN] << " " << customer.checking[customer.counterN] << endl;
	while (!inFile.eof())
		customer.counterN++;
		inFile >> employee.name[customer.counterN] >> customer.checking[customer.counterN];
		cout << "name: " << employee.name[customer.counterN] << " " << customer.checking[customer.counterN] << endl;
		inFile.close();
}
int main()
{
	customertype customer;
	employeetype employee;
	managertype manager;
	char input = 0;

	/*readFile(customer, employee, manager);*/
	mainMenu(input, customer, employee, manager);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	ifstream inFile;
	cout << "Are you a (c)ustomer, (e)mployee, or (m)anager?" << endl;
	cin >> input;
	if (input == 'c')
	{
		cout << endl;
		cout << "X. Exit program." << endl;
		customerUI();
		cin >> input;
		customerActions(input, customer, employee, manager);
		if (tolower(input) == 'x')
		{
			exit(1);
		}

	}
	else if (input == 'e')
	{
		cout << endl;
		cout << "X. Exit program." << endl;
		tellerUI();
		cin >> input;
		tellerActions(input, customer, employee, manager);
		if (tolower(input) == 'x')
		{
			exit(1);
		}
	}
	else if (input == 'm')
	{
		cout << endl;
		cout << "X. Exit program." << endl;
		managerUI();
		cin >> input;
		managerActions(input, customer, employee, manager);
		if (tolower(input) == 'x')
		{
			exit(1);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void addCustomer(customertype &customer, employeetype &employee, managertype &manager)
{
	char input;
	string name;
	cout << "What is the person's first name you want to add?" << endl;
	cout << "Name: ";
	cin >> name;
	employee.name[customer.counterN] = name;
	customer.counterN++;
	cout << "Person is added! What's next?" << endl;
	cout << "(A)dd more or (E)xit to main menu." << endl;
	cin >> input;
	if (tolower(input) == 'a')
	{
		addCustomer(customer, employee, manager);
	}
	else if (tolower(input) == 'e')
	{
		mainMenu(input, customer, employee, manager);
	}
}
void delCustomer(customertype &customer, employeetype &employee, managertype &manager)
{
	char input;
	string inputSearch;
	cout << "Who would you like to remove from the list?" << endl;
	cin >> inputSearch;
	employee.found = 0;
	while (employee.found < customer.counterN)
	{
		if (employee.name[employee.found] == inputSearch)
		{

			for (int i = employee.found; i <= customer.counterN; employee.found++)
			{
				employee.name[i] = employee.name[i++];
			}
			customer.counterN--;
			cout << "The person has been successfully removed!" << endl << endl;
			break;
		}
		else
		{
			employee.found++;
		}
	}
	cout << "Would you like to continue? Y/N" << endl;
	cin >> input;
	if (tolower(input) == 'y')
	{
		delCustomer(customer, employee, manager);
	}
	else if (tolower(input) == 'n')
	{
		mainMenu(input, customer, employee, manager);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void totalCustomers(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	cout << "The current total customer at the bank is: " << customer.counterN << endl;
	cout << "Is there anything else you would like to do from the menu?" << endl;
	cin >> input;
	managerActions(input, customer, employee, manager);
}
void totalMoney(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	for (int i = 0; i < customer.counterN; i++)
	{
		manager.total += customer.checking[customer.counterN];
	}
	cout << "The total money in the bank: " << manager.total << endl;
	cout << "Is there anything else you would like to do from the menu?" << endl;
	managerActions(input, customer, employee, manager);
}
void totalDeposits(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	cout << "The total deposity today: " << manager.deposit << endl;
	cout << "Is there anything else you would like to do from the menu?" << endl;
	managerActions(input, customer, employee, manager);
}
void totalWithdrawals(char input, customertype &customer, employeetype &employee, managertype &manager)
{
	cout << "The total withdraw today: " << manager.withdraw << endl;
	cout << "Is there anything else you would like to do from the menu?" << endl;
	managerActions(input, customer, employee, manager);
}