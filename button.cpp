#include "Button.h"

void Button::myClicked() {
    emit iChanged(this);
}
