/* Numbers manipulating functions */

#pragma once

#include <stdio.h>
#include <stdint.h>

#include "system.h"
#include "io.h"
#include "locale.h"


/* STRUCTURES */

/* Natural number */

typedef struct {
    
    signed char *digits;
    size_t length;
    size_t offset_digits;       /* Service */
    size_t offset_struct;       /* Service */
    
} natural;


/* Integer number */

typedef struct {
    
    signed char *digits;
    size_t length;
    size_t offset_digits;       /* Service */
    size_t offset_struct;       /* Service */
    bool sign;
    
} integer;


/* Fraction */

typedef struct {
    
    integer *numerator;
    natural *denominator;
    size_t offset_struct;       /* Service */
    
} fraction;



/* FUNCTIONS */

int read_int(const char *message);							/* Read from stdin */

void write_int(int n);									/* Write to stdout */

void write_bool(bool value);							/* Write to stdout */


/* Natural numbers */

natural *init_natural(size_t length);                   /* Initialize */

natural *copy_natural(natural *N);                      /* Copy */

void resize_natural(natural *N, size_t new_length);     /* Resize */

void free_natural(natural *N);                          /* Remove from memory */

natural *read_natural(const char *message);             /* Read from stdin */

void write_natural(natural *N);                         /* Write to stdout */


/* Integer numbers */

integer *init_integer(size_t length);                   /* Initialize */

integer *copy_integer(integer *N);                      /* Copy */

void resize_integer(integer *N, size_t new_length);     /* Resize */

void free_integer(integer *N);                          /* Remove from memory */

integer *read_integer(const char *message);             /* Read from stdin */

void write_integer(integer *N);                         /* Write to stdout */


/* Fractions */

fraction *init_fraction(integer *A, natural *B);        /* Initialize */

fraction *copy_fraction(fraction *F);                   /* Copy */

void free_fraction(fraction *F);                        /* Remove from memory */

fraction *read_fraction(const char *message);           /* Read */

void write_fraction(fraction *F);                       /* Write to stdout */



/* FUNCTIONS IMPLEMENTATIONS */


int read_int(const char *message) {
	
    int result = 0;
    bool success = false;
	bool sign = true;
    
    while(success == false) {
        
        success = true;
        
        print(message);
        
        char current = skip_spaces();   /* Reading first non-space symbol */
        
        if(current == '-') {
            
            sign = false;
            current = skip_spaces();
        }
        
        while(!feof(stdin) && current != '\n') {
            
            if(isdigit(current) && result <= 100000000) {
                
                result *= 10;
                result += current - '0';
                current = getchar();
                
            } else if(current == ' ') {
                
                current = getchar();
                
            } else {
                
                /* Unexpected symbol */
                
                success = false;
                print(UNEXP_SYMBOL "\n\n");
                
                while(!feof(stdin) && current != '\n') current = getchar();
            }
        }
        
        if(feof(stdin)) terminate(RCODE_EOF);
    }
    
    if(sign == false) result = -result;
    
    return result;
}


void write_int(int n) {
	
	printf("%d\n", n);
}

void write_bool(bool value) {
	
	if(value == true)
		printf(TRUE "\n");
	else
		printf(FALSE "\n");
}


natural *init_natural(size_t length) {
    
    size_t offset;
    
    natural *N = mallocate(sizeof(*N), &offset);
    
    N -> offset_struct = offset;
    
    N -> digits = mallocate(length * sizeof(*(N -> digits)), &offset);
    
    N -> offset_digits = offset;
    
    N -> length = length;
    
    return N;
}


natural *copy_natural(natural *N) {
	
	natural *result = init_natural(N -> length);
	
	for(size_t i = 0; i < (N -> length); ++i)
		result -> digits[i] = N -> digits[i];
	
	return result;
}


void resize_natural(natural *N, size_t new_length) {
    
    N -> digits = reallocate(N -> digits, new_length * sizeof(*(N -> digits)), N -> offset_digits);
    N -> length = new_length;
}


void free_natural(natural *N) {
	
	/* TEMPORARY BUGFIX */
	
	bool correct_address = false;
	
	for(size_t i = 0; i < pointers_offset; ++i) {
		
		if(pointers[i] == N) {
			correct_address = true;
			break;
		}
	}
	
	if(correct_address == false) return;
	
    
    free_logged(N -> digits, N -> offset_digits);
    
    free_logged(N, N -> offset_struct);
}


natural *read_natural(const char *message) {
    
    /* Reading number to string */
    
    size_t offset;
    size_t str_offset;
    size_t str_size = 2;
    
    bool success = false;
    
    char *str = mallocate(str_size * sizeof(*str), &offset);
    
    while(success == false) {
        
        success = true;
		str_offset = 0;
        
        print(message);
        
        char current = skip_spaces();   /* Reading first non-space symbol */
        
        /* Skipping leading zeros */
        
        bool was_zero = false;
        
        while(!feof(stdin) && current != '\n' && (current == '0' || current == ' ')) {
			
			if(current == '0') was_zero = true;
			current = getchar();
		}
        
        /* Handling possible errors */
        
        if(feof(stdin)) terminate(RCODE_EOF);
        
        if(current == '\n') {
			
			if(was_zero == true) {
				
				str[0] = '0';
				str_offset = 1;
				
			} else success = false;		/* Non-digital symbol */
		}
        
        while(!feof(stdin) && current != '\n') {
            
            if(isdigit(current)) {
                
                if(str_offset == str_size) {
                    
                    str_size *= 2;
                    str = reallocate(str, str_size * sizeof(*str), offset);
                }
                
                str[str_offset++] = current;
                current = getchar();
                
            } else if(current == ' ') {
                
                current = getchar();
                
            } else {
                
                /* Unexpected symbol */
                
                success = false;
                
                print(UNEXP_SYMBOL "\n\n");
                
                while(!feof(stdin) && current != '\n') current = getchar();
            }
        }
        
        if(feof(stdin)) terminate(RCODE_EOF);
    }
    
    /* Initializing number */
    
    natural *result = init_natural(str_offset);
    
    /* Copying */
    
    size_t j = 0;
    
    for(size_t i = str_offset - 1; i != SIZE_MAX; --i)
        result -> digits[j++] = str[i] - '0';
    
    free_logged(str, offset);
    
    return result;
}


void write_natural(natural *N) {
    
    for(size_t i = N -> length - 1; i != SIZE_MAX; --i)
        putchar(N -> digits[i] + '0');
    
    putchar('\n');
}


integer *init_integer(size_t length) {
    
    size_t offset;
    
    integer *N = mallocate(sizeof(*N), &offset);
    
    N -> offset_struct = offset;
    
    N -> digits = mallocate(length * sizeof(*(N -> digits)), &offset);
    
    N -> offset_digits = offset;
    
    N -> length = length;
    
    return N;
}


integer *copy_integer(integer *N) {
	
	integer *result = init_integer(N -> length);
	
	result -> sign = N -> sign;
	
	for(size_t i = 0; i < (N -> length); ++i)
		result -> digits[i] = N -> digits[i];
	
	return result;
}


void resize_integer(integer *N, size_t new_length) {
    
    N -> digits = reallocate(N -> digits, new_length * sizeof(*(N -> digits)), N -> offset_digits);
    N -> length = new_length;
}


void free_integer(integer *N) {
	
	/* TEMPORARY BUGFIX */
	
	bool correct_address = false;
	
	for(size_t i = 0; i < pointers_offset; ++i) {
		
		if(pointers[i] == N) {
			correct_address = true;
			break;
		}
	}
	
	if(correct_address == false) return;
	
    
    free_logged(N -> digits, N -> offset_digits);
    
    free_logged(N, N -> offset_struct);
}


integer *read_integer(const char *message) {
    
    /* Reading number to string */
    
    size_t offset;
    
    size_t str_size = 2;
    size_t str_offset;
    bool sign = true;
    
    bool success = false;
    
    char *str = mallocate(str_size * sizeof(*str), &offset);
    
    while(success == false) {
        
        success = true;
        str_offset = 0;
        
        print(message);
        
        char current = skip_spaces();   /* Reading first non-space symbol */
        
        if(current == '-') {
            
            sign = false;
            current = skip_spaces();
        }
        
        /* Skipping leading zeros */
        
        bool was_zero = false;
        
        while(!feof(stdin) && current != '\n' && (current == '0' || current == ' ')) {
			
			if(current == '0') was_zero = true;
			current = getchar();
		}
        
        /* Handling possible errors */
        
        if(feof(stdin)) terminate(RCODE_EOF);
        
        if(current == '\n') {
			
			if(was_zero == true) {
				
				str[0] = '0';
				str_offset = 1;
				
			} else success = false;		/* Non-digital symbol */
		}
        
        while(!feof(stdin) && current != '\n') {
            
            if(isdigit(current)) {
                
                if(str_offset == str_size) {
                    
                    str_size *= 2;
                    str = reallocate(str, str_size * sizeof(*str), offset);
                }
                
                str[str_offset++] = current;
                current = getchar();
                
            } else if(current == ' ') {
                
                current = getchar();
                
            } else {
                
                /* Unexpected symbol */
                
                success = false;
                
                print(UNEXP_SYMBOL "\n\n");
                
                while(!feof(stdin) && current != '\n') current = getchar();
            }
        }
        
        if(feof(stdin)) terminate(RCODE_EOF);
    }
    
    /* Initializing number */
    
    integer *result = init_integer(str_offset);
    
    result -> sign = sign;
    
    /* Copying */
    
    size_t j = 0;
    
    for(size_t i = str_offset - 1; i != SIZE_MAX; --i)
        result -> digits[j++] = str[i] - '0';
    
    free_logged(str, offset);
    
    return result;
}


void write_integer(integer *N) {
    
    if(N -> sign == false) putchar('-');
    
    for(size_t i = N -> length - 1; i != SIZE_MAX; --i)
        putchar(N -> digits[i] + '0');
    
    putchar('\n');
}


fraction *init_fraction(integer *A, natural *B) {
    
    size_t offset;
    
    fraction *F = mallocate(sizeof(*F), &offset);
    
    F -> numerator = copy_integer(A);
    F -> denominator = copy_natural(B);
    F -> offset_struct = offset;
    
    return F;
}


fraction *copy_fraction(fraction *F) {
    
    return init_fraction(F -> numerator, F -> denominator);
}


void free_fraction(fraction *F) {
    
	/* TEMPORARY BUGFIX */
	
	bool correct_address = false;
	
	for(size_t i = 0; i < pointers_offset; ++i) {
		
		if(pointers[i] == F) {
			correct_address = true;
			break;
		}
	}
	
	if(correct_address == false) return;
    
    free_integer(F -> numerator);
    free_natural(F -> denominator);
    
    free_logged(F, F -> offset_struct);
}


fraction *read_fraction(const char *message) {
    
    print(message);
    
    integer *A = read_integer(NUMERATOR);
    natural *B = read_natural(DENOMINATOR);
    
    fraction *F = init_fraction(A, B);
    
    free_integer(A);
    free_natural(B);
    
    return F;
}


void write_fraction(fraction *F) {
    
    write_integer(F -> numerator);
    write_natural(F -> denominator);
}
