#ifndef FileException_hh
#define FileException_hh
#include <exception>
class FileException :public std::exception {
public:
	FileException() :exception("Invalid file !") {

	}
};
#endif // !FileException_hh

