//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        istringstream iss(str);
        string fraction1, fraction2;
    
        // Read the fractions from the string
        getline(iss, fraction1, ',');
        iss.ignore(1); // Ignore the space
        getline(iss, fraction2);
    
        // Extract numerator and denominator for the first fraction
        int a, b, c, d;
        char slash;
        istringstream iss1(fraction1);
        iss1 >> a >> slash >> b;
    
        // Extract numerator and denominator for the second fraction
        istringstream iss2(fraction2);
        iss2 >> c >> slash >> d;
    
        // Calculate the decimal values of the fractions
        double value1 = static_cast<double>(a) / b;
        double value2 = static_cast<double>(c) / d;
    
        // Compare the fractions
        if (value1 > value2) {
            return fraction1;
        } else if (value1 < value2) {
            return fraction2;
        } else {
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends