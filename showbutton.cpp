#include "showbutton.h"

void ShowButton::myClicked()
{
    emit iChanged(this); // Emitting the custom signal.
}
