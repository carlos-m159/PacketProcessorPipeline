#ifndef FIELD_TYPES_HPP
#define FIELD_TYPES_HPP

#include <iostream>

struct sField1_type
{
    uint32_t field;
    std::string identifier = "Field 1";
};

struct sField2_type
{
    uint32_t field;
    std::string identifier = "Field 2";
};
struct sField3_type
{
    uint32_t field;
    std::string identifier = "Field 3";
};

struct sField4_type
{
    uint32_t field;
    std::string identifier = "Field 4";
};
struct sField5_type
{
    uint32_t field;
    std::string identifier = "Field 5";
};

struct sMessageLaserScan
{
    sField1_type header;
    sField2_type body1;
    sField3_type body2;
};

struct sMessageCalibration
{
    sField4_type header;
    sField5_type body1;
};

#endif // FIELD_TYPES_HPP
