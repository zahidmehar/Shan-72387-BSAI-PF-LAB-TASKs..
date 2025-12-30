/*
//Just a Practice Code for Function Addressing
#include<iostream>
using namespace std;
int makeDouble( int x);
int main()
{
	int number = 20;
	int result = makeDouble(number);
	cout << "Doubled Number :" << result << endl;
	return 0;
	
}
int makeDouble(int x)
{
	return x * 2 ;
	
}
*/
/*
// just a Practice Code for Function Addressing
#include <iostream>
using namespace std;
double calAreaRectangle (double length, double width);
int main ()
{
	double Length = 0;
	double Width = 0;
	double Area = 0;
	cout <<"Enter Length of Rectangle (cm):";
	cin >> Length;
	cout <<"Enter Width of Rectangle (cm):";
	cin >> Width;
	Area = calAreaRectangle (Length,Width);
	cout << "Area of Rectangle = " << Area  << endl;
	return 0;
}
double calAreaRectangle (double l, double w)
{
	return l * w ;
	
}
	*/





// Lab Task 9: Assignment Calculator using Functions
#include <iostream>
using namespace std;
float add(float a, float b) {
    return a + b;
}
float sub(float a, float b) {
    return a - b;
}
float mul(float a, float b) {
    return a * b;
}
float divd(float a, float b) {
    return a / b;
}
float power(float a, float b) {
    float res = 1;
    for(int i = 0; i < b; i++) {
        res = res * a;
    }
    return res;
}

int main() 
{
	do{
	cout << "(Name: Shan)     (PF LAB)      (Roll No: 72387)      (BSAI)"<<endl;
    float n1, n2;
    char op;
    cout << "Enter two numbers: "<<endl;
    cin >> n1 >> n2;
    cout << "Choose (+, -, *, /, p): ";
    cin >> op;
    switch(op) {
        case '+':
            cout << "Result: " << add(n1, n2)<<endl;
            break;
        case '-':
            cout << "Result: " << sub(n1, n2)<<endl;
            break;
        case '*':
            cout << "Result: " << mul(n1, n2)<<endl;
            break;
        case '/':
            if(n2 == 0)
                cout << "Cannot divide by zero";
            else
                cout << "Result: " << divd(n1, n2)<<endl;
            break;
        case 'p':
            cout << "Result: " << power(n1, n2)<<endl;
            break;
        default:
            cout << "Invalid choice";
    }
} while (true);
    return 0;
}