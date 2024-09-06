// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

/*
 *
 * Ok boys, run and weep (aka raw) :-D
 *
 *
*/


//
// Custom grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
//
struct my_numpunct : std::numpunct<char> {
	// We want to group in numbers of three
	std::string do_grouping() const {return "\03";}
};



void SieveOfEratosthenes(unsigned long long n, bool _print)
{
    unsigned long long   counter = 0;


    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    if(n > 10000000)
        cout << "Calculating primes...";

    for (unsigned long long i = 2; i <= n; i++) {
        //cout << i << " ";
        if (is_prime[i] && (unsigned long long)i * i <= n) {
            for (unsigned long long j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
        if(is_prime[i]){
            counter++;
            if(_print)
                cout << " " << i;
        }

    }
    std::locale loc (std::cout.getloc(),new my_numpunct);
    std::cout.imbue(loc);
    cout << endl << endl << "Number of primes between 2 and " << n << " is " << counter << endl;
}



void SieveOfEratosthenesOptimized(unsigned long long n, bool _print)
{
    unsigned long long   counter = 0;


    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    if(n > 10000000)
        cout << "Calculating primes...";

    for (unsigned long long i = 2; i <= n; i++) {
        //cout << i << " ";
        if (is_prime[i] && (unsigned long long)i * i <= n) {
            for (unsigned long long j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
        if(is_prime[i]){
            counter++;
            if(_print)
                cout << " " << i;
        }

    }
    std::locale loc (std::cout.getloc(),new my_numpunct);
    std::cout.imbue(loc);
    cout << endl << endl << "Number of primes between 2 and " << n << " is " << counter << endl;
}



// Driver Program to test above function
int main(int argc, char* argv[])
{
    unsigned long long  num;
    bool            print = false;

    argc <= 1 ? num = 50 : num = (unsigned long long)atol(argv[1]);
    if(argc > 2)
        print = true;

    std::locale loc (std::cout.getloc(),new my_numpunct);
    std::cout.imbue(loc);

    if(print)
        cout << "Following are the prime numbers smaller than or equal to " << num << endl;
    else
        cout << "Calculating number of primes between 2 and " << num << endl;

    SieveOfEratosthenes(num, print);

    cout << endl;

    return 0;
}
