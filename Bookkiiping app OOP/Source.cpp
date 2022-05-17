#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
Change log
------------
1. Started making viewBudget()
2. created stringOtherExpensesVector;
3. Made stringOtherExpensesVector work
4. created a function called  fillVector() that fills stringOtherExpensesVector; and placed it at the start of the main() function.
5. Made char inputChar; into a global variable
6. Made a switch table into the viewBudget() that opens addExpense() or viewExpense()
7. created mainMenu() for the main menu.
8. made main() to only write data to stringOtherExpensesVector; and it now opens mainMenu().
9. FIXED INFINITY LOOP BUG THAT WAS IN THE for loop at the line 178.
10. Changed float values to doubles.
11. Started making addExpense() and got it half done.
12. created devTerminal() where you can try functions and features.
13. Made billsSpendVectorDouble and otherExpensesSpendVectorDouble.
14. Made billsSpendVectorDouble Save information and print it in viewBudget!!!! and created a bug where otherExpensesSpendVectorDouble wont print again[Expression: Vector Subscript out of range]
15. Vector Subscript error still occures in the viewBudget()
16. The problem is that insert is adding a new ELEMENT in to the array and not adding data to an existing element.
For future
----------
1. Make stringOtherExpensesVector work and save "housing", "food", "transport" there. (DONE)
2. Complete viewBudget()
3. Create mainMenu() and make the main() to start it. in clear english separate main menu from main(). (DONE)
4. Create addExpense() and viewExpense().
5. Make the expenses minus from totalSum so it can display it.
6. Change all Type floats to doubles. (DONE)
7. fix the way spending is saved in to the "database". (DONE)
8. [FEATURE]Kun maksaa laskun niin sovellus kertoo k‰ytt‰j‰lle budjetissa teoreettisesti varatun rahanm‰‰r‰n ja todellisuudessa maksetun osion erotuksen (esim: Budjetin s‰hkˆlasku 8.50e - tod.maksettu 8.00e = 0.50e buidjetti ylij‰‰m‰‰. 
9. Fix when in viewBudget() printing spend second time the otherExpensesSpendVectorDouble wont print.
*/

// "DataBase"
vector<double> billsVectorDouble; 
vector<string> billsVectorString;
vector<double> billsSpendVectorDouble;

vector<double> otherExpensesVectorDouble;
vector<double> otherExpensesSpendVectorDouble;
vector<string> otherExpensesVectorString;


//global variables and function initialization .
char   inputChar;
string inputString;
double inputDouble;
int    inputInt;
double totalBudgetSum;
double totalBills;
double totalMonthsSpending = 0.00;
double netIncome;
double fuelKilometers;
double fuelUsage;
double fuelCost;
double fuelTotal;
int countIndex = 0;
int    mainMenu();
int    createBudget();
int    viewBudget();
int    incomeInfo();
int    backToMainMenu();
int    devTerminal();
int    addExpense();
int	   calcCarFuelCost();
int    calcOtherTransportCost();
int    addExtraExpense();
int main()
{
	int fillVector();
	{
		otherExpensesVectorString.push_back("Housing");
		otherExpensesVectorString.push_back("Food");
	}

	mainMenu();
	return 0;
}

//Modular functions that can be used in multiple menus.
int	calcCarFuelCost()
{
	otherExpensesVectorString.push_back("Fuel");

	cout << "How many kilometers do you drive in a week?" << endl;
	cout << "kilometers: ";
	cin >> fuelKilometers;
	cin.get();

	cout << "What is the average fuel consumption in liters per 100km for your car?" << endl;;
	cout << "Liters: ";
	cin >> fuelUsage;
	cin.get();

	cout << "How much did the fuel cost at the gas station per litre last time you where there?" << endl;
	cout << "cost: ";
	cin >> fuelCost;
	cin.get();

	fuelTotal = ((fuelKilometers / 100) * fuelUsage * fuelCost) * 4;
	otherExpensesVectorDouble.push_back(fuelTotal);

	cout << otherExpensesVectorDouble[2] << "e saved for fuel in monthly budget." << endl;
	return 0;
}
int calcOtherTransportCost()
{
	cout << "What transport do you use?" << endl;
	cout << "Transport: ";
	getline(cin, inputString);

	otherExpensesVectorString.push_back(inputString);

	cout << "How much the " << otherExpensesVectorString[2] << " trips cost you in total on weekly basis?" << endl;
	cout << "Cost: ";
	cin >> inputDouble;
	cin.get();

	inputDouble *= 4;
	otherExpensesVectorDouble.push_back(inputDouble);

	cout << otherExpensesVectorDouble[2] << "e saved for " << otherExpensesVectorString[2] << "trips in monthly budget" << endl;
	return 0;
}
int backToMainMenu()
{
	char inputChar;
	cout << "Go back to main Menu by pressing A: ";
	cin >> inputChar;
	cin.get();
	if (inputChar == 'a')
	{
		mainMenu();

	}
	return 0;
}
int addExpense() 
{


	cout << endl;
	cout << "Did you pay" << endl;
	cout << "A) a bill"<< endl << "B) Or something else?" << endl;
	cin >> inputChar;
	cin.get();

	if (inputChar == 'a' || inputChar == 'A')
	{
		for (int i = 0; i < billsVectorString.size(); i++)
		{
			countIndex++;
			cout << countIndex << ". " << billsVectorString[i] << endl; // please delete this e it should not be there. (DONE)
		}
		countIndex = 0;
		cout << "Type the number of the bill you paid: ";
		cin >> inputInt;
		inputInt -= 1;
		cin.get();
		cout << "How much you paid for " << billsVectorString[inputInt] << " bill?: ";
		cin >> inputDouble; // (BUG) program crashes here probably because you are trying to insert a value to an non existant vector index. (FIXED)
		cin.get();
		
		billsSpendVectorDouble.at(inputInt) = inputDouble;
		totalMonthsSpending += billsSpendVectorDouble[inputInt];
		cout << billsVectorString[inputInt] << ": " << billsSpendVectorDouble[inputInt] << "e saved." << endl;
	}

	else if (inputChar == 'b' || inputChar == 'B')
	{
		for (int i = 0; i < otherExpensesVectorString.size(); i++)
		{
			countIndex++;
			cout << countIndex << ". " << otherExpensesVectorString[i] << endl; // please delete this e it should not be there. (DONE)
		}
		countIndex = 0;
		cout << "Type the number that corresponds rent, food or transportation: ";
		cin >> inputInt;
		inputInt -= 1;
		cin.get();
		cout << "how much you paid for " << otherExpensesVectorString[inputInt] << "?: ";
		cin >> inputDouble;
		cin.get();
		otherExpensesSpendVectorDouble.at(inputInt) = inputDouble;
		totalMonthsSpending += otherExpensesSpendVectorDouble[inputInt];
		cout << otherExpensesVectorString[inputInt] << ": " << otherExpensesSpendVectorDouble[inputInt] << "e saved" << endl;
	}

	cout << "If you want to add another expense press A. To stop adding expenses press anything: ";
	cin >> inputChar;
	cin.get();
	if (inputChar == 'a' || inputChar == 'A')
	{
		addExpense();
	}
	else
	{
		viewBudget();
	}
	
	return 0;
}
int addExtraExpense()
{
	cout << "EXTRA EXPENSES" << endl;

	while (inputChar != 'q')
	{
		cout << "Name of the expense: ";
		getline(cin, inputString);

		otherExpensesVectorString.push_back(inputString);

		cout << "how much does " << otherExpensesVectorString.back() << " cost you per month?" << endl;
		cout << "Monthly cost: ";
		cin >> inputDouble;
		cin.get();

		otherExpensesVectorDouble.push_back(inputDouble);
		
		cout << otherExpensesVectorString.back() << ": " << otherExpensesVectorDouble.back() << "e/month saved." << endl;
		cout << endl;

		cout << "Do you want to" << endl;
		cout << "A) Add another expense." << endl;
		cout << "Q) stop adding expenses. " << endl;
		cout << "input: ";
		cin >> inputChar;
		cout << endl;

	}
	return 0;
}
//Different menus and actions in those menus

int mainMenu()
{
	
	cout << "PERSONAL FINANCE BOOKKEEPING." << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
	cout << "Hello user, welcome to personal finance bookkeeping!" << endl;
	cout << "Do you want to?" << endl;
	cout << "A) create personal monthly budget?" << endl;
	cout << "B) view your personal budget and add expenses?" << endl;
	cout << "C) Edit your income information?" << endl;
	cout << "D) Developer Terminal" << endl;
	cin >> inputChar;
	cin.get();
	switch (inputChar)
	{
	case 'A':
		createBudget();
		break;
	case 'a':
		createBudget();
		break;

	case 'b':
		viewBudget();
		break;
	case 'B':
		viewBudget();
		break;

	case 'c':
		incomeInfo();
		break;
	case 'C':
		incomeInfo();
		break;

	case'D':
		devTerminal();
		break;
	case'd':
		devTerminal();
		break;

	default:
		cout << "You entered invalid Character. enter a valid character" << endl;
		break;
	}



	return 0;
}
int createBudget()
{

	int count = 0;
	cout << endl;
	cout << "A) CREATE A BUGDET." << endl;
	cout << "-------------------" << endl << endl;
	cout << "Here you can create yourself a monthly budget based on your must" << endl <<
		"have expenses. First you save the amount of net-income(after taxes" << endl <<
		"income, The green+ you get to your bank account every month), Second" << endl <<
		"We go through all the bills you have to pay on monthly basis, third" << endl <<
		"you tell the program the total sum of your housing costs(water," << endl <<
		"payment, rent, homeload payment,car parking space),fourth how much" << endl <<
		"Money you need for transportation and fifth how much money you" << endl <<
		"need for food.This is only a guide line but it is strongly adviced" << endl <<
		"that you stick to your budget. Now with that out of the way,lets start!" << endl << endl;
			
	cout << "How much is your monthly net-income?: ";
	cin >> netIncome;
	cin.get();
	cout << "Net-income " << netIncome << "e saved." << endl;
	cout << endl;

	cout << "BILLS" << endl;
	cout << "Name of the bill: ";
	getline(cin, inputString);
	billsVectorString.push_back(inputString);

	cout << "bill amount: ";
	cin >> inputDouble;
	cin.get();

	countIndex++;
	billsVectorDouble.push_back(inputDouble);
	billsSpendVectorDouble.push_back(0.0);

	cout <<countIndex<<". " << billsVectorString[count] << " " << billsVectorDouble[count] << "e saved " << endl;
	cout << endl;

	cout << "Press A to add another bill,Press Q to quit adding bills: ";
	cin >> inputChar;
	cin.get();
	cout << endl;


	while (inputChar != 'q') //  BUG REPORT: while user is typing bill name and if user types it like this -> "car insurance" and not like this "carInsurance" it will cause infinite loop. (FIXED!)
	{
		count++;
		cout << "Name of the bill: ";
		getline(cin, inputString);
		billsVectorString.push_back(inputString);

		cout << billsVectorString[count] << " bill amount: ";
		cin >> inputDouble;
		cin.get();

		countIndex++;
		billsVectorDouble.push_back(inputDouble);
		billsSpendVectorDouble.push_back(0.0);
		
		cout << countIndex <<". " << billsVectorString[count] << " " << billsVectorDouble[count] << "e " << "saved. " << endl;
		cout << endl;

		cout << "Press A to add another bill,Press Q to quit adding bills: ";
		cin >> inputChar;
		cin.get();
		cout << endl;
	} 
	countIndex = 0;

	cout << "HOUSING" << endl;
	cout << "How much is the sum of all of your housing costs (water/rent/car parking/home loan) payment every month?" <<endl;
	
	cout << "Cost: ";
	cin >> inputDouble;
	cin.get();

	otherExpensesVectorDouble.push_back(inputDouble);
	otherExpensesSpendVectorDouble.push_back(0.0);
	cout << endl;

	cout << "FOOD" << endl;
	cout << "how much do you need money for food everyweek?" << endl;
	cout << "Amount: ";
	cin >> inputDouble;
	cin.get();

	inputDouble *= 4;
	otherExpensesVectorDouble.push_back(inputDouble);
	otherExpensesSpendVectorDouble.push_back(0.0);
	cout << endl;

	cout << "TRANSPORT" << endl;
	cout << "For transport, do you use " << endl;
	cout << "A) a car." << endl << "B) Something else." << endl;

	cout << "input: ";
	cin >> inputChar;
	cin.get();
	switch (inputChar)
	{
	case 'a':
		calcCarFuelCost();
		break;
	case 'A':
		calcCarFuelCost();
		break;
	case 'b':
		calcOtherTransportCost();
		break;
	case 'B':
		calcOtherTransportCost();
		break;
	default:
		cout << "ERROR 506. You entered invalid character" << endl;
		break;
	}
	cout << endl;

	cout << "Do you have any other expenses that were not mentioned above that you must take care of?" << endl;

	cout << "A) Yes i have." << endl << "B) No i dont." << endl;
	cout << "input: ";
	cin >> inputChar;
	cin.get();

	if (inputChar == 'a' || inputChar == 'A')
	{
		addExtraExpense();
	}



	cout << "YOUR MONTHLY BUDGET" << endl;
	cout << "-------------------" << endl;

	for (int i = 0; i < billsVectorDouble.size(); i++) 	
	{
		countIndex++;
		cout << countIndex << ". " << billsVectorString[i] << ": " << billsVectorDouble[i] << "e " << endl;
	}
	for (int i = 0; i < otherExpensesVectorDouble.size(); i++)
	{
		countIndex++;
		cout << countIndex << ". " << otherExpensesVectorString[i] <<": " << otherExpensesVectorDouble[i] << "e " << endl;
	}
	countIndex = 0;

	for (int i = 0; i < billsVectorDouble.size(); i++)
	{
		totalBudgetSum += billsVectorDouble[i];
	}
	for (int i = 0; i < otherExpensesVectorDouble.size(); i++)
	{
		totalBudgetSum += otherExpensesVectorDouble[i];
	}


	cout << "----------------------" << endl;
	cout << "Your monthly net-income is: " << netIncome << "e." << endl;
	cout << "Total monthly bugdet: " << totalBudgetSum << "e." << endl;
	cout << "You can save " << netIncome - totalBudgetSum << "e." << endl;

	backToMainMenu();

	return 0;
} //here user creates a budget and here the vectors get values inserted.
int viewBudget()
{



	cout << "B) VIEW BUDGET/ SPENDING." << endl;
	cout << "-------------------------" << endl<< endl;
	cout << "Here you can view your budget," << endl << "keep book of your spending," << endl << "and view how much money you have left to spend for this month." << endl << endl;
	cout << "Your monthly budget" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	for (int i = 0; i < billsVectorDouble.size(); i++)
	{
		countIndex++;
		cout << countIndex << ". " << billsVectorString[i] << ": " << billsVectorDouble[i] << "e " << endl;
	} 
	for (int i = 0; i < otherExpensesVectorDouble.size(); i++)
	{
		countIndex++;
		cout << countIndex << ". " << otherExpensesVectorString[i] << ": " << otherExpensesVectorDouble[i] << "e " << endl;
	}
	countIndex = 0;
	cout << "---------------" << endl;
	cout << "Monthly budget: " << totalBudgetSum << "e " << endl;
	cout << endl;

	cout << "Your spending this month" << endl;
	cout << "------------------------" << endl;
	cout << endl;

	for (int i = 0; i < billsSpendVectorDouble.size(); i++) //BUG REPORT! This doesnt print to user(SOLVED!).
	{
		countIndex++;
		cout << countIndex << ". " << billsVectorString[i] << ": " << billsSpendVectorDouble[i] << "e " << endl;
	}

	for (int k = 0; k < otherExpensesSpendVectorDouble.size(); k++)
	{
		countIndex++;
		cout << countIndex << ". " << otherExpensesVectorString[k] << ": " << otherExpensesSpendVectorDouble[k] << "e " << endl; //BUG REPORT! This throws expection when seconds time loading after adding a bill.
	}
	countIndex = 0;
	cout << "--------------" << endl;
	cout << "You have spend: " << totalMonthsSpending << "e this month." << endl; 
	cout << endl;

	cout << "A) Add an expense" << endl;
	cout << "B) Back to main menu." << endl;
	cin >> inputChar;
	switch (inputChar)
	{
	case 'a':
		addExpense();
		break;
	case 'A':
		addExpense();
	    break;

	case 'b':
		mainMenu();
		break;
	case 'B':
		mainMenu();
		break;


	default:
		break;
	}


	return 0;
} // here user can view hes/her budget and how much user has spend of that budget and on what
int incomeInfo()
{
	cout << "income information" << endl;


	backToMainMenu();


	return 0;
} //here user can edit income info
int devTerminal()
{
	
	for (int i = 0; i < billsSpendVectorDouble.size(); i++) //BUG REPORT! This doesnt print to user(SOLVED!).
	{
		countIndex++;
		cout << countIndex << ". " << billsVectorString[i] << ": " << billsSpendVectorDouble[i] << "e " << endl;
	}
	cout << "Size of bills spend vector is: " << billsSpendVectorDouble.size() << endl;

	countIndex = 0;
	cin >> inputInt;
	cin.get();
	cin >> inputDouble;
	cin.get();
	billsSpendVectorDouble.insert(billsSpendVectorDouble.begin() + inputInt, inputDouble);
	cout << "Size of bills spend vector is: " << billsSpendVectorDouble.size() << endl;




	backToMainMenu();
	return 0;
} //This is not for users only devs.



