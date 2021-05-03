#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void displayTitle();
string getResolutionString(int);
double getMultiplier(int);
double calculatePerformanceScore(int, int, int, double);
string getRecommendedQuality(double);
void displayInfo(int, int, int, string, double, string);

//-------------------------------------------------------------------------------------------------------------

int main()
{
	//Variables	
	int computers; // Amount of computers
	int gSpeed, pSpeed; // CPU and Processor Speeds
	int cores, resolutionChoice; // Cores and Res Choice
	double multiplier; // Multiplier based on Res Choice
	string resolutionString; // Selected Resolution
	double performanceScore; // Performance Score
	string quality; // Recommended Graphics Quality
	double highPerformance, lowPerformance; // High and Low Perf Scores
		
	// Get amount of computers from user
	cout << "How many computers are going to be processed? ";
	cin >> computers;
	
	// Amount of computers validation
	while(computers < 1)
	{
		cout << "\n**ERROR: MUST PROCESS AT LEAST 1 COMPUTER.** \n\n";
		cout << "How many computers are going to be processed? ";
		cin >> computers;
	}
	
	// call displayTitle Function
	displayTitle();
	
	// For loop to loop through each computer to be processed
	for(int c = 1; c <= computers; c++)
	{
		// input of the graphics card speed
		cout << "Plesse enter the clock speed (in Megahertz) of your graphics card: ";
		cin >> gSpeed;
		
		// GPU Speed validation
		while(gSpeed < 0)
		{
			cout << "**ERROR: Invalid graphics card speed entered.**\n\n";
			cout << "Plesse enter the clock speed (in Megahertz) of your graphics card: ";
			cin >> gSpeed;
		}
		
		// get Processor speed from user
		cout << "Plesse enter the clock speed (in Megahertz) of your processor: ";
		cin >> pSpeed;
		
		// validate Processor speed
		while(pSpeed < 0)
		{
			cout << "**ERROR: Invalid processor speed entered.** \n\n";
			cout << "Plesse enter the clock speed (in Megahertz) of your processor: ";
			cin >> pSpeed;
		}
		
		// Get amount of cores from user
		cout << "Plesse enter the number of cores of your processor: ";
		cin >> cores;
		
		// Processor core Validation
		while(cores < 0)
		{
			cout << "**ERROR: Invalid cores entered.**\n\n";
			cout << "Plesse enter the number of cores of your processor: ";
			cin >> cores;
		}
		
		// display menu for the monitor resolution
		cout << "What is the resolution of your monitor? " << endl;
		cout << "\t 1. 1280 x 720" << endl;
		cout << "\t 2. 1920 x 1080" << endl;
		cout << "\t 3. 2560 x 1440" << endl;
		cout << "\t 4. 3840 x 2160" << endl;
		cout << "Please select one option from the menu above: ";
		cin >> resolutionChoice;
		
	// Validate the user menu choice
		while(resolutionChoice < 1 or resolutionChoice > 4)
		{
			cout << "**ERROR: Invalid Resolution menu choice.**\n\n";
			cout << "What is the resolution of your monitor? " << endl;
			cout << "\t 1. 1280 x 720" << endl;
			cout << "\t 2. 1920 x 1080" << endl;
			cout << "\t 3. 2560 x 1440" << endl;
			cout << "\t 4. 3840 x 2160" << endl;
			cout << "Please select one option from the menu above: ";
			cin >> resolutionChoice;
		}
		
		// call ResolutionString function and set the variable based on the menu choice
		resolutionString = getResolutionString(resolutionChoice);
		
		// call the getMultiplier function and set the variable based on the resolution menu choice.
		multiplier = getMultiplier(resolutionChoice);
		
		// call the calculatePerformanceScore function to calculate the performance score of the computer
		performanceScore = calculatePerformanceScore(gSpeed, pSpeed, cores, multiplier);
		
		// call the getRecommendedQuality function to compute the recommended graphics quality for this computer
		quality = getRecommendedQuality(performanceScore);
		
		// determine the highest and lowest PerfScores
		if(c == 1)
		{
			// if it is the first computer entered, the highest and lowest are going to be the current PerfScore
			highPerformance = performanceScore;
			lowPerformance = performanceScore;
		}
		else
		{
			// if it is a later computer from the loop, find the highest performance score
			if(performanceScore >= highPerformance)
			{
				highPerformance = performanceScore;
			}
			
			// if it is a later computer from the loop, find the lowest performance score
			if(performanceScore <= lowPerformance)
			{
				lowPerformance = performanceScore;
			}
		}
		
		// Display the results of the program
		cout << setprecision(2) << showpoint << fixed;
		displayInfo(gSpeed, pSpeed, cores, resolutionString, performanceScore, quality);
	} 
		
	// display the highest PerfScore
	cout << "The highest performance score was: " << highPerformance << endl;
	
	// display the lowest PerfScore
	cout << "The lowest performance score was: " << lowPerformance << endl;
	
} //Main function end

//------------------------------------------Callable Functions-------------------------------------------------------------------

// Create and display the tool title
void displayTitle()
{
	// String object to hold the output title
	string title = "Computer Hardware Graphics Quality Recommendation Tool";
	cout << endl << endl << title << endl << endl;	
}

// Based on the menu choice of resolution, assign a string.
string getResolutionString(int res)
{
	switch(res)
	{
		case 1: // 1280 x 720
			return "1280 x 720";
		case 2: // 1920 x 1080
			return "1920 x 1080";
		case 3: // 2560 x 1440
			return "2560 x 1440";
		case 4: // 3840 x 2160
			return "3840 x 2160";
	}
}

// Based on the menu choice of resolution, assign a multiplier integer
double getMultiplier(int res)
{
	switch(res)
	{
		case 1: // 1280 x 720
			return 1;
		case 2: // 1920 x 1080
			return 0.75;
		case 3: // 2560 x 1440
			return 0.55;
		case 4: // 3840 x 2160
			return 0.35;	
	}
}

// Calculate PerfScore based on GPU clock speed, CPU clock speed, CPU number of cores, and multiplier value.
double calculatePerformanceScore(int g, int p, int c, double m)
{
	return ((5 * g) + (c * p)) * m;
}

// Use the performance score that was calculated to recommend a graphics quality to the user.
string getRecommendedQuality(double p)
{
	if(p <= 11000)
	{
		return "Unable to Play";
	}
	else if(p > 11000 and p <= 13000)
	{
		return "Low";
	}
	else if(p > 13000 and p <= 15000)
	{
		return "Medium";
	}
	else if(p > 15000 and p <= 17000)
	{
		return "High";
	}
	else
	{
		return "Ultra";
	}	
}

// Display all necessary information to the user.
void displayInfo(int g, int p, int c, string r, double ps, string q)
{
	cout << "GPU Clock Speed: " << g << " MHz" << endl; 
	cout << "CPU Clock Speed: " << p << " MHz" << endl;
	cout << "Number of cores: " << c << endl;
	cout << "Monitor Resoltion: " << r << endl;
	cout << "Performance Score: " << ps << endl;
	cout << "Recommended Graphics Quality: " << q << endl << endl;	
}

