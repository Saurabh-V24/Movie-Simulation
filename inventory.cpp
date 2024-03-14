#include "inventory.h"

using namespace std;

Inventory::Inventory() {}

Inventory::~Inventory() {}

bool Inventory::perform(MovieInventory& m, CustomerInventory& c)
{
    m.printInventory();
    return true;
}
