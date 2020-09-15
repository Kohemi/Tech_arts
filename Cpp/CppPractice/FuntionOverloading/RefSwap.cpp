#include <iostream>
using namespace std;

//void swapbyref2(int &ref1, int &ref2)
//{
//	int temp = ref1;
//	ref1 = ref2;
//	ref2 = temp;
//}
//
//int main(void)
//{
//	int val1 = 10;
//	int val2 = 20;
//
//	swapbyref2(23, 45);
//	cout << "val1 : " << val1 << endl;
//	cout << "val2 : " << val2 << endl;
//	return 0;
//}

//Question 1
//void Adder1(int &num1)
//{
//	num1 = num1 + 1;
//	
//}
//
//void Swap(int &num1)
//{
//	num1 = -(num1);
//}
//
//int main(void)
//{
//	int val1 = 1;
//	int val2 = 1;
//
//	Adder1(val1);
//	Swap(val2);
//	cout << "val1 : " << val1 << endl;
//	cout << "Val2 : " << val2 << endl;
//	return 0;
//}

//Question2 변수로 불러와야 되는데, 값으로 불러오고 있기 때문에

//Question3 
void SwapPointer(int *(&num1), int *(&num2))
{
	int *temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void)
{
	int num1 = 5;
	int *ptr = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	cout << *ptr << endl;
	cout << *ptr2 << endl;

	SwapPointer(ptr, ptr2);

	cout << *ptr << endl;
	cout << *ptr2 << endl;
	return 0; 
	
	

}