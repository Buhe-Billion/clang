#include "../../collections/collections.h"

int main(int argc, char const *argv[])
{
	
	/*
	*
	* Line below makes only pmonth to be a pointer!
	*
	int* pmonth, pday;
	*
	*/
	integer_pointer pmonth, pday;

	/* Pointers have to have something to point to and -1 is a nonsense value that indicates an error*/
	signed month, day = -1;

	pmonth = &day;
	pday = &month;
	
	printf("This is the: %d th day of the year\n", day_of_year(2025, 5, 3));

	/*
	month_day(2025, 123, pmonth, pday);
	printf("The 123rd day of 2025, vandaag, is on the %drd day of the %dth month \n", *pday, *pmonth);
	*/

	month_day(2025, 123, &month, &day);
	printf("The 123rd day of 2025, vandaag, is on the %drd day of the %dth month \n", day, month);

	return 0;
}