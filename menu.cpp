#include<iostream>
#include<iomanip>
#include"console.cpp"
using namespace std;




void Nocursorttype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void menu()
{
	for (int i=0;i<=100;i++)
	{
		TextColor(3);
		std::cout <<"*";
		TextColor(7);
		
	}
	for(int i=0;i<=25;i++)
	{
		std::cout <<endl<<"|"<<setw(100)<<"|";
		if(i==1)  cout <<" Game Xe Tang";
		
		if (i == 3)   cout <<"A,D,4,6 Bat Dau";
		if (i == 5)   cout <<"A,D Di Chuyen Tank";
		if (i == 7)   cout <<"4,6 Di Chuye Tank1";
		if (i == 9)   cout <<"S Ban Dan Tank";
		if (i == 11)   cout <<"5 Ban Dan Tank1";
		if (i == 25)
		{
			cout <<endl;
			for(int j=0;j<=100;j++)
			{
				TextColor(10);
				cout <<"*";
				TextColor(7);
			}
		}
	}
	gotoXY(5,28);
	TextColor(95);
	cout << "CHU Y: KHI BAN DAN , VIEC DI CHUYEN SE KHONG THUC HIEN ! ";
	TextColor(7);
}
