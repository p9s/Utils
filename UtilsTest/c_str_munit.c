#include "munit.h"
#include "c_str.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4127)
#endif

void main( void ) {
    
    char src[] = "abcdcdcde";
    int pos = 0;
    find_char_in_str(src, 'c', 0, &pos);
    munit_assert_int(pos, ==, 2);
    find_char_in_str(src, 'c', 3, &pos);
    munit_assert_int(pos, !=, 2);


    char to_find[] = "cd";
    find_str_in_str(src, to_find, 0, &pos);
    munit_assert_int(pos, ==, 2);
    find_str_in_str(src, to_find, 4, &pos);
    munit_assert_int(pos, ==, 4);

    char to_find1[] = "cde";
    find_str_in_str(src, to_find1, 0, &pos);
    munit_assert_int(pos, ==, 6);

    return;
}