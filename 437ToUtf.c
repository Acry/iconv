#include <stdlib.h>
#include <errno.h>
#include <iconv.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

  (void)argc;
  (void)argv;

  iconv_t foo = iconv_open("UTF-8", "437");
  if (!foo)
  {
    if (errno == EINVAL)
    {
      fprintf(stderr,
              "Conversion is not supported");
    }
    else
    {
      fprintf(stderr, "Initialization failure:\n");
    }
  }

  unsigned char letter = 153; // 437 Ö
  int **lp = &letter;
  // UTF-8 uses 1 to 4 bytes per character
  // '\0' - terminating null character
  char *converted = calloc(5, sizeof(char));
  char *converted_start = converted;
  printf("\nSize of in Bytes: %zu\n", sizeof(&converted));
  size_t ibl = sizeof(letter); // len of iso
  size_t obl = 5;              // len of converted

  int ret = iconv(foo, &lp, &ibl, &converted, &obl);

  if (!ret == (iconv_t)-1)
  {
    perror("iconv");
  }
  else
  {
    printf("result: '%s'\n", converted_start);
  }
  iconv_close(foo);
  return EXIT_SUCCESS;
}