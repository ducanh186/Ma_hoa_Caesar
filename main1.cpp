// A C++ program to illustrate Caesar Cipher Technique
#include <iostream>
#include <string.h>
using namespace std;

// This function receives text and shift and
// returns the encrypted text
string encrypt(string text, int key)
{
	string result = "";
	for (int i = 0; i < text.length(); i++) {
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			result += char(int(text[i] + key - 65) % 26 + 65);

		// Encrypt Lowercase letters
		else
			result += char(int(text[i] + key - 97) % 26 + 97);
	}

	// Return the resulting string
	return result;
}

string decrypt(string text, int key){
               string result = "";
	for (int i = 0; i < text.length(); i++) {
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			result += char(int(text[i] - key - 65 +26 ) % 26 + 65);//

		// Encrypt Lowercase letters
		else
			result += char(int(text[i] - key - 97 + 26 ) % 26 + 97);
	}

	// Return the resulting string
	return result;
}
// Driver program to test the above function
int main()
{            while(1)  {
               cout<<"\n1.Giai Ma";
               cout<< "\n2.Ma Hoa";
               cout<<"\n3.Exit";
               //Menu
	string text = "ATTACK";
               string text_1="RKKRTB";
	int key = 17;
	cout << "Text : " << text;
	cout << "\nShift: " << key;
	cout << "\nCipher: " << encrypt(text, key);
               cout << "\nPlain: " << decrypt(text_1, key);
	return 0;}
}