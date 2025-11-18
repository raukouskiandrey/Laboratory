#pragma once
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class InvalidArgumentException :public InputValidationException {
	using InputValidationException::InputValidationException;
};