/*		  @author : AU1841073  Meet Akbari
   @Project-title : Bus Ticket Booking System
*/
/* NOTE : Use this admin_id and password to log into admin screen.
   Admin id : manager
   password : 1234
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include <ctype.h>
#include "gotoxy.h"

void mainmenu();
void Intercity();
void searchbus();
void busavailable();
void bookticket();
void sleeper();
void seating();
void contactdetails();
void Support();
void feedback();
void customersup();
void Details();
void Admin();
void adminhandle();
void addbus();
void addcity();
void printticket();

	int i, j, choice, num1;
char origin[30], destination[30];
char email[35], ch, colomn;
long long int mobile;
	int d[3], m[3], y[3];
char passengername[50];
	int age, choose;
	int busnumber;
float tempdistance;
	int tmhst=6, tmmst=30;//timemorninghourstart/stop , timemorningminutestart/stop
	int tnhst=13,tnmst=20;//timenoonhourstart/stop , timenoonminutestart/stop
	int tehst=22,temst=10;//timeeveninghourstart/stop , timeeveningminutestart/stop
	int arr_h_m, arr_h_n, arr_h_e, arr_m_m, arr_m_n, arr_m_e, fare;
	int count=1, row;


struct seat
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
};

struct addbus
{
	char busid[5];
	char bustype[10];
	char busorigin[20];
	char busdestin[20];
	int busdeparthour;
	int busdepartminute;
};

struct addcity
{
	char cityname[20];
};

struct chairbus
{
	char colomn;
	int row;
}chair;

struct bedbus
{
	char colomn;
	int row;
}bed;

int main()
{
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			printf(" ");
		}printf("\n");
	}
	system ("color E5");
	printf("\t\t\t\t\t         BUS TICKET BOOKING SYSTEM");
	printf("\n\n\n\n\t\t\t\t\t\t\tWelcome...!");
	printf("  \n\n\n\n\t\t\t\t\t\t       ");
	for(i=0; i<7; i++)
	{
		printf("%c ",254);
		system("color 01");
		Sleep(10);
		system("color 36");
		Sleep(10);
		system("color 24");
		Sleep(10);
		Sleep(100);
	}
	system("color E5");
	system("cls");
	mainmenu();

	return 0;
}

void mainmenu()
{
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			printf(" ");
		}printf("\n");
	}
	printf("\t\t\t\t     =============== EASY TRAVEL ================");
	printf("\n\n\t\t\t\t\t1. Intercity Bus");
	printf("\n\n\t\t\t\t\t2. Details about this application.");
	printf("\n\n\t\t\t\t\t3. Admin");
	printf("\n\n\t\t\t\t\t4. Support");
	printf("\n\n\t\t\t\t\t5. Close");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&choice);
		system("cls");
	if (choice==1)
	{
		Intercity();
	}
	if (choice==2)
	{
		Details();
	}
	if (choice==3)
	{
		Admin();
	}
	if (choice==4)
	{
		Support();
	}
	if (choice==5)
	{
		gotoxy(50,11);
		printf("Thanks for Visiting.\n");
		gotoxy(10,20);
		exit(0);
	}
}

void Intercity()
{
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			printf(" ");
		}printf("\n");
	}
	printf("\t\t\t\t     =============== INTERCITY BUS ================");
	printf("\n\n\n\t\t\t\t\t1. Search for Bus. ");
	printf("\n\n\t\t\t\t\t2. Back to MAIN MENU.");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&choice);
	system("cls");
	if (choice==1)
	{
		searchbus();
	}
	if (choice==2)
	{
		mainmenu();
	}
}


void searchbus()
{
	int num1, num2;

	printf("\n\t\t\t\t-: Enter Origin and Destination name out of this 17 cities :-\n");
	printf("\n\t\t[01]ahmedabad [02]anand       [03]ankleshwar  [04]bhuj           [05]bhavnagar  [06]bharuch");
	printf("\n\t\t[07]gondal    [08]gandhinagar [09]jamnagar    [10]mehsana        [11]morbi      [12]nadiad");
	printf("\n\t\t[13]rajkot    [14]saputara    [15]surat       [16]surendranagar  [17]vadodara\n");
	printf("\n\n\t\t\t\t...Please enter city name not number.");
	printf("\n\n\t\t\t\tEnter Origin      : ");
	fflush(stdin);
	gets(origin);

	printf("\n\n\t\t\t\tEnter Destination : ");
	fflush(stdin);
	gets(destination);

	printf("\n\n\n\n\t\tFor Search the Route and check availability of bus kindly PRESS ' 1 '\n");
	printf("\n\t\tEnter Here : ");
	scanf("%d",&num1);
		system("cls");

	if(num1==1)
	{
		busavailable();
	}
	if(num1!=1)
	printf("\n\nERROR !!! Kindly PRESS ' 1 '\n\nOR\n\nFor back to Main-Menu PRESS ' 2 '\n");
	scanf("%d",&num2);
    system("cls");

	if(num2==1)
	{
		busavailable();
	}
	if(num2==2)
	{
		mainmenu();
	}
}


void busavailable()
{
	FILE *fp;
	char departdate[15], returndate[15], choice;
	int num2, date, month, year, rdate, rmonth, ryear;
	int a, b;
	int tempminute, temphour;
	char temporigin[30], tempdestination[30];
	char t1[5], t2[5], t3[5];

    printf("\n\n\n\t\t\t--------------------------------------------------\n");
	printf("\t\t\t| 1. One Way\t\t |2. Round Trip\t\t |\n");
	printf("\t\t\t--------------------------------------------------\n");
	printf("\n\n\t\t\tEnter your choice by PRESS No. : ");
	scanf("%d",&num1);
	if(num1==1)
	{
		up1 :
		printf("\n\nEnter Travel-Date : [ dd-mm-yyyy ]\t\t !!! Date should be in this format. !!!\n");
		scanf("%d-%d-%d",&date, &month, &year);
		if(date>31 || month>12 || date<0 || month<0 || year<0 || year<2018 || year>2020)
		{
			printf("!!!ERROR...Enter valid info.");
			goto up1;
		}
		d[0]=date;
		m[0]=month;
		y[0]=year;
	}
	if(num1==2)
	{
		up2 :
		printf("\n\nEnter Departing-Date : [ dd-mm-yyyy ]\t\t !!! Date should be in this format. !!!\n");
		scanf("%d-%d-%d",&date, &month, &year);
		if(date>31 || month>12 || date<0 || month<0 || year<0 || year<2018 || year>2020 )
		{
			printf("!!!ERROR...Enter valid info.");
			goto up2;
		}
		d[0]=date;
		m[0]=month;
		y[0]=year;
		up :
		printf("\n\n\nEnter Return-Date : [ dd-mm-yyyy ]\t\t !!! Date should be in this format. !!!\n");
		scanf("%d-%d-%d",&rdate, &rmonth, &ryear);

		if(rdate>0 && rdate<=31 && rmonth<=12 && rmonth>0 && ryear>0 && ryear>year && rmonth<month)
		{
			goto new;
		}
		
		if(rdate<0 || rdate>31 || rmonth>12 || rmonth<0 || year<0 || ryear<2018 || ryear>2020)
		{
			printf("!!!ERROR...Enter valid info.");
			goto up;
		}
		if((rdate<=date) || (ryear<year) || (rmonth<month))
		{
			printf("\n!!!ERROR...Enter valid info.");
			goto up;
		}
		d[1]=rdate;
		m[1]=rmonth;
		y[1]=ryear;
	}
	new:
	printf("\n\nTo search the bus kindly PRESS ' 1 '\n");
	scanf("%d",&num2);
		system("cls");
	
	if (num2==1)
	{

		fp = fopen("distance_1.txt","r");
		if(fp == NULL)
		{
			printf("!!!...File couldn't be opened.\n");
		}
		for(i=0; i<272; i++)
		{
			fscanf(fp,"%s %s %s %s %s",&temporigin,&tempdestination,&t1,&t2,&t3);

			a = strcmp(origin,temporigin);
			b = strcmp(destination,tempdestination);

			if(a==0 && b==0)
			{
				tempdistance=atoi(t1);
				temphour=atoi(t2);
				tempminute=atoi(t3);
			}
		}
		fclose(fp);

		arr_h_m = tmhst + temphour;
		arr_h_n = tnhst + temphour;
		arr_h_e = tehst + temphour;
		arr_m_m = tmmst + tempminute;
		arr_m_n = tnmst + tempminute;
		arr_m_e = temst + tempminute;
		
		arr_h_m = tmhst + temphour;
		arr_h_n = tnhst + temphour;
		arr_h_e = tehst + temphour;
		arr_m_m = tmmst + tempminute;
		arr_m_n = tnmst + tempminute;
		arr_m_e = temst + tempminute;
		if(arr_m_m > 60)
		{
			
			arr_m_m = arr_m_m - 60;
			arr_h_m = arr_h_m + 1;
		}
		if(arr_m_n > 60)
		{
			arr_m_n = arr_m_n - 60;
			
			arr_h_n = arr_h_n + 1;
			
		}
		if(arr_m_e > 60)
		{
			arr_m_e = arr_m_e - 60;
			arr_h_e = arr_h_e + 1;
			
		}
		if(arr_h_m >= 24)
		{
			arr_h_m = arr_h_m - 24;
			if(arr_h_m < 0)
			{
				arr_h_m = (-1)*arr_h_m;
			}
		}
		if(arr_h_n >= 24)
		{
			arr_h_n = arr_h_n - 24;
			if(arr_h_n < 0)
			{
				arr_h_n = (-1)*arr_h_n;
			}
		}
		if(arr_h_e >= 24)
		{
			arr_h_e = arr_h_e - 24;
			if(arr_h_e < 0)
			{
				arr_h_e = (-1)*arr_h_e;
			}
		}

		if(tempdistance <= 50)
		{
			fare = 150;
		}
		else if(tempdistance >50 && tempdistance <= 100)
		{
			fare = 200;
		}
		else if(tempdistance >100 && tempdistance <= 150)
		{
			fare = 270;
		}
		else if(tempdistance >150 && tempdistance <= 220)
		{
			fare = 320;
		}
		else if(tempdistance >220 && tempdistance <= 300)
		{
			fare = 430;
		}
		else if(tempdistance >300 && tempdistance <= 400)
		{
			fare = 510;
		}
		else if(tempdistance >400 && tempdistance <= 500)
		{
			fare = 600;
		}
		else if(tempdistance >500 && tempdistance <= 600)
		{
			fare = 730;
		}
		else if(tempdistance >600 && tempdistance <= 750)
		{
			fare = 850;
		}

		printf("\n\n\t\t\t\t\t3 Buses are available from %s to %s\n\n\n\t\t",origin,destination);
		for(i=0; i<95; i++)
		{     printf("=");     }
		printf("\n\t\tBus Name\t\tDeparture\tDuration\tArrival\t\tDistance\tFare\n\t\t");
		for(i=0; i<95; i++)
		{     printf("=");     }
		printf("\n\t\tBus 1   \t\t%d:%d     \t %d:%d \t\t %d:%d \t\t%.2f km\t%d Rs.\n\n\t\t",tmhst,tmmst,temphour,tempminute,arr_h_m,arr_m_m,tempdistance,fare);
		for(i=0; i<95; i++)
		{     printf("-");     }
		printf("\n\t\tBus 2   \t\t%d:%d     \t %d:%d \t\t %d:%d \t\t%.2f km\t%d Rs.\n\n\t\t",tnhst,tnmst,temphour,tempminute,arr_h_n,arr_m_n,tempdistance,fare+30);
		for(i=0; i<95; i++)
		{     printf("-");     }
		printf("\n\t\tBus 3   \t\t%d:%d     \t %d:%d \t\t %d:%d \t\t%.2f km\t%d Rs.\n\n\t\t",tehst,temst,temphour,tempminute,arr_h_e,arr_m_e,tempdistance,fare+55);
		for(i=0; i<95; i++)
		{     printf("=");     }

	}

	printf("\n\n\t\tPRESS \' b \' for Book ticket :\n");
	printf("\n\t\tPRESS \' m \' for back to mainmenu :\n");
	choice = getch();

	if(choice=='b')
	{
		system("cls");
		system("color E6");
		bookticket();
	}
	if(choice=='m')
	{
		system("cls");
		mainmenu();
	}
	getch();
}


void bookticket()
{
	char Traveldate[15], bustype[10], anotherseat, addname;
	char bookedseat[7][3];
	int seatnumber;
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			printf(" ");
		}printf("\n");
	}
	printf("\t\t\t\t     =============== Service Details ================");
	printf("\n\n\t\t\t\t\t1. Travel-Date : %d-%d-%d",d[0],m[0],y[0]);

	if(num1==2)
	{
		printf("\n\n\t\t\t\t\t   Return-Date : %d-%d-%d",d[1],m[1],y[1]);
	}

	printf("\n\n\t\t\t\t\t2. Bus number[1/2/3] : ");
	scanf("%d",&busnumber);
	
	printf("\n\t\t\t\t\t3. 1.Sleeper/2.Seating - PRESS[1/2] : ");
	scanf("%d",&choose);

	if(choose==1)                 	//for sleeper type :
	{
		FILE *fp;
		fp = fopen("sleeperbooked.dat","w");
		fclose(fp);
		sleeper();
	}
	if(choose==2)					//for seating type :
	{
		FILE *fp;
		fp = fopen("seatingbooked.dat","w");
		fclose(fp);
		seating();
	}

	//-----------------passenger details ---------------------------
	
	FILE *fp;
	fp=fopen("contactdetails.txt","a");
	printf("\n\n\n\n\n\n\n\t\t\t\t     =============== Passenger Details ================");
	name :
	printf("\n\n\t\t\t\t\t1. Name : ");
	fflush(stdin);
	gets(passengername);

	fprintf(fp, "%s",passengername);
	printf("\n\t\t\t\t\t2. Age   : ");
	scanf("%d",&age);
	fprintf(fp, "%d\n",age);
	printf("\n\t\t\t\t\tIf anyone other passenger-[Y/N] : ");
	addname=getch();
	if(addname=='y' || addname=='Y')
	{
		printf("\n");
		goto name;
	}
	if(addname=='n' || addname=='N')
	{
		system("cls");
		contactdetails();
	}
		fclose(fp);
}


void sleeper()
{
	char change=176;
	char sleeperseat[10][3];
	struct seat manage[5];
	int anotherseat;
	for(i=0; i<5; i++)
	{
		manage[i].a=178;
		manage[i].b=178;
		manage[i].c=178;
		manage[i].d=178;
		manage[i].e=178;
		manage[i].f=178;
	}
	printf("\n\t\t\t\t\t    ---lower---   ---upper---");
	printf("\n\t\t\t\t\t   |  a   b   | |  c   d   |\n");
	for(i=0;i<5;i++)
	{
		printf("\n\t\t\t\t\t%2d |  %c   %c%c  | |  %c   %c%c  |\n",i+1,manage[i].a,manage[i].b,manage[i].e,manage[i].c,manage[i].d,manage[i].f);
	}
	back :
	printf("\n\n\t\t\t\t\tBook your seat number : ! [You can book your one seat at a time]\n\t\t\t\t\t| ");
	printf("enter colomn : ");
	fflush(stdin);
	scanf("%c",&colomn);

	printf("\n\t\t\t\t\t| enter row : ");
	fflush(stdin);
	scanf("%d",&row);
	

	if(colomn=='a')
	{
		int i=0;
		while(manage[i].a!='\0')
		{
			if(i+1==row)
			{
				manage[i].a=change;
			}
			i++;
		}
	}
	if(colomn=='b')
	{
		int i=0;
		while(manage[i].b!='\0')
		{
			if(i+1==row)
			{
				manage[i].b=change;
				manage[i].e=change;
			}
			i++;
		}
	}
	if(colomn=='c')
	{
		int i=0;
		while(manage[i].c!='\0')
		{
			if(i+1==row)
			{
				manage[i].c=change;
			}
			i++;
		}
	}
	if(colomn=='d')
	{
		int i=0;
		while(manage[i].d!='\0')
		{
			if(i+1==row)
			{
				manage[i].d=change;
				manage[i].f=change;
			}
			i++;
		}
	}
	system("cls");
	printf("\n\t\t\t\t\t    ---lower---   ---upper---");
	printf("\n\t\t\t\t\t   |  a   b   | |  c   d   |\n");
	for(i=0;i<5;i++)
	{
		printf("\n\t\t\t\t\t%2d |  %c   %c%c  | |  %c   %c%c  |\n",i+1,manage[i].a,manage[i].b,manage[i].e,manage[i].c,manage[i].d,manage[i].f);
	}
	printf("\n\n\t\t\t\t\t      %c-%d seatnumber has reserved for you !\n",colomn,row);

	FILE *fp;
	fp = fopen("sleeperbooked.dat","a");
	bed.colomn = colomn;
	bed.row = row;
	fwrite(&bed,sizeof(bed),1,fp);
	fclose(fp);

	printf("\n\t\t\t\t\tAre you want to book another seat [y/n] : ");
	anotherseat=getch();
	if(anotherseat=='y' || anotherseat=='Y')
	{
		count++;
		goto back;
	}
	if(anotherseat=='n' || anotherseat=='N')
	{
		printf("\n\n\n\t\t\t\t\tTotal No. of seats booked = %d",count);
	}
	Sleep(2000);
	system("cls");
}



void seating()
{
	char change=176;
	char seatingseat[3];
	struct seat manage[10];
	int anotherseat;

	for(i=0; i<10; i++)
	{
		manage[i].a=178;
		manage[i].b=178;
		manage[i].c=178;
		manage[i].d=178;
	}

	printf("\n\t\t\t\t\t      a  b    c  d\n");
	printf("\n\t\t\t\t\t--------------------\n");
	for(i=0;i<10;i++)
	{
		printf("\n\t\t\t\t\t%2d |  %c  %c    %c  %c |\n",i+1,manage[i].a,manage[i].b,manage[i].c,manage[i].d);
	}

	first:

	printf("\n\n\t\t\t\t\tBook your seat number : ! [You can book your one seat at a time]\n\t\t\t\t\t| ");
	printf("enter colomn : ");
	fflush(stdin);
	scanf("%c",&colomn);

	printf("\n\t\t\t\t\t| enter row : ");
	fflush(stdin);
	scanf("%d",&row);


	if(colomn=='a')
	{
		int i=0;
		while(manage[i].a!='\0')
		{
			if(i+1==row)
			{
				manage[i].a=change;
			}
			i++;
		}
	}
	if(colomn=='b')
	{
		int i=0;
		while(manage[i].b!='\0')
		{
			if(i+1==row)
			{
				manage[i].b=change;
			}
			i++;
		}
	}
	if(colomn=='c')
	{
		int i=0;
		while(manage[i].c!='\0')
		{
			if(i+1==row)
			{
				manage[i].c=change;
			}
			i++;
		}
	}
	if(colomn=='d')
	{
		int i=0;
		while(manage[i].d!='\0')
		{
			if(i+1==row)
			{
				manage[i].d=change;
			}
			i++;
		}
	}
	system("cls");
	printf("\n\t\t\t\t\t-------------------\n");
	printf("\n\t\t\t\t\t     a  b    c  d\n");
	for(i=0;i<10;i++)
	{
		printf("\n\t\t\t\t\t%2d |  %c  %c    %c  %c |\n",i+1,manage[i].a,manage[i].b,manage[i].c,manage[i].d);
	}
	printf("\n\n\t\t\t\t\t      %c-%d seatnumber has reserved for you !\n",colomn,row);

	FILE *fp;
	fp = fopen("seatingbooked.dat","a");
	chair.colomn = colomn;
	chair.row = row;
	fwrite(&chair,sizeof(chair),1,fp);
	fclose(fp);

	printf("\n\t\t\t\t\tAre you want to book another seat [y/n] : ");
	anotherseat=getch();
	if(anotherseat=='y' || anotherseat=='Y')
	{
		count++;
		goto first;
	}
	if(anotherseat=='n' || anotherseat=='N')
	{
		printf("\n\n\n\t\t\t\t\tTotal No. of seats booked = %d",count);
	}
	Sleep(4000);
	system("cls");

}


void contactdetails()
{
	FILE *fp;
	char ch;
	fp=fopen("contactdetails.txt","a");
	printf("\n\n\n\n\n\t\t\t\t     =============== Contact Details ================");
	printf("\n\n\t\t\t\t\t1. Mobile number : ");
	scanf("%lld",&mobile);
	fprintf(fp, "%lld\n",mobile);
	printf("\n\n\t\t\t\t\t2. Email-id : ");
	fflush(stdin);
	gets(email);
	fprintf(fp, "%s\n\n",email);
	fclose(fp);
	
	system("cls");
	printticket();

}

void printticket()
{
	char ch, pch, tch;
	int t1;
	gotoxy(12,2);
	printf("====================================== DIGITAL TICKET ======================================");
	gotoxy(15,5);
	printf("From       : %s",origin);
	gotoxy(15,7);
	printf("To         : %s",destination);
	gotoxy(15,9);
	printf("Distance   : %.2f km",tempdistance);
	gotoxy(15,11);
	printf("Name       : %s",passengername);
	gotoxy(15,13);
	printf("Age        : %d",age);
	gotoxy(15,15);
	printf("Mobile no. : %lld",mobile);
	gotoxy(15,17);
	printf("Email      : %s",email);
	gotoxy(73,5);
	printf("Depart date: %d-%d-%d",d[0],m[0],y[0]);
	if(num1==1)
	{
		gotoxy(73,7);
		printf("---------------------");
	}
	if(num1==2)
	{
		gotoxy(73,7);
		printf("Return date: %d-%d-%d\n",d[1],m[1],y[1]);
	}
	if(choose==1)
	{
		gotoxy(73,9);
		printf("Bus-number : %d | Sleeper\n",busnumber);
	}
	if(choose==2)
	{
		gotoxy(73,9);
		printf("Bus-number : %d | Seating\n",busnumber);
	}
	if(choose==1)
	{
		FILE *ft, *oc;
		ft = fopen("sleeperbooked.dat","r");
		gotoxy(73,11);
		printf("Seat no.   : ");
		while(fread(&bed,sizeof(bed),1,ft) == 1)
		{
			printf("%c-%d | ",bed.colomn,bed.row);
		}
		fclose(ft);
	}
	if(choose==2)
	{
		FILE *ft, *oc;
		ft = fopen("seatingbooked.dat","r");
		gotoxy(73,11);
		printf("Seat no.   : ");
		while(fread(&chair,sizeof(chair),1,ft) == 1)
		{
			printf("%c-%d | ",chair.colomn,chair.row);
		}
		fclose(ft);
	}
	
	if(busnumber==1)
	{
		gotoxy(73,13);
		printf("Departure  : %d-%d",tmhst,tmmst);
	}
	if(busnumber==2)
	{
			gotoxy(73,13);
		printf("Departure  : %d-%d",tnhst,tnmst);
	}
	if(busnumber==3)
	{
		gotoxy(73,13);
		printf("Departure  : %d-%d",tehst,temst);
	}

	if(busnumber==1)
	{
		gotoxy(73,15);
		printf("Arrival    : %d-%d",arr_h_m,arr_m_m);
	}
	if(busnumber==2)
	{
		gotoxy(73,15);
		printf("Arrival    : %d-%d",arr_h_n,arr_m_n);
	}
	if(busnumber==3)
	{
		gotoxy(73,15);
		printf("Arrival    : %d-%d",arr_h_e,arr_m_e);
	}

	if(busnumber==1)
	{
		gotoxy(73,17);
		printf("Fare       : %d Rs.",(fare*count));
	}
	if(busnumber==2)
	{
		gotoxy(73,17);
		printf("Fare       : %d Rs.",(fare+30)*count);
	}
	if(busnumber==3)
	{
		gotoxy(73,17);
		printf("Fare       : %d Rs.",(fare+55)*count);
	}

	gotoxy(25,22);
	printf("Your ticket is booked.");

	gotoxy(20,27);
	printf("Back to main-menu PRESS 'b' : ");
	fflush(stdin);
	ch=getch();
	if(ch=='b'||ch=='B')
	{
		system("cls");
		mainmenu();
	}
}


void Support()
{
	printf("\n\n\n\n\n\t\t\t\t     =============== Support ================");
	printf("\n\n\t\t\t\t\t1. Customer Support.");
	printf("\n\n\t\t\t\t\t2. Feedback");
	printf("\n\n\t\t\t\t\t3. Back to mainmenu.");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&choice);
		system("cls");
	if (choice==1)
	{
		customersup();
	}
	if (choice==2)
	{
		feedback();
	}
	if (choice==3)
	{
		mainmenu();
	}

}


void customersup()
{
	char ch;
	gotoxy(25,7);
	printf("Dear User you can contact us on any-time on below Email-id which is helpful to you. \n");
	gotoxy(25,9);
	printf("Email : easytravel@gmail.com\n");
	gotoxy(25,12);
	printf("OR contact us by call between 9 a.m. to 6 p.m. on working days.\n");
	gotoxy(25,14);
	printf("Contact number : 8347452326\n");
	gotoxy(25,18);
	printf("Back to main-menu PRESS 'b' : ");
	fflush(stdin);
	ch=getch();
	if(ch=='b'||ch=='B')
	{
		system("cls");
		mainmenu();
	}

}


void feedback()
{
	int apprate;
	char goal, suggestion[500], ch;
	FILE *fp1, *fp2;
		fp1=fopen("apprate.txt","a");
	printf("-: Your overall satisfaction to this application :-\n");
	printf("---------------------\n");
	printf("| 1 | 2 | 3 | 4 | 5 |\n");
	printf("---------------------\n");
	printf("\n\nGive your response :  ");
	scanf("%d",&apprate);
	fprintf(fp1,"%d--",apprate);
		fclose(fp1);
		fp1=fopen("apprate.txt","a");
	printf("\n\nDid you achieve your goal ? \n");
	printf("---------------------\n");
	printf("| a. Yes            |\n");
	printf("| b. Partially      |\n");
	printf("| c. No             |\n");
	printf("---------------------\n");
	printf("\n\nEnter your response by PRESS a/b/c:  ");
	fflush(stdin);
	scanf("%c",&goal);
	fprintf(fp1,"%c\n",goal);
		fclose(fp1);
	if(goal=='b' || goal=='c')
	{
		fp2=fopen("suggestion.txt","a");
		printf("\n\nDo you have any suggestion to improve our app ?\n\n");
		printf("Write your suggestion here : ! [ For submit this suggestion Kindly PRESS 'ENTER' key. ]\n\n\t");
		fflush(stdin);
		scanf("%[^\n]",suggestion);

		fprintf(fp2,"%s\n\n",suggestion);
		fflush(stdin);
		printf("\n\n\t\t\t\t\tThanks for your suggestion...!\n");
		fclose(fp2);
	}
	if(goal=='a')
	{
		printf("\n\n\n\t\t\t\t\tThanks for your Support.\n");
		getch();
	}

	for(i=0; i<4; i++)
	{
		system("color 01");
		Sleep(100);
		system("color 12");
		Sleep(100);
		system("color 36");
		Sleep(100);
		system("color 24");
		Sleep(100);
	}

	printf("Back to main-menu PRESS 'b' : ");
	fflush(stdin);
	ch=getch();
	if(ch=='b'||ch=='B')
	{
		system("cls");
		mainmenu();
	}
}

void Details()
{
	char ch, c;
	FILE *fp;
	fp=fopen("details.txt","r");
	while((c=getc(fp)) != EOF)
	{
		printf("%c",c);
	}
	fclose(fp);
	printf("\n\n\t\t   Back to main-menu PRESS 'b' : ");
	fflush(stdin);
	ch=getch();
	if(ch=='b'||ch=='B')
	{
		system("cls");
		mainmenu();
	}
}

void Admin()
{
	char adminid[10], password[10], pwd[]="1234", ch;
	int n, ans;

	start :
	printf("\n\n\n\t\t\t\t\tAdmin-id : ");
	fflush(stdin);
	gets(adminid);
	n=strcmp(adminid,"manager");
	if(n!=0)
	{
		printf("\n\n\n\t\t\t\t\t\t!!! Invalid Admin-id...\n");
		Sleep(1500);
		system("cls");
		goto start;
	}
	if(n==0)
	{
		back :
		printf("\n\n\t\t\t\t\tPassword : ");
		fflush(stdin);
			for(i=0; i<10; i++)
			{
				ch=getch();
				password[i]=ch;

				if(ch!=13)
				{
					printf("*");
				}
				if(ch==13)
				{
					goto p;
				}
			}
			p :
			password[i]='\0';

			ans = strcmp(password,pwd);

		if(ans!=0)
		{
			printf("\n\n\n\t\t\t\t\t\t!!! Invalid Password...\n");
			Sleep(1500);
			system("cls");
			goto back;
		}
		if(ans==0)
		{
			system("cls");
			adminhandle();
		}
	}
}

void adminhandle()
{
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			printf(" ");
		}printf("\n");
	}
	printf("\t\t\t\t     =============== Hello ! Admin ================");
	printf("\n\n\t\t\t\t\t1. Add Bus Information.");
	printf("\n\n\t\t\t\t\t2. Add new cities.");
	printf("\n\n\t\t\t\t\t3. Back to main menu.");
	printf("\n\n\n\t\t\t\t\t   Enter your choice : ");
	scanf("%d",&choice);
		system("cls");
	if (choice==1)
	{
		addbus();
	}
	if (choice==2)
	{
		addcity();
	}
	if (choice==3)
	{
		mainmenu();
	}
}

void addbus()
{
	struct addbus add;
	char ch;
	FILE *fp;

	fp = fopen("addbus.txt","a+");
	ct :
	printf("\n\n\t\t\tEnter New Bus-id : ");
	fflush(stdin);
	gets(add.busid);
	fprintf(fp,"%s==",add.busid);
	printf("\n\n\t\t\tEnter Bus-type : ");
	fflush(stdin);
	gets(add.bustype);
	fprintf(fp,"%s==",add.bustype);
	printf("\n\n\t\t\tEnter Bus-Origin where bus will depart : ");
	fflush(stdin);
	gets(add.busorigin);
	fprintf(fp,"%s==",add.busorigin);
	printf("\n\n\t\t\tEnter Bus-Destination where bus will arrive : ");
	fflush(stdin);
	gets(add.busdestin);
	fprintf(fp,"%s==",add.busdestin);
	printf("\n\n\t\t\tEnter Bus depart time [hour-minute]: ");
	fflush(stdin);
	scanf("%d-%d",&add.busdeparthour,&add.busdepartminute);
	fprintf(fp,"%d==",add.busdeparthour);
	fprintf(fp,"%d\n",add.busdepartminute);
	printf("\n\n\n\t\t\t\t");
	for(i=0; i<7; i++)
	{
		printf("%c ",254);
		Sleep(200);
	}
	printf("\n\n\n\t\t\tBUS Information is added successfully...!\n");
	printf("\n\n\tAdd another Bus [y/n] : ");
	fflush(stdin);
	choice=getch();
	if(choice=='y'||choice=='Y')
	{
		system("cls");
		goto ct;
	}
	fclose(fp);
	if(choice=='n'||choice=='N')
	{
		system("cls");
		printf("\n\n\t\tPRESS 'm' for go to main-menu\n\t\tOR\n\t\tPRESS 'b' for go to back\n\n");
	}

	fflush(stdin);
	ch=getch();
	system("cls");
	if(ch=='m'||ch=='M')
	{
		mainmenu();
	}
	if(ch=='b'||ch=='B')
	{
		adminhandle();
	}

}

void addcity()
{
	FILE *fp;
	struct addcity new;
	char choice, ch;
	static int num=18;

	fp=fopen("citynames.txt","a+");

	ct :
	printf("\n\n\n\t\tEnter city name which you want to add in City names file : ");
	fflush(stdin);
	gets(new.cityname);

	num++;
	fprintf(fp,"%d]%s\n",num,new.cityname);

	printf("\n\n\n\t\t\t\t");
	for(i=0; i<7; i++)
	{
		printf("%c ",254);
		Sleep(200);
	}
	printf("\n\n\n\t\t\tCity name is added successfully...!\n");
	printf("\n\n\tAdd another city [y/n] : ");
	fflush(stdin);
	choice=getch();
	if(choice=='y'||choice=='Y')
	{
		system("cls");
		goto ct;
	}
	fclose(fp);
	if(choice=='n'||choice=='N')
	{
		system("cls");
		printf("\n\n\t\tPRESS 'm' for go to main-menu\n\t\tOR\n\t\tPRESS 'b' for go to back\n\n");
	}

	fflush(stdin);
	ch=getch();
	system("cls");
	if(ch=='m'||ch=='M')
	{
		mainmenu();
	}
	if(ch=='b'||ch=='B')
	{
		adminhandle();
	}
}
