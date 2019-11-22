#include <iostream>
#include <atomic>
#include <thread>
#include <utility>
#include "field_template.hpp"
#include "factory_template.hpp"
#include "message_types.hpp"

int main()
{
    // Memory Pool for messages
    sMessageLaserScan msg_LaserScan_0;
    sMessageLaserScan msg_LaserScan_1;
    sMessageCalibration msg_Calibration_0;
    sMessageCalibration msg_Calibration_N;

    // Factory
    LaserScanFactoryType factory_LaserScan;
    CalibrationFactoryType factory_Calibration;

    // Message containing the ptr to factory
    LaserScanMessage msg0(&msg_LaserScan_0, factory_LaserScan);
    LaserScanMessage msg1(&msg_LaserScan_0, factory_LaserScan);
    CalibrationMessage msg2(&msg_Calibration_0, factory_Calibration);
    CalibrationMessage msg3(&msg_Calibration_0, factory_Calibration);

    // Process Messages
    std::cout << "\nLaser Scan" << std::endl;
    msg0.process();
    msg1.process();

    std::cout << "\nCalibration" << std::endl;
    msg2.process();
    msg3.process();

    // Specific routine for 1 message or 2
    std::cout << "\nSpecific Routines" << std::endl;
    msg0.specificMessageRoutine();
    msg1.specificMessageRoutine();

    return 0;
}
