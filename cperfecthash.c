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
// Enums for the mappings of string -> token
enum fnv1_with_mod_func0_enums
{
    AUTO_FNV1_FUNC0_TOKEN = 15,
    BREAK_FNV1_FUNC0_TOKEN = 2,
    CASE_FNV1_FUNC0_TOKEN = 34,
    CHAR_FNV1_FUNC0_TOKEN = 10,
    CONST_FNV1_FUNC0_TOKEN = 21,
    CONTINUE_FNV1_FUNC0_TOKEN = 36,
    DEFAULT_FNV1_FUNC0_TOKEN = 8,
    DO_FNV1_FUNC0_TOKEN = 27,
    DOUBLE_FNV1_FUNC0_TOKEN = 22,
    ELSE_FNV1_FUNC0_TOKEN = 9,
    ENUM_FNV1_FUNC0_TOKEN = 23,
    EXTERN_FNV1_FUNC0_TOKEN = 0,
    FLOAT_FNV1_FUNC0_TOKEN = 19,
    FOR_FNV1_FUNC0_TOKEN = 31,
    GOTO_FNV1_FUNC0_TOKEN = 12,
    IF_FNV1_FUNC0_TOKEN = 35,
    INT_FNV1_FUNC0_TOKEN = 25,
    INLINE_FNV1_FUNC0_TOKEN = 7,
    LONG_FNV1_FUNC0_TOKEN = 14,
    REGISTER_FNV1_FUNC0_TOKEN = 16,
    RESTRICT_FNV1_FUNC0_TOKEN = 28,
    RETURN_FNV1_FUNC0_TOKEN = 26,
    SHORT_FNV1_FUNC0_TOKEN = 6,
    SIGNED_FNV1_FUNC0_TOKEN = 4,
    SIZEOF_FNV1_FUNC0_TOKEN = 13,
    STATIC_FNV1_FUNC0_TOKEN = 30,
    STRUCT_FNV1_FUNC0_TOKEN = 3,
    SWITCH_FNV1_FUNC0_TOKEN = 32,
    TYPEDEF_FNV1_FUNC0_TOKEN = 18,
    UNION_FNV1_FUNC0_TOKEN = 1,
    UNSIGNED_FNV1_FUNC0_TOKEN = 24,
    VOID_FNV1_FUNC0_TOKEN = 29,
    VOLATILE_FNV1_FUNC0_TOKEN = 17,
    WHILE_FNV1_FUNC0_TOKEN = 5
};

// FNV1A Hash (https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)
// NOTE: There are no 8-bit FNV1A Perfect hash functions for the C programming language
// NOTE: There are no 16-bit FNV1A Perfect hash functions for the C programming language

// Level 0 
uint32_t c_perfect_hash_fnv1a(const char* string)
{
  return 0;
}
