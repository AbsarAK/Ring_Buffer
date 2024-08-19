/******************************************************************************

Ring Buffer For Automotive sensor

*******************************************************************************/
#include "ringbuffer.h"

int main()
{
    RingBufferType ringBuffer;
    RingBufferInit(&ringBuffer);
    
    SensorDataType data1 = {1,31.24};
    SensorDataType data2 = {2,32.24};
    SensorDataType data3 = {3,33.24};
    SensorDataType data4 = {4,34.24};
    SensorDataType data5 = {5,35.24};
    SensorDataType data6 = {6,36.24};
    SensorDataType data7 = {7,37.24};
    SensorDataType data8 = {8,38.24};
    SensorDataType data9 = {9,39.24};
    SensorDataType data10 = {10,40.24};
    SensorDataType data11 = {11,41.24}; // this will overwrite the oldets data
    SensorDataType data12 = {11,41.24};
    
    RingBufferWriteQueue(&ringBuffer,data1);
    RingBufferWriteQueue(&ringBuffer,data2);
    RingBufferWriteQueue(&ringBuffer,data3);
    RingBufferWriteQueue(&ringBuffer,data4);
    RingBufferWriteQueue(&ringBuffer,data5);
    RingBufferWriteQueue(&ringBuffer,data6);
    RingBufferWriteQueue(&ringBuffer,data7);
    RingBufferWriteQueue(&ringBuffer,data8);
    RingBufferWriteQueue(&ringBuffer,data9);
    RingBufferWriteQueue(&ringBuffer,data10);
    
    PrintRingBuffer(&ringBuffer);
    
    RingBufferWriteQueue(&ringBuffer,data11);
    
    PrintRingBuffer(&ringBuffer);
    
    // RingBufferWrite(&ringBuffer,data12);
    
    // PrintRingBuffer(&ringBuffer);
    SensorDataType rdData;
    RingBufferReadDequeue(&ringBuffer,&rdData);
    printf("Dequeued: Sensor ID:%d  Temprature=%.2f  \n",rdData.sensorID,rdData.temprature);
    
    PrintRingBuffer(&ringBuffer);
 

    return 0;
}