#include <iostream>
#include "HeadTubes.h"
using namespace std;

int main()
{
    ListMenu Lmenu;
    buatListMenu(&Lmenu);
    isiMenu(&Lmenu);
    printMenu(Lmenu);
}
