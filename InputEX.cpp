#include "Input.h"

bool Input::PushPrekey(BYTE keyNumber) const{ 
	if (keyPre_[keyNumber] != 0) {
		return true;
	}
	return false;
}