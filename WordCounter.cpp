#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int wordCount = 0;
    int minWordSize; //Starts at 1, since string.length() does so.
    string path; //Path to file
    cout << "Enter Minimum Word Size: ";
    cin >> minWordSize;
    cout << "\n";
    cout << "Enter Path To Text File: ";
    cin >> path;
    cout << "\n";
    string line;
    string content;
    string splitContent;
    vector<string> vecContent;
    ifstream inpf;
    inpf.open(path);
    if (!inpf.is_open())
    {
        cout << "Error. ?Invalid File?" << "\n";
    }
    while(getline(inpf, line))
    {
        content += line;
    }
    inpf.close();
    for (int charItr = 0; charItr <= content.length() - 1; charItr++)
    {
        if (content[charItr] == ' ' || charItr == content.length() - 1)
        {
            if (splitContent.length() >= minWordSize) vecContent.push_back(splitContent);
            splitContent = "";
        }
        else
        {
            splitContent += content[charItr];
        }
    }
    cout << "Word Count: " << vecContent.size() << "\n";
    return 0;
}
