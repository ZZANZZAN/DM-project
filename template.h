/* Description of available structures and functions */


/* Natural number */

typedef struct {
    
    signed char *digits;
    size_t length;
    
} natural;


/* Integer number */

typedef struct {
    
    signed char *digits;
    size_t length;
    bool sign;          /* True - plus, otherwise minus */
    
} integer;


/* Natural numbers */

natural *init_natural(size_t length);                   /* Initialize */

void resize_natural(natural *N, size_t new_length);     /* Resize */

void free_natural(natural *N);                          /* Remove from memory */


/* Integer numbers */

integer *init_integer(size_t length);                   /* Initialize */

void resize_integer(integer *N, size_t new_length);     /* Resize */

void free_integer(integer *N);                          /* Remove from memory */
