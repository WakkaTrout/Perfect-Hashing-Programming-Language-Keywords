#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <algorithm> // for std::sort

#define WORKSPACE_SIZE 256

char * c_terms[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if",
                    "int", "inline", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
                    "unsigned", "void", "volatile", "while"};

void calculate_fnv1_constants(char ** terms, size_t terms_len)
{
    bool values[WORKSPACE_SIZE];

    // loop through all pairs of constants
    for ( uint64_t fnv_offset_basis = 0; fnv_offset_basis < 4294967296; ++fnv_offset_basis )
    {
        for ( uint64_t fnv_offset_prime = 0; fnv_offset_prime < 4294967296; ++fnv_offset_prime)
        {
            // reset the checker array
            memset(values, 0, sizeof(bool)*terms_len);
            // calculate the hashes of all of the strings and set the indices to true
            for (size_t i = 0; i < terms_len; ++i)
            {
                uint32_t hash = (uint32_t) fnv_offset_basis;
                char* byte_ptr = terms[i];
                while(*byte_ptr != 0)
                {
                    hash = hash * (uint32_t) fnv_offset_prime;
                    hash = hash ^ (uint32_t)*byte_ptr;
                    byte_ptr = byte_ptr + 1;
                }
                uint32_t mod_hash = hash % terms_len;
                values[mod_hash] = true;
            }

            // Check to see that we set the first terms_len flags to true. If so, then we got a hit
            bool hit = true;
            for (size_t i = 0; i < terms_len; ++i)
            {
                if (!values[i])
                {
                    hit = false;
                    break;
                }
            }
            if (hit)
            {
                printf("Perfect FNV1 Hash: Offset %d, Prime: %d\n", (uint32_t) fnv_offset_basis, (uint32_t) fnv_offset_prime);
            }
        }
        if (fnv_offset_basis %10000 == 0)
        {
            printf("Done with 32-bit offset basis %d\n", (uint32_t) fnv_offset_basis);
        }
    }
}

void calculate_fnv1a_constants(char ** terms, size_t terms_len)
{
    bool values[WORKSPACE_SIZE];

    // loop through all pairs of constants
    for ( uint64_t fnv_offset_basis = 0; fnv_offset_basis < 4294967296; ++fnv_offset_basis )
    {
        for ( uint64_t fnv_offset_prime = 0; fnv_offset_prime < 4294967296; ++fnv_offset_prime)
        {
            // reset the checker array
            memset(values, 0, sizeof(bool)*terms_len);
            // calculate the hashes of all of the strings and set the indices to true
            for (size_t i = 0; i < terms_len; ++i)
            {
                uint32_t hash = (uint32_t) fnv_offset_basis;
                char* byte_ptr = terms[i];
                while(*byte_ptr != 0)
                {
                    hash = hash ^ (uint32_t)*byte_ptr;
                    hash = hash * (uint32_t) fnv_offset_prime;
                    byte_ptr = byte_ptr + 1;
                }
                uint32_t mod_hash = hash % terms_len;
                values[mod_hash] = true;
            }

            // Check to see that we set the first terms_len flags to true. If so, then we got a hit
            bool hit = true;
            for (size_t i = 0; i < terms_len; ++i)
            {
                if (!values[i])
                {
                    hit = false;
                    break;
                }
            }
            if (hit)
            {
                printf("Perfect FNV1A Hash: Offset %d, Prime: %d\n", (uint32_t) fnv_offset_basis, (uint32_t)fnv_offset_prime);
            }
        }
        if (fnv_offset_basis %10000 == 0)
        {
            printf("Done with 32-bit offset basis %d\n", (uint32_t) fnv_offset_basis);
        }
    }
}

void calculate_fnv1_constants_16bit(char ** terms, size_t terms_len)
{
    bool values[WORKSPACE_SIZE];

    // loop through all pairs of constants
    for ( uint32_t fnv_offset_basis = 0; fnv_offset_basis < 65536; ++fnv_offset_basis )
    {
        for ( uint32_t fnv_offset_prime = 0; fnv_offset_prime < 65536; ++fnv_offset_prime)
        {
            // reset the checker array
            memset(values, 0, sizeof(bool)*terms_len);
            // calculate the hashes of all of the strings and set the indices to true
            for (size_t i = 0; i < terms_len; ++i)
            {
                uint16_t hash = (uint16_t) fnv_offset_basis;
                char* byte_ptr = terms[i];
                while(*byte_ptr != 0)
                {
                    hash = hash * (uint16_t) fnv_offset_prime;
                    hash = hash ^ (uint16_t)*byte_ptr;
                    byte_ptr = byte_ptr + 1;
                }
                uint16_t mod_hash = hash % terms_len;
                values[mod_hash] = true;
            }

            // Check to see that we set the first terms_len flags to true. If so, then we got a hit
            bool hit = true;
            for (size_t i = 0; i < terms_len; ++i)
            {
                if (!values[i])
                {
                    hit = false;
                    break;
                }
            }
            if (hit)
            {
                printf("Perfect FNV1 Hash: Offset %d, Prime: %d\n", fnv_offset_basis, fnv_offset_prime);
            }
        }
        if (fnv_offset_basis %10000 == 0)
        {
            printf("Done with 16-bit offset basis %d\n", fnv_offset_basis);
        }
    }
}

void calculate_fnv1a_constants_16bit(char ** terms, size_t terms_len)
{
    bool values[WORKSPACE_SIZE];

    // loop through all pairs of constants
    for ( uint32_t fnv_offset_basis = 0; fnv_offset_basis < 65536; ++fnv_offset_basis )
    {
        for ( uint32_t fnv_offset_prime = 0; fnv_offset_prime < 65536; ++fnv_offset_prime)
        {
            // reset the checker array
            memset(values, 0, sizeof(bool)*terms_len);
            // calculate the hashes of all of the strings and set the indices to true
            for (size_t i = 0; i < terms_len; ++i)
            {
                uint16_t hash = (uint16_t) fnv_offset_basis;
                char* byte_ptr = terms[i];
                while(*byte_ptr != 0)
                {
                    hash = hash ^ (uint16_t)*byte_ptr;
                    hash = hash * (uint16_t) fnv_offset_prime;
                    byte_ptr = byte_ptr + 1;
                }
                uint16_t mod_hash = hash % terms_len;
                values[mod_hash] = true;
            }

            // Check to see that we set the first terms_len flags to true. If so, then we got a hit
            bool hit = true;
            for (size_t i = 0; i < terms_len; ++i)
            {
                if (!values[i])
                {
                    hit = false;
                    break;
                }
            }
            if (hit)
            {
                printf("Perfect FNV1A Hash: Offset %d, Prime: %d\n", fnv_offset_basis, fnv_offset_prime);
            }
        }
        if (fnv_offset_basis %10000 == 0)
        {
            printf("Done with 16-bit offset basis %d\n", fnv_offset_basis);
        }
    }
}

#if MAIN_DEBUG
int main()
#else
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#endif
{
  const size_t term_len = sizeof(c_terms)/sizeof(char*);
  //printAllPermutationTerms((const char**)terms, term_len, 4);
  calculate_fnv1_constants(c_terms, term_len);
  printf("Done with fnv1\n");
  calculate_fnv1a_constants(c_terms, term_len);
  printf("Done with fnv1a");
  //test_print();
	return 0;
}
