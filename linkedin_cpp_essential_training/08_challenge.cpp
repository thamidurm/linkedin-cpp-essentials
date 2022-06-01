#include <cstdio>
#include <cstring>
#include <cstdlib>

constexpr size_t MaxSKUSize = 10;
constexpr size_t MaxNameSize = 30;
constexpr size_t MaxDescSize = 200;
constexpr size_t BufferSize = MaxSKUSize + MaxNameSize + MaxDescSize + 1;

struct Item 
{
	int sku;
	char name[MaxNameSize];
	char description[MaxDescSize];
};

Item* getItemFromLine(Item* item, const char* line) 
{

	const char* first_tab_ptr = strchr(line, '\t');
	const char* last_tab_ptr = strrchr(line, '\t');

	const char* name_ptr = first_tab_ptr + 1;
	const char* desc_ptr = last_tab_ptr + 1;

	int sku_length = first_tab_ptr - line;
	int name_length = last_tab_ptr - first_tab_ptr - 1;
	int desc_length = strnlen(desc_ptr, MaxDescSize);
	char sku[MaxSKUSize];

	// Copy SKU into variable
	strncpy(sku, line, sku_length);
	sku[sku_length] = 0;
	item->sku = atoi(sku);

	// Copy name into variable
	strncpy(item->name, name_ptr, name_length);
	item->name[name_length] = 0;

	// Copy description into variable
	if (desc_length >= 1){
		strncpy(item->description, desc_ptr, desc_length);
		item->description[desc_length - 1] = 0;
	}
	return item;
}

void printItem(const Item& item) 
{
	printf("sku: %d, name: %s, desc: %s\n", item.sku, item.name, item.description);
}

void transformFile() {

	const char* filename = "../linkedin_cpp_essential_training/data.txt";
	FILE* file = fopen(filename, "r");
	char buffer[BufferSize];

	while (fgets(buffer, BufferSize, file) != nullptr)
	{
		Item item;
		getItemFromLine(&item, buffer);
		printItem(item);
	}
	fclose(file);
}

//int main()
//{
//	transformFile();
//}