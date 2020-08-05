#ifndef HEAP_HJ
#define HEAP_HJ

#include <stdint.h>
#include <stdio.h>

#define portBYTE_ALIGNMENT 8

#if portBYTE_ALIGNMENT == 8
#define portBYTE_ALIGNMENT_MASK (0x0007U)
#endif

#if portBYTE_ALIGNMENT == 4
#define portBYTE_ALIGNMENT_MASK (0x0003)
#endif

#if portBYTE_ALIGNMENT == 2
#define portBYTE_ALIGNMENT_MASK (0x0001)
#endif

#if portBYTE_ALIGNMENT == 1
#define portBYTE_ALIGNMENT_MASK (0x0000)
#endif

#define configTOTAL_HEAP_SIZE 256 * 1024

#define configASSERT(x)

#define vTaskSuspendAll()
#define xTaskResumeAll()

#define mtCOVERAGE_TEST_MARKER()

typedef struct _SHeapRegion {
  uint8_t* pucStartAddress;
  size_t xSizeInBytes;
} SHeapRegion;

void vPortDefineHeapRegions(const SHeapRegion* const pxHeapRegions);

void* pvPortMalloc(size_t xWantedSize);

void vPortFree(void* pv);

size_t xPortGetFreeHeapSize(void);

size_t xPortGetMinimumEverFreeHeapSize(void);

void dump_mem_block_list();

#endif