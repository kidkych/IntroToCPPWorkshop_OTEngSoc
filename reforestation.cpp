#include <iostream> //input output library
#include <tgmath.h> //math library

using namespace std;



/**
 * Engineering problem solving with c++ - Chapter 4 Question 29 & 30
 * 
 * @param num_acres_total       (int) Total amount of forestable land.
 * @param acres_left            (int) Number of uncut acres.
 * @param table_num_years       (int) Number of years to print for table.
 * @param reforestation_rate    (double) The reforestation rate.
 * */
void reforest_table_calc(int num_acres_total, int acres_left, int table_num_years, double reforestation_rate) {

    // holds running acres uncut as we iterate over years
    double running_acres_left = acres_left;

    // loop runs number of times equal to year input by user
    for (int i = 0; i < table_num_years; i++) {

        // calculate yearly acre increase in uncut forest.
        running_acres_left = running_acres_left * (1.0 + reforestation_rate);

        // display yearly forested row of table
        cout << "(Year " << i+1 << "): " << num_acres_total - running_acres_left << " acres forested." << endl;
    }
}



/**
 * Engineering problem solving with c++ - Chapter 4 Question 31
 * 
 * @param inital_acres_left     (int) Starting number of unforested acres.
 * @param required_acres_left   (int) Number of unforested acres being queried.
 * @param reforestation_rate    (double) The reforestation rate.
 * */
void years_reforestation_pred(int inital_acres_left, int required_acres_left, double reforestation_rate) {

    // Compound interest formula rearranged to solve for n (https://www.onlinemathlearning.com/compound-interest.html)
    // A is final amount, P is inital amount, i is reforestation rate, n is number of years for reforestation
    double num_years_growth = log((double) required_acres_left/inital_acres_left) / log(1.0 + reforestation_rate);

    // display result to user
    cout << "It would take " << num_years_growth << " years before " << required_acres_left << " acres is reforested." << endl;
}



int main() {
    // boolean for when user wants to exit
    bool exit = false;

    // constants from question
    const int TOTAL_ACRES = 14000;
    const int UNCUT_ACRES = 2500;
    const double REFOR_RATE = 0.02;

    // main interface loop. When this exits program ends
    while(!exit) {

        // variable to hold user mode choice
        int selection;

        // Display main options to user
        cout << "Select Reforestation calculator mode" << endl;
        cout << "\t(1) Reforestation table." << endl;
        cout << "\t(2) Years until specific reforested acreage." << endl;
        cout << "Enter Choice (0 to exit): ";

        // read user choice to selection variable
        cin >> selection;

        // Run if user wants to generate the reforestation table
        if (selection == 1) {
            
            // Request num_years from user
            int num_years;
            cout << "Please enter number of years to calculate for table: ";
            cin >> num_years;

            // generate and display reforestation table
            reforest_table_calc(TOTAL_ACRES, UNCUT_ACRES, num_years, REFOR_RATE);
            cout << endl;

        // Run if user wants to predict years until specific reforestation
        } else if (selection == 2) {

            // Request num_acres from user
            int num_acres;
            cout << "Please enter number of acres for reforestation query: ";
            cin >> num_acres;

            // Calculate years until specific reforestation and display to user
            years_reforestation_pred(UNCUT_ACRES, num_acres, REFOR_RATE);
            cout << endl;
        
        // Run if user wishes to exit
        } else if (selection == 0) {
            exit = true;

        // Run if user enters invalid selection
        } else {
            cout << "Selection invalid, please try again" << "\n\n";
        }
    }
}