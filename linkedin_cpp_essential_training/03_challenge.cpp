#include <cstdint>

struct CatalogCard
{
	const char* title;
	const char* author;
	const char* publisher;
	const char* subject;
	const char* isbn;
	const char* oclc;

	uint32_t deweyDecimal1;
	uint32_t deweyDecimal2;
	uint16_t pubYear;
	uint16_t acqYear;
	uint32_t quantity;
};