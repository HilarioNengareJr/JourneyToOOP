#include <iostream>

class M{
    
private:
	char* item;

public:

	// Constructor
	M(char it)
	{
		item = new char;
		*item = it;
		// Track constructor calls
		std::cout << "M Constructor has been invoked : "
			<< it << std::endl;
	};

	// create a new object from another existing object
	M(const M& obj )
		: M{ *obj.item }
	{
		std::cout << "Copy Constructor invoked: " << *obj.item << std::endl;
	}

	// Move Constructor
	M(M&& obj)
		: item{ obj.item }
	{

		std::cout << "Move Constructor invoked: "
			<< *obj.item << std::endl;
		obj.item = nullptr;
	}

	// Destructor
	~M()
	{
		if (item != nullptr)
		{
			std::cout << "Destructor is invoked: "
				<< *item << std::endl;
		    
		}
		else
			std::cout << "Destructor is called for nullptr "
				<< std::endl;

		delete[] item;
	}
};

// Driver Code
int main()
{
	
	return 0;
}
