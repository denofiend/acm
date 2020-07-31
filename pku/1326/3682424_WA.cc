//

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 1000

char record[MAXN];
char city[MAXN];

int main(){
	while (gets(record))
	{
		if ('#' == record[0])	break;
		int totalMileage = 0;
		while (1)
		{
			int fee;
			char mode;
			sscanf(record, "%s %s %d %c", city, city, &fee, &mode);
			
			//printf("%s %s %d %c\n", city, city, fee, mode);
			if ('F' == mode)	totalMileage += fee * 2;
			else if ('B' == mode)	totalMileage += fee + (fee + 1) / 2;
			else if ('Y' == mode)
			{
				if (0 < fee <= 500)	totalMileage += 500;
				else totalMileage += fee;
			}
			gets(record);
			if ('0' == record[0])	break;
		}
		printf("%d\n", totalMileage);
	}
	return 0;
}