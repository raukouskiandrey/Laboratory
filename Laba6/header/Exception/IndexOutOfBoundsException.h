#pragma once
#include <stdexcept>
#include <string>
#include "InputValidationException.h"

class IndexOutOfBoundsException :public InputValidationException {
	using InputValidationException::InputValidationException;
};