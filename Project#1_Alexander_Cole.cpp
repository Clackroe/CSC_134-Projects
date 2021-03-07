#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Variable initialization
	
	int GPUspd, CPUspd, CPUcor, ChoiceMnu;

	double PerfScr, Mult;
	
	string Title = "Computer Hardware Graphics Quality Recommendation Tool";
	string Resolution, Quality;
	
	// Get User's Information
	
	// Get User GPU Clock Speed
	cout << "Please enter the clock speed (in Megahertz) of your current graphics card: ";
	cin >> GPUspd;
	
	// User Input Number Check
	if (GPUspd < 0)
	{
		cout << "Invalid graphics card Clock Speed entered. Program will terminate.";
		return 0;
	}
	
	// Get User's CPU Clock Speed
	cout << "Please enter the clock speed (in Megahertz) of your current processor: ";
	cin >> CPUspd;
	
	// User Input Number Check
	if (CPUspd < 0)
	{
		cout << "Invalid processor clock speed entered. Program will terminate.";
		return 0;
	}
	
	// Get User's CPU Core Count
	cout << "Please enter the number of cores that your current processor has: ";
	cin >> CPUcor;
	
	// User input Number Check
	if (CPUcor < 0)
	{
		cout << "Invalid processor core count entered. Program will terminate.";
	}
	
	
	// Resolution Menu Creation
	
	cout << "What resolution is your monitor? \n";
	
	cout << "\t 1. 1280 x 720 \n";
	cout << "\t 2. 1920 x 1080 \n";
	cout << "\t 3. 2560 x 1440 \n";
	cout << "\t 4. 3840 x 2160 \n";
	
	// User Menu Choice Input
	cout << "Please enter your choice from the items listed above: ";
	cin >> ChoiceMnu;
	
	// User Menu Input Check
	if (ChoiceMnu < 1 or ChoiceMnu > 4)
	{
		cout << "Invalid menu item chosen. Program will terminate.";
		return 0;
	}
	
	// User Menu Input Logic
	
	
	
	
	
	
	
	
	
}
