#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;



bool read( string NameOfFile )
{
    int index = 0;
    unordered_map<string, int> hashtable;


    ifstream file;
    file.open( NameOfFile.c_str() );
    if( !file.good() )
        return false;

    string buffer, word;

    while(getline(file, buffer))
    {
        word = "";
        for(size_t i = 0; i <= buffer.length(); i++)
        {
            if(word != "" && (i == buffer.length() || !isalpha(buffer[i])))
            {
                //insertElem(tree, word);
                ++hashtable[word];
                word = "";
            }
            else if(isalpha(buffer[i]))
            {
                word += tolower(buffer[i]);
            }
            else
            {
                continue;
            }
        }
    }

    file.close();
    return true;

    }

int main()
{
    if( !read( "Nostromo" ) )
        cout << "error" << endl;

    for (pair<string, int> element : hashtable)
        cout << element.first << " :: " << element.second << endl;

    system ("PAUSE");
    return 0;
}