#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to analyze the suitability of the temperatures
void analyzeTempSuitability(double daytimeTemp, double nighttimeTemp) {
    if (daytimeTemp >= 70 && daytimeTemp <= 80 && nighttimeTemp >= 60 && nighttimeTemp <= 62) {
        cout << "Temperature is suitable for orchid flowering." << endl;
    } else {
        cout << "Temperature is not suitable for orchid flowering." << endl;
    }
}

// Function to input temperatures for a month
void inputTemp(vector<double>& daytimeTemps, vector<double>& nighttimeTemps) {
    for (int i = 0; i < daytimeTemps.size(); i++) {
        cout << "Enter daytime temperature (Celsius) for day " << (i + 1) << ": ";
        cin >> daytimeTemps[i];
        cout << "Enter nighttime temperature (Celsius) for day " << (i + 1) << ": ";
        cin >> nighttimeTemps[i];
    }
}

// Function to calculate and display statistics
void calStatistics(const vector<double>& daytimeTemps, const vector<double>& nighttimeTemps) {
    double totalDayTemp = 0, totalNightTemp = 0;
    double maxDayTemp = daytimeTemps[0], minDayTemp = daytimeTemps[0];
    double maxNightTemp = nighttimeTemps[0], minNightTemp = nighttimeTemps[0];
    double totalFluctuation = 0;
    const int DAYS_IN_MONTH = daytimeTemps.size();

    // Calculate total, min, and max temperatures
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        totalDayTemp += daytimeTemps[i];
        totalNightTemp += nighttimeTemps[i];

        // Max and min calculations
        if (daytimeTemps[i] > maxDayTemp) maxDayTemp = daytimeTemps[i];
        if (daytimeTemps[i] < minDayTemp) minDayTemp = daytimeTemps[i];
        if (nighttimeTemps[i] > maxNightTemp) maxNightTemp = nighttimeTemps[i];
        if (nighttimeTemps[i] < minNightTemp) minNightTemp = nighttimeTemps[i];

        // Daily fluctuation
        double fluctuation = daytimeTemps[i] - nighttimeTemps[i];
        totalFluctuation += fluctuation;
        cout << "Day " << (i + 1) << " fluctuation: " << fluctuation << " °C" << endl;
    }

    double avgDayTemp = totalDayTemp / DAYS_IN_MONTH;
    double avgNightTemp = totalNightTemp / DAYS_IN_MONTH;
    double avgFluctuation = totalFluctuation / DAYS_IN_MONTH;

    // Output results
    cout << fixed << setprecision(2);
    cout << "\nAverage Daytime Temperature: " << avgDayTemp << " °C (" 
         << celsiusToFahrenheit(avgDayTemp) << " °F)" << endl;
    cout << "Average Nighttime Temperature: " << avgNightTemp << " °C (" 
         << celsiusToFahrenheit(avgNightTemp) << " °F)" << endl;
    cout << "Maximum Daytime Temperature: " << maxDayTemp << " °C (" 
         << celsiusToFahrenheit(maxDayTemp) << " °F)" << endl;
    cout << "Minimum Daytime Temperature: " << minDayTemp << " °C (" 
         << celsiusToFahrenheit(minDayTemp) << " °F)" << endl;
    cout << "Maximum Nighttime Temperature: " << maxNightTemp << " °C (" 
         << celsiusToFahrenheit(maxNightTemp) << " °F)" << endl;
    cout << "Minimum Nighttime Temperature: " << minNightTemp << " °C (" 
         << celsiusToFahrenheit(minNightTemp) << " °F)" << endl;
    cout << "Average Daily Fluctuation: " << avgFluctuation << " °C" << endl;
}

// Function to analyze each day's temperature
void analyzeDailyTemp(const vector<double>& daytimeTemps, const vector<double>& nighttimeTemps) {
    const int DAYS_IN_MONTH = daytimeTemps.size();
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        cout << "\nDay " << (i + 1) << ": ";
        analyzeTempSuitability(daytimeTemps[i], nighttimeTemps[i]);
    }
}

// Function to display the menu and execute the corresponding function
void displayMenu() {
    vector<double> daytimeTemps(30);
    vector<double> nighttimeTemps(30);
    int choice;

    do {
        cout << "\n--- Orchid Temperature Analyzer Menu ---" << endl;
        cout << "1. Input Temperatures" << endl;
        cout << "2. Calculate Statistics" << endl;
        cout << "3. Analyze Daily Temperatures" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputTemp(daytimeTemps, nighttimeTemps);
                break;
            case 2:
                calStatistics(daytimeTemps, nighttimeTemps);
                break;
            case 3:
                analyzeDailyTemp(daytimeTemps, nighttimeTemps);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 4);
}

int main() {
    displayMenu();
    return 0;
}

