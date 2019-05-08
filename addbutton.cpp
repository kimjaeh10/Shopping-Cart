#include "addbutton.h"

void AddButton::myClicked()
{
    emit iChanged(this); // Emitting the custom signal.
}
