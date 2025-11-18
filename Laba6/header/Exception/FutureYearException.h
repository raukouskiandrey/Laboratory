
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class FutureYearException :public InputValidationException {
	using InputValidationException::InputValidationException;
}; 
