#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>

using namespace std;
void main()
{
	fstream file;
	file.open("./input.txt");


	int total = 0;

	int currentline = 1;
	for(string line; getline(file, line);)
	{
		size_t start = line.find(":");
		string temp = line.substr(start + 1, line.size());

		std::map<string, int> maximum{ {"blue", 0}, {"green", 0}, {"red", 0}};
		string num = "";
		string col = "";
		int val = 0;
		for(int i = 0; i < temp.size(); i++)
		{
			if(isdigit(temp[i]))
			{
				num += temp[i];
			}
			else if(temp[i] == ' ' && !num.empty())
			{
				val = stoi(num);
			}
			else if(isalpha(temp[i]))
			{
				col += temp[i];
			}
			else if(temp[i] == ';' || temp[i] == ',')
			{
				if(maximum[col] < val)
				{
					maximum[col] = val;
				}
				col = "";
				num = "";
				val = 0;
			}
		}

		if (maximum[col] < val)
		{
			maximum[col] = val;
		}

		total += maximum["blue"] * maximum["red"] * maximum["green"];
	}
	std::cout << total;

	file.close();
}