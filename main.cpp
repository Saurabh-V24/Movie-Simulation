#include <iostream>
#include "inventory.h"
#include "business.h"
#include "Movie.h"


int main()
{
    Business a("data4movies.txt");
    
    a.buildCustomer("data4customers.txt");
    
    a.runningCommands("data4commands.txt");
}