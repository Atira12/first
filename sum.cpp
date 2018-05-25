#include <iostream>
using namespace std;
void sum()
{
int var = 0;
int answer = 0;
int n;
int mass[100];
int i = 0;
cout << "Size of mass";
cin >> n;
while (i < n)
{
  do{ 
  cout << "Enter array of " << i << "=";
  cin >> mass[i];
  }while(mass[i]%2 == 0 || mass[i] < 0);
i++;
}
while( var < n)
{
answer = answer + mass[var];
var ++;
}
cout << answer;
}
int main()
{
sum();
return 0;
}
