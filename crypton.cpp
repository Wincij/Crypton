#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<iomanip>
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>
#include<cmath>
#include<fstream>
#include <Windows.h>
#include<string>
using namespace std;
long pomc=3;
int licznik=0;
long big_prime=3;

void logo()

{
	system("CLS");
	fstream logo;
	logo.open("logo.txt", ios::in);
	string bufor;
	cout<<endl;
	while(getline(logo, bufor)) cout<< "\t" << bufor <<endl;
	logo.close();
	cout<< "\n\nCURRENT BIGGEST PRIME NUMBER: " << big_prime << "\n\n" ;

}

unsigned long prim(long x) //prime number generator
{
	if(x%2==0) return 0;	//checking parity 
	if(x==3) return 3;
	else
	{
		while(x%pomc != 0)
		{
			if(pomc >= sqrt(x))
			{
				licznik++;
				return x;
			}
			else pomc+=2;
		}
		
		return 0;
	}
		
}

long pomoc = 1000000000;
int cyfry(long klucz)
{
	long x = klucz;
	int cyfry=10;
	long pom=1000000000;
	while(floor(x/pom)==0)
	{
		pom=pom/10;
		cyfry--;
	}
	pomoc = pom;
	return cyfry;
}

void encrypto()
{

	logo();
	string to_encrypto, encrypted;
	cout<< "ENTER FILE NAME YOU WANT TO ENCRYPT: ";
	cin.clear();	cin.sync();
	getline(cin, to_encrypto);
	cin.clear();	cin.sync();
	fstream first; 
	first.open(to_encrypto.c_str(),ios::in );
	if( !first.good() ) 
	{
		cout<< "ERROR. INVALID FILE NAME \n";
		sleep(1000);
		encrypto();

	}
	size_t dot = to_encrypto.find( "____crypted.txt" );
	encrypted.insert(0, to_encrypto);
	encrypted.erase( dot, 15 );
	encrypted.insert(dot, "____encrypted.txt");
	cout<< "ENTER KEY: ";
	string key; cin>>key; 
	cin.clear();	cin.sync();
	
	
	
	fstream second;  
	second.open(encrypted.c_str(),ios::out );

	
		int x = key.length();
		int key_tab[x];
		for(int i = 0; i<x; i++) 	
		{	
			key_tab[i] = (int)key[i] - 48;
			cout<< key_tab[i];
		}
		cout<< endl;
		
		string pomc; //bufor 1 linijki tekstu
		char znak; // pomocniczo - szyfrowanie znak po znaku
		int j=0; //iterator dla tabeli szyfrujacej
		while(getline(first,pomc)) //"iterator" dla linijek
		{
			for(int i=0; i<pomc.length(); i++)
			{
				znak = (int)pomc[i] - key_tab[j];
				if(j== x) j=0;
				else j++; 
				second<< znak;
				
			}
					second<< endl;
		}
		
		first.close();
		second.close();
		cout << "ENCRYPTING COMPLETED\n\n\n" ;
		system("PAUSE");
	
	
}


void crypto()
{
	logo();
	string normalny, szyfrowany; //FILE NAMES (TO CRYPT, CRYPTED)
	cout<< "ENTER FILE NAME YOU WANT TO CRYPT: ";
	cin.clear();	cin.sync();
	getline(cin, normalny);
	cin.clear();	cin.sync();

	size_t dot = normalny.find( "." );
	szyfrowany.insert(0, normalny);
	szyfrowany.insert(dot, "____crypted");
	cout<< "ENTER KEY: ";
	string key; cin>>key; // ENTERING LONG KEY
	cin.clear();	cin.sync();
	fstream plik; // POINTER (FILE TO CRYPT)
	fstream cryptoplik; // POINTER (FILE AFTER CRYPTING)
	cryptoplik.open(szyfrowany.c_str(),ios::out ); 
	plik.open(normalny.c_str(),ios::in );
	if( !plik.good() ) 
	{
		cout<< "ERROR. INVALID FILE NAME \n";
		sleep(1000);
		crypto();
	}
	else
	{
		int x = key.length(); 
		int key_tab[x]; 	//CRYPTING TABLE (SIZE = LENGTH OF STRING "key")
		for(int i = 0; i<x; i++) 	key_tab[i] = (int)key[i] - 48; //INSERTING NUMBERS IN CRYPTING TABLES (CONST. 48 LOOK AT ASCII TABLE)
		string pomc; //ONE LINE BUFOR
		cout<<endl;
		char znak; //FRIENDLY CHAR
		int j=0; //ITERATOR FOR CRYPTING TABLE
		while(getline(plik,pomc)) //STOP WHEN END OF FILE
		{
			for(int i=0; i<pomc.length(); i++) //CREATING CRYPTED FILE 
			{
				znak = (int)pomc[i] + key_tab[j];  
				if(j== x) j=0;
				else j++; 
				cryptoplik<< znak;
				
			}
			cryptoplik<< endl; //ENDL AFTER EACH GETEDLINE(plik, pomc)
			
		}
		
		cryptoplik.close(); 
		plik.close();
		cout << "CRYPTING COMPLETED\n\n\n" ;
		system("PAUSE");
	}
	
}


void open() // SIMPLE PROCEDURE FOR OPENING FILE IN CONSOLE
{
	logo();
	
	string nazwa, bufor;
	cout<< "ENTER FILE NAME: ";
	cin.clear();	cin.sync();
	getline(cin, nazwa);
	fstream plik;
	plik.open(nazwa.c_str(),ios::in ); 
	cout<< "\n \n \n";
	while(getline(plik,bufor))
	{
		cout<< bufor << endl;
	}
	
	cout<< endl;
	plik.close();
	system("PAUSE");
}




unsigned long lista_liczb() //PRIME NUMBERS IN GIVEN RANGE PRINTER
{
	logo();
	licznik = 0;

	long granica1, granica2; //LIMES1, LIMES2
	cout<< "FROM: ";
	cin >> granica1;
	cout<< "TO: ";
	cin >> granica2;
	long przedzial=granica2-granica1+1;
	if(granica1%2 == 0) granica1++; 
	int i=0;
	while(granica1<=granica2) 
	
	{
		if(prim(granica1) == granica1) 
		{
			cout<<  granica1 <<endl; 
			big_prime=granica1;
		}
		granica1=granica1+2;

		
	}
	cout<< "\nIN ENTERED RANGE : "<< licznik <<"/" << przedzial << " ARE PRIME NUMBERS \n";
	system("PAUSE");
}
int main()
{

char jeszczeraz;
while(jeszczeraz!='0')
{
logo();
cout<< "1. PRIME NUMBERS GENERATOR\n";
cout<< "2. CRYPT FILE\n";
cout<< "3. ENCRYPT FILE\n";
cout<< "4. OPEN FILE \n";
jeszczeraz = getch();


        switch (jeszczeraz)  //sterowanie
        {
        case '1':
            
            lista_liczb();
			
			break;
			 
        case '2':
        	crypto();
            break;
       	case '3':
        	
			encrypto();
            
            break;
        
        case '4':
        	open();
        	break;
        
       	} 
       	

}    	
       	
return 0;

}

