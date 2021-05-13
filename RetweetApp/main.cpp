#include <iostream>

using namespace std;

int main()
{
    cout << "Current C++ standard no. = " << __cplusplus << endl;
    cout << "Current program is " << sizeof(void*) * 8 << "-bit.\n" << endl;

    return 0;
}
