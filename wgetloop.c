#include <stdlib.h>

#include <stdio.h>
#include <string.h>

int
main(int argc, char* argv[])
{
    size_t file_digits;
    char* full_command;
    unsigned long i, file_number, files_to_download;

    if (argc < 2) {
        fprintf(stderr, "%s:  missing base URI\n", argv[0]);
        return 1;
    }
    if (argc < 3) {
        fputs("missing common file extension or naming suffix\n", stderr);
        return 1;
    }

    if (argc < 4) {
        fputs("unspecified number of download iterations to run\n", stderr);
        return 1;
    }
    files_to_download = strtoul(argv[3], NULL, 0);

    if (argc < 5) {
        file_number = 0;
        file_digits = strlen("0");
    } else {
        file_number = strtoul(argv[4], NULL, 10);
        file_digits = strlen(argv[4]);
    }

    full_command = (char *)malloc(
        sizeof("wget")
      + strlen(argv[1]) /* example:  "http://www.example.com/image-number-" */
      + strlen(argv[2]) /* example:  ".jpg" */
      + file_digits /* example:  "000000" */
      + 1 /* in case URL counts like (9.jpg, 10.jpg), not (09.jpg, 10.jpg) */
      + sizeof("--auth-no-challenge")
    );
    if (full_command == NULL) {
        fputs("insufficient free memory available\n", stderr);
        return 1;
    }

    for (i = 0; i < files_to_download; i++) {
        sprintf(
            full_command, "wget %s%.*lu%s %s",
            argv[1], file_digits, file_number + i, argv[2],
            "--auth-no-challenge"
        );
        system(full_command);
    }
    free(full_command);
    return 0;
}
