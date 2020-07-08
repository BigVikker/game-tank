#include<iostream>
#include "menu.cpp"

using namespace std;

class Bullet
{
	public:
		 int xBullet, yBullet;
		
		Bullet()
		{
			xBullet = 1;
			yBullet = 1;
		}
		
		Bullet(int x, int y)
		{
			xBullet = x;
			yBullet = y;
		}
		
//		methods
	
		void drawBulletDown(int x, int y)
		{
			gotoXY(x,y-1);
			cout<<" ";
			gotoXY(x,y);
			TextColor(10);
			cout << "*";
			TextColor(7);	
		}
		void drawBulletUp(int x, int y)
		{
			gotoXY(x,y+1);
			cout<<" ";
			gotoXY(x,y);
			TextColor(3);
			cout << "*";
			TextColor(7);
		}
//destructor
		~Bullet();
};




class Tank
{
	public:
		int xTank,yTank;
		Bullet bullet;	

//construction
		Tank()
		{
			xTank = 1;
			yTank = 1;
			bullet.xBullet = xTank;
			bullet.yBullet = yTank;
		}	
	
		Tank(int x,int y)
		{
			this->xTank=x;
			this->yTank=y;
			bullet.xBullet = x;
			bullet.yBullet = y;
		}

//methods
		void hinhTank(int x,int y)
		{
			gotoXY(x, y);
			TextColor(10);
			cout <<"[--+--]";
			TextColor(7);
			
		}
		void hinhTank1(int x,int y)
		{
			gotoXY(x, y);
			TextColor(3);
			cout <<"[--+--]";
			TextColor(7);
		}
	
	
	
	// destructor
	~Tank();
};



int main()
{
	menu();
	Nocursorttype();
	Tank *tank = new Tank(1,1);
	Tank *tank1 = new Tank(92,26);
	tank1->xTank = 93;
	int mau1 =10;
	int mau2 =10;
	bool running = true;
	while(running)
	{
		switch(_getch())
		{
			case'd':
			{
				if(tank->xTank >= 100-8)
				{
					break;
				}
				gotoXY(tank->xTank,1);
				cout <<" ";	
				tank->hinhTank(tank->xTank + 1, tank->yTank);
				tank1->hinhTank1(tank1->xTank , 26);
                tank->xTank += 1;
				break;			
			}
			case'a':
			{
				if(tank->xTank <= 1)
				{
					break;
				}
				gotoXY(tank->xTank+6,1);
				cout<<" ";
				tank->hinhTank(tank->xTank - 1, tank->yTank);
				tank1->hinhTank1(tank1->xTank , 26);
				tank->xTank -= 1;
				break;
			}
			
			case's':
			{
				tank->bullet.xBullet = tank->xTank + 3; //cong voi do dai/2 cua tank
				tank->bullet.yBullet = tank->yTank;
				while(tank->bullet.yBullet < 27)
				{
					tank->bullet.yBullet += 1;
					tank->bullet.drawBulletDown(tank->bullet.xBullet,tank->bullet.yBullet);
					if(tank->bullet.yBullet == 26 && tank->bullet.xBullet - tank1->xTank >=0  && tank->bullet.xBullet - tank1->xTank <=6)
					{
						mau1 -=1;
						if(mau1 == 0)
						{
							clrscr();
						    TextColor(10);
						    cout <<endl<<endl<<endl << "      Tank from UPPER Won !";
						    running = false;
						}
					}
					Sleep(50);
				}
				break;
			}
			case'4':
			{
				if(tank1->xTank <= 1)
				{
					break;
				}
				gotoXY(tank1->xTank+6,26);
				cout<<" ";
				tank1->hinhTank1(tank1->xTank - 1, 26);
				tank1->xTank -= 1;
				tank->hinhTank(tank->xTank , 1);
				break;
			}
			case'6':
			{
				if(tank1->xTank >= 100-8)
				{
					break;
				}
				gotoXY(tank1->xTank,26);
				cout <<" ";
				tank1->hinhTank1(tank1->xTank + 1, 26);
				tank->hinhTank(tank->xTank , 1);
                tank1->xTank += 1;
				break;
			}
			case'5':
			{
				tank1->bullet.xBullet = tank1->xTank + 3;
				tank1->bullet.yBullet = tank1->yTank;
				while(tank1->bullet.yBullet > 0)
				{
					tank1->bullet.yBullet -= 1;
					tank->bullet.drawBulletUp(tank1->bullet.xBullet,tank1->bullet.yBullet);
					if(tank1->bullet.yBullet == 1 && tank1->bullet.xBullet - tank->xTank >= 0 && tank1->bullet.xBullet - tank->xTank <= 6)
					{
					    mau2 -=1;
					    if(mau2 ==0)
					    {
					    	clrscr();
						    TextColor(3);
						    cout << endl << endl <<endl <<"      Tank from LOWER WON ! ";
						    running = false;
						}
					}
					gotoXY(0,29);
					cout << " mau Xe Tank1:"<<mau1 <<"    mau Xe Tank2:"<< mau2;
					Sleep(50);
				}
			}	
		}

	}
	system("pause > NULL");
	tank = NULL;
	tank1 = NULL;
}
