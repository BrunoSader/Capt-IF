#include <iostream>

regex capteurRegex("(.*);(.*);(.*);(.*);");
smatch matches;
if (regex_search(/*mettre le nom du parametre de ligne*/, matches, capteurRegex))
{
	if (matches[0].str() == /*mettre le nom du parametre de ligne*/)
	{
		smatch matchesTime;
		string timestampS = matches[1].str();
		string sensorId = matches[2].str();
		string attributeId = matches[3].str();
		int  value = matches[4].str().atoi()
			regex timeRegex("(.*-.*-.*)T(.*:.*:.*)\..*") /*devrait marcher mais pas sur, à tester sur un PC qui peut compiler ave cdes lines comme celles du csv*/
			if (regex_search(timestampS, matchesTime, timeRegex))
			{
				if (matchesTime[0].str() == /*mettre le nom du parametre de ligne*/)
				{
					// Construction de la string avec ce qu'on veut

					struct std::tm tm;
					std::istringstream ss(matchesTime[1].str() + "-" + matchesTime[2].str());
					ss >> std::get_time(&tm, "%F-%T"); // or just %T in this case
					std::time_t timestamp = mktime(&tm);

				}
			}
	}
}