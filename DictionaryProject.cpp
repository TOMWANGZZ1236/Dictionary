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
                                                        { "爭好遠", "差一大截" },
                                                        { "嘥", "浪費 E.G 嘥氣：浪費時間和精力" },
                                                        { "噏", "亂講嘢；講冇意義、無謂嘅嘢 E.G 你知唔知個先生噏緊乜呀？"},
                                                        { "郁手郁脚", "動手動腳" },
                                                        { "兜口兜面", "劈頭劈臉的、不分青紅皂白、完全不給下台的意思" },
                                                        { "乞人憎", "討人厭" },
                                                        { "串", "動詞：揶揄，嘲諷 ；形容詞：囂張" },
                                                        { "唞", "休息" },
                                                        { "口水佬", "話癆" },
                                                        { "折墮", "缺德，造孽" },
                                                        { "燶", "焦" },
                                                        { "唔挐褦", "冇關係" },
                                                        { "牙煙", "危險" },
                                                        { "有路", "兩人之間有未公開嘅愛情關係" },
                                                        { "賣花讚花香", "賣花讚花香" },
                                                        { "一文雞", "一塊錢" },
                                                        { "啢", "過時的" },
                                                        { "無計", "沒辦法" },
                                                        { "離地", "形容某些人的想法甚至行為脫離普羅大眾，不食民間煙火，不知民間疾苦。他們雙腳離地，活於天際，高高在上。" },
                                                        { "閂門", "關門" },
                                                        { "蝕本", "賠本" },
                                                        { "肉酸", "在廣東話里,「肉酸」是形容某個人的行為表現出來很難看，讓別人看上去很不舒服的意思。" },
                                                        { "零舍", "特別" },
                                                        { "挨", "依靠" },
                                                        { "陰公", "真是可憐, 真是悲慘, 真是造孽" },
                                                        { "執笠", "閂門，結業" },
                                                        { "花款", "花樣" },
                                                        { "冇嘢撈", "沒錢賺" },



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

   // Page_Switch();
    std::cout << std::endl;
    std::cout << "\t\t\t\t\t\t-------------------------\n\n";
    std::cout << "\t\t\t\t\t\t     Tom's Dictionary\n\n";
    std::cout << "\t\t\t\t\t\t-------------------------\n\n\n\n";
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
            data.insert(
                    {word, definition});
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

  //  Page_Switch();
    std::cout << "\n\n";
    std::cout << "\t\t\t\t\t\t   MAIN MENU";
    std::cout << std::endl<< "\t\t\t\t\t\tP1 SEARCH P2 HISTORY P3 EXIT";
    std::cout << "\n\n\n\n\n";
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
