#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> currentToppings;

int main()
{
    
    // Holds the number of orders
    int numOfOrders;
    
    // normal string request that is given by a user
    string request;
    stringstream ss(request);
    
    // temp var to go thrugh the stream
    string reader;
    
    // temp var to hold whether it is currently at the first word
    bool firstWord = true;
    
    // getting user input to see how many orders there are
    cin >> numOfOrders;
    
    for (int i = 0; i < numOfOrders; i++)
    {
        
        // Takes in the user request
        cin >> request;
        
        // clears the string stream of any past variables
        ss.clear();
        
        // puts the user input into the string stream
        ss << request;
        
        // loops through all the words in the stream
        while (ss >> reader)
        {
            // First checks if there is a first word
            if (firstWord)
            {
                if (reader != "if")
                {
                    currentToppings.insert(reader);
                }
                
                firstWord = false;
            }
        }
        
        // Resets the var for the next word
        firstWord = true;
    }
    
    cout << currentToppings.size();

    return 0;
}