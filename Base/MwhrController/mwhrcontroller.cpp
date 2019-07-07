#include "mwhrcontroller.h"

#include "mwrf32.h"

MwhrController::MwhrController()
{
}

void MwhrController::startConnect()
{
   rf_init(0,115200);
}
