#include <iostream>
#include <cmath>

bool isprime_opt(int number)
{

	if(number <= 1)
		return false;

    // If 2 or 3, is prime
	if(number <= 3)
		return true;

	// If divisible by 2 or 3, is not prime
	if(number % 2 == 0 || number % 3 == 0)
		return false;

	// Check for factors from 5 to the square of the number
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0 )
            return false;
    }

    // If no factors were found, the number is prime
    return true;
}

/*
bool isprime(int number)
{
	// Check for factors from 2 to the square root of the number
    for (int i = 2; i <= std::sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }

    // If no factors were found, the number is prime
    return true;
}
*/

int main(int argc, char* argv[]) {

    unsigned long	ceiling;
	int				numprimes = 0;

	argc <= 1 ? ceiling = 10000000 : ceiling = (long) atol(argv[1]);

	for(int i = 2; i <= ceiling; i++){
		//isprime(i) ? std::cout << " prime :-)" << std::endl : std::cout << " not prime :-(" << std::endl;
        isprime_opt(i) ? numprimes++ : numprimes += 0;
	}

	std::cout << "Number of primes from 2 to " << ceiling << " is " << numprimes << std::endl;

    return 0;
}
