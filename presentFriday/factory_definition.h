#ifndef FACTORY_DEFINITION_H
#define FACTORY_DEFINITION_H

#include "fieldinterfacedefinition.h"

class PacketFieldFactory
{
public:
    PacketFieldFactory(){}
    virtual ~PacketFieldFactory(){}

    // We need to have a supper set here, that the children can overload
    virtual void createPacket(){}
    virtual void setTimeStamp(){}
    virtual void setCalibrationParameters(){}

};


class PacketCalibrationSphFactory : public PacketFieldFactory
{
public:
    virtual void setTimeStamp() override
    {
        time.print();
    }

private:
    CIntrinsicCalibrationSpherical time;
};


class PacketCalibrationCarFactory : public PacketFieldFactory
{
public:
    virtual void setTimeStamp() override
    {
        time.print();
    }

private:
    CIntrinsicCalibrationCartesian time;
};


class PacketTimeCostumer1 : public PacketFieldFactory
{
public:
    PacketTimeCostumer1(){}

    virtual void createPacket() override
    {
        setTimeStamp();
    }

    virtual void setTimeStamp() override
    {
        time.print();
    }

private:
    CTimeCostumer1 time;
};


class PacketTimeCostumer2 : public PacketFieldFactory
{
public:
    virtual void setTimeStamp() override
    {
        time.print();
    }

private:
    CTimeCostumer2 time;
};


#endif // FACTORY_DEFINITION_H
