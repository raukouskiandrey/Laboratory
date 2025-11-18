#pragma once
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class OutOfRangeException :public InputValidationException {
	using InputValidationException::InputValidationException;
};