#include "inventory.h"

using namespace std;

Inventory::Inventory() {}

Inventory::~Inventory() {}

bool Inventory::perform(MovieInventory& m, HashTable& c)
{
    m.printInventory();
    return true;
}
