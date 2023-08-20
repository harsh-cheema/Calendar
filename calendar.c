#include <stdio.h>

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char* months[13]={
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

int input_year(){
    int year;
    printf("\nPlease enter an year in format (YYYY) : ");
    scanf("%d",&year);
    return year;
}

int determine_leap_year(int year){
    if((year%100==0 && year%400==0) || year%4==0){
        days_in_month[2]=29;
        return 1;
    }
    return 0;
}

int determine_day_code(int year){
    int daycode;
    int d1=(year-1)/4;
    int d2=(year-1)/100;
    int d3=(year-1)/400;
    daycode=(year+d1-d2+d3)%7;
    return daycode;

}

void calender(int year,int daycode){
    int month,day;
    for(month=1;month<=12;month++){
        printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		// finding position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			
			//if next day coming is sun,start from next line
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
    }
}

int main(){
    int year,daycode,leapyear;
    year=input_year();
    daycode=determine_day_code(year);
    determine_leap_year(year);
    calender(year,daycode);
    printf("\n");
}