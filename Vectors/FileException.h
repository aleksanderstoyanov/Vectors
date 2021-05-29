#ifndef FileException_hh
#define FileException_hh
#include <exception>
class FileException :std::exception {
public:
	FileException() :exception("Invalid file !") {

	}
};
#endif // !FileException_hh

