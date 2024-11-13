#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> currentToppings;

vector<condPref> condPrefVec;

class condPref
{

    public:
        // temp var that turns true once it has been stated whether is is an and or or type
        bool typeStated;

        // if or ==> then this is true, if it's an and type, then this is false
        bool isOrType;

        // set of the target ingredients that this class wants
        set <string> wants;

        // 
        string topppingRequested;

};

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
    
    // holds whether the reader is inherently at the last word
    bool lastWord = false;
    
    // getting user input to see how many orders there are
    cin >> numOfOrders;
    
    // Input handling
    for (int i = 0; i < numOfOrders; i++)
    {
        
        // Takes in the user request
        cin >> request;
        
        // First checks if this is the first word
        if (firstWord)
        {
            if (request != "if")
            {
                currentToppings.insert(reader);
            }

            // implicative request input handler 
            else {

                condPref tempCondPref;
                tempCondPref.typeStated = false;

                while (!lastWord)
                {
                    cin >> request;

                    // Deals with typing

                    if ((request == "or" || request == "and"))
                    {

                        if (!tempCondPref.typeStated)
                        {
                            if (request == "or")
                            {
                                tempCondPref.isOrType = true;
                            }
                            else
                            {
                                tempCondPref.isOrType = false;
                            }

                            tempCondPref.typeStated = true;
                        }

                    }
                    else if (request == "then")
                    {
                        lastWord = true;
                    }
                    else 
                    {
                        tempCondPref.wants.insert(request);
                    }

                    // 


                }

                // then at the end, it'll get the last word and set it as the target

                cin >> request;
                tempCondPref.topppingRequested = request;

                // Finally, the 

            }
            
            firstWord = false;
        }
        


        // Resets the vars for the line
        firstWord = true;
        lastWord = false;
    }
    
    cout << currentToppings.size();

    return 0;
}