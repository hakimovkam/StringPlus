#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (*str++) {
    i++;
  }
  return i;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    if (*((char *)str + i) == c) {
      return (char *)str + i;
    }
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *a = (char *)str1;
  char *b = (char *)str2;
  int counter = 0;
  for (s21_size_t i = 0; i < n; i++) {
    counter = (*a++ - *b++);
    if (counter != 0) {
      return counter;
    }
  }
  return counter;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *a = (char *)dest;
  char *b = (char *)src;
  while (n--) {
    *a = *b;
    a++;
    b++;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *a = (char *)dest;
  char *b = (char *)src;
  char *temp = (char *)calloc(n, sizeof(char));
  if (temp == s21_NULL) {
    return s21_NULL;
  } else {
    s21_size_t i = 0;
    for (i = 0; i < n; i++) {
      *(temp + i) = *(b + i);
    }
    for (i = 0; i < n; i++) {
      *(a + i) = *(temp + i);
    }
    free(temp);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *a = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    *a++ = c;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t a = s21_strlen(src);
  s21_size_t b = s21_strlen(dest);
  for (s21_size_t i = b; i < a + b; i++) {
    *(dest + i) = *src++;
  }
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t b = s21_strlen(dest);
  for (s21_size_t i = b; i < n + b; i++) {
    *(dest + i) = *src++;
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (*(str + i) == c) {
      return (char *)str + i;
    }
  }
  return s21_NULL;
}

int s21_strcmp(const char *str1, const char *str2) {
  int counter = 0;
  s21_size_t a = 0;
  if (s21_strlen(str1) < s21_strlen(str2)) {
    a = s21_strlen(str2);
  } else {
    a = s21_strlen(str1);
  }
  for (s21_size_t i = 0; i < a; i++) {
    counter = *str1++ - *str2++;
    if (counter != 0) {
      return counter;
    }
  }
  return counter;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int counter = 0;
  for (s21_size_t i = 0; i < n; i++) {
    counter = *str1++ - *str2++;
    if (counter != 0) {
      return counter;
    }
  }
  return counter;
}

char *s21_strcpy(char *dest, const char *src) {
  if (dest == s21_NULL) {
    return s21_NULL;
  }
  char *point = dest;
  while (*src != '\0') {
    *dest++ = *src++;
    // printf("%c", *src);
  }
  *dest = '\0';
  return point;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest == s21_NULL) {
    return s21_NULL;
  }
  while (n--) {
    *dest++ = *src++;
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  if (str1 == s21_NULL || str2 == s21_NULL) {
    return counter;
  }
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      return counter;
    } else {
      str1++;
      counter++;
    }
  }
  return counter;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      return (char *)str1;
    } else {
      str1++;
    }
  }
  return s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *ch = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == c) {
        ch = (char *)str;
      }
    } while (*str++);
  }
  return ch;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t a = 0;
  int countStart = 0;
  int prev = 0;
  do {
    if (s21_strchr(str2, *str1)) {
      if (prev == 0 && countStart != 0) {
        return a;
      }
      a++;
      prev = 1;
    } else {
      prev = 0;
    }
    countStart++;
  } while (*str1++);
  return a;
}

char *s21_strstr(const char *haystack, const char *needle) {
  while (*haystack != '\0') {
    if (*haystack == *needle && s21_strstrHelper(haystack, needle)) {
      return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}

int s21_strstrHelper(const char *haystack, const char *needle) {
  while (*haystack && *needle) {
    if (*haystack != *needle) {
      return 0;
    }
    haystack++;
    needle++;
  }
  return 1;
}

char *s21_strtok(char *str, const char *delim) {
  static char *newGen;
  if (!str) {
    str = newGen;
  }
  if (!str) {
    return s21_NULL;
  }
  while (1) {
    if (s21_strchr(delim, *str)) {
      str++;
      continue;
    }
    if (*str == '\0') {
      return s21_NULL;
    }
    break;
  }
  char *ret = str;
  while (1) {
    if (*str == '\0') {
      newGen = str;
      return ret;
    }
    if (s21_strchr(delim, *str)) {
      *str = '\0';
      newGen = str + 1;
      return ret;
    }
    str++;
  }
  return ret;
}

#ifdef __APPLE__
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "
static const char *errorList[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
#endif

#ifdef __linux__
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "

static const char *errorList[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};
  if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST) {
    s21_strcpy(result, "Unknown error");
  } else {
    s21_strcpy(result, ((char *)errorList[errnum]));
  }
  return result;
}
