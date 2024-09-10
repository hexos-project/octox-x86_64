// temporary heap for small allocations inside of the kernel

#include <types.hh>
#include <cpu.hh>
#include <uart.hh>

constexpr size_t HEAP_SIZE = 0x1000; // 4KB

// heap buffer
char heap[HEAP_SIZE];
// heap map
size_t heap_map[HEAP_SIZE / sizeof(size_t)];

// heap allocation
void *heap_alloc(size_t size) {
    // find a free block
    for (size_t i = 0; i < HEAP_SIZE / sizeof(size_t); i++) {
        if (heap_map[i] == 0) {
            // allocate
            heap_map[i] = size;
            return (void *)(heap + i * sizeof(size_t));
        }
    }
    uart::cout << "HeapFull\n";
    cpu::halt();
}

// heap free
void heap_free(void *ptr) {
    // find the block
    size_t i = 0;
    for (; i < HEAP_SIZE / sizeof(size_t); i++) {
        if (heap_map[i] == 0) {
            // free
            heap_map[i] = 0;
            return;
        }
    }
}

void *operator new(size_t size) {
    void *ptr = heap_alloc(size);
    return ptr;
}

void operator delete(void *ptr) {
    heap_free(ptr);
}

void operator delete(void *ptr, size_t size) {
    heap_free(ptr);
}

void *operator new[](size_t size) {
    void *ptr = heap_alloc(size);
    return ptr;
}

void operator delete[](void *ptr) {
    heap_free(ptr);
}

void operator delete[](void *ptr, size_t size) {
    heap_free(ptr);
}
