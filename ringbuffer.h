#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SET              1
#define RESET            0
#define TRUE             SET
#define FALSE            RESET

#define RING_BUFFER_SIZE 10

typedef struct
{
    uint32_t sensorID;
    float    temprature;
    
    
} SensorDataType;


typedef struct
{
    SensorDataType buffer[RING_BUFFER_SIZE];
    uint32_t head;
    uint32_t tail;
    uint32_t size;
} RingBufferType;




void RingBufferInit(RingBufferType *p_RingBuffer);
bool RingBufferWriteQueue (RingBufferType *p_RingBuffer,SensorDataType data);
bool RingBufferReadDequeue (RingBufferType *p_RingBuffer,SensorDataType *p_Data);
bool IsRingBufferFull (RingBufferType *p_RingBuffer);
bool IsRingBufferEmpty(RingBufferType *p_RingBuffer);
void PrintRingBuffer(RingBufferType *p_RingBuff);

#endif