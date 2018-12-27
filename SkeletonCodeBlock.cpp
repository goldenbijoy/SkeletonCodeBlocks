/**********************************************************/
/**            Bismillahir-rahmanir-rahim                **/
/**  In the name of Allah, the Beneficent, the Merciful. **/
/**********************************************************/
/**@author: Sayed Sohan*/
/**url: */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;


//** Code starts from here

int main()
{
    string skeleton = "skeleton";
    string pathAndFileType = "Path_FileType.txt";
    string path,type;
    string outputFile;
    string fileName;
    string line;

    ifstream myfile (pathAndFileType);

    if(myfile.is_open()){

        getline(myfile,path);
        getline(myfile,type);

        myfile.close();
    }
    else{
        cout<<"Path_FileType.txt is missing...";
        cin.get();
        return 0;
    }
    path = path + "\\";

    cout<<"Enter filename: ";
    getline(cin,fileName);


    outputFile = path  + fileName + "." + type ;
    skeleton = skeleton + "." + type;

    cout<<outputFile<<endl;

    ifstream sk (skeleton);

    if(sk.is_open()){
        ofstream out (outputFile);
        while(getline(sk,line)){
            out<< line <<"\n";
        }
        sk.close();
    }
    else{
        cout<<"Skeleton file is missing...";
        cin.get();
        return 0;
    }
    outputFile = "\"" + path + fileName + "." + type + "\"" ;
    system(outputFile.c_str());

    return 0;
}
