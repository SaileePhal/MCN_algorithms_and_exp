#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
int check_parity(int n, int i, int code[])
{
	int p = 0, k;
	for (int j = i; j <= n; j = k + i)
	{
		for (k = j; k < j + i && k <= n; k++)        //for i=1 ->bits=1,3,5,7,9,11    for i=2 ->bits 2,3,6,7,10,11
		{                    //i is parity bit position
			if (code[k] == 1)
				p++;
		}
	}
	if (p % 2 == 0)
		return 0;        //if no. of 1 is even return 0
	else
		return 1;        //if no. of 1 is odd return 1
}

void hamming_code(int data[], int num)
{
	int r = 0, m = 0, n, j = 1, c, code[50];
	while ((r + num + 1) > (pow(2, r)))         //calculating no. of redundant bits
		r++;
	n = num + r;                    //adding no. of redundant bits to array size
	for (int i = 1; i <= n; i++)
	{
		if (i == pow(2, m) && m <= r)
		{
			code[i] = 0;            //initializing all the bit position of power 2 to zero
			m++;
		}
		else
		{
			code[i] = data[j];       //assigning data to remaining positions
			j++;
		}
	}
	m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == pow(2, m) && m <= r)
		{
			c = check_parity(n, i, code);        //assigning parity bit to position of power 2
			code[i] = c;
			m++;
		}
	}
	cout << "Redundant bits to be added: " << r << endl;
	cout << "The hamming code for given data is:";
	for (int i = n; i > 0; i--)
		cout << code[i] << " ";
	cout << "\n\nEnter the received code:";
	for (int i = n; i > 0; i--)
		cin >> code[i];
	int err[5], q, p = 0;
	m = j = c = q = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == pow(2, m) && m <= r)
		{
			c = check_parity(n, i, code);
			q = q + (pow(2, j) * check_parity(n, i, code));// decimal value of error code
			err[p] = c;
			j++, m++, p++;
		}
	}
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (err[p] == 0)
			flag = 0;
		else
			flag = 1;
	}
	if (flag == 0 || q==0)
		cout << "Received word is correct.";
	else
	{
		cout << "There is an error: ";
		for (int i = 3; i >= 0; i--)
			cout << err[i] << " ";
		cout << "\nThere is error in bit position: " << q << endl;
	}
}
int main()
{
	int data[50], num;
	cout << "Enter the size of data: ";
	cin >> num;
	cout << "Enter the data: ";
	for (int i = num; i > 0; i--)
		cin >> data[i];
	hamming_code(data, num);
	return 0;
}
