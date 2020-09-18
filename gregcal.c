#define DAYS_IN_MONTHS {31,28,31,30,31,30,31,31,30,31,30,31}
#include<stdio.h>
int isleap(char*);
int main(){
	printf("Enter date in YYYY-MM-DD format with the hifens. The code will tell you how many days have been passed since beginning of that year.\n THis requires a  C compiler");
	char dat[10];
	int days[12]=DAYS_IN_MONTHS;
	
	scanf("%s",dat);
	//printf("%s \n",dat);
	int months=0;
	months+=(dat[5]-48)*10;
	months+=(dat[6]-48);
	//printf("%d \n",months);
	int days_open=0;
	days_open+=(dat[8]-48)*10;
	days_open+=(dat[9]-48);
	//printf("%d \n");
	char * s=dat;
	int total=days_open;
	if(months>2) total+=isleap(s);
	for(int i=1;i<months;++i){
		total+=days[i];
	}
	
	printf("\n %d \n",total);
	
	return 0;
}

int isleap(char *dat){
	int year=0;
	year+=(*(dat+0)-48)*1000;
	year+=(*(dat+1)-48)*100;
	year+=(*(dat+2)-48)*10;
	year+=(*(dat+3)-48);
	//printf("%d",year);
	if(year%4==0){
		if(year%100==0 && year%400!=0) return 0;
		else return 1;
	}
	else return 0;
		
}
