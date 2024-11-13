

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;
class GAMES
{
public:
    string player1,player2;
    virtual int display()=0;
    virtual int Instructions()=0;
};
class SNAKEANDLADDERS:public GAMES
{
    int startp1=0;
    int startp2=0;
    int p1=0;
    int p2=0;
    char p_1;
    char p_2;
    int dice=0;
    int *lt;
    int *lb;
    int *sh;
    int *st;
public:
    int display()override
    {
        int c=111;
        for(int j=0;j<=9;j++)
        {
            cout<<"--+-------+--";
        }
        cout<<endl;
        for(int i=0;i<=9;i++)
        {
            if(i%2==0)
            {
                c-=11;
                for(int j=0;j<=9;j++)
                {
                    if(p1==c&&p2==c)
                    {
                        cout<<"  |   "<<"\033[1;41m"<<p_1<<p_2<<"\033[0m"<<"\033[0;36m"<<"  |  ";
                        c--;
                    }
                    else if(p1==c)
                    {
                        cout<<"  |   "<<"\033[1;41m"<<p_1<<"\033[0m"<<"\033[0;36m"<<"   |  ";
                        c--;
                    }
                    else if(p2==c)
                    {
                        cout<<"  |   "<<"\033[1;41m"<<p_2<<"\033[0m"<<"\033[0;36m"<<"   |  ";
                        c--;
                    }
                    else if(c==100)
                    {
                        cout<<"  |  "<<c--<<"  |  ";
                    }
                    else if(c<10)
                    {
                        cout<<"  |   "<<c--<<"   |  ";
                    }
                    else
                    {
                        cout<<"  |   "<<c--<<"  |  ";
                    }
                }
            }
            else
            {
                c-=9;
                for(int j=0;j<=9;j++)
                {
                    if(p1==c&&p2==c)
                    {
                        cout<<"  |   "<<"\033[1;41m"<<p_1<<p_2<<"\033[0m"<<"\033[0;36m"<<"  |  ";
                        c++;
                    }
                    else if(p1==c)
                    {
                        cout<<"  |   "<<"\033[1;41m"<<p_1<<"\033[0m"<<"\033[0;36m"<<"   |  ";
                        c++;
                    }
                    else if(p2==c)
                    {
                        cout<<"  |   "<<"\033[1;41m"<<p_2<<"\033[0m"<<"\033[0;36m"<<"   |  ";
                        c++;
                    }
                    else if(c<10)
                    {
                        cout<<"  |   "<<c++<<"   |  ";
                    }
                    else
                    {
                        cout<<"  |   "<<c++<<"  |  ";
                    }
                }
            }
            cout<<endl;
            for(int j=0;j<=9;j++)
            {
                cout<<"--+-------+--";
            }
            cout<<endl;
        }
        return 0;
    }

    int dice1()
    {
        dice=rand()%6+1;
        cout<<"Dice rolled at : "<<dice<<endl;
        if(dice==6)
        {
            startp1=1;
        }
        return 0;
    }

    int dice2()
    {
        dice=rand()%6+1;
        cout<<"Dice rolled at : "<<dice<<endl;
        if(dice==6)
        {
            startp2=1;
        }
        return 0;
    }

    int forced(int p,string player)
    {
        for(int i=0;i<=7;i++)
        {
            if(p==lb[i])
            {
                display();
                cout<<player<<" got a ladder at "<<lb[i]<<" and advanced to "<<lt[i]<<"."<<endl;
                p=lt[i];
            }
            if(p==sh[i])
            {
                display();
                cout<<player<<" got bitten by a snake at "<<sh[i]<<" and moved to "<<st[i]<<"."<<endl;
                p=st[i];
            }
        }
        return p;
    }


    int Instructions()override
    {
        cout<<"\n* Instructions \n\n";
        cout<<"1. Each player gets one token to play.\n";
        cout<<"2. The players move their tokens from left to right,starting at 1.\n";
        cout<<"3. To move the token for first time,the player must roll a 6.\n";
        cout<<"4. After following the numbers on the board,the player goes to the next row from right to left and then goes to the next row from left to right and repeats.\n";
        cout<<"5. The value on the dice decides the number of boxes to move. If players roll a 3,they will move their token three places.\n";
        cout<<"6. If the player lands at the ladder’s base,their token immediately climbs to the top,landing on the box where the ladder ends. Their token will remain in the same spot until their next turn.\n";
        cout<<"7. If the player lands on the snake’s head,the token will slide down to the bottom of its tail,landing on the box where the tail ends. Their token will remain in the same spot until their next turn.\n";
        cout<<"8. If the player rolls a 6,they get an extra turn. The player can keep rolling sixes and move ahead in the game.\n";
        cout<<"9. If the player land at the bottom of the ladder or on the snake’s head when 6 is rolled,they must move their token down or up and then roll again to take their extra turn.\n";
        cout<<"10. The player’s token cannot move up the snake’s tail.\n";
        cout<<"11. The player’s token cannot move to the bottom of the ladder.\n";
        cout<<"12. The winner is the player who takes their token to the finish line,i.e.,the 100th box.\n";
        cout<<"\n\tTo exit from game,Enter E\n";
        cout<<"\n\tLadder's Bottom ------> Ladder's Top";
        return 0;
    }

    SNAKEANDLADDERS()
    {
        int lt1[]={38,14,31,42,84,67,91,99};
        int lb1[]={2,4,9,21,28,51,72,80};
        int sh1[]={17,54,62,64,87,93,95,98};
        int st1[]={7,34,19,60,36,73,75,79};
        lt=lt1;
        lb=lb1;
        sh=sh1;
        st=st1;
        srand(time(NULL));
        Instructions();
        cout<<"--------- Snake And Ladders ----------\n\n";
        for(int i=0;i<=7;i++)
        {
            cout<<"\n\t\t"<<lb[i]<<"\t------>\t   "<<lt[i];
        }
        cout<<"\n\n\t  Snake's Head  ------> Snake's Tail";
        for(int i=0;i<=7;i++)
        {
            cout<<"\n\t\t"<<sh[i]<<"\t------>\t   "<<st[i];
        }
        cout<<"\n\n* Snake and Ladders Board\n\n\n";
        display();
        cout<<"Enter name of Player 1 : ";
        fflush(stdin);
        getline(cin,player1);
        cout<<"Enter name of Player 2 : ";
        fflush(stdin);
        getline(cin,player2);
        p_2=player2[0];
        char c;
        int p1_choice;
        re:
        cout<<player1<<", enter your choice\n1 for heads\n2 for tails\n";
        try
            {
                fflush(stdin);
                cin>>p1_choice;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument("Invalid input. Please enter an integer value.");
                }
            }
            catch(const exception& e)
            {
                cerr<<"Error: "<<e.what()<<endl;
                goto re;
            }
        if(p1_choice==1)
        {
            cout<<player1<<" Choice is Heads\n";
            cout<<player2<<" Choice is Tails\n";
        }
        else if(p1_choice==2)
        {
            cout<<player1<<" Choice is Tails\n";
            cout<<player2<<" Choice is Heads\n";
        }
        else
        {
            cout<<"--------------------------------------------Invalid Choice--------------------------------------------\n";
            goto re;
        }
        cout<<"Press Enter to toss :";
        fflush(stdin);
        cin.get(c);
        int toss=rand()%2+1;
        if(toss==1)
        {
            cout<<"Toss comes out to be....... Heads!!\n";
        }
        else
        {
            cout<<"Toss comes out to be....... Tails!!\n";
        }
        if(toss==p1_choice)
        {
            cout<<player1<<" won the toss.\nLet's Start :\n";
            p_1=player1[0];
            p_2=player2[0];
        }
        else
        {
            cout<<player2<<" won the toss.\nLet's Start :\n";
            char temp[50];
            p_1=player1[0];
            p_2=player2[0];
        }
        p1=1;
        p2=1;
        while(p1!=100||p2!=100)
        {
            cout<<player1<<"'s Turn ---> Press Enter to roll the dice :\n";
            fflush(stdin);
            cin.get(c);
            if(c=='E'||c=='e')
            {
                cout<<"\n\tGame Terminated\n";
                goto x;
            }
            a:
            dice1();
            if(startp1)
            {
                p1+=dice;
                if(p1>100)
                {
                    p1-=dice;
                }
                p1=forced(p1,player1);
            }
            cout<<player1<<" at "<<p1<<" position.\n\n";
            display();
            if(dice==6)
            {
                cout<<player1<<",It's a SIX so press Enter to reroll the dice :\n";
                fflush(stdin);
                cin.get(c);
                goto a;
            }
            if(p1==100)
            {
                break;
            }
            cout<<player2<<"'s Turn ---> Press Enter to roll the dice :\n";
            fflush(stdin);
            cin.get(c);
            if(c=='E'||c=='e')
            {
                cout<<"\n\tGame Terminated\n";
                goto x;
            }
            b:
            dice2();
            if(startp2)
            {
                p2+=dice;
                if(p2>100)
                {
                    p2-=dice;
                }
                p2=forced(p2,player2);
            }
            cout<<player2<<" at "<<p2<<" position.\n\n";
            display();
            if(dice==6)
            {
                cout<<player2<<",It's a SIX so press Enter to reroll the dice :\n";
                cin.ignore();
                fflush(stdin);
                cin.get(c);
                goto b;
            }
            if(p2==100)
            {
                break;
            }
        }
        if(p1==100)
        {
            cout<<player1<<" wins.\n";
        }
        if(p2==100)
        {
            cout<<player2<<" wins.\n";
        }
        x:
        cout<<"\nThanks for Playing the Game.\n";
    }
};

class CHECKERS:public GAMES
{
    int r=8;
    int c=8;
    int blank=-1;
    int red=1;
    int black=2;
    int d[8][8]={
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {-1,0,-1,0,-1,0,-1,0},
        {0,-1,0,-1,0,-1,0,-1},
        {2,0,2,0,2,0,2,0},
        {0,2,0,2,0,2,0,2},
        {2,0,2,0,2,0,2,0}};
    public:
    char symbol(int a)
    {
        switch(a)
        {
            case 0:
                return ' ';
            case 1:
                return 'R';
            case 2:
                return 'B';
            case -1:
                return '_';
        }
        return '!';
    }

    int Instructions()
    {
        cout<<"------------Instructions-----------\n\n";
        cout<<"1. Checkers is a board game played between two people on an 8x8 checked board like the one shown above. \n";
        cout<<"2. Each player has 12 pieces that fit inside each of the boxes on the board.\n";
        cout<<"3. Player 1's pieces are red(R).\n";
        cout<<"4. Player 2's pieces are black(B).\n";
        cout<<"5. Red Piece moves first.\n";
        cout<<"6. Each player takes their turn by moving a piece.\n";
        cout<<"7. Pieces are always moved diagonally to an empty square.\n";
        cout<<"8. If there is one of the opponent's pieces just next to your piece and an empty space on the other side,you may jump over your opponent's piece and remove it.\n";
        cout<<"9. You win the game when the opponent has no more pieces or can't move (even if he/she still has pieces)\n";
        cout<<"10. If neither player can move then it is a draw or a tie.\n";
        cout<<"11. On your turn,just Enter the row number and column number of the piece you want to move and where to move.\n\n\nLet's Start :\n\n";
        return 0;
    }

    int gameOver()
    {
        int check_r=0;
        int check_b=0;
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                if(d[i][j]==1)
                {
                    check_r=1;
                    goto a;
                }
            }
        }
        a:
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                if(d[i][j]==2)
                {
                    check_b=1;
                    goto b;
                }
            }
        }
        b:
        return check_r&&check_b;
    }

    int display()
    {
        cout<<"\t\t\t  +---+---+---+---+---+---+---+---+\n";
        for (int i=0;i<r;i++)
        {
            cout<<"\t\t\t"<<i+1<<" |";
            for (int j=0;j<c;j++)
            {
                cout<<" "<<"\033[0;32m"<<symbol(d[i][j])<<"\033[0m"<<"\033[0;36m"<<" |";
            }
            cout<<endl;
            cout<<"\t\t\t  +---+---+---+---+---+---+---+---+\n";
        }
        cout<<"\t\t\t    1   2   3   4   5   6   7   8\n\n";
        return 0;
    }

    int swap(int i,int j,int k,int l)
    {
        int temp;
        temp=d[i][j];
        d[i][j]=d[k][l];
        d[k][l]=temp;
    }

    int play_move(int player,int i,int j,int k,int l)
    {
        int move_r;
        int move_c;
        if(d[i][j]!=blank)
        {
            cout<<"Piece must move to a blank position.Please enter correct position.\n";
            return -1;
        }
        if(d[k][l]!=blank)
        {
            cout<<"Piece must move to a blank position.Please enter correct position.\n";
            return -1;
        }
        if(player==red)
        {
            if(i>=k)
            {
                cout<<"Invalid Move!\n";
                return -1;
            }
        }
        else
        {
            if(i<=k)
            {
                cout<<"Invalid Move!\n";
                return -1;
            }
        }
        if(i-k==-1||i-k==1)
        {
            if(j-l==1||j-l==-1)
            {
                swap(i,j,k,l);
                if(player==red)
                {
                    cout<<"Red Piece moved from "<<i+1<<","<<j+1<<" to "<<k+1<<","<<l+1<<endl;
                }
                else
                {
                    cout<<"Black Piece moved from "<<i+1<<","<<j+1<<" to "<<k+1<<","<<l+1<<endl;
                }
                return 0;
            }
        }
        if(i-k==-2||i-k==2)
        {
            if(j-l==-2||j-l==2)
            {
                if(i<k)
                {
                    move_r=i+1;
                }
                else
                {
                    move_r=i-1;
                }
                if(j<l)
                {
                    move_c =j+1;
                }
                else
                {
                    move_c=j-1;
                }
                if(player==red&&d[move_r][move_c]!=black)
                {
                    cout<<"No Black Piece at "<<move_r+1<<","<<move_c+1<<" to jump over.\n";
                    return -1;
                }
                if(player==black&&d[move_r][move_c]!=red)
                {
                    cout<<"No Red Piece at "<<move_r+1<<","<<move_c+1<<" to jump over.\n";
                    return -1;
                }
                if(player==red)
                {
                    cout<<"Black Piece at "<<move_r+1<<","<<move_c+1<<" has been captured.\n";
                }
                if(player==black)
                {
                    cout<<"Red piece at "<<move_r+1<<","<<move_c+1<<" has been captured.\n";
                }
                d[move_r][move_c]=-1;
                swap(i,j,k,l);
                return 0;
            }
        }
        cout<<"Piece can only move diagonally\n";
        return -1;
    }

    int Winner()
    {
        int check_r=0;
        int check_b=0;
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                if(d[i][j]==1)
                {
                    check_r==1;
                    break;
                }
            }
        }
        if(check_r==0)
        {
            cout<<player2<<" wins.";
        }
        else
        {
            cout<<player1<<" wins.";
        }
        return 0;

    }

    CHECKERS()
    {
        cout<<"-----------------------Checkers-----------------------------\n\n";
        int i,j,k,l;
        char c;
        display();
        Instructions();
        fflush(stdin);
        cout<<"Enter name of Player 1 : ";
        fflush(stdin);
        getline(cin,player1);
        cout<<"Enter name of Player 2 : ";
        fflush(stdin);
        getline(cin,player2);
        while (1&&gameOver())
        {

            display();
            cout<<"Enter to Continue or Input E to exit\n";
            cin.ignore();
            fflush(stdin);
            cin.get(c);
            if(c=='E'||c=='e')
            {
                goto exit;
            }
            while (1)
            {
                re1:
                cout<<player1<<"'s turn:\n";
                cout<<"From -:\n";
                try
                {
                    iin1:
                    cout<<"Row : ";
                    fflush(stdin);
                    cin>>i;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(i<0||r<=i)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto iin1;
                    }
                    jin1:
                    cout<<"Column : ";
                    fflush(stdin);
                    cin>>j;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(j<0||c<=j)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto jin1;
                    }
                    if(d[i-1][j-1]!=red)
                    {
                        cout<<"No red token at given position!!Please enter correct position.\n";
                        goto iin1;
                    }
                    cout<<"To -:\n";
                    kin1:
                    cout<<"Row : ";
                    fflush(stdin);
                    cin>>k;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(k<0||r<=k)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto kin1;
                    }
                    lin1:
                    cout<<"Column : ";
                    fflush(stdin);
                    cin>>l;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(l<0||c<=l)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto lin1;
                    }

                }
                catch(const exception& e)
                {
                    cerr<<"Error: "<<e.what()<<endl;
                    goto re1;
                }

                if(play_move(red,i-1,j-1,k-1,l-1)==0)
                {
                     break;
                }
                cout<<"\nIllegal move,try again.\n\n";
            }
            display();
            while (1)
            {
                re2:
                cout<<player2<<"'s turn:\n";
                cout<<"From -:\n";
                try
                {
                    iin:
                    cout<<"Row : ";
                    fflush(stdin);
                    cin>>i;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(i<0||r<=i)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto iin;
                    }
                    jin:
                    cout<<"Column : ";
                    fflush(stdin);
                    cin>>j;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(j<0||c<=j)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto jin;
                    }
                    if(d[i-1][j-1]!=black)
                    {
                        cout<<"No black token at given position!!Please enter correct position.\n";
                        goto iin;
                    }
                    cout<<"To -:\n";
                    kin:
                    cout<<"Row : ";
                    fflush(stdin);
                    cin>>k;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(k<0||r<=k)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto kin;
                    }
                    lin:
                    cout<<"Column : ";
                    fflush(stdin);
                    cin>>l;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                    if(l<0||c<=l)
                    {
                        cout<<"Position is Invalid.Please enter correct position.\n";
                        goto lin;
                    }
                }
                catch(const exception& e)
                {
                    cerr<<"Error: "<<e.what()<<endl;
                    goto re2;
                }
                if(play_move(black,i-1,j-1,k-1,l-1)==0)
                {
                     break;
                }
                cout<<"\nIllegal move,try again.\n\n";
            }
        }
        if(gameOver()==0)
        {
            Winner();
        }
        exit:
        cout<<"\nThanks for Playing the Game.\n";
    }
};

class HANDCRICKET:public GAMES
{
    int player1Score,player2Score,target=10000;
    public:
    int Toss(int oversToplay)
    {

        int p1_choice,p2_choice,toss,player1Toss,bat_bowlChoice;
        re:
        cout<<player1<<", enter your choice :\n1 for heads\n2 for tails\n";
        try
        {
            fflush(stdin);
            cin>>p1_choice;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("Invalid input. Please enter an integer value.");
            }
        }
        catch(const exception& e)
        {
            cerr<<"Error: "<<e.what()<<endl;
            goto re;
        }
        if(p1_choice<1||p1_choice>2)
        {
            cout<<"Invalid choice. Enter 1 or 2\n";
            goto re;
        }
        if(p1_choice==1)
        {
            p2_choice=2;
            cout<<player1<<"'s choice is Heads\n";
            cout<<player2<<"'s choice is Tails\n";
        }
        else if(p1_choice==2)
        {
            p2_choice=1;
            cout<<player1<<"'s choice is Tails\n";
            cout<<player2<<"'s choice is Heads\n";
        }
        srand(time(NULL));
        toss=rand()%2+1;
        if(toss==1)
        {
            cout<<"Toss comes out to be....... Heads!!\n";
        }
        else
        {
            cout<<"Toss comes out to be....... Tails!!\n";
        }
        if(toss==p1_choice)
        {
            re1:
            cout<<player1<<" won the Toss\n"<<"Choose\n1-Batting\n2-Bowl: ";
            try
            {
                cin>>bat_bowlChoice;
                if(cin.fail())
                {
                    cin.ignore();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument("Invalid input. Please enter an integer value.");
                }
            }
            catch(const exception& e)
            {
                cerr<<"Error: "<<e.what()<<endl;
                goto re1;
            }
            if(bat_bowlChoice==1)
            {
                cout<<"---------------"<<player1<<" is Going to bat Now-----------------------\n";
                player1Score=batting(player1,player2,oversToplay);
                target=player1Score;
                cout<<"---------------"<<player2<<" is Going to bat Now-----------------------\n";
                player2Score=batting(player2,player1,oversToplay);
                cout<<"-------------------Results-----------------------\n";
            }
            else if(bat_bowlChoice==2)
            {
                cout<<"---------------"<<player2<<" is Going to bat Now-----------------------\n";
                player2Score=batting(player2,player1,oversToplay);
                target=player2Score;
                cout<<"---------------"<<player1<<" is Going to bat Now-----------------------\n";
                player1Score=batting(player1,player2,oversToplay);
                cout<<"-------------------Results-----------------------\n";
            }
            else
            {
                cout<<"--------------------------------------------Invalid Choice--------------------------------------------\n";
                cin.ignore();
                goto re1;
            }
        }
        else if(toss==p2_choice)
        {
            cout<<player2<<" Won the Toss\n";
            re2:
            cout<<"Choose\n1-Batting\n2-Bowl: ";
            try
            {
                cin>>bat_bowlChoice;
                if(cin.fail())
                {
                    cin.ignore();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument("Invalid input. Please enter an integer value.");
                }
            }
            catch(const exception& e)
            {
                cerr<<"Error: "<<e.what()<<endl;
                goto re2;
            }
            if(bat_bowlChoice==1)
            {
                cout<<"---------------"<<player2<<" is Going to bat Now-----------------------\n";
                player2Score=batting(player2,player1,oversToplay);
                target=player2Score;
                cout<<"---------------"<<player1<<" is Going to bat Now-----------------------\n";
                player1Score=batting(player1,player2,oversToplay);
                cout<<"-------------------Results-----------------------\n";
            }
            else if(bat_bowlChoice==2)
            {
                cout<<"---------------"<<player1<<" is Going to bat Now-----------------------\n";
                player1Score=batting(player1,player2,oversToplay);
                target=player1Score;
                cout<<"---------------"<<player2<<" is Going to bat Now-----------------------\n";
                player2Score=batting(player2,player1,oversToplay);
                cout<<"-------------------Results-----------------------\n";
            }
            else
            {
                cout<<"--------------------------------------------Invalid Choice--------------------------------------------\n";
                cin.ignore();
                goto re2;
            }
        }
        if(player1Score==player2Score)
        {
            cout<<"Draw Match\n";
        }
        if(player1Score>player2Score)
        {
            cout<<player1<<" won the Match.\n";
        }
        if(player1Score<player2Score)
        {
            cout<<player2<<" won the Match.\n";
        }
        return 0;
    }
    int display(){}
    int batting(string& battingplayer,string& bowlingplayer,int oversToplay)
    {
        int i,j,battingScore,runs=0,bowlerScore,wicket=1;
        char c;
        if(oversToplay>0)
        {
            for (i=0;i<oversToplay;i++)
            {
                for (j=0;j<=5;j++)
                {
                    cout<<"Overs : "<<i<<"."<<j<<"\n";
                    cout<<bowlingplayer<<" Press Enter key to bowl :";
                    cin.ignore();
                    fflush(stdin);
                    cin.get(c);
                    bowlerScore=(int)rand()%7;
                a:
                    cout<<endl<<battingplayer<<" Enter the runs(0-6) you want to score on this coming ball :";
                    try
                    {
                        cin>>battingScore;
                        if(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            throw invalid_argument("Invalid input. Please enter an integer value.");
                        }
                    }
                    catch(const exception& e)
                    {
                        cerr<<"Error: "<<e.what()<<endl;
                        goto a;
                    }
                    if(battingScore>6||battingScore<0)
                    {
                        cout<<"Invalid runs enetered";
                        goto a;
                    }
                    if(battingScore==bowlerScore)
                    {
                        wicket=0;
                        cout<<"----------------"<<battingplayer<<" is Out----------------\n";
                        cout<<battingplayer<<"'s Total Score="<<runs<<"\n";
                        if(runs==0&&i==0&&j==0)
                        {
                            cout<<"Alas! You got a Golden Duck\n";
                        }
                        else if(runs==0)
                        {
                            cout<<"Alas! You got a Duck\n";
                        }
                        break;
                    }
                    else
                    {
                        if(battingScore==6)
                        {
                            cout<<"It's a SIX !!!!!! Bravo\n";
                        }
                        if(battingScore==4)
                        {
                            cout<<"It's a FOUR !!!!!! Nice\n";
                        }
                        cout<<"Got "<<battingScore<<" runs\n";
                        runs=runs+battingScore;
                        cout<<battingplayer<<"'s Score="<<runs<<"\n";
                        if(runs>target)
                        {
                            return runs;
                        }
                    }
                }
                if(wicket==0)
                {
                    break;
                }
            }
            return runs;
        }
        if(oversToplay==0)
        {
            int i=0,j=0;
            while (wicket)
            {
                cout<<"Overs : "<<i<<"."<<j<<"\n";
                cout<<bowlingplayer<<" Press Enter key to bowl :";
                cin.ignore();
                fflush(stdin);
                cin.get(c);
                bowlerScore=(int)rand()%7;
            b:
                cout<<endl<<battingplayer<<" Enter the runs(0-6) you want to score on this coming ball :";
                try
                {
                    cin>>battingScore;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw invalid_argument("Invalid input. Please enter an integer value.");
                    }
                }
                catch(const exception& e)
                {
                    cerr<<"Error: "<<e.what()<<endl;
                    goto b;
                }
                if(battingScore>6||battingScore<0)
                {
                    cout<<"Invalid runs";
                    goto b;
                }
                if(battingScore==bowlerScore)
                {
                    wicket=0;
                    cout<<"----------------"<<battingplayer<<" is Out----------------\n";
                    cout<<battingplayer<<"'s Total Score="<<runs<<"\n";
                    if(runs==0)
                    {
                        cout<<"Alas! You got a Duck\n";
                        break;
                    }
                }
                else
                {
                    cout<<"Got "<<battingScore<<" runs\n";
                    if(battingScore==6)
                    {
                        cout<<"It's a SIX !!!!!! Bravo\n";
                    }
                    if(battingScore==4)
                    {
                        cout<<"It's a FOUR !!!!!! Nice\n";
                    }
                    runs += battingScore;
                    cout<<battingplayer<<"'s Score= "<<runs<<"\n";
                    j++;
                    if(j>5)
                    {
                        j=0;
                        i++;
                    }
                    if(runs>target)
                    {
                        return runs;
                    }
                }
            }
            return runs;
        }
        return 0;
    }

    int Instructions()
    {
        cout<<"Instructions :\n";
        cout<<"1. Until a player Won the toss Follow the Output and Enter whatever it asks you to Enter.\n";
        cout<<"2. The Player who won the toss chooses either to Bat or to Bowl\n";
        cout<<"3. The Player who chose bowling has to proceed by pressing Enter Key one by one\n";
        cout<<"4. Batsman has to enter the runs(0-6) they want to hit on upcoming ball.";
        cout<<"5. Runs to prevent on the upcoming ball is generated by system.\n";
        cout<<"6. If the runs to prevent equalled the runs hit by the batsman on the upcoming ball,batsman is out.\n";
        cout<<"7. Finally whoever is having Highest Score is the Winner.\n\n\n";
        cout<<"For Example: \nPlayer 1 Won the Toss And Chose Batting.Then When Player 1 Press Enter Key,A score will be generated for Player 1\n";
        cout<<"Suppose runs are 5 So Player 1 Score=5.Then Player 2 Also Presses Enter key.Then ifhe got a Score of 4.So Player 2 Score =4\n";
        cout<<"As Player 1 Score is not equal to player 2 Score Then Player 1 is not out and hi score will be 5 after 1st ball \n";
        cout<<"In 2nd ball Player 1 got 3 runs and Player 2 got 4.Since again both are not equal.Player 1 Score=5+3=8\n";
        cout<<"If in the 3rd Ball Player 1 got 4 runs and Player 2 also got 4 runs Then Player 1 Score is equal to Player 2's Score Then Player 1 is Out\n";
        cout<<"Then Final Score of player 1 is 8 runs.\n";
        cout<<"The Same Process is done for Player 2.So Finally who ever got more score is Winner\n\n\n";
        return 0;
    }

    HANDCRICKET()
    {
        int i,j,overs,choice;
        srand(time(NULL));
        cout<<"-----------------------------------Hand Cricket Game-------------------------------------\n\n\n\n\n";
        Instructions();
        cout<<"Enter Player 1 Name:";
        fflush(stdin);
        getline(cin,player1);
        cout<<"Enter Player 2 Name:";
        fflush(stdin);
        getline(cin,player2);
        re:
        cout<<"Enter\n1-Fixed Overs\n2-Play Until Out\n3-Exit: \n";
        try
        {
            cin>>choice;
            if(cin.fail())
            {
                cin.ignore();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("Invalid input. Please enter an integer value.");
            }
        }
        catch(const exception& e)
        {
            cerr<<"Error : "<<e.what()<<endl;
            goto re;
        }
        if(choice==1)
        {
            repeat:
            cout<<"Enter no. Of Overs: ";
            try
            {
                fflush(stdin);
                cin>>overs;
                if(cin.fail())
                {
                    cin.ignore();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument("Invalid input. Please enter an integer value.");
                }
            }
            catch(const exception& e)
            {
                cerr<<"Error: "<<e.what()<<endl;
                goto repeat;
            }
            Toss(overs);
        }
        else if(choice==2)
        {
            Toss(0);
        }
        else if(choice==3)
        {
            goto x;
        }
        else
        {
            cout<<"--------------------------------------------Invalid Choice--------------------------------------------\n";
            cin.ignore();
            goto re;
        }
        x:
        cout<<"\nThanks for Playing the Game.\n";
    }
};

class SUDOKU:public GAMES
{
    int grid[9][9];
public:
    int setGrid()
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                grid[i][j]=0;
            }
        }
        return 0;
    }

    int Instructions()
    {
        cout<<"Instructions :\n\n";
        cout<<"1. Sudoku grid consists of 9x9 spaces.\n";
        cout<<"2. You can use only numbers from 1 to 9.\n";
        cout<<"3. Each 3*3 block can only contain numbers from 1 to 9.\n";
        cout<<"4. Each vertical column can only contain numbers from 1 to 9.\n";
        cout<<"5. Each horizontal row can only contain numbers from 1 to 9.\n";
        cout<<"6. Each number in the 3*3 block,vertical column or horizontal row can be used only once.\n";
        cout<<"7. Fill the block by Entering the block position(1-81) you want to fill.\n";
        cout<<"8. Once completely filled the known cells,Enter 0 to get the Solution.\n\n\n";
    }

    int solveSudoku(int row,int col)
    {
        if(row==8&&col==9)
        {
            return 1;
        }
        if(col==9)
        {
            row++;
            col=0;
        }
        if(grid[row][col]!=0)
        {
            return solveSudoku(row,col+1);
        }
        for(int num=1;num<10;num++)
        {
            if(isCorrect(row,col,num))
            {
                grid[row][col]=num;
                if(solveSudoku(row,col+1))
                {
                    return 1;
                }
            }
            grid[row][col]=0;
        }
        return 0;
    }

    int display()
    {
        cout<<"\n\t\t\t||===========++===========++===========||\n";
        for(int i=0;i<9;i++)
        {
            cout<<"\t\t\t||";
            for(int j=0;j<9;j++)
            {
                if(j%3!=2)
                {
                    if(grid[i][j]==0)
                    {
                        cout<<"   |";
                    }
                    else
                    {
                        cout<<" "<<"\033[0;32m"<<grid[i][j]<<"\033[0m"<<"\033[0;36m"<<" |";
                    }
                }
                else
                {
                    if(grid[i][j]==0)
                    {
                        cout<<"   ||";
                    }
                    else
                    {
                        cout<<" "<<"\033[0;32m"<<grid[i][j]<<"\033[0m"<<"\033[0;36m"<<" ||";
                    }
                }
            }
            if(i%3!=2)
            {
                cout<<"\n\t\t\t||-------------------------------------||\n";
            }
            else
            {
                cout<<"\n\t\t\t||===========++===========++===========||\n";
            }
        }
        return 0;
    }

    int isCorrect(int row,int col,int num)
    {
        for(int x=0;x<=8;x++)
        {
            if(grid[row][x]==num)
            {
                return 0;
            }
        }
        for(int x=0;x<=8;x++)
        {
            if(grid[x][col]==num)
            {
                return 0;
            }
        }
        int startRow=row-row%3,startCol=col-col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i+startRow][j+startCol]==num)
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    SUDOKU()
    {
        cout<<"------------------ Sudoku Solver ------------------\n";
        setGrid();
        display();
        Instructions();
        cout<<"----------Start---------\n\n";
        int a=0,b=0,pos=0;
        while(true)
        {
            repeat1:
            cout<<"Input the block position :\n";
            try
            {
                fflush(stdin);
                cin>>pos;
                if(cin.fail())
                {
                    cin.ignore();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument("Invalid input. Please enter an integer value.");
                }
            }
            catch (const exception& e)
            {
                cerr<<"Error: "<<e.what()<<endl;
                goto repeat1;
            }
            if(pos==0)
            {
                break;
            }
            if(pos<0||pos>81)
            {
                cout<<"Invalid position\n";
                continue;
            }
            a=pos/9;
            b=pos%9-1;
            if(pos%9==0)
            {
                a=--a;
                b=8;
            }
            repeat2:
            cout<<"Input the number :\n";
            try
            {
                fflush(stdin);
                cin>>grid[a][b];
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument("Invalid input. Please enter an integer value.");
                }
            }
            catch(const exception& e)
            {
                cerr<<"Error: "<<e.what()<<endl;
                goto repeat2;
            }
            display();
        }
        if(solveSudoku(0,0))
        {
            cout<<"Solution :\n";
            display();
        }
        else
        {
            cout<<"No Solution exists.\n";
        }
        cout<<"\nThanks for Playing the Game.\n";
    }
};

int main()
{
    cout<<"\033[0;36m";
    int choice;
    cout<<"-----------------------------------------WELCOME TO THE WORLD OF GAMES---------------------------------------"<<endl;
    repeat:
        cout<<"\n\t\t\t\t\t1. Snake and Ladders"<<endl;
        cout<<"\t\t\t\t\t2. Checkers"<<endl;
        cout<<"\t\t\t\t\t3. Hand Cricket"<<endl;
        cout<<"\t\t\t\t\t4. Sudoku Solver"<<endl;
        cout<<"\n\t\t\t\t\t5. Exit the WORLD OF GAMES\n\n"<<endl;
        cout<<"Choose the game you want to play : ";
        try
        {
            fflush(stdin);
            cin>>choice;
            if(cin.fail())
            {
                cin.ignore();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. Please enter an integer value.");
            }
        }
        catch (const exception& e)
        {
            cerr<<"Error: "<<e.what()<<endl;
            goto repeat;
        }
        GAMES* obj;
        switch(choice)
        {
            case 1:
                cout<<"\n\n";
                obj=new SNAKEANDLADDERS;
                break;
            case 2:
                cout<<"\n\n";
                obj=new CHECKERS;
                break;
            case 3:
                cout<<"\n\n";
                obj=new HANDCRICKET;
                break;
            case 4:
                cout<<"\n\n";
                obj=new SUDOKU;
                break;
            case 5:
                cout<<"Thanks for playing the games :)"<<endl;
                return 0;
                break;
            default:
                cout<<"Invalid option."<<endl;
                goto repeat;
        }
    char choose;
    c:
        cout<<"\nEnter\nY,to Play Again"<<endl;
        cout<<"N,to Exit\n"<<endl;
         fflush(stdin);
        cin>>choose;
        switch(choose)
        {
            case 'Y':
                goto repeat;
                break;
            case 'y':
                goto repeat;
                break;
            case 'N':
                cout<<"\nThanks for playing the games :)"<<endl;
                return 0;
                break;
            case 'n':
                cout<<"\nThanks for playing the games :)"<<endl;
                return 0;
                break;
            default:
                cout<<"\nInvalid Input"<<endl;
                goto c;
        }
    return 0;
}









