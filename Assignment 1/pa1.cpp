/*
 * pa1.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Budi Ryan
 */
/*
 * COMP2011 (Spring 2015) Assignment 1: Tax Calculator
 * A basic tax calculator that helps you estimate the amount of salaries tax you need to pay in Hong Kong
 *
 * Student name: Budi Ryan
 * Student ID: 20214841
 * Student email: bryanaa@connect.ust.hk
 */

#include <iostream>

using namespace std;

/* This is the tax calculation function. Parameters are self-explanatory.
 * This function will calculate the salaries tax to be paid.
 * Read all the assignment descriptions carefully and complete your assignment by writing the content of this function.
 * Do NOT modify the function name and the parameter list in any way. */
int tax( int incomeForTheYearOfAssessment,
		 int valueOfAllPlacesOfResidenceProvidedByEmployerOrAssociatedCorporation,
		 int outgoingsAndExpenses,
		 int selfEducationExpenses,
		 int approvedCharitableDonations,
		 int mandatoryContributionsToRecognizedRetirementSchemes,
		 int homeLoanInterest,
		 int elderlyResidentialCareExpenses,
		 bool isMarried,
		 bool isSingleParent,
		 int numberOfChildren,
		 int numberOfDependentBrothersAndDependentSisters,
		 int numberOfDependentParentsAndDependentGrandparentsAgedAbove60,
		 int numberOfDependentParentsAndDependentGrandparentsAged55OrAboveButBelow60,
		 int numberOfDisabledDependants )
{

	//Do NOT modify the function name and the parameter list in any way.
	//Finish the implementation of tax() here.

	//TOTALINCOME
	int totalincome= incomeForTheYearOfAssessment + valueOfAllPlacesOfResidenceProvidedByEmployerOrAssociatedCorporation;
	//DEDUCTIONS
	if (selfEducationExpenses>80000){
		selfEducationExpenses= 80000;
	}

	int deductions= outgoingsAndExpenses+selfEducationExpenses+approvedCharitableDonations
			+mandatoryContributionsToRecognizedRetirementSchemes+homeLoanInterest+
			elderlyResidentialCareExpenses;
	//ALLOWANCES
	int basicallowance,childallowance,brosisallowance,grandpaabove60,grandpabelow60,disabledallowance,singleparentallowance;
	if (isMarried==true){
		basicallowance=240000;
	}
	else {
		basicallowance=120000;
		}
	if (isSingleParent==true){
		singleparentallowance=120000;
	}
	else{
		singleparentallowance=0;
	}
	childallowance=(numberOfChildren)*70000;
	brosisallowance=(numberOfDependentBrothersAndDependentSisters)*33000;
	grandpaabove60=(numberOfDependentParentsAndDependentGrandparentsAgedAbove60)*40000;
	grandpabelow60=(numberOfDependentParentsAndDependentGrandparentsAged55OrAboveButBelow60)*20000;
	disabledallowance=(numberOfDisabledDependants)*66000;
	int allowance=basicallowance+singleparentallowance+childallowance+brosisallowance+grandpaabove60+grandpabelow60+disabledallowance;
	//TOTAL TAX CALCULATIONS
	int netchargeableincome= totalincome-deductions-allowance;
	int netincome= totalincome-deductions;
	int totaltax, progressiverate, standardrate;
	if ((netchargeableincome<0)||(netincome<0))
	{
				totaltax=0;

	}
	else{
     standardrate=0.15*netincome;
	 if (netchargeableincome<=40000)
	 {progressiverate=netchargeableincome*0.02;}
	 else if((netchargeableincome<=80000)&&(netchargeableincome>40000)){
	progressiverate=(40000*0.02)+((netchargeableincome-40000)*0.07);
	 	 }
	 	 else if((netchargeableincome>80000)&&(netchargeableincome<=120000)){
	 		 progressiverate=(40000*0.02)+(40000*0.07)+((netchargeableincome-80000)*0.12);
	 	 	 }
	 	 else if(netchargeableincome>120000){
	 		 progressiverate=(40000*0.02)+(40000*0.07)+(40000*0.12)+
				((netchargeableincome-120000)*0.17);
	 	 	 }


	if (standardrate<progressiverate)
	{totaltax=standardrate;
	}
	else{
	totaltax=progressiverate;
	}
	}
return totaltax;
}

/* This is the entry point of the program. It is already complete. Do NOT modify any of it. */
int main()
{
	//Declare the variables for input
	int incomeForTheYearOfAssessment,
		valueOfAllPlacesOfResidenceProvidedByEmployerOrAssociatedCorporation,
		outgoingsAndExpenses,
		selfEducationExpenses,
		approvedCharitableDonations,
		mandatoryContributionsToRecognizedRetirementSchemes,
		homeLoanInterest,
		elderlyResidentialCareExpenses,
		isMarried,
		isSingleParent,
		numberOfChildren,
		numberOfDependentBrothersAndDependentSisters,
		numberOfDependentParentsAndDependentGrandparentsAgedAbove60,
		numberOfDependentParentsAndDependentGrandparentsAged55OrAboveButBelow60,
		numberOfDisabledDependants;
	char charAnswerForIsMarried,
		 charAnswerForIsSingleParent;

	//Print the assignment title
	cout << "Assignment 1: Tax Calculator" << endl;

	//Get the input
	cout << "What is your Income for the Year of Assessment?" << endl;
	cin >> incomeForTheYearOfAssessment;
	cout << "What is the Value of All Places of Residence Provided by Employer or Associated Corporation?" << endl;
	cin >> valueOfAllPlacesOfResidenceProvidedByEmployerOrAssociatedCorporation;
	cout << "What is your Outgoings and Expenses?" << endl;
	cin >> outgoingsAndExpenses;
	cout << "What is your Self Education Expenses?" << endl;
	cin >> selfEducationExpenses;
	cout << "What is your Approved Charitable Donations?" << endl;
	cin >> approvedCharitableDonations;
	cout << "What is your Mandatory Contributions to Recognized Retirement Schemes?" << endl;
	cin >> mandatoryContributionsToRecognizedRetirementSchemes;
	cout << "What is your Home Loan Interest?" << endl;
	cin >> homeLoanInterest;
	cout << "What is your Elderly Residential Care Expenses?" << endl;
	cin >> elderlyResidentialCareExpenses;
	cout << "Are your married? (y/n)" << endl;
	cin >> charAnswerForIsMarried;
	isMarried = (charAnswerForIsMarried=='y');
	cout << "Are you a single parent? (y/n)" << endl;
	cin >> charAnswerForIsSingleParent;
	isSingleParent = (charAnswerForIsSingleParent=='y');
	cout << "How many children do you have?" << endl;
	cin >> numberOfChildren;
	cout << "How many dependent brothers and sisters do you have?" << endl;
	cin >> numberOfDependentBrothersAndDependentSisters;
	cout << "How many dependent parents and grandparents who aged above 60 do you have?" << endl;
	cin >> numberOfDependentParentsAndDependentGrandparentsAgedAbove60;
	cout << "How many dependent parents and grandparents who aged 55 or above but below 60 do you have?" << endl;
	cin >> numberOfDependentParentsAndDependentGrandparentsAged55OrAboveButBelow60;
	cout << "How many disabled dependants do you have?" << endl;
	cin >> numberOfDisabledDependants;

	//Output the tax calculation result
	cout << "You need to pay $"
	     << tax( incomeForTheYearOfAssessment,
				 valueOfAllPlacesOfResidenceProvidedByEmployerOrAssociatedCorporation,
				 outgoingsAndExpenses,
				 selfEducationExpenses,
				 approvedCharitableDonations,
				 mandatoryContributionsToRecognizedRetirementSchemes,
				 homeLoanInterest,
				 elderlyResidentialCareExpenses,
				 isMarried,
				 isSingleParent,
				 numberOfChildren,
				 numberOfDependentBrothersAndDependentSisters,
				 numberOfDependentParentsAndDependentGrandparentsAgedAbove60,
				 numberOfDependentParentsAndDependentGrandparentsAged55OrAboveButBelow60,
				 numberOfDisabledDependants )
		 << " for your salaries tax."
		 << endl;

	return 0;
}



