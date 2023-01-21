#include <stdio.h>


#include <iostream>

#include <chrono>
#include <thread>
#include <fstream>
#include <unordered_map>
#include <locale>
#include <string>
//using namespace std;
std:: unordered_map<std::string, std:: string> data = { { "冧", "倒  E.G 冧咗落嚟：倒塌下來" },
                                                        { "㤿憸", "挑剔" },
                                                        { "囉囉攣", "心裡上嘅衝突" },
                                                        { "叻執生", "識變通，識隨機應變" },
                                                        { "嘥", "浪費" }

};




void searching()
{
    std::cout << "\t\tsearching";
    for (int n = 0; n < 10; n++)
    {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(140));
    }

}

void loading()
{
    std::cout << "\t\tloading";
    for (int n = 0; n < 10; n++)
    {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(140));
    }

}
void exiting()
{
    std::cout << "\t\texiting";
    for (int n = 0; n < 110; n++)
    {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(140));
    }

}


void Page_Switch ()
{
    for (int i = 0; i < 300; i++)
    {
        std::cout << "         ";
    }

}
void cover()
{

    Page_Switch();
    std::cout << std::endl;
    std::cout << "\t\t\t\t\t\t-------------------------\n\n";
    std::cout << "\t\t\t\t\t\t     Tom's Dictionary\n\n";
    std::cout << "\t\t\t\t\t\t-------------------------\n\n\n\n\n\n\n\n\n\n";
    std::cout << std::endl << std::endl;
    std::cout << "\n\n\t\t\t\t Copy rights 2019, Tom's dictionary, All Rights Reserved.";
    for (int n = 0; n < 10; n++)
    {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(140));
    }


}
//
void search(std::ofstream & His_File, std::fstream & Data_File)
{
    Page_Switch ();
    std::string search_word = " ";
    std::cout << std::endl << "\t\t\t\t\t\t-------------------------\n\n";
    std::cout << "\t\t\t\t\t\t       Search \n\n";
    std::cout << "\t\t\t\t\t\t-------------------------\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\t\t\t\t\t\t Enter the word in lowercase: ";
    std::cin >> search_word;
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

        std::string option = "";
        std::cout << "\t\t\tits not found" << std::endl;
        std::cout << "Not what you want? Help us built the database! Yes/No";
        std::cin >> option;

        if (option == "Yes")
        {

            std::string word = "";
            std::string definition = "";
            std::cout << "\t\t\t\t\tPlease enter the word that you would like to add: ";
            std::cin >> word;
            std::cout << std::endl;
            std::cout << "\t\t\t\t\t\tPlease enter the definition of this word: ";
            std::cin >> definition;
            data.insert({word, definition});
            Data_File.clear();
            Data_File.seekp(0, std::ios::end);
            Data_File << std::endl << word << " " << definition << std::endl;

        }

    }
    else
            std::cout << "\n\n\n\t\t\t\t\t\tThe definition of this word is: " <<  i -> second;
            std::cout << "\n\n\n";


}



void history()
{

    std::ifstream FileIn ("history.txt");
    system("color d7");
    Page_Switch ();
    std::string his_word = " ";
    std::cout << std::endl << "\t\t\t\t\t\t-------------------------\n\n";
    std::cout << "\t\t\t\t\t\t         History \n\n";
    std::cout << "\t\t\t\t\t\t-------------------------\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "The last search is: " << std::endl;
    int i = 1;
    while(FileIn >> his_word)
    {

        std::cout << i << ": " << his_word << " " << std::endl;
        i++;

    }
    std::cout << "Press enter to continue";
    getc(stdin);

}



int main() {

    std::fstream Data_File ("database.txt", std::ios::in | std::ios::out | std::ios::app);
    std::string data_word = "";
    std::string data_definition = "";

    Data_File.clear();
    Data_File.seekg(0, std::ios::beg);


    while (Data_File >> data_word >> data_definition)
    {
        data.insert({data_word, data_definition});
    }
    cover();

    menue:
    std::ofstream His_File ("history.txt", std::ios::app);

    Page_Switch();
    std::cout << "\n\n";
    std::cout << "\t\t\t\t\t\t   MAIN MENU";
    std::cout << std::endl<< "\t\t\t\t\t\tP1 SEARCH P2 HISTORY P3 EXIT";
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    int option = 0;
    std::cin >> option;
    if (option == 1)
    {

        search(His_File, Data_File);
        Data_File.close();
        std::cout << "Press enter to continue";

        getc(stdin);
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
