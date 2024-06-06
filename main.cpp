#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int GetMode(char* input_prompt, char* confirm_message) {
    int option = 0;
    do {
        printf("\n%s: ", input_prompt);
        scanf("%d", &option); // Read the selected mode from the user
        while (getchar() != '\n'); // Clear the input buffer. Input buffer always end with Enter ('\n')
        printf("\n%s: %d\n",confirm_message, option);
     // Display the confirmed mode to the user
    } while(!(option >= 1 && option <= 3)); // Repeat until a valid mode is selected
    return  option;
}
string encrypt(string text, int key)
{
	string result = "";
	for (int i = 0; i < (int)text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] + key - 65) % 26 + 65);
		else
			result += char(int(text[i] + key - 97) % 26 + 97);
	}
	return result;
}

string decrypt(string text, int key){
               string result = "";
	for (int i = 0; i <(int) text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] - key - 65 +26 ) % 26 + 65);//

		else
			result += char(int(text[i] - key - 97 + 26 ) % 26 + 97);
	}
	return result;
}
int main()
{            while(1)  {
	cout<<setw(11)<<"Cesar"<<endl;
	cout<<setw(30)<<"P = C = K = Zn"<<endl;
	cout<<setw(35)<<"ek(x) = (x+k) mod n"<<endl;
	cout<<setw(35)<<"dk(y) = (y-k) mod n"<<endl;
	cout<<setw(19)<<"Ex:"<<endl;
	cout<<setw(37)<<"plaintext: ATTACK"<<endl;
	cout<<setw(27)<<"key: 17"<<endl;
	cout<<setw(38)<<"ciphertext: RKKRTB"<<endl;
	cout<<endl;
	cout<<"---MA HOA CAESAR---"<<endl;
               cout<<"  1.Giai Ma"<<endl;
               cout<<"  2.Ma Hoa"<<endl;
               cout<<"  3.Exit"<<endl;
               //Menu
	int option=GetMode("Select mode [1-3]", "Mode selected") ; 
	if(option==1){
	 cout<<setw(23)<<"___GIAI MA___";
	 cout<<setfill('-')<<setw(61)<<endl;
	 string text;
	 cout<<"\nNhap text can giai ma:";
	 cin.ignore();
	 getline(cin,text);
	 int key;
	 cout<<"Shift: ";
	 cin>>key;
	 cout<<"Cipher: "<<encrypt(text,key)<<endl;
	}else if(option==2){
	cout<<"___MA HOA___"<<endl;
	 string text;
	 cout<<"Nhap text can giai ma:";
	 cin.ignore();
	 getline(cin,text);
	 int key;
	 cout<<"Shift: ";
	 cin>>key;
	 cout<<"Plain: "<<decrypt(text,key)<<endl;
	}else if(option==3){
		printf("\nExit program!");
		getchar();
        		exit(0);
	}
	}
}