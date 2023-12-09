#include "Headers.hpp"

Headers::Headers()
{
}
Headers::~Headers()
{
}
Headers::Headers(const Headers &other)
{
	*this = other;
}
Headers &Headers::operator=(const Headers &other)
{
	if (this != &other)
		this->headers = other.headers;
	return *this;
}

std::string Headers::getHeader(std::string key)
{
	std::string keyLower = StringUtils::LowerCase(key);
	return this->headers[keyLower];
}

void Headers::setHeader(std::string key, std::string value)
{
	std::string keyLower = StringUtils::LowerCase(key);
	std::string valueTrim = StringUtils::Trim(value);
	this->headers[keyLower] = valueTrim;
}

std::map<std::string, std::string> Headers::getHeaders() const
{
	return this->headers;
}