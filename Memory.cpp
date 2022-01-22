
/*___________________________________________________
____________________________________________________/

Домашняя работа - Julian AkA LaughnOutLaw.

____________________________________________________
__________________________________________________*/


#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;



/*_____________________________________________________________________________________________

	TASK 1: Functions.
_____________________________________________________________________________________________*/



void arrayPowInit(int arr[], int SIZE)
{
	int mult = 1;
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = mult;
		mult *= 2;
	}
}


void printArray(int arr[], int SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



/*_____________________________________________________________________________________________

	TASK 2: Functions.
_____________________________________________________________________________________________*/




void megarrInit(int **arr, int SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void megarrPrint(int **arr, int SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}



/*_____________________________________________________________________________________________

	TASK 3: Function.
_____________________________________________________________________________________________*/



void arrayInit(int arr[], int SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 999;
	}
}



/*_____________________________________________________________________________________________

	TASK 4: Function.
_____________________________________________________________________________________________*/




void fileCopy(int arr[], int SIZE)
{
	string name1, name2, name3;

	cout << "Enter the name of the first file ( don't input .txt ): ";
	cin >> name1;
	cout << "Enter the name of the second file ( don't input .txt ): ";
	cin >> name2;
	cout << "Enter the name of the third file ( don't input .txt ): ";
	cin >> name3;

	ifstream read;
	read.open(name1 + ".txt");
	ifstream read2;
	read2.open(name2 + ".txt");
	ofstream write;
	write.open(name3 + ".txt");

	for (size_t i = 0; i < SIZE; i++)
	{
		read >> arr[i];
		write << arr[i] << endl;
	}
	for (size_t j = 0; j < SIZE; j++)
	{
		read2 >> arr[j];
		write << arr[j] << endl;
	}
	read.close();
	read2.close();
	write.close();

}



int main()
{

	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

/*_____________________________________________________________________________________________

	TASK 1:
_____________________________________________________________________________________________*/


	size_t n;
	cout << "Enter the power number: ";
	cin >> n;
	cout << endl;

	int* arr = new (nothrow) int[n];

	if (arr != nullptr)
	{
		arrayPowInit(arr, n);
		printArray(arr, n);
		delete[] arr;
	}
	else
	{
		cerr << "Bad alloc error!" << endl;
	}

	cout << endl;


/*_____________________________________________________________________________________________

	TASK 2: 
_____________________________________________________________________________________________*/


	int M_SIZE = 4;

	int **megArr = new (nothrow) int* [M_SIZE];

	if (megArr != nullptr)
	{
		for (size_t i = 0; i < M_SIZE; i++)
		{
			megArr[i] = new int[M_SIZE];
		}

		megarrInit(megArr, M_SIZE);
		megarrPrint(megArr, M_SIZE);


		for (size_t i = 0; i < M_SIZE; i++)
		{
			delete[] megArr[i];
		}
		delete[] megArr;
	}
	else
	{
		cerr << "Bad alloc error!" << endl;
	}
	
	cout << endl;


/*_____________________________________________________________________________________________

	TASK 3:
_____________________________________________________________________________________________*/


	string name1, name2;
	cout << "Enter the name of the first file ( don't input .txt ):";
	cin >> name1;
	cout << "Enter the name of the second file ( don't input .txt ): ";
	cin >> name2;


	const size_t S_SIZE = 50;

	int farray[S_SIZE];

	arrayInit(farray, S_SIZE);


	ofstream file1(name1 + ".txt");
	if (file1.is_open())
	{
		for (size_t i = 0; i < S_SIZE; i++)
		{
			file1 << farray[i] << endl;
		}

		file1.close();
	}

	arrayInit(farray, S_SIZE);

	ofstream file2(name2 + ".txt");
	if (file2.is_open())
	{
		for (size_t i = 0; i < S_SIZE; i++)
		{
			file2 << farray[i] << endl;
		}

		file2.close();
	}

	cout << endl;

/*_____________________________________________________________________________________________

	TASK 4:
_____________________________________________________________________________________________*/


	fileCopy(farray, S_SIZE);

	cout << endl;


/*_____________________________________________________________________________________________

	TASK 5:
_____________________________________________________________________________________________*/



	string name;
	ofstream lostname("lostname.txt");
	cout << "Input this names one by one: Juian Katya Damian Talia Sam " << endl;
	if (lostname.is_open())
	{
		for (size_t i = 0; i < 5; i++)
		{
			cout << "Input the name:";
			cin >> name;
			lostname << name << endl;
		}
		lostname.close();
	}
	else
	{
		cerr << "Oops, we got a problem!" << endl;
	}
	
	cout << endl;
	
	ifstream findname("lostname.txt");
	if (findname.is_open())
	{
		string input;
		const string fnd = "Damian";
		while (!findname.eof())
		{
			getline(findname, input);
			cout << input << endl;
		}
		if (fnd.find("Damian") != string::npos)
		{
			cout << "We found Damian!" << endl;
		}
		else
		{
			cout << "We cannot find Damian" << endl;
		}
		findname.close();
	}
	else
	{
		cerr << "Oops, we got a problem!" << endl;
	}

	cout << endl;


	return 0;


};
