#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
    public:
    int maximumDifference;
    // Add your code here

    // Constructor
    Difference(vector<int> elements)
    {
        this->elements = elements;
    }

    // Compute max difference
    void computeDifference(void)
    {
        int minValue;
        int maxValue;

        auto result = std::minmax_element(this->elements.begin(), this->elements.end());

        minValue = *result.first;
        maxValue = *result.second;

        this->maximumDifference = maxValue - minValue;
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}