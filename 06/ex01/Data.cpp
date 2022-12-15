#include "Data.hpp"

Data::Data(void* data) :m_data(data) { }
Data::Data(const Data& copy) :m_data(copy.m_data) { }

Data& Data::operator=(const Data& copy)
{
	m_data = copy.m_data;
	return *this;
}

void* Data::getData() { return m_data; }
void Data::setData(void *data) { m_data = data; }