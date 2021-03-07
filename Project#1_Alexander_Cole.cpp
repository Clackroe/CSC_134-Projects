#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

// Step #1

	// Variable initialization
	
	int GPUspd, CPUspd, CPUcor, ChoiceMnu;

	double PerfScr, Mult;
	
	const string Title = "Computer Hardware Graphics Quality Recommendation Tool";

	string Res, Quality;
	
	
	
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
	cout << "Please enter the number of cores of your processor: ";
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
	
	// User Menu Input Logic and Multiplier assignment
	if (ChoiceMnu == 1)
	{
		Mult = 1;
		Res = "1280 x 720";
	}
	
	else if(ChoiceMnu == 2)
	{
		Mult = 0.75;
		Res = "1920 x 1080";
	}
	
	else if(ChoiceMnu == 3)
	{
		Mult = 0.55;
		Res = "2560 x 1440";
	}
	else if(ChoiceMnu == 4)
	{
		Mult = 0.35;
		Res = "3840 x 2160";
	}
	
	
	// Step #2 Calculations
	
	// Calculate Performance Score
	PerfScr = ((5 * GPUspd) + (CPUcor * CPUspd)) * Mult;
	
	// Use Performance Score to calculate recommended quality
		
	if(PerfScr > 17000)
	{
		Quality = "Ultra";
	}
	
	else if(PerfScr <= 17000 and PerfScr > 15000)
	{
		Quality = "High";
	}
	
	else if(PerfScr <= 15000 and PerfScr > 13000)
	{
		Quality = "Medium";
	}
	
	else if(PerfScr <= 13000 and PerfScr > 11000)
	{
		Quality = "Low";
	}
	
	else if(PerfScr <= 11000)
	{
		Quality = "Unable to Play";
	}
	
	
	// Step #3 
	
	// Display Final Results and Recommendations
	
	// Title
	cout << "\n \n" << Title << "\n";
	// GPU Speed
	cout << "\n GPU Clock Speed: " << GPUspd << " MHz";
	//CPU Speed
	cout << "\n CPU Clock Speed: " << CPUspd << " MHz";
	//CPU Cores
	cout << "\n Number of cores: " << CPUcor;
	//Resolution
	cout << "\n Monitor Resolution: " << Res;
	//Performance Score
	cout << "\n Performance Score: " << setprecision(7) << showpoint << PerfScr;
	// Recommended Quality
	cout << "\n Recommended Graphics Quality: " << Quality << "\n";
	
	
}
