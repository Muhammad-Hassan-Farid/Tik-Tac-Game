#include<iostream>
using namespace std;

char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char move1='X';
int row,col;
bool Tie=false;
string n1,n2;


void display()
{
   system("cls");
   cout<<"    "<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<endl; 
   cout<<"   ___|___|___"<<endl;
   cout<<"      |   |   "<<endl;
   cout<<"    "<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<endl;
   cout<<"   ___|___|___"<<endl;
   cout<<"      |   |   "<<endl;
   cout<<"    "<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<endl; 
   cout<<"      |   |   "<<endl;
}

void Game()
{
    int ch;
    
    if(move1=='X')
    {
      cout<<n1<<"'s Turn: ";
      cin>>ch;
      
    }

    if(move1=='O')
    {
      cout<<n2<<"'s Turn: ";
      cin>>ch;
      
    }
    
    switch(ch)
    {
        case 1:
              {
                row=0;
                col=0;
                break;
              }

        case 2:
              {
                row=0;
                col=1;
                break;
              }

        case 3:
              {
                row=0;
                col=2;
                break;
              }

        case 4:
             {
                row=1;
                col=0;
                break;
             }

        case 5:
             {
                row=1;
                col=1;
                break;
             }

        case 6:
            {
                row=1;
                col=2;
                break;
            }

        case 7:
            {
                row=2;
                col=0;
                break;
            }

        case 8:
            {
                row=2;
                col=1;
                break;
            }

        case 9:
            {
                row=2;
                col=2;
                break;
            }

        default:
        {
            cout<<"Opps something want wrong...."<<endl;
            return Game();
        }
    }
    if (move1=='X' && arr[row][col]!='O' && arr[row][col]!='X') 
    { 
        arr[row][col]='X';
        move1='O';
    }
    else if (move1=='O' && arr[row][col]!='O' && arr[row][col]!='X')
    { 
        arr[row][col]='O';
        move1='X';
    }
    else
    {
        cout<<"Box is already filled.... try Again..."<<endl;
        Game();
    }
    display();
}

bool CheckStatus()
{
    for(int i=0; i<3; i++)
    {
        if(arr[i][0]==arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i]==arr[1][i] && arr[0][i] == arr[2][i] )
        {
         return false;
        }
               
    }

        if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] || arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0])
        { 
         return false;
        }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j]!='X' && arr[i][j]!='O')
            {
                return true;
            }
        }
    } 
    
    Tie=true;
    return false;

}


int main()
{
system("cls");

char y;
cout<<"Wellcome to TikTac Toe Game...."<<endl;

cout<<"Enter 1's player name: ";
cin>>n1;
cout<<"Enter the 2's player name: ";
cin>>n2;
display();

while(CheckStatus())
{
    Game();
    

}

if(move1=='X' && Tie==false)
{
    cout<<n2<<" has won....."<<endl;
}
else if(move1=='O' && Tie==false)
{
    cout<<n1<<" has won....."<<endl;
}
else 
{
    cout<<"Game is Draw....."<<endl;
}

cout<<"Do you want to play Again(y/n)...";
cin>>y;
if(y=='y'|| y=='Y')
{
    
    arr[0][0]='1';
    arr[0][1]='2';
    arr[0][2]='3';
    arr[1][0]='4';
    arr[1][1]='5';
    arr[1][2]='6';
    arr[2][0]='7';
    arr[2][1]='8';
    arr[2][2]='9';
    system("cls");
    move1='X';
    
    main();
}
    return 0;
}