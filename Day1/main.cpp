#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
void main()
{
	fstream file;
	file.open("./input.txt");

	vector<std::string> alphaNum = { "one","two","three","four","five","six","seven","eight","nine" };

	int total = 0;

	for(string line; getline(file, line);)
	{
		string firstNum = "";
		string lastNum = "";

		int lowest = INT_MAX;
		for(int i = 0; i < line.size(); i++)
		{
			if(isdigit(line.at(i)))
			{
				firstNum = line.at(i);
				lowest = i;
				break;
			}
		}

		int lowestForAlphaNum = INT_MAX;
		for(int i = 0; i < alphaNum.size(); i++)
		{
			size_t f = line.find(alphaNum.at(i));
			if(f < lowestForAlphaNum)
			{
				lowestForAlphaNum = f;
				if(lowestForAlphaNum < lowest)
				{
					firstNum = to_string(i + 1);
				}
			}
		}
		
		int highest = -INT_MAX;
		for (int i = line.size() - 1; i >= 0; i--)
		{
			if (isdigit(line.at(i)))
			{
				lastNum = line.at(i);
				highest = i;
				break;
			}
		}

		int highestForAlphaNum = -INT_MAX;
		for (int i = 0; i < alphaNum.size(); i++)
		{
			size_t f = line.rfind(alphaNum.at(i));
			if (static_cast<int>(f) > highestForAlphaNum && f != string::npos)
			{
				highestForAlphaNum = f;
				if (highestForAlphaNum > highest)
				{
					lastNum = to_string(i + 1);
				}
			}
		}

		//std::cout << firstNum + lastNum << "\n";
		total += std::stoi(firstNum + lastNum);
	}
	cout << total;

	file.close();
}
