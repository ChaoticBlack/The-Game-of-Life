#include <iostream>
#include <time.h>
//#include <curses.h>

using namespace std;



int main()
{
	int grid[10][10];
	int nextGen[10][10];
	int row,column;
	int Acount =0;
	int i=0;
	//Dcount=0;
	//assigning initial values to grid
	for(row=0;row<10;row++)
		{
			srand(time(NULL));
			for(column=0;column<10;column++)
			{
				//srand(time(NULL));
				int random = rand() % 2; 
				//cout<<random<<endl;
				if(random == 1)
					grid[row][column]=1;
				else
					grid[row][column]=0;
			}

		}	
	for(row=0;row<10;row++)
		{
			for(column=0;column<10;column++)
			{
				nextGen[row][column]=grid[row][column];
			}
		}

		//displaying the grid	
		cout<<"GRID IS "<<endl;
	for(row=0;row<10;row++)
		{
			for(column=0;column<10;column++)
			{
				cout<<grid[row][column];
			}
		cout<<endl;
		}
		cout<<endl;
		cout<<"nextGen IS "<<endl;
	for(row=0;row<10;row++)
		{
			for(column=0;column<10;column++)
			{
				cout<<nextGen[row][column];
			}
		cout<<endl;
		}
		cout<<endl;
	for (i=0;i<8;i++)
//	while (1)
	{
		for(row=0;row<10;row++) //matrix traversal
		{
			for(column=0;column<10;column++)
			{
				if(grid[row][column]==1) //if cell is alive
				{
					//if cell is alive then check neighboring 8 cells to find how many are alive

					if(row-1>=0 && grid[row-1][column] == 1)
					Acount++;
					if(row-1>=0 && column+1<10 && grid[row-1][column+1] == 1)
					Acount++;
					if(column+1<10 && grid[row][column+1] == 1)
					Acount++;
					if(row+1<10 && column+1<10 && grid[row+1][column+1] == 1)
					Acount++;
					if(row+1<10 && grid[row+1][column] == 1)
					Acount++;
					if(row+1<10 && column-1>=0 && grid[row+1][column-1] == 1)
					Acount++;
					if(column-1>=0 && grid[row][column-1] == 1)
					Acount++;
					if(row-1>=0 && column-1>=0 && grid[row-1][column-1] == 1)
					Acount++;

					//check game of life rules
					if(Acount<2)
					nextGen[row][column]=0;
					else if (Acount==2 || Acount==3)
					nextGen[row][column]=1;
					else if (Acount>3)
					nextGen[row][column]=0;
					Acount=0;

				}
				if(grid[row][column]==0) //if cell is dead
				{
					//if cell is dead check neighboring 8 cells to find how many cells are alive

					if(row-1>=0 && grid[row-1][column] == 1)
					Acount++;
					if(row-1>=0 && column+1<10 && grid[row-1][column+1] == 1)
					Acount++;
					if(column+1<10 && grid[row][column+1] == 1)
					Acount++;
					if(row+1<10 && column+1<10 && grid[row+1][column+1] == 1)
					Acount++;
					if(row+1<10 && grid[row+1][column] == 1)
					Acount++;
					if(row+1<10 && column-1>=0 && grid[row+1][column-1] == 1)
					Acount++;
					if(column-1>=0 && grid[row][column-1] == 1)
					Acount++;
					if(row-1>=0 && column-1>=0 && grid[row-1][column-1] == 1)
					Acount++;

					if(Acount==3)
					{
						nextGen[row][column]=1;
					}
					Acount=0;

				}
				//
			
			}
		}
		//displaying the new grid	
	for(row=0;row<10;row++)
		{
			for(column=0;column<10;column++)
			{
				cout<<nextGen[row][column];
			}
		cout<<endl;
		}
		cout<<endl;
		//cout<<"\033[2J\033[1;1H";
		//clrscr();
//		clear();
//		refresh();
		//shifting nextGen to grid	
	for(row=0;row<10;row++)
		{
			for(column=0;column<10;column++)
			{
				grid[row][column]=nextGen[row][column];
			}
		
		}
	}	



return 0;
}
