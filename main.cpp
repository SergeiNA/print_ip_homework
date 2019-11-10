#include "print_ip.h"

using namespace std;

int main()
{
    print_ip_integral(char(-1));
    print_ip_integral(short(0));
    print_ip_integral(int(2130706433));
    print_ip_integral(long(8875824491850138409));
}
