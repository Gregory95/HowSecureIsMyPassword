//============================================================================
// Name        : HowSecureIsMyPassword.cpp
// Author      : Grigoris Kokozides
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {

	string password;
	int counter = 0, base = 26; //base is depends what type of password user will give
	int i;
	long long int calculations;
	float seconds;
	char lowAlphaBetArr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//not case-sensitive 26bits length
	char UppAlphaBetArr[26] = {'A', 'B','C', 'D','E','F','G','H','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//case-sensitive 52bits length
	char specCharArray[12] = {'!','£','$','%','&','@','~','#','>','<','-','_'};//special characters +12bits length
	char numberArray[10] = {'0','1','2','3','4','5','6','7','8','9'};//numerical characters +10bits length

    cout <<endl;
	cout <<"\t\t\tHOW SECURE IS YOUR PASSWORD??" <<endl;
	cout <<"\t\t\t=============================" << endl <<endl<<endl;

    cout <<"Enter your password: ";
    getline(cin, password);

    for(i = 0; password[i] != '\0'; i++)
    {
    	for(int j = 0; j < 26; j++) //checks whole alphabet upper and lower cased.
    	{
         if(password[i] == lowAlphaBetArr[j])
    	     counter++;
         else if(password[i] == UppAlphaBetArr[j])
         {
        	 counter++;
        	 base += 26;//base = 52
         }
    	}
        for(int k = 0; k < 12; k++) // checks specCharArray
         {
           if(password[i] == specCharArray[k])
             {
        	 counter++;
        	 base += 12;//base = 64
             }
         }
        for(int t = 0; t < 10; t++)// checks numberArray
        {
          if(password[i] == numberArray[t])
         {
        	 counter++;
        	 base += 10;//base = 74
         }
        }

    }
      cout<<endl <<endl;
      calculations = pow(base, i); // 'i' is the size of the password
      cout<<"Program will require those calculations: "<<base << " ^ " << i << " = " << calculations;
      cout <<endl;
      seconds = calculations / 40000000;
      cout<<"Your password could be cracked in: " <<seconds <<" seconds" ;


	return 0;
}
