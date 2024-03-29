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
	
	//Additional Variables for Project 2
	double Highest, Lowest;
	int CompAmmount;
	
	//Get Number of Computers to be processed
	
	cout << "Please enter the ammount of computers that you would like to process.";
	cin >> CompAmmount;
	
	//Validate Computer Ammount
	while(CompAmmount < 1)
	{
		cout << "\nERROR: Invalid Ammount Entered. Must have at least 1 computer.\n";
		cout << "Please enter the ammount of computers that you would like to process.";
		cin >> CompAmmount;
	}
	
	// Output Title
	cout << "\n \n" << Title << "\n" << endl;
	
	//Loop Code
	
	for(int count = 1; count <= CompAmmount; count++)
	{
		
		// Get User's Information
		
		// Get User GPU Clock Speed
		cout << "\nPlease enter the clock speed (in Megahertz) of your current graphics card: ";
		cin >> GPUspd;
		
		// User Input Number Check
		while(GPUspd < 800 or GPUspd > 2000)
		{
			cout << "\nERROR: Invalid GPU Speed Entered. GPU Speed should be between 800 and 2000\n";
			cout << "Please enter the clock speed (in Megahertz) of your current graphics card: ";
			cin >> GPUspd;
		}
		
		// Get User's CPU Clock Speed
		cout << "Please enter the clock speed (in Megahertz) of your current processor: ";
		cin >> CPUspd;
		
		// User Input Number Check
		while(CPUspd < 1000 or CPUspd > 5500)
		{
			cout << "\nERROR: Invalid CPU Speed Entered. CPU Speed should be between 1000 and 5500\n";
			cout << "Please enter the clock speed (in Megahertz) of your current processor: ";
			cin >> CPUspd;
		}
		
		// Get User's CPU Core Count
		cout << "Please enter the number of cores of your processor: ";
		cin >> CPUcor;
		
		// User input Number Check
		while(CPUcor < 1 or CPUcor > 16)
		{
			cout << "\nERROR: Invalid Number CPU Cores Entered. CPU Cores should be between 1 and 16\n";
			cout << "Please enter the number of cores of your processor: ";
			cin >> CPUcor;
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
		while(ChoiceMnu < 1 or ChoiceMnu > 4)
		{
			cout << "\nERROR: Invalid Menu Choice Entered. Menu Choices should be between 1 and 4\n";
		
			//Re-ask the user to choose from the menu
			cout << "What resolution is your monitor? \n";
		
			cout << "\t 1. 1280 x 720 \n";
			cout << "\t 2. 1920 x 1080 \n";
			cout << "\t 3. 2560 x 1440 \n";
			cout << "\t 4. 3840 x 2160 \n";
			
			// User Menu Choice Input
			cout << "Please enter your choice from the items listed above: ";
			cin >> ChoiceMnu;
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
		
		// GPU Speed
		cout << "\n\n GPU Clock Speed: " << GPUspd << " MHz";
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
		
		//Decide the Highest and lowest Performance Score
		
		if (count == 1)
		{
			Highest = PerfScr; //set highest
			Lowest = PerfScr; // set lowest
		}
		
		else
		{
			//if the performance score is larger, set to highest
			if (PerfScr >= Highest)
			{
				Highest = PerfScr;
			}
			//if the performance score is smaller, set to Lowest
			if (PerfScr <= Lowest)
			{
				Lowest = PerfScr;
			}
			
		} 
		
		
	}//Graphics Quality Loop End
	
	
	// display the Highest and Lowest Performance Scores
	
	cout << "\nThe highest performance score was: " << Highest << endl;
	cout << "\nThe lowest performance score was: " << Lowest << endl;
	
}
