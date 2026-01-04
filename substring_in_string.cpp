////
//// Created by mac on 09.10.2025.
////
//
//int substring_count(char *string, char *substring) {
//    int count = 0;
//    char *str_ptr, *sub_ptr;
//
//    if (*substring == '\0') {
//        return 0;
//    }
//
//    while (*string != '\0') {
//        str_ptr = string;
//        sub_ptr = substring;
//
//        while (*sub_ptr != '\0' && *str_ptr == *sub_ptr) {
//            str_ptr++;
//            sub_ptr++;
//        }
//
//        if (*sub_ptr == '\0') {
//            count++;
//        }
//
//        string++;
//    }
//
//    return count;
//}
//
//int main() {
//    assert(substring_count_equals("abcabc", "ab", sizeof("ab")) == 2);
//    assert(substring_count("abcabcd", "d") == 1);
//    assert(substring_count("abcabcd", "q") == 0);
//    assert(substring_count("aaaaaa", "aa") == 5);
//    assert(substring_count("", "ab") == 0);
//    assert(substring_count("abc", "") == 0);
//
//    return 0;
//}