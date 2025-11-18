#pragma once
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class NonPositiveNumberException :public InputValidationException {
	using InputValidationException::InputValidationException;
};