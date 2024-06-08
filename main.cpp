#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
string encrypt(string text, int key)// truyền vâo chuỗi cần giải mã và key
{
	string result = "";// khai báo 1 chuỗi trống 
	for (int i = 0; i < (int)text.length(); i++) {//xét từng phần tử của chuỗi
		if (isupper(text[i]))//nếu viết hoa thì ...
		result += char(int(text[i] + key - 65) % 26 + 65);//A =
		//Chuyển số thứ tự từ ASCII sang 0-26 để thêm bớt keyint//(text[i] + key - 65) % 26//
		//Sau đó, lại chuyển về mã ASCII để gắn vào biến result(+65)

		else//nếu viết thường thì tương tự với viết hoa
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
	cout<<"\n---MA HOA CAESAR---\n"<<endl;
               cout<<"  1.Giai Ma"<<endl;
               cout<<"  2.Ma Hoa"<<endl;
               cout<<"  3.Exit"<<endl;
	int option = 0;
	do {
	printf("Nhap lua chon[1-3]: ");
	scanf("%d", &option); // Read the selected mode from the user
	while (getchar() != '\n'); // Clear the input buffer. Input buffer always end with Enter ('\n')
	printf("\nLua chon hien tai la:%d\n", option);
	// Display the confirmed mode to the user
	} while(!(option >= 1 && option <= 3));
	if(option==1){
	system("cls");
	 cout<<setw(23)<<"\n___MA HOA___\n";
	 string text;
	 cout<<"\nNhap text can ma hoa:";
	 cin.ignore();
	 getline(cin,text);
	 int key;
	 cout<<"Shift: ";
	 cin>>key;
	 cout<<"Cipher: "<<encrypt(text,key)<<endl;
	}else if(option==2){
	system("cls");
	cout<<"\n___GIAI MA___\n"<<endl;
	 string text;
	 cout<<"\nNhap text can giai ma:";
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