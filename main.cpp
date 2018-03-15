#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Vehicle{
private:
    bool left;
    bool right;
    bool FourWheelerEngine;
    bool TwoWheelerEngine;
    int SteeringAngle;
    int LightBeam;

public:
    void delay(int delay)//used wherever blink is needed
    {
        int now=time(NULL);
        int later=now+delay;
        while(now<=later)now=time(NULL);
    }
    int vehicle(int Night,int SteeringAngle,int FourWheelerEngine,int Right,int Left)//function for four wheeler adaptive headlight
    {
        int i,j;
        if(Night == 1)
        {
            if(FourWheelerEngine==1)
            {
                if(Right == 1)//turn headlights to right direction
                {
                        cout << "Headlights are towards right direction" << endl;
                        for(i=0;i<3;i++)
                            {
                                cout <<"------>"<<endl;
                            }
                }
                if(Left==1)//turn headlights to left direction
                {
                    cout << "Headlights are towards left direction" << endl;
                    for(i=0;i<3;i++)
                            {
                                for(j=0;j<i;j++)
                                {
                                    cout<<" ";
                                }
                                cout <<"^^^"<<endl;
                            }
                }

                }

                }
       return 0;  }

    int vehicle(int Night,int FourWheelerEngine,int left,int right)//adaptive blinker for four wheeler
    {
    int i;

        if(Night == 1)
        {
            if(left==1 && right==1)//vehicle on both side
            {
                 for(i=0;i<2;i++){
                    cout << "\t|****|" << endl;
                    cout << "\t|-**-|" << endl;
                    delay(0.9);
            }
            }
            if(left==0 && right==1)//vehicle on right side
            {
                 for(i=0;i<2;i++){
                    cout << "\t|****|" << endl;
                    cout << "\t|***-|" << endl;
                    delay(0.9);
            }
            }
            if(left==1 && right==0)//vehicle on left side
            {
                 for(i=0;i<2;i++){
                    cout << "\t|****|" << endl;
                    cout << "\t|-***|" << endl;
                    delay(0.9);
            }
            }
        }
        else
        {
            cout << " Its a Day time.Headlights will be OFF" << endl;
        }
                return 0;
    }
    int vehicle(int Night,int TwoWheelerEngine, int LightBeam)//adaptive blinker for two wheeler
    {
        int i,j;
        if(Night == 1)
        {
            if(TwoWheelerEngine==1)
            {
                if(LightBeam==1)
                {
                    cout << " High Beam " << endl;

                    for(i=0;i<3;i++)//blink
                    {
                            cout <<"*"<<endl;
                            delay(0.6);
                            cout<<" "<<endl;
                    }

                }
                else
                {
                    cout << " Usual Beam " << endl;
                    for(i=0;i<3;i++)//usual light
                    {
                            cout <<"*"<<endl;
                    }

                }
            }
            else
            {
                cout << " Engine is OFF" << endl;
            }
        }
        else
        {
            cout << " Its a Day time.Headlights will be OFF" << endl;

        }

    }


    void display()//function to display menu
    {
        cout << "\n\n ---------------MENU------------" << endl;
        cout <<" Press 'F' or 'f' for Four wheeler Vehicle" << endl;
        cout << "Press 'T' or 't' for Two wheeler vehicle " << endl;
        cout << " press 'E' or 'e' to exit the program" << endl;
    }
};


int main()
{
    Vehicle v;
    char choice;
    int SteeringAngle,Night,Right,Left,FourWheelerEngine,TwoWheelerEngine,LightBeam,engine,Intensity,both,ex=0;

    while(ex<1)//infinite loop based on ex value
	{
		v.display();
		cin >> choice;
    if(toupper(choice)=='F')//four wheeler
    {
        cout <<" Four wheeler " << endl;
        FourWheelerEngine=1;
        cout<<"Enter 1 to On the engine"<<endl;
        cin>>engine;
        if(engine==1)//engine is on
        {
                    cout << "Press 1 for NIGHT else 0 for Day" << endl;
                    cin >> Night;
                    if(Night==0)
                    {
                        cout<<"Day time : Headlights are Off"<<endl;
                        break;
                    }
                    cout<<"Enter Light Intensity"<<endl;
                    cin>>Intensity;
                    if(Intensity>50)//intensity is high
                    {
                    cout<<"Enter 1: Both\t2:left\t3:right"<<endl;
                    cin>>both;
                    if(both==1)//vehicle on both side
                    {
                        Right=1;
                        Left=1;
                        v.vehicle(Night,FourWheelerEngine,Right,Left);
                    }
                    else if(both==2)//vehicle on left side
                    {
                        Left=1;
                        Right=0;
                        v.vehicle(Night,FourWheelerEngine,Left,Right);
                    }
                    else if(both==3)//vehicle on right side
                    {
                        Left=0;
                        Right=1;
                        v.vehicle(Night,FourWheelerEngine,Left,Right);
                    }
                    }

                    else{
                    cout << " Enter the steering angle " << endl;
                    cin >> SteeringAngle;
                    if(SteeringAngle>90)//for adaptive headlight based on direction
                    {
                        Right=0;
                        Left=1;
                        v.vehicle(Night,SteeringAngle,FourWheelerEngine,Right,Left);
                    }
                    else{
                        Left=0;
                        Right=1;
                        v.vehicle(Night,SteeringAngle,FourWheelerEngine,Right,Left);
                    }
                    }
        }
        else{
            cout<<"Engine is in Off state"<<endl;
        }
    }
    else if(toupper(choice)=='T')//two wheeler
    {
        cout <<" Two wheeler engine  "<< endl;
        TwoWheelerEngine=1;
        cout<<"Enter 1 to On the engine"<<endl;
        cin>>engine;
        if(engine==1)//engine is on
        {
            cout << "Press 1 for NIGHT else 0 for Day" << endl;
            cin >> Night;
            if(Night==0)
            {
                cout<<"Day time : Headlights are Off";
            }
            else{
                    cout<<"Enter Light Intensity"<<endl;
                    cin>>Intensity;
                    if(Intensity>50)//blink if intensity is high
                    {
                      LightBeam=1;
                      v.vehicle(Night,TwoWheelerEngine,LightBeam);
                    }
                    else{
                        LightBeam=0;
                      v.vehicle(Night,TwoWheelerEngine,LightBeam);
                    }
            }
        }

    }
    else if(toupper(choice)=='E')//block to exit out of loop
    {
        ex=ex+1;
    }
	}
    return 0;
}



