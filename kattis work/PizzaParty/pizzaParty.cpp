#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

set<string> currentToppings;

class condPref
{

    public:
        // temp var that turns true once it has been stated whether is is an and or or type
        bool typeStated = false;

        // if or ==> then this is true, if it's an and type, then this is false
        bool isOrType;

        bool isCompleted = false;

        // set of the target ingredients that this class wants
        set <string> wants;

        // 
        string toppingRequested;

};

vector<condPref> condPrefVec;

int main()
{
    
    // Holds the number of orders
    int numOfOrders;
    
    // normal string request that is given by a user
    string request;
    
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
        
        if (request != "if")
        {
            currentToppings.insert(request);
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
                    // IF the type has not been stated, then this will take care of it
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
            tempCondPref.toppingRequested = request;

            condPrefVec.push_back(tempCondPref);

            // Finally, the 

        }
            
        
        lastWord = false;
    }

    // Makes an iterator for the vectors
    set<string>::iterator itr;

    bool addedAnotherTopping = true;

    stack<int>elementsToClear;

    while (addedAnotherTopping)
    {

        addedAnotherTopping = false;

        // Runs a basic loop to check the prefrences and if they can be fixed up
        for (int i = 0; i < condPrefVec.size(); i++)
        {
            // loops through all the elements in the set
            for (itr = currentToppings.begin(); itr != currentToppings.end(); itr++) {
                // *itr

                // This checks if one of the ingredients is in the 
                if (condPrefVec[i].wants.count(*itr) != 0)
                {
                    condPrefVec[i].wants.erase(*itr);
                    if (!condPrefVec[i].isOrType)
                    {
                        if (condPrefVec[i].wants.size() == 0)
                        {
                            condPrefVec[i].isCompleted = true;
                            break;
                        }
                    }
                    else{
                        condPrefVec[i].isCompleted = true;
                        break;
                    }
                }

            }

            if (condPrefVec[i].isCompleted)
            {
                currentToppings.insert(condPrefVec[i].toppingRequested);
                addedAnotherTopping = true;
                elementsToClear.push(i);
            } 
        }

        while (!elementsToClear.empty())
        {
            condPrefVec.erase(condPrefVec.begin()+elementsToClear.top());
            elementsToClear.pop();
        }

    }
    
    cout << currentToppings.size();

    return 0;
}