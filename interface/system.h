/* System functions - memory management, terminating */

#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


/* SYSTEM VARIABLES AND ARRAYS */

#define START_POINTERS_SIZE 1

bool mem_log_enabled = false;       /* Memory logging flag */
void **pointers;                    /* Allocated memory pointers */
size_t pointers_size;               /* Pointers array size */
size_t pointers_offset;             /* Pointers array position */
size_t pointers_last = SIZE_MAX;    /* Last freed position */


/* RETURN CODES */

#define RCODE_OK        0   /* Success */
#define RCODE_EOF       1   /* EOF reached */
#define RCODE_UNEXP     2   /* Unexpected symbol */
#define RCODE_EMPTY     3   /* Empty input */
#define RCODE_UNKN      4   /* Unknown error */
#define RCODE_NF        5   /* Not found */
#define RCODE_MALLOC    6   /* Memory allocating error */
#define RCODE_REALLOC   7   /* Memory reallocating error */


/* FUNCTIONS */

void mem_init();                                            /* Initializes memory logging */

size_t mem_log(void *p);                                    /* Makes record */

void global_free();                                         /* Frees all allocated memory */

void terminate(unsigned char return_code);                  /* Terminates program correctly */

void *mallocate(size_t size, size_t *offset);               /* Allocates memory with logging */

void *reallocate(void *p, size_t new_size, size_t offset);  /* Reallocates memory with logging */

void free_logged(void *p, size_t offset);                   /* Frees memory with logging */



/* FUNCTIONS IMPLEMENTATION */


void mem_init() {
    
    if(mem_log_enabled == false) {
    
        pointers_size = START_POINTERS_SIZE;
        
        /* Trying to allocate memory for pointers array */
        
        pointers = malloc(pointers_size * sizeof(*pointers));
        
        if(pointers == NULL) terminate(RCODE_MALLOC);
        
        mem_log_enabled = true;
        
    } else if(pointers_offset == pointers_size) {
        
        pointers_size *= 2;
        pointers = realloc(pointers, pointers_size * sizeof(*pointers));
        
        if(pointers == NULL) terminate(RCODE_REALLOC);
    }
}


size_t mem_log(void *p) {
    
    if(pointers_last == SIZE_MAX) {
        
        /* Writing to previously unused memory */
        
        mem_init();
        
        pointers[pointers_offset++] = p;
        
        return pointers_offset - 1;
        
    } else {
        
        /* Writing to freed memory */
        
        void **q = pointers[pointers_last];
        
        size_t offset = pointers_last;      /* Copying last pointer */
        
        if(((uintptr_t)q & 1) == 1) {
            
            /* Cell contains pointer to another freed cell */
            
            q = (void *)((char *)q - 1);        /* Unmarking pointer */
            
            pointers_last = q - pointers;       /* Refreshing last pointer */
            
            pointers[offset] = p;               /* Assiging new value */
            
        } else {
            
            /* Last free cell */
            
            pointers[pointers_last] = p;
            
            pointers_last = SIZE_MAX;
        }
        
        return offset;
    }
}


void global_free() {
    
    if(mem_log_enabled == true) {
        
        /* Freeing memory with skipping marked pointers */
        
        for(size_t i = 0; i < pointers_offset; ++i)
            if(((uintptr_t)pointers[i] & 1) != 1 && pointers[i] != NULL)
                free(pointers[i]);
        
        free(pointers);
    }
}


void terminate(unsigned char return_code) {
    
    global_free();
    
    exit(return_code);
}


void *mallocate(size_t size, size_t *offset) {
    
    void *p = malloc(size);
    
    if(p == NULL) terminate(RCODE_MALLOC);
    
    *offset = mem_log(p);
    
    return p;
}


void *reallocate(void *p, size_t new_size, size_t offset) {
    
    p = realloc(p, new_size);
    
    if(p == NULL) terminate(RCODE_REALLOC);
    
    pointers[offset] = p;
    
    return p;
}


void free_logged(void *p, size_t offset) {
    
    free(p);
    
    /* Freeing cell */
    
    if(pointers_last == SIZE_MAX) {
        
        /* First freed cell */
        
        pointers[offset] = NULL;
        
        pointers_last = offset;
        
    } else {
        
        /* Writing marked pointer */
        
        pointers[offset] = (void *)((char *)(&pointers[pointers_last]) + 1);
        
        pointers_last = offset;
    }
}
