/** @file vdl.cpp
 *  @author Dieko Akinrowo
 *  @date 17MAY2020
 *  @brief Vehicle Data Logger main function
 */

#include <cstdio>
#include <unistd.h>
#include "vdl.h"
#include "logger.h"

/** @brief Vehicle Data Logger main function
 *  @author Dieko Akinrowo
 *  @date 17MAY21
 *  @param None void
 *  @return int program status
 */
int main(void)
{
    readings lgread = {0};
    lgread = DlGetLoggerReadings();
    int tc = 0;

    DlInitialization();
    DlDisplayLogo();
    sleep(3);
    DlUpdateLevel(DXA, DYA);
    if (tc == LOGCOUNT)
    {
        DlDisplayLoggerReadings(lgread);
        DlSaveLoggerData(lgread);
        tc = 0;
    } else {
        usleep(SLEEPTIME);
        tc ++;
    }

    while(1)
    {
//      lgread = DlGetLoggerReadings();
        DlDisplayLoggerReadings(lgread);
        DlSaveLoggerData(lgread);
        sleep(5);
    }
    return 1;
}

