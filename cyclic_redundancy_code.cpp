#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
#define N strlen(generator) // length of the generator polynomial
char dataa[28];// data to be transmitted and received
char check_value[28];// CRC value
char generator[10];// generator polynomial
int data_length, i, j; // data->i , check_value->j

void XOR()  //  performs XOR operation
{
    for (j = 1; j < N; j++)
    {
        check_value[j] = ((check_value[j] == generator[j]) ? '0' : '1');
    }
}

void crc() 
{
    for (i = 0; i < N; i++) // initializing check_value to data
    {
        check_value[i] = dataa[i];
    }
    do 
    {
        if (check_value[0] == '1') // check if the first bit is 1 and calls XOR function
        {
            XOR();
        }
        for (j = 0; j < N - 1; j++)  // Move the bits by 1 position for the next computation
        {
            check_value[j] = check_value[j + 1];
        }
        check_value[j] = dataa[i++]; // appending a bit from data
    } while (i <= data_length + N - 1); // loop until the data ends
}

void receiver() // Function to check for errors on the receiver side
{
    cout << "Enter the received data: " << endl; 
    cin >> dataa;
    crc(); // crc
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++); // Check if the remainder is zero to find the error
    
    if (i < N - 1)
    {
        cout<<"Error detected"<<endl;
    }
    else
    {
        cout << "No error detected:"<<endl;
    }
}

int main()
{
    cout << "Enter data to be transmitted : " << endl;
    cin>>dataa;
    int k = 0,flagg=0;
    while(dataa[k]!='\0')
    {
        if (dataa[k] == '0' || dataa[k] == '1' || dataa[k] == '\n') {}
        else
        {
            flagg = 1;
            break;
        }
        k++;
    }
    if (flagg == 1)
    {
        cout << "Error wrong input for data " << endl;
        cout << "That is either '0' or '1'" << endl;
        return 0;
    }
    else
    {
        cout << "Enter the Generating polynomial " << endl;
        cin >> generator;
        k = 0;
        flagg=0;
        while (generator[k] != '\0')
        {
            if (generator[k] == '0' || generator[k] == '1' || dataa[k] == '\n') {}
            else
            {
                flagg = 1;
                break;
            }
            k++;
        }
        if (flagg == 1)
        {
            cout << "Error wrong input for generator " << endl;
            cout << "That is either '0' or '1'" << endl;
            return 0;
        }
        else
        {
            data_length = strlen(dataa);    // length of data
            for (i = data_length; i < data_length + N - 1; i++)// appending n-1 zeros to the data
            {
                dataa[i] = '0';
            }
            crc();          // Cyclic Redundancy Check
            cout << "CRC or Check value is: " << check_value << endl;    // remainder :
            for (i = data_length; i < data_length + N - 1; i++) // Append remainder  
            {
                dataa[i] = check_value[i - data_length];
            }
            cout << "Final data to be sent : " << dataa << endl;
            receiver();// Calling the receiver function to check errors
        }
    }
    _getch();
    return 0;
}

