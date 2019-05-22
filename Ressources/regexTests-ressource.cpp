#include <iostream>
#include <regex>
#include <string>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

int main () 
{
    
    string line = "2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936";
    regex capteurRegex("(.*);(.*);(.*);(.*)");
    smatch matches;
    
    if (regex_search(line, matches, capteurRegex))
    {
    	if (matches[0].str() == line)
    	{
    		smatch matchesTime;
    		string timestampS = matches[1].str();
    		string sensorId = matches[2].str();
    		string attributeId = matches[3].str();
    		string valueS = matches[4].str();
    		float value = stof(valueS.c_str());
    		cout << timestampS << endl; 
    		cout << sensorId << endl; 
    		cout << attributeId << endl; 
    		cout << valueS << endl; 
    		cout << value << endl; 
    		regex timeRegex("(.*-.*-.*)T(.*:.*:.*)\\..*"); /*devrait marcher mais pas sur, à tester sur un PC qui peut compiler avec des lines comme celles du csv*/
    		if (regex_search(timestampS, matchesTime, timeRegex))
    		{
    			if (matchesTime[0].str() == timestampS)
    			{	
				cout << matchesTime[1].str() << endl << matchesTime[2].str() << endl;
    				struct tm tm;
    				istringstream ss(matchesTime[1].str() + "-" + matchesTime[2].str());
    				ss >> std::get_time(&tm, "%F-%T");
    				time_t timestamp = mktime(&tm);
    			}
    		}
    	}
    }
    return 0;
}
