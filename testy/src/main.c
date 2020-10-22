#include "testy/customer.h"
#include "testy/widget.h"

int main(int argc, char* argv[])
{
    if (widget_ok(1, 1))
    {
        return customer_check(5);
    }
    return 0;
}