#include <stdio.h>
#define No_Calibration_Point 5

struct CalibrationData
{
    double X[No_Calibration_Point];
    double Y[No_Calibration_Point];
};

double linear_mapping(double x, struct CalibrationData *cal_data)
{
    int i;
    double y = 0.0;

    for (i = 1; i < No_Calibration_Point; i++)
    {
        if (x <= cal_data->X[i])
        {
            double x1 = cal_data->X[i - 1];
            double y1 = cal_data->Y[i - 1];
            double x2 = cal_data->X[i];
            double y2 = cal_data->Y[i];

            y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
            break;
        }
    }

    if (i == No_Calibration_Point)
    {
        y = cal_data->Y[No_Calibration_Point - 1];
    }

    return y;
}

int main()
{
    struct CalibrationData cal_data = 
	{
        {0.0, 1.0, 2.0, 3.0, 4.0},
        {0.0, 15.0, 30.0, 45.0, 60.0}
    };

    double x = -2;
    double mapped_value = linear_mapping(x, cal_data);
    printf("Mapped value: %.2f\n", mapped_value);

    return 0;
}
