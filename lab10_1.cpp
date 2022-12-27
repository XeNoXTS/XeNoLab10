#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan, intpery, paypery;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> intpery;
	cout << "Enter amount you can pay per year: ";
	cin >> paypery;

	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	int EndOfYear = 1;
	double PrevBalance = loan, Interest = (intpery/100)*loan, Total = PrevBalance + Interest, Payment = paypery, NewBalance;	
	cout << fixed << setprecision(2); 
	while(PrevBalance > 0)
	{
		cout << setw(13) << left << EndOfYear; 
		cout << setw(13) << left << PrevBalance;
		cout << setw(13) << left << Interest;
		cout << setw(13) << left << Total;
		if(Total >= paypery)
		{
			Payment = paypery;
		}
		else
		{
			Payment = Total;
		}
		cout << setw(13) << left << Payment;
		NewBalance = Total - Payment;
		if(NewBalance < 0) NewBalance = 0;
		cout << setw(13) << left << NewBalance;
		cout << "\n";
		EndOfYear++;
		PrevBalance	= NewBalance;
		Interest = PrevBalance*(intpery/100);
		Total = PrevBalance + Interest;
		
	};
	
	return 0;
}
