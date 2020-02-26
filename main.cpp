#include <iostream>
#include "Forest.h"

//This tale is about a strange forest, where various creatures live.
//Animals can walk and talk, while plants are standing and watching.
//You are welcome to make this strange forest a lot more strange.

using namespace std;

int main()
{
    //It always pays up to do things in a proper way.
    Forest* f = Forest::get_instance(20, 10, 15, 10);   // We try to initialize our Forest with
                                                    // animals/plants/cells along x/cells along y
    f->live();
    Forest::clear_instance();
    return 0;
}
