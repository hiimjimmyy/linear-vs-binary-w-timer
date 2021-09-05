//Written by: Jimmy Tran
//IDE: VS Code
/*The purpose of this exercise is to demonstrate with evidence, timer, which searching method is faster, binary or linear*/

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


//function prototype
int linearSearch(vector<int>, int);
int binarySearch(vector<int>, int);
vector<int> selectionSort(vector<int>);

int main()
{
    //declaring timer
    clock_t begin, end;
	double elapsed_seconds;


    int input; //value to be searched through
    int n; //value stored within the array (1000)


    srand(time(NULL));
    cout<<"\nInput the value if integers within the array: "<<endl;
    cin>>n;
    vector<int> array(n);
    for(int i=0; i<n; i++)
    {
		array[i] = rand() % 1000; //stores 1000 random integers within an array
    }
    cout<<endl;

    input = rand() % 1000; //this will randomly select a value to be searched from 0-1000

    cout<<"\tIf the return position is -1, this means the random array created did not contain the value of the random input created."<<endl;

    int index; //because I declared the void to be an int to keep consistency
    cout<<"\n\tlinear Search: "<<endl;
    begin = clock();
    index = linearSearch(array, input);
    cout<<"Element found at position: " << index << endl;
    end = clock();
	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;

    array = selectionSort(array); //sort the list of integers before timer
    cout<<"\n\tBinary Search: "<<endl;
    begin = clock();
    index = binarySearch(array, input);
    cout<<"Element found at position: " << index << endl;
    end = clock();
	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;

    cout<<endl;
    return 0;
}

int linearSearch(vector<int>a, int target) //declare values
{
    int temp = -1; //flag

    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==target)
        {
            temp = i;
            break;
        }
    }

    return temp;
}

int binarySearch(vector<int>a, int targetValue)
{
    int left = 0;
    int right = a.size(); //this will provide the size of the vector

    while(left <= right)
    {
        int middle = (left + right)/2;
        if(a[middle] == targetValue)
        {
            return middle;
        }
        else if(targetValue < a[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1; 
        }
    }
    return -1; 
}

vector<int> selectionSort(vector<int>a)
{
    for(int i=0; i<a.size()-1; i++)
    {
        int min = i;

        for(int j=i+1; j<a.size();j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int temp = a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }

    return a;
}
