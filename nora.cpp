#include <iostream>
using namespace std;

void printmessage ()
{
 int a;
 int ha;
 cout << "Input a = ";
 cin >> a; 
 cout << "Input height ha =";
 cin >> ha;
 while(a <=0 || ha <=0)
{

cout << "Wrong input\n"; 
   cout << "Input a = ";
   cin >> a;
   cout << "Input height = ";
   cin >> ha;
}
int answer = a * ha;
cout << answer;
}

int main ()
{
  printmessage ();
}
