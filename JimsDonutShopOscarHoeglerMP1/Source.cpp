/* Oscar Hoegler, September 27th 2022, Jims Donut Shop MP1
 * JimsDonutShopOscarHoeglerMP1.cpp, Based on a given order and the amount of money given, return change*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void) {
	//Initialization of variables
	const double TAXRATE = 1.075;
	int donutREGULAR = 0, donutFANCY = 0, donutFRITTER = 0, moneyFACTOR;
	string moneyNAME;
	double priceREGULAR, priceFANCY, priceFRITTER, priceTOTAL, priceTAX, pricePAID, priceCHANGE;
	//Receive the amount of 
	cout << "Number of regular donuts ordered: "; cin >> donutREGULAR;
	cout << "Number of fancy donuts ordered: "; cin >> donutFANCY;
	cout << "Number of apple fritters ordered:  "; cin >> donutFRITTER;

	//Gets the price of the regular donuts
	//the first part, due to int/int = int, will only work if donutREGULAR is > 12, which is the only case that the donzen discount applies
	//the second part will work in cleaning up every donut that is not apart of a dozen donuts
	priceREGULAR = (donutREGULAR / 12) * 7.99 + (donutREGULAR % 12) * 0.75;

	//Same as above but with fancy donuts
	priceFANCY = (donutFANCY / 12) * 8.49 + (donutFANCY % 12) * 0.85;

	//Same as above but with fritters
	priceFRITTER = (donutFRITTER / 12) * 8.49 + (donutFRITTER % 12) * 0.85;

	//sums the prices of the individual sections, and multiplies it by the tax rate to get the true total
	priceTOTAL = priceREGULAR + priceFANCY + priceFRITTER;
	priceTOTAL *= TAXRATE;

	//This rounds off to the nearest penny the price total, which permits exact change to be provided
	priceTOTAL = (priceTOTAL * 1000);			//sets the variable up to be integered
	priceTOTAL = (int)priceTOTAL % 10 > 4 ?			//this checks for if the variable has more than 4 decipennies
		(						//if it has more than 4 decipennies it rounds up
		priceTOTAL + (10 - (int)priceTOTAL % 10)	//as seen here
		) : (						//if it has fewer than 4 decipennies it rounds down
		priceTOTAL
		);
	
	//this eliminates any stragler centipennies or smaller denominations and then reconverts it into a floating point number
	priceTOTAL = ((int)(priceTOTAL)) / 1000.0;

	//puts out the total price, and then requests the amount you are paying with
	//the set precision abuses the fact that we use base 10 to find the total whole digit of a number, when the log10 of it is rounded up
	//we then add 2 to this to account for the fact we do not use parts of pennies in the states
	//we then request the amount of money the user is paying with
	cout << "Customer pays $" << setprecision(ceil(log10(priceTOTAL)) + 2) << priceTOTAL << endl
		<< "Customer owes $"; cin >> pricePAID;
	
	//reducing variable clutter
	priceCHANGE = pricePAID - priceTOTAL;

	if (priceCHANGE)
	{	//this uses the same formula as above to show the amount of change owed
		cout << "Change owed is $" << setprecision(ceil(log10(priceCHANGE)) + 2) << priceCHANGE << " - ";
	}else
	{	//because we truncated any centipennies we do not have to worry about truly exact same prices
		cout << "Exact payment recieved - no change owed.";
		return 0;
	}
	//prevents being shortchanged and negative values being put into 
	if (priceCHANGE < 0) 
	{
		cout << "shortchanged";
		return 1;
	}

	priceCHANGE *= 100;
	//easily modifiable money outputter that will get put out the maximum amount of the max bill, 
	//then reduce the amount to the amount without that amount
	moneyFACTOR = 500;	 //initalize the number of pennies the amount is worth
	moneyNAME = "five";	 //initialize the name of the currency, does not work with pennies
	if ((int)priceCHANGE / moneyFACTOR)											//returns true if you would get that bill in return
	{															//
		if ((int)priceCHANGE / moneyFACTOR-1)										//returns true if the number of bills is > 1
		{														//
		cout << (int)priceCHANGE / moneyFACTOR << " " << moneyNAME << "s, ";	//puts out the bills			//
		} else														//
		{														//
			cout << "1 " << moneyNAME << ", ";									//puts out 1 bill
		}														//
	}															//
	priceCHANGE = (int)priceCHANGE%moneyFACTOR;										//gets the number of pennies without the bills taken out
	
	moneyFACTOR = 100;	 
	moneyNAME = "dollar";	 
	if ((int)priceCHANGE / moneyFACTOR)										
	{																		
		if ((int)priceCHANGE / moneyFACTOR - 1)								
		{																	
			cout << (int)priceCHANGE / moneyFACTOR << " " << moneyNAME << "s, ";
		}
		else																
		{																	
			cout << "1 " << moneyNAME << ", ";								
		}																	
	}																		
	priceCHANGE = (int)priceCHANGE % moneyFACTOR;

	moneyFACTOR = 25;
	moneyNAME = "quarter";
	if ((int)priceCHANGE / moneyFACTOR)
	{
		if ((int)priceCHANGE / moneyFACTOR - 1)
		{
			cout << (int)priceCHANGE / moneyFACTOR << " " << moneyNAME << "s, ";
		}
		else
		{
			cout << "1 " << moneyNAME << ", ";
		}
	}
	priceCHANGE = (int)priceCHANGE % moneyFACTOR;

	moneyFACTOR = 10;
	moneyNAME = "dime";
	if ((int)priceCHANGE / moneyFACTOR)
	{
		if ((int)priceCHANGE / moneyFACTOR - 1)
		{
			cout << (int)priceCHANGE / moneyFACTOR << " " << moneyNAME << "s, ";
		}
		else
		{
			cout << "1 " << moneyNAME << ", ";
		}
	}
	priceCHANGE = (int)priceCHANGE % moneyFACTOR;

	moneyFACTOR = 5;
	moneyNAME = "nickel";
	if ((int)priceCHANGE / moneyFACTOR)
	{
		if ((int)priceCHANGE / moneyFACTOR - 1)
		{
			cout << (int)priceCHANGE / moneyFACTOR << " " << moneyNAME << "s, ";
		}
		else
		{
			cout << "1 " << moneyNAME << ", ";
		}
	}
	priceCHANGE = (int)priceCHANGE % moneyFACTOR;

	moneyFACTOR = 1;//custom function for pennies because they are stupid with their plural
	if ((int)priceCHANGE / moneyFACTOR)
	{
		if ((int)priceCHANGE / moneyFACTOR - 1)
		{
			cout << (int)priceCHANGE / moneyFACTOR << " pennies";
		}
		else
		{
			cout << "1 penny";
		}
	}
	priceCHANGE = (int)priceCHANGE % moneyFACTOR;


	return 0;
}
