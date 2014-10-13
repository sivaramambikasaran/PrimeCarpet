#include <iostream>
#include <fstream>
#include <cmath>

bool isPrime(int n) {
	int k		=	sqrt(n);
	bool result	=	true;
	if (n==1) {
		return false;
	}
	int j=2;
	while (j<=k && result == true) {
		// std::cout << j << std::endl;
		if (n%j==0) {
			result	=	false;
		}
		++j;
	}
	return result;
}

void generateFile(int N1, int N2) {
	std::cout << "Enter the degree of the first polynomial: ";
	int n1;
	std::cin >> n1;
	int* p1	=	new int[n1+1];
	std::cout << "Enter the coefficients (all positive) of the polynomial starting from the leading degree: " << std::endl;

	for (int k=n1; k>=0; --k) {
		std::cin >> p1[k];
	}

	std::cout << "Enter the degree of the second polynomial: ";
	int n2;
	std::cin >> n2;
	int* p2	=	new int[n2+1];
	std::cout << "Enter the coefficients (all positive) of the polynomial starting from the leading degree: " << std::endl;
	for (int k=n2; k>=0; --k) {
		std::cin >> p2[k];
	}

	int* x	=	new int[N1];
	int* y	=	new int[N2];

	int* f1	=	new int[N1];
	int* f2	=	new int[N2];

	//	X label
	std::string xlabel	=	"f(n) = ";
	for (int k=n1; k>1; --k) {
		if (p1[k]!=0) {
			if (p1[k]!=1) {
				xlabel+=std::to_string(p1[k]);
			}
			xlabel+="n^";
			xlabel+=std::to_string(k);
			xlabel+=" + ";	
		}
	}
	if (p1[1]!=0) {
		if (p1[1]!=1) {
			xlabel+=std::to_string(p1[1]);
		}
		xlabel+="n";
		xlabel+=" + ";		
	}
	if (p1[0]!=0) {
		xlabel+=std::to_string(p1[0]);		
	}
	std::cout << xlabel << std::endl;

	//	Y label
	std::string ylabel	=	"g(n) = ";
	for (int k=n2; k>1; --k) {
		if (p2[k]!=0) {
			if (p2[k]!=1) {
				ylabel+=std::to_string(p2[k]);
			}
			ylabel+="n^";
			ylabel+=std::to_string(k);
			ylabel+=" + ";			
		}
	}
	if (p2[1]!=0) {
		if (p2[1]!=1) {
			ylabel+=std::to_string(p2[1]);
		}
		ylabel+="n";
		ylabel+=" + ";		
	}
	if (p2[0]!=0) {
		ylabel+=std::to_string(p2[0]);		
	}
	std::cout << ylabel << std::endl;

	for(int k=0; k<N1; ++k) {
		f1[k]		=	p1[n1];
		for (int j=n1-1; j>=0; --j) {
			f1[k]	=	f1[k]*k+p1[j];
		}
		x[k]		=	isPrime(f1[k]);
	}
	for (int k=0; k<N2; ++k) {
		f2[k]		=	p2[n2];
		for (int j=n2-1; j>=0; --j) {
			f2[k]	=	f2[k]*k+p2[j];
		}
		y[k]		=	isPrime(f2[k]);
	}
	std::ofstream myfile;
	myfile.open("primeCarpet.tex",std::ios::out);
	myfile << "\\documentclass{standalone}" << std::endl;
	myfile << "\\usepackage{tikz}" << std::endl;
	myfile << "\\begin{document}" << std::endl;
	myfile << "\\begin{tikzpicture}" << std::endl;
	std::string bgColor[2][2]	=	{{"white","blue!50"},{"green","red"}};
	std::string color[3]		=	{"blue!50","green","red"};
	for (int k=0; k<N1; ++k) {
		myfile << "\\node at (" << k+0.5 << ", -1)" << "{\\huge \\rotatebox{90}{$" << f1[k] << "$}};";
	}
	for (int k=0; k<N2; ++k) {
		myfile << "\\node at (-1, " << k+0.5 << ")" << "{\\huge $" << f2[k] << "$};";
	}

	for (int i=0; i<N1; ++i) {
		if (x[i]==1) {
			myfile << "\\draw[draw=white, fill = " << color[0] << "] (" << i << ", 0) rectangle (" << i+1 << "," << N2 << ");" << std::endl;
		}
	}
	for (int i=0; i<N2; ++i) {
		if (y[i]==1) {
			myfile << "\\draw[draw=white, fill = " << color[1] << "] (0, " << i << ") rectangle (" << N1 << "," << i+1 << ");" << std::endl;
		}
	}

	for (int i=0; i<N1; ++i) {
		for (int j=0; j<N2; ++j) {
			if (x[i]==1 && y[j]==1) {
				myfile << "\\draw [draw = white, fill=" << color[2] << "] (" << i << "," << j << ") rectangle (" << i+1 << "," << j+1 <<");" << std::endl;
			}
		}		
	}

	myfile << "\\draw (0,0) grid (" << N1 << "," << N2 << ");" << std::endl;
	myfile << "\\node at (" << N1/2 << ",-3) {\\Huge $" << xlabel << "$};" << std::endl;
	myfile << "\\node at (-3," << N2/2 << ") {\\Huge \\rotatebox{90}{$" << ylabel << "$}};" << std::endl;
	myfile << "\\node at (" << N1/2-6 << ",-5.5) {\\Huge $(x,y)$ = };" << std::endl;
	myfile << "\\node at (" << N1/2+2 << ",-5.5) {\\Huge if both $x$ and $y$ are primes};" << std::endl;
	myfile << "\\node at (" << N1/2-6 << ",-7) {\\Huge $(x,y)$ = };" << std::endl;
	myfile << "\\node at (" << N1/2+2 << ",-7) {\\Huge if $x$ is prime and $y$ is not};" << std::endl;
	myfile << "\\node at (" << N1/2-6 << ",-8.5) {\\Huge $(x,y)$ = };" << std::endl;
	myfile << "\\node at (" << N1/2+2 << ",-8.5) {\\Huge if $y$ is prime and $x$ is not};" << std::endl;

	myfile << "\\draw[fill=" << bgColor[1][1] << "] (" << N1/2-4 << ",-6) rectangle (" << N1/2-3 << ",-5);" << std::endl;
	myfile << "\\draw[fill=" << bgColor[1][0] << "] (" << N1/2-4 << ",-7.5) rectangle (" << N1/2-3 << ",-6.5);" << std::endl;
	myfile << "\\draw[fill=" << bgColor[0][1] << "] (" << N1/2-4 << ",-9) rectangle (" << N1/2-3 << ",-8);" << std::endl;

	myfile << "\\end{tikzpicture}" << std::endl;
	myfile << "\\end{document}" << std::endl;
	myfile.close();
}

int main(int argc, char* argv[]) {
	int N1		=	atoi(argv[1]);
	int N2		=	atoi(argv[2]);
	generateFile(N1, N2);
}