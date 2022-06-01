#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

constexpr size_t BufferSize = 500;
constexpr char Separator = '\t';
constexpr int SplitStringCount = 3;

struct Item
{
	int sku;
	std::string name;
	std::string description;
};


// Set as static to prevent linker error in VS project due to conflict
static void printItem(const Item& item)
{
	std::cout << "sku: " << item.sku << ", name: " << item.name << ", desc: " << item.description << '\n';
	std::cout << std::endl;
}

std::vector<std::string> splitString(const std::string& string, char separator = Separator) {
	size_t start = 0;
	std::vector<std::string> strings;
	strings.reserve(SplitStringCount);
	for (size_t i = 0; i < string.size(); ++i) {
		if (string[i] == separator) {
			auto substr = string.substr(start, i - start);
			strings.push_back(substr);
			start = i + 1;
		}
	}
	strings.push_back(string.substr(start, string.length() - start));
	return strings;
}


void transformFileSTL() 
{
	const char* filename = "../linkedin_cpp_essential_training/data.txt";
	std::ifstream infile(filename);
	char buffer[BufferSize];
	while (infile.good()) {
		infile.getline(buffer, BufferSize);
		std::vector<std::string> strings = splitString(buffer);
		Item item = { std::stoi(strings[0]), strings[1], strings[2] };
		printItem(item);
	}
	infile.close();
}


//int main() 
//{
//	transformFileSTL();
//}