// FNV1 Hash (https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)
// NOTE: There are no 8-bit FNV1 Level 1 or higher Perfect hash functions for the C programming language
// NOTE: There are no 16-bit FNV1 Level 1 or higher Perfect hash functions for the C programming language

// Level 0 
uint32_t c_perfect_hash_32bit_fnv1_with_mod_func_0(const char* string, const size_t string_len)
{
    uint32_t hash = 3; // fnv1 offset
    for(size_t i = 0; i < string_len; ++i)
    {
        hash = hash * 3462989662; // fnv1 prime
        hash = hash ^ ((uint32_t)string[i]);
    }
    hash = hash % 37; // mod to fit into 37 entries (there are 34 for C keywords, so it is not tight making it a level 0 function)
    return hash;
}

// FNV1A Hash (https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)
// NOTE: There are no 8-bit FNV1A Perfect hash functions for the C programming language
// NOTE: There are no 16-bit FNV1A Perfect hash functions for the C programming language

// Level 0 
uint32_t c_perfect_hash_fnv1a(const char* string)
{
  return 0;
}
