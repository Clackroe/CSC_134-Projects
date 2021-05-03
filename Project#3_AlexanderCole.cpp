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
	
} //Main Function end

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

