#pragma once
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class EmptyInputException :public InputValidationException {
	using InputValidationException::InputValidationException;
};