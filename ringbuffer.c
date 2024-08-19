#include "ringbuffer.h"

void RingBufferInit(RingBufferType *p_RingBuffer)
{
    p_RingBuffer->head = 0;
    p_RingBuffer->tail = 0;
    p_RingBuffer->size = 0;
}


bool RingBufferWriteQueue (RingBufferType *p_RingBuffer,SensorDataType data)
{
    if(IsRingBufferFull(p_RingBuffer))
    {
        printf("Ring buffer is full So overwriting sensor ID:%d\n",p_RingBuffer->buffer[p_RingBuffer->tail].sensorID);
        p_RingBuffer->tail = (p_RingBuffer->tail + SET) % RING_BUFFER_SIZE; 
    }else 
    {
        p_RingBuffer->size++;
    }
    p_RingBuffer->buffer[p_RingBuffer->head] = data;
    p_RingBuffer->head = (p_RingBuffer->head + 1) % RING_BUFFER_SIZE;
    
    return TRUE;
    
       
}
bool RingBufferReadDequeue (RingBufferType *p_RingBuffer,SensorDataType *p_Data)
{
    if (IsRingBufferEmpty(p_RingBuffer))
    {
        printf("Ring buffer is empty.Can not write \n");
        return FALSE;
    }
    *p_Data = p_RingBuffer->buffer[p_RingBuffer->tail];
    p_RingBuffer->tail = (p_RingBuffer->tail + SET) % RING_BUFFER_SIZE;
    p_RingBuffer->size--;
     return TRUE;
    
}
bool IsRingBufferFull (RingBufferType *p_RingBuffer)
{
    return (p_RingBuffer->size == RING_BUFFER_SIZE);
}
bool IsRingBufferEmpty(RingBufferType *p_RingBuffer)
{
    return (p_RingBuffer->size == RESET);
}
void PrintRingBuffer(RingBufferType *p_RingBuffer)
{
    if (!p_RingBuffer->size)
    {
        printf("Ring buffer is empty\n");
    }
    uint32_t loopVar,sensorIDVar=0;
    printf("Sensor Data\n");
    for (loopVar=0,sensorIDVar=p_RingBuffer->tail;loopVar<p_RingBuffer->size;loopVar++,sensorIDVar=((sensorIDVar+1)%RING_BUFFER_SIZE))
    {
        printf("Sensor ID:%d    Temprature=%.2f\n",p_RingBuffer->buffer[sensorIDVar].sensorID,p_RingBuffer->buffer[sensorIDVar].temprature);
    }
}