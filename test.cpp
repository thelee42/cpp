#include    <iostream>

/* int main()
{
    //char input[20];
    //
    //std::cout << "Hello, " << std::endl;
    //std::cout << "hi" << std::endl << "my name is " << "THEA" << std::endl;
    // std::cout << "Your name : ";
    // std::cin >> input;
    // std::cout << "Hi, " << input << std::endl;
    int a = 10;
    {
        std::cout << "out a : " << a << std::endl;
        int a = 4;
        std::cout << "in a : " << a << std::endl;
    }
    std::cout << "out a : " << a << std::endl;
    return 0;
} */

/* int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
    std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
    std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list;
    return 0;
} */




class Date {
	private:
    int year_;
    int month_;  // 1 부터 12 까지.
    int day_;    // 1 부터 31 까지.
	int is_leap_year(int year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}

	int days_of_month(int year, int month)
	{
		const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if(month == 2 && is_leap_year(year))
			return (29);
		return(days[month - 1]);
	}
	public:
    void SetDate()
	{
		std::cout << "year : ";
		std::cin >> year_;
		while (year_ < 1)
		{
			std::cout << "set the right year\nyear : ";
			std::cin >> year_;
		}
		std::cout << "month : ";
		std::cin >> month_;
		while (month_ < 1 || month_ > 12)
		{
			std::cout << "set the right month\nmonth : ";
			std::cin >> month_;
		}
		std::cout << "day : ";
		std::cin >> day_;
		while (day_ < 1 || day_ > days_of_month(year_, month_))
		{
			std::cout << "set the right day\nday : ";
			std::cin >> day_;
		}
	}
    void AddDay(int inc)
    {
		int d = day_ + inc;
		while(d > 0)
		{
			int last_day = days_of_month(year_, month_);
			if (d > last_day)
			{
				d = d - last_day;
				AddMonth(1);
			}
			else
			{
				day_ = d;
				return ;
			}
		}
    }
    void AddMonth(int inc)
    {
		int m = month_ + inc;
		while(m > 12)
		{
			AddYear(1);
			m = m - 12;
		}
		month_ = m;
		//
    }
    void AddYear(int inc)
    {
        year_ += inc;
    }
    void ShowDate()
    {
        std::cout << "today's date is " << year_ << "/" << month_ << "/" << day_ << std::endl;
    }
};




int main()
{
	Date date;

	while(1)
	{
		std::cout << "Enter 1 to set the date\n"
				<< "Enter 2 to see the date\n"
				<< "Enter 3 to add year\n"
				<< "Enter 4 to add month\n"
				<< "Enter 5 to add day\n"
				<< "Enter 6 to exit\n"
				<< "Enter your choice : ";
		int input;
		int inc;
		std::cin >> input;
		if (input < 1 || input > 6)
		{
			std::cout << "Enter the right number" << std::endl;
			continue;
		}
		switch(input)
		{
			case 1:
				date.SetDate();
				break;
			case 2:
				date.ShowDate();
				break;
			case 3:
				std::cout << "Enter year to add : ";
				std::cin >> inc;
				while (inc < 1){
					std::cout << "Enter a valid year to add : ";
					std::cin >> inc; }
				date.AddYear(inc);
				break;
			case 4:
				std::cout << "Enter month to add : ";
				std::cin >> inc;
				while (inc < 1){
					std::cout << "Enter a valid month to add : ";
					std::cin >> inc; }
				date.AddMonth(inc);
				break;
			case 5:
				std::cout << "Enter day to add : ";
				std::cin >> inc;
				while (inc < 1){
					std::cout << "Enter a valid day to add : ";
					std::cin >> inc; }
				date.AddDay(inc);
				break;
			case 6:
				return 0;
		}
	}
	return 0;
}



//c++ test.cpp -std=c++98