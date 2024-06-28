#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int ip_add[4], network[4], net_add[4], host[4], subnet_mask[4] = { 0,0,0,0 }, range[4] = { 0,0,0,0 };

void host_net_id(int k)  //k will give position of dot
{
	for (int i = 0; i < k; i++) //k will tell no of 255 inserted
	{
		subnet_mask[i] = 255;
	}

	for (int i = 0; i < 4; i++)
	{
		net_add[i] = ip_add[i] & subnet_mask[i];  //formula for network address
		if (net_add[i] == 0)
		{
			network[i] = 0; //bcoz result zero;
			host[i] = ip_add[i]; //host remaining ip
			range[i] = 255; //rem
		}
		else
		{
			network[i] = ip_add[i];
			host[i] = 0;
			range[i] = ip_add[i]; //rem
		}
	}
}

void display1(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] != 0)  //half print possible -condn
		{
			cout << arr[i] << ".";
		}
	}
}

void display2(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i];
		if (i != 3)        //bcoz end of ip
			cout << ".";
	}
}

int main()
{
	string ip, oct, _class; 
	int ind = 0;
	cout << "Enter IP ";
	cin >> ip;
	cout << "IP address: " << ip << endl;       //printing IP
	for (int i = 0; i < ip.length()+1; i++)     // +1 for length otherwise host-not printed
	{
		if (ip[i] == '.' || ip[i] == '\0')       //checking dot and end of string
		{
			ip_add[ind] = stoi(oct); //accumulated number before '.' will be converted to integers
			ind++;
			oct = "";  //assign oct to empty to get ready for next set of elements
			continue;
		}
		oct += ip[i];        //each octect numbers will be appended
	}
	//Classes of IP 
	//flag to keep track if it belongs to D and E
	int flag = 0;
	if (ip_add[0] >= 0 && ip_add[0] < 128)
	{
		_class = "A";
		host_net_id(1);
	}
	else if (ip_add[0] >= 128 && ip_add[0] < 192)
	{
		_class = "B";
		host_net_id(2);
	}
	else if (ip_add[0] >= 192 && ip_add[0] < 224) 
	{
		_class = "C";
		host_net_id(3);
	}
	else
	{
		flag = 1;
		if (ip_add[0] >= 224 && ip_add[0] < 240) 
		{
			_class = "D";
		}
		else
		{
			_class = "E";
		}
	}
	if (flag == 0)
	{
		cout << "Class of ip address is: " << _class << endl;
		cout << "Network ID: ";
		display1(network);   //display 1 bcoz half print
		cout << endl;
		cout << "Host ID: ";
		display1(host); 
		cout << endl;
		cout << "Network address: ";
		display2(net_add); cout << endl;//display 2 bcoz full print
		cout << "Default subnet mask ";
		display2(subnet_mask); 
		cout << endl;
		cout << "Range ";
		display2(net_add);
		cout << " - ";
		display2(range);
		cout << endl;
	}
	else
	{
		cout << "No Properly defined NetworkID,HostID,Default subnet mask etc" << endl;
	}
	_getch();
	return 0;
}


