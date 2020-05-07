#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
private:
	unsigned short day, month, year;

	bool isValidDate(unsigned short day, unsigned short month, unsigned short year);

public:
	Date();
	Date(unsigned, unsigned, unsigned);
	Date(const Date &);

	void read();

	void print() const;
	Date &operator=(const Date &);

	unsigned getDay() const;
	void setDay(unsigned);

	unsigned getMonth() const;
	void setMonth(unsigned);

	unsigned getYear() const;
	void setYear(unsigned);

	Date &getLiveData();
	bool operator==(const Date&);
	bool isEqual(const Date &other) const;
	bool isBefore(const Date &other) const;
	friend std::ostream &operator<<(std::ostream &, const Date&);
};

#endif