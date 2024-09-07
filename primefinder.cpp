/******************************************************************************
 * primefinder.cpp
 *
 *  Created on: 7 Sep 2024
 *      Author: jole
 *
 *      Program for printing primes
 *
 * 
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>
#include <bits/stdc++.h>

using namespace std;



void printUsage(char* _progName)
{
	if(_progName[0] == '.'){
		*_progName++;
		*_progName++;
	}

	cout << "Terminal utility to print primes to tty,  based on the sieve of Eratosthenes" << endl;
	cout << "It comes with absolutely NO WARRANTY at all!" << endl;
	cout << "Source found here: git@github.com:faksdal/primefinder.git, modify at will" << endl;
	cout << "Jon Leithe 2024" << endl << endl;

	cout << "Usage: " << _progName << " [switches]" << endl;
	cout << "\t\t-a (--start)\tnumber to start from (default = 2)" << endl;
	cout << "\t\t-o (--stop)\tnumber to stop at (default = 23)" << endl;
	cout << "\t\t-p (--print)\tprint primes to screen" << endl;
	cout << "\t\t-c (--col)\tnumber of columns to print (default = 5)" << endl;
	cout << "\t\t   (--algo)\t[atkin] specify if you want sieve of Atkin (default = sieve of Eratosthenes)" << endl;
	cout << "\t\t-h (--help)\tprint this help text" << endl;
}



//
// Custom grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
//
struct my_numpunct : std::numpunct<char> {
	// We want to group in numbers of three
	string do_grouping() const {return "\03";}
};


/*
 * just preverving a copy of the original from web

void sieveOfAtkin(int lmt) {

	cout << "Atkin" << endl;

   if (lmt > 2)
      cout << 2 << " ";
   if (lmt > 3)
      cout << 3 << " ";
   bool sieve[lmt];
   for (int i = 0; i < lmt; i++)
      sieve[i] = false;
   for (int a = 1; a * a < lmt; a++) {
      for (int b = 1; b * b < lmt; b++) {
         // Main part of Sieve of Atkin
         int n = (4 * a* a) + (b * b);
         if (n <= lmt && (n % 12 == 1 || n % 12 == 5))
            sieve[n] ^= true;
            n = (3 * a * a) + (b * b);
         if (n <= lmt && n % 12 == 7)
            sieve[n] ^= true;
            n = (3 * a * a) - (b * b);
         if (a > b && n <= lmt && n % 12 == 11)
            sieve[n] ^= true;
      }
   }
   for (int r = 5; r * r < lmt; r++) {
      if (sieve[r]) {
         for (int i = r * r; i < lmt; i += r * r)
            sieve[i] = false;
      }
   }
   for (int x = 5; x < lmt; x++)
      if (sieve[x])
         cout << x << " ";
}
*/



void sieveOfAtkin(unsigned long long _start, unsigned long long _stop, bool _print, short _columns)
{
	bool				newColumn = false;
	short				column = 1;
	unsigned long long	counter = 0;

	cout << "Atkin" << endl;


	if(_print && _start == 2){
		if (_stop > 2)
			cout << 2;
		if (_stop > 3)
			cout << "\t\t" <<  3;

		counter	+= 2;
		column	+= 2;
	}

	if(_print && _start == 3){
			if (_stop > 3)
				cout <<  3;

			counter	+= 1;
			column	+= 1;
		}


	// create as vectors to better handle memory issues
	//bool sieve[_stop];
	vector<bool> sieve(_stop+1, true);
	sieve[0] = sieve[1] = false;

	for (unsigned long long i = 0; i <= _stop; i++)
		sieve[i] = false;

	for (unsigned long long a = 1; a * a <= _stop; a++){
		for (unsigned long long b = 1; b * b <= _stop; b++){
			// Main part of Sieve of Atkin
			unsigned long long n = (4 * a* a) + (b * b);
			if (n <= _stop && (n % 12 == 1 || n % 12 == 5))
				sieve[n] = !sieve[n];	//sieve[n] ^= true;
			n = (3 * a * a) + (b * b);
			if (n <= _stop && n % 12 == 7)
				sieve[n] = !sieve[n];	//sieve[n] ^= true;
			n = (3 * a * a) - (b * b);
			if (a > b && n <= _stop && n % 12 == 11)
				sieve[n] = !sieve[n];	//sieve[n] ^= true;
		}
	}
	for (unsigned long long r = 5; r * r <= _stop; r++) {
		if (sieve[r]){
			for (unsigned long long i = r * r; i <= _stop; i += r * r)
				sieve[i] = false;
			}
	}
	if(_print){
		for (unsigned long long x = 2; x <= _stop; x++){
			if(sieve[x]){
				counter++;
				if(column > 1)
					cout << "\t\t";
				cout << x;
				column++;

				if(column > _columns){
					column = 1;
					cout << endl;
				}

			}
		}
	}

	std::locale loc (std::cout.getloc(),new my_numpunct);
	std::cout.imbue(loc);

	cout << endl << "Number of primes between " << _start << " and " << _stop << " is " << counter << endl;
}



void sieveOfEratosthenes(unsigned long long _start, unsigned long long _stop, bool _print, short _columns)
{
	bool				newColumn = false;
	short				column = 1;
    unsigned long long	counter = 0;

    cout << "Eratosthenes" << endl;

    vector<bool> is_prime(_stop+1, true);
    is_prime[0] = is_prime[1] = false;

    if(_stop > 10000000)
        cout << "Calculating primes...";

    for (unsigned long long i = _start; i <= _stop; i++) {
        if (is_prime[i] && (unsigned long long)i * i <= _stop) {
            for (unsigned long long j = i * i; j <= _stop; j += i){
                is_prime[j] = false;
            }
        }
        if(is_prime[i]){
            counter++;
            if(_print){
            	if(column > 1)
            		cout << "\t\t";
            	cout << i;
            	column++;

            	if(column > _columns){
            		column = 1;
            		cout << endl;
            	}
            }
        }

    }
    std::locale loc (std::cout.getloc(),new my_numpunct);
    std::cout.imbue(loc);
    if(_print)
    	cout << endl;

    cout << "Number of primes between " << _start << " and " << _stop << " is " << counter << endl;
}



int main(int argc, char *argv[])
{
	bool				print = false;
	bool				atkin = false;

	int					columns = 5;
	unsigned long long	start, stop;

	// assign default values
	start = 2;
	stop = 23;

	//
	//	getopt variables
	//
	int		c, optionIndex;
	char	*shortOptions = (char*)"a:c:ho:p";
	
	struct option	longOptions[] = {
					{"start",	required_argument,	NULL,	'a'},
					{"stop",	required_argument,	NULL,	'o'},
					{"printz",	required_argument,	NULL,	'p'},
					{"col",		required_argument,	NULL,	'c'},
					{"algo",	required_argument,	NULL,	1},
					{"help",	no_argument,		NULL,	'h'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables
	
	//
	//	getopt() switch statement
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'a':	{
							start = atol(optarg);
							break;
						}
			case 'c':	{
							columns = atoi(optarg);
							break;
						}
			case 'h':	{
							printUsage(argv[0]);
							exit(1);
						}
			case 'o':	{
							stop = atol(optarg);
							break;
						}
			case 'p':	{
							print = true;
							break;
						}
			case 1:		{
							if(!string(optarg).compare("atkin"))
								atkin = true;

							break;
						}
			default:	{
							cout << "Switch default\n" << endl;
							break;
						}
		}	//end of getopt() switch statement
	}	// end of while-loop

	locale loc (cout.getloc(),new my_numpunct);
	cout.imbue(loc);

	atkin ? sieveOfAtkin(start, stop, print, columns) : sieveOfEratosthenes(start, stop, print, columns);

	if(argc == 1){
		cout << endl;
		printUsage(argv[0]);
	}

	return 0;
}	//	int main(int argc, char *argv[])








