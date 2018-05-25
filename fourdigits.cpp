#include <iostream>
using namespace std;

void multiply()
{
int mass[3];
int i;
while(i <= 3)
{
do {
cout << "Enter number for mass of " << i;
cin  >> mass[i];
}while(mass[i] == 0);
i++;
}
int answer = mass[0] * mass[1] * mass[2] * mass[3];
cout << answer;
}
int main()
{
multiply();
return 0;
}

