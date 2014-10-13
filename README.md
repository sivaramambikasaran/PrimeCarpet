Prime Carpet
============

<img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC8.png" />

We define a prime carpet as follows: Consider functions <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC1.png" width = "100" /> and <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC2.png" width = "100" />.

The prime carpet is obtained by plotting <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC3.png" width = "30" /> versus <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC4.png" width = "30" /> (as <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC9.png" width = "10" /> takes on each natural number in order) and coloring each lattice point <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC5.png" width = "30" /> based on the following criterion:

Use color 1: If <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC6.png" width = "10" /> and <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC7.png" width = "9" /> are both primes.

Use color 2: If <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC6.png" width = "10" /> is a prime and <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC7.png" width = "9" /> is not.

Use color 3: If <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC7.png" width = "9" /> is a prime and <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC6.png" width = "10" /> is not.

---

The code generates a prime carpet where <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC4.png" width = "30" /> and <img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC3.png" width = "30" /> are polynomials with non-negative integers as it coefficients. To run the code, key in

	./primeCarpet.sh

This will prompt you with the following statement:

	Enter the number of grid points along X axis

Let's key in '40' and return

	40

Next it will prompt you with the following statement:

	Enter the number of grid points along Y axis

Let's key in '100' and return

	100

Then it will prompt you with the following:

	Enter the degree of the first polynomial: 

Say we want a linear polynomial along 'X' axis

	1

Next:

	Enter the coefficients (all positive) of the polynomial starting from the leading degree:

Let's key in '6' and '5' to denote the polynomial 6n+5

	6
	5

Next:

	Enter the degree of the second polynomial:

Let's key in a quadratic polynomial

	2

Next:

	Enter the coefficients (all positive) of the polynomial starting from the leading degree:

Let's key in '1', '0' and '1' to denote the polynomial n*n+1

	1
	0
	1

This will generate a pdf file named primeCarpet.pdf containing the following prime carpet.

<img style="float: middle" src="https://raw.githubusercontent.com/sivaramambikasaran/PrimeCarpet/master/images/PC10.png" />