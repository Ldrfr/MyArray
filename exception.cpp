#include "exception.h"

size_t str_length(const char str[]) {
	size_t count;
	for (count = 0; str[count] != '\0'; ++count);
	return count;
}
const char* Exception::GetMessage() const {
	return message_;
}
ErrorCode Exception::GetCode() const {
	return code_;
}
