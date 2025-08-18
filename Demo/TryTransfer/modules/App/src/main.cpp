#include <iostream>
#include <type_traits>
#include "TransferBackend.hpp"
#include "TransferBackendImpl/CoutTransferBackend.hpp"

class MyClass
{
public:
	int foo = 100;
	double bar = 3.1415926;
	std::vector<double> dbl_vector;

	void Transfer(CoutTransferBackend &a_backend)
	{
		a_backend.Transfer(FS_NV_META("foo", foo));
		a_backend.Transfer(FS_NV_META("bar", bar));
		a_backend.Transfer(FS_NV_META("dbl_vector", dbl_vector));
	}

	std::string_view GetTypeName() const { return "MyClass"; }
};

int main()
{
	std::cout << "HelloWorld" << std::endl;

	CoutTransferBackend cout_transfer;
	MyClass cls;
	cls.dbl_vector.push_back(1);
	cls.dbl_vector.push_back(1);
	cls.dbl_vector.push_back(2);
	cls.dbl_vector.push_back(3);
	cls.dbl_vector.push_back(5);

	cout_transfer.Transfer(FS_NV_META("cls", cls));

	return 0;
}