#ifndef DATA_HPP
#define DATA_HPP


class Data {
private:
	void* m_data;

	Data();
public:
	Data(void* data);
	Data(const Data& copy); // (!) THIS WILL NOT CREATE A COPY OF THE DATA

	~Data();

	Data& operator=(const Data& copy); // (!) THIS WILL NOT CREATE A COPY OF THE DATA

	void* getData();
	void setData(void *data);
};


#endif