#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <chrono>
#include <thread>
#include <fstream>  
#include <unordered_map>
#include<wchar.h>
#include "Chinese.h"
#include <stdio.h>
#include <string.h>
#include <codecvt>
#include<locale>
#include <io.h>
#include <fcntl.h>
#include <string>  
using namespace std;
unordered_map<string, string> data = { { "b", "b" }, { "a", "a" }, { "c", "c" }};



// for converting chinese characters
auto UnicodeToUTF8 = [](const wstring &wstr)
    {
        string ret;
        try
        {
            wstring_convert<codecvt_utf8<wchar_t>> wcv;
            ret = wcv.to_bytes(wstr);
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
        return ret;
    };

    auto UTF8ToUnicode = [](const string &str)
    {
        wstring ret;
        try
        {
            wstring_convert<codecvt_utf8<wchar_t>> wcv;
            ret = wcv.from_bytes(str);
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
        return ret;
    };

void searching()
{
  cout << "\t\tsearching";
  for (int n = 0; n < 10; n++)
  {
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(140));
  }
  
}

void loading()
{
  cout << "\t\tloading";
  for (int n = 0; n < 10; n++)
  {
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(140));
  }
  
}
void exiting()
{
  cout << "\t\texiting";
  for (int n = 0; n < 10; n++)
  {
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(140));
  }
  
}


void Page_Switch ()
{
   for (int i = 0; i < 300; i++)
  {
      cout << "         ";
  }
  
}
void cover()
{
  
  
  system("color 07");
  
  Page_Switch();
  cout << endl;
  cout << "\t\t\t\t\t\t-------------------------\n\n";
  cout << "\t\t\t\t\t\t     Tom's Dictionary\n\n";
  cout << "\t\t\t\t\t\t-------------------------\n\n\n\n\n\n\n\n\n\n";
  cout << endl << endl;
  cout << "\n\n\t\t\t\t Copy rights 2019, Tom's dictionary, All Rights Reserved.";
  for (int n = 0; n < 10; n++)
  {
    cout << ".";
    this_thread::sleep_for(chrono::milliseconds(140));
  }
  
  
}
//
void search(ofstream & His_File, ofstream & Data_File)
{

  Data_File << "Test1";
  system("color 07");
  Page_Switch ();
  string search_word = " ";
  cout << endl << "\t\t\t\t\t\t-------------------------\n\n";
  cout << "\t\t\t\t\t\t       Search \n\n";
  cout << "\t\t\t\t\t\t-------------------------\n\n\n\n\n\n\n\n\n\n\n\n";
  cout << "\t\t\t\t\t\t Enter the word in lowercase: ";
  cin >> search_word;
  His_File << " "; 
  His_File << search_word;
 
  searching();
  auto i = data.begin(); 

  while (i != data.end() && search_word != (i->first))
  {
    i++;
  } 
  
  if (i == data.end())
 { 
 
    string option = "";
    cout << "\t\t\tits not found" << endl;
    cout << "Not what you want? Help us built the database! Yes/No";
    cin >> option;
    
    if (option == "Yes")
    {
      
      string word = "";
      string definition = "";
      cout << "\t\t\t\t\tPlease enter the word that you would like to add: ";
      cin >> word;
      cout << endl;
      cout << "\t\t\t\t\t\tPlease enter the defintion of this word: ";
      cin >> definition;
      data.insert({word, definition});
      Data_File << "Test2";// << " " << definition << endl;
      cout << "reached" << word << definition;
    } 
    
  }
    else 
    cout << "\n\n\n\t\t\t\t\t\tThe definition of this word is: " <<  i -> second;
    cout << "\n\n\n"; 
    
    
    }
    
  

void history()
{
  
  ifstream FileIn ("history.txt");
  system("color d7");
  Page_Switch ();
  string his_word = " ";
  cout << endl << "\t\t\t\t\t\t-------------------------\n\n";
  cout << "\t\t\t\t\t\t         History \n\n";
  cout << "\t\t\t\t\t\t-------------------------\n\n\n\n\n\n\n\n\n\n\n\n";
  cout << "The last search is: " << endl;
  int i = 1;
  while(FileIn >> his_word)
  {
     
     cout << i << ": " << his_word << " " << endl;
     i++;
     
  }
  cout << "Press enter to continue";
  getch();
  
}



int main() {
    system("chcp 65001");
    string his_word = "";
   
    ofstream Data_File ("database.txt", ios::app | ios::out); // ios::in);
    string data_word = "";
    string data_definition = "";
    Data_File << "Test3";
 /*   while (Data_File >> data_word >> data_definition)
    {
      data.insert({data_word, data_definition});
    } */
    cover();
   
   
    menue:
    ofstream His_File ("history.txt", ios::app);
  
    Page_Switch();
    cout << "\n\n";
    cout << "\t\t\t\t\t\t   MAIN MENU";
    cout << endl<< "\t\t\t\t\t\tP1 SEARCH P2 HISTORY P3 EXIT";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    int option = 0;
    cin >> option;
    if (option == 1)
    {
      
      search(His_File, Data_File);
      Data_File.close();
      cout << "Press enter to continue";
      getch();
      goto menue;
    }
   
    else if (option == 2)
    {
    His_File.close();
    history();
    goto menue;
    
    }
    else 
    return 0;
            

}
