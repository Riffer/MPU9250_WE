/******************************************************************************
 *
 * This is a library for the 6-axis gyroscope and accelerometer MPU6500.
 *
 ******************************************************************************/

#ifndef MPU6500_WE_H_
#define MPU6500_WE_H_

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

/* Registers MPU6500*/
static uint8_t constexpr MPU6500_SELF_TEST_X_GYRO       = 0x00;
static uint8_t constexpr MPU6500_SELF_TEST_Y_GYRO       = 0x01;
static uint8_t constexpr MPU6500_SELF_TEST_Z_GYRO       = 0x02;
static uint8_t constexpr MPU6500_SELF_TEST_X_ACCEL      = 0x0D;
static uint8_t constexpr MPU6500_SELF_TEST_Y_ACCEL      = 0x0E;
static uint8_t constexpr MPU6500_SELF_TEST_Z_ACCEL      = 0x0F;
static uint8_t constexpr MPU6500_XG_OFFSET_H            = 0x13;
static uint8_t constexpr MPU6500_XG_OFFSET_L            = 0x14;
static uint8_t constexpr MPU6500_YG_OFFSET_H            = 0x15;
static uint8_t constexpr MPU6500_YG_OFFSET_L            = 0x16;
static uint8_t constexpr MPU6500_ZG_OFFSET_H            = 0x17;
static uint8_t constexpr MPU6500_ZG_OFFSET_L            = 0x18;
static uint8_t constexpr MPU6500_SMPLRT_DIV             = 0x19;
static uint8_t constexpr MPU6500_CONFIG                 = 0x1A;
static uint8_t constexpr MPU6500_GYRO_CONFIG            = 0x1B;
static uint8_t constexpr MPU6500_ACCEL_CONFIG           = 0x1C;
static uint8_t constexpr MPU6500_ACCEL_CONFIG_2         = 0x1D;
static uint8_t constexpr MPU6500_LP_ACCEL_ODR           = 0x1E;
static uint8_t constexpr MPU6500_WOM_THR                = 0x1F;
static uint8_t constexpr MPU6500_FIFO_EN                = 0x23;
static uint8_t constexpr MPU6500_I2C_MST_CTRL           = 0x24;
static uint8_t constexpr MPU6500_I2C_SLV0_ADDR          = 0x25;
static uint8_t constexpr MPU6500_I2C_SLV0_REG           = 0x26;
static uint8_t constexpr MPU6500_I2C_SLV0_CTRL          = 0x27;
static uint8_t constexpr MPU6500_I2C_MST_STATUS         = 0x36;
static uint8_t constexpr MPU6500_INT_PIN_CFG            = 0x37;
static uint8_t constexpr MPU6500_INT_ENABLE             = 0x38;
static uint8_t constexpr MPU6500_INT_STATUS             = 0x3A;
static uint8_t constexpr MPU6500_ACCEL_OUT              = 0x3B; // accel data registers begin
static uint8_t constexpr MPU6500_TEMP_OUT               = 0x41;
static uint8_t constexpr MPU6500_GYRO_OUT               = 0x43; // gyro data registers begin
static uint8_t constexpr MPU6500_EXT_SLV_SENS_DATA_00   = 0x49;
static uint8_t constexpr MPU6500_I2C_SLV0_DO            = 0x63;
static uint8_t constexpr MPU6500_I2C_MST_DELAY_CTRL     = 0x67;
static uint8_t constexpr MPU6500_SIGNAL_PATH_RESET      = 0x68;
static uint8_t constexpr MPU6500_MOT_DET_CTRL           = 0x69;
static uint8_t constexpr MPU6500_USER_CTRL              = 0x6A;
static uint8_t constexpr MPU6500_PWR_MGMT_1             = 0x6B;
static uint8_t constexpr MPU6500_PWR_MGMT_2             = 0x6C;
static uint8_t constexpr MPU6500_FIFO_COUNT             = 0x72; // 0x72 is COUNT_H
static uint8_t constexpr MPU6500_FIFO_R_W               = 0x74;
static uint8_t constexpr MPU6500_WHO_AM_I               = 0x75;
static uint8_t constexpr MPU6500_XA_OFFSET_H            = 0x77;
static uint8_t constexpr MPU6500_XA_OFFSET_L            = 0x78;
static uint8_t constexpr MPU6500_YA_OFFSET_H            = 0x7A;
static uint8_t constexpr MPU6500_YA_OFFSET_L            = 0x7B;
static uint8_t constexpr MPU6500_ZA_OFFSET_H            = 0x7D;
static uint8_t constexpr MPU6500_ZA_OFFSET_L            = 0x7E;

/* Register Values */
static uint8_t constexpr MPU6500_RESET       = 0x80;
static uint8_t constexpr MPU6500_BYPASS_EN   = 0x02;
static uint8_t constexpr MPU6500_I2C_MST_EN  = 0x20;
static uint8_t constexpr MPU6500_CLK_SEL_PLL = 0x01;

/* Others */
static float constexpr MPU6500_ROOM_TEMP_OFFSET    = 0.0f;
static float constexpr MPU6500_T_SENSITIVITY       = 333.87f;
static float constexpr MPU6500_WHO_AM_I_CODE       = 0x70;


/* Enums */

typedef enum MPU9250_BW_WO_DLPF {
    MPU9250_BW_WO_DLPF_3600 = 0x02,
    MPU9250_BW_WO_DLPF_8800 = 0x01
} MPU9250_bw_wo_dlpf;

typedef enum MPU9250_DLPF {
    MPU9250_DLPF_0, MPU9250_DLPF_1, MPU9250_DLPF_2, MPU9250_DLPF_3, MPU9250_DLPF_4, MPU9250_DLPF_5,
    MPU9250_DLPF_6, MPU9250_DLPF_7
} MPU9250_dlpf;

typedef enum MPU9250_GYRO_RANGE {
    MPU9250_GYRO_RANGE_250, MPU9250_GYRO_RANGE_500, MPU9250_GYRO_RANGE_1000, MPU9250_GYRO_RANGE_2000
} MPU9250_gyroRange;

typedef enum MPU9250_ACC_RANGE {
    MPU9250_ACC_RANGE_2G, MPU9250_ACC_RANGE_4G, MPU9250_ACC_RANGE_8G, MPU9250_ACC_RANGE_16G
} MPU9250_accRange;

typedef enum MPU9250_LOW_PWR_ACC_ODR {
    MPU9250_LP_ACC_ODR_0_24, MPU9250_LP_ACC_ODR_0_49, MPU9250_LP_ACC_ODR_0_98, MPU9250_LP_ACC_ODR_1_95,
    MPU9250_LP_ACC_ODR_3_91, MPU9250_LP_ACC_ODR_7_81, MPU9250_LP_ACC_ODR_15_63, MPU9250_LP_ACC_ODR_31_25,
    MPU9250_LP_ACC_ODR_62_5, MPU9250_LP_ACC_ODR_125, MPU9250_LP_ACC_ODR_250, MPU9250_LP_ACC_ODR_500
} MPU9250_lpAccODR;

typedef enum MPU9250_INT_PIN_POL {
    MPU9250_ACT_HIGH, MPU9250_ACT_LOW
} MPU9250_intPinPol;

typedef enum MPU9250_INT_TYPE {
    MPU9250_DATA_READY = 0x01,
    MPU9250_FIFO_OVF   = 0x10,
    MPU9250_WOM_INT    = 0x40
} MPU9250_intType;

typedef enum MPU9250_WOM_EN {
    MPU9250_WOM_DISABLE, MPU9250_WOM_ENABLE
} MPU9250_womEn;

typedef enum MPU9250_WOM_COMP {
    MPU9250_WOM_COMP_DISABLE, MPU9250_WOM_COMP_ENABLE
} MPU9250_womCompEn;

typedef enum MPU9250_XYZ_ENABLE {
    MPU9250_ENABLE_XYZ,  //all axes are enabled (default)
    MPU9250_ENABLE_XY0,  // x, y enabled, z disabled
    MPU9250_ENABLE_X0Z,
    MPU9250_ENABLE_X00,
    MPU9250_ENABLE_0YZ,
    MPU9250_ENABLE_0Y0,
    MPU9250_ENABLE_00Z,
    MPU9250_ENABLE_000,  // all axes disabled
} MPU9250_xyzEn;

typedef enum MPU9250_ORIENTATION {
  MPU9250_FLAT, MPU9250_FLAT_1, MPU9250_XY, MPU9250_XY_1, MPU9250_YX, MPU9250_YX_1
} MPU9250_orientation;

typedef enum MPU9250_FIFO_MODE {
    MPU9250_CONTINUOUS, MPU9250_STOP_WHEN_FULL
} MPU9250_fifoMode;

typedef enum MPU9250_FIFO_TYPE {
    MPU9250_FIFO_ACC        = 0x08,
    MPU9250_FIFO_GYR        = 0x70,
    MPU9250_FIFO_ACC_GYR    = 0x78
} MPU9250_fifo_type;

struct xyzFloat {
    float x;
    float y;
    float z;
};


class MPU6500_WE
{
public:
    /* Constructors */

    MPU6500_WE(int const addr);
    MPU6500_WE(TwoWire * const w = &Wire, int const addr = 0x68);

    /* Basic settings */

    bool init();
    uint8_t whoAmI();
    void autoOffsets();
    void setAccOffsets(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax);
    void setGyrOffsets(float xOffset, float yOffset, float zOffset);
    void setGyrDLPF(MPU9250_dlpf dlpf);
    void setSampleRateDivider(uint8_t splRateDiv);
    void setGyrRange(MPU9250_gyroRange gyroRange);
    void enableGyrDLPF();
    void disableGyrDLPF(MPU9250_bw_wo_dlpf bw);
    void setAccRange(MPU9250_accRange accRange);
    void enableAccDLPF(bool enable);
    void setAccDLPF(MPU9250_dlpf dlpf);
    void setLowPowerAccDataRate(MPU9250_lpAccODR lpaodr);
    void enableAccAxes(MPU9250_xyzEn enable);
    void enableGyrAxes(MPU9250_xyzEn enable);

    /* x,y,z results */

    xyzFloat getAccRawValues();
    xyzFloat getCorrectedAccRawValues();
    xyzFloat getGValues();
    xyzFloat getAccRawValuesFromFifo();
    xyzFloat getCorrectedAccRawValuesFromFifo();
    xyzFloat getGValuesFromFifo();
    float getResultantG(xyzFloat gVal);
    float getTemperature();
    xyzFloat getGyrRawValues();
    xyzFloat getCorrectedGyrRawValues();
    xyzFloat getGyrValues();
    xyzFloat getGyrValuesFromFifo();


    /* Angles and Orientation */

    xyzFloat getAngles();
    MPU9250_orientation getOrientation();
    String getOrientationAsString();
    float getPitch();
    float getRoll();

    /* Power, Sleep, Standby */

    void sleep(bool sleep);
    void enableCycle(bool cycle);
    void enableGyrStandby(bool gyroStandby);

    /* Interrupts */

    void setIntPinPolarity(MPU9250_intPinPol pol);
    void enableIntLatch(bool latch);
    void enableClearIntByAnyRead(bool clearByAnyRead);
    void enableInterrupt(MPU9250_intType intType);
    void disableInterrupt(MPU9250_intType intType);
    bool checkInterrupt(uint8_t source, MPU9250_intType type);
    uint8_t readAndClearInterrupts();
    void setWakeOnMotionThreshold(uint8_t womthresh);
    void enableWakeOnMotion(MPU9250_womEn womEn, MPU9250_womCompEn womCompEn);

    /* FIFO */

    void startFifo(MPU9250_fifo_type fifo);
    void stopFifo();
    void enableFifo(bool fifo);
    void resetFifo();
    int16_t getFifoCount();
    void setFifoMode(MPU9250_fifoMode mode);
    int16_t getNumberOfFifoDataSets();
    void findFifoBegin();

protected:

    bool init(uint8_t const expectedValue);

    void correctAccRawValues();
    void correctGyrRawValues();
    void getAsaVals();
    void reset_MPU9250();
    void enableI2CMaster();
    void writeMPU9250Register(uint8_t reg, uint8_t val);
    uint8_t readMPU9250Register8(uint8_t reg);
    int16_t readMPU9250Register16(uint8_t reg);
    uint64_t readMPU9250Register3x16(uint8_t reg);
    xyzFloat readMPU9250xyzValFromFifo();

    TwoWire * const _wire;
    int const i2cAddress;

private:
    xyzFloat accRawVal;
    xyzFloat gyrRawVal;
    xyzFloat accOffsetVal;
    xyzFloat gyrOffsetVal;
    uint8_t accRangeFactor;
    uint8_t gyrRangeFactor;
    MPU9250_fifo_type fifoType;

};

#endif // MPU6500_WE_H_
