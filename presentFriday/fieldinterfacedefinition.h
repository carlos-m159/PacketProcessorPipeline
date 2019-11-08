#ifndef FIELDINTERFACEDEFINITION_H
#define FIELDINTERFACEDEFINITION_H

#include <iostream>
// Interfaces
// Time stamp
class CTimeStamp
{
public:
    CTimeStamp(){}

    virtual ~CTimeStamp(){}

    virtual void print() = 0;
};

class CTimeCostumer1 : public CTimeStamp
{
public:
    void print() override
    {
        std::cout << "Time Stamp CTimeCostumer1" << std::endl;
    }};


class CTimeCostumer2 : public CTimeStamp
{
public:
    void print() override
    {
        std::cout << "Time Stamp CTimeCostumer1" << std::endl;
    }

};


// Calibration factors
class CIntrinsicCalibration
{
public:
    CIntrinsicCalibration(){}
    virtual ~CIntrinsicCalibration(){}

    virtual void print() = 0;
};

class CIntrinsicCalibrationSpherical : public CIntrinsicCalibration
{
public:
    CIntrinsicCalibrationSpherical(){}

    virtual void print() override
    {
        std::cout << "Calibration Spherical" << std::endl;
    }
};

class CIntrinsicCalibrationCartesian : public CIntrinsicCalibration
{
public:
    CIntrinsicCalibrationCartesian(){}

    virtual void print() override
    {
        std::cout << "Calibration Cartesian" << std::endl;
    }
};

#endif // FIELDINTERFACEDEFINITION_H
