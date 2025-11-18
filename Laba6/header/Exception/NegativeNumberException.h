#pragma once
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class NegativeNumberException :public InputValidationException {
	using InputValidationException::InputValidationException;
};