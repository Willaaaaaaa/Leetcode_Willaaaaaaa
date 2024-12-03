/**
 * 2469. Convert the Temperature
 * Created Time: 2024-11-08
 * the_SIMPLEST_OneInLeetcode Math
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return vector<double>{ celsius + 273.15, celsius * 1.80 + 32.00 };
    }
};