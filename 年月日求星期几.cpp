#include<iostream>
using namespace std;
int getJulianDayNumber(int year, int month, int day)
{
 // (void) require_32_bit_integer_at_least; // no warning please
  int a = (14 - month) / 12;
  int y = year + 4800 - a;
  int m = month + 12 * a - 3;
  return day + (153*m + 2) / 5 + y*365 + y/4 - y/100 + y/400 - 32045;
}

int main(){
	cout<<getJulianDayNumber(2016,10,27)%7;//0-6 ĞÇÆÚ1-7 
}
