#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <cstddef>
#include <cstring>

enum ErrorCode {
	EC_FUNCTION = -4,
	EC_RANGE = -3,
	EC_MEMORY = -2,
	EC_UNKNOWN = -1,
	EC_OK = 0
};

size_t str_length(const char str[]) {
	size_t count;
	for (count = 0; str[count] != '\0'; ++count);
	return count;
}
/*
std::ostream& operator << (std::ostream& os, const char* str) { // why it works only with iosfwd??????
	size_t size = str_length(str);
	for (size_t i = 0; i < size; ++i) {
		os << str[i];
	}
	return os;
}
*/
class Exception {
private:
	char message_[256];
	ErrorCode code_;

public:
	const char *GetMessage() const {
		return message_;
	}
	ErrorCode GetCode() const {
		return code_;
	}
	Exception operator=(const Exception &) = delete;
	Exception(ErrorCode c, const char *msg) {
		code_ = c;
		strncpy(message_, msg, 256); // destination, source, size to copy
	}
	//friend std::ostream &operator<<(std::ostream &o, const Exception &e);
};

#endif
