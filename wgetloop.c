#include <stdlib.h>

#include <stdio.h>
#include <string.h>

int
main(int argc, char* argv[])
{
    size_t file_digits;
    char* full_command;
    unsigned long i, file_count, file_start, file_final;

    if (argc < 2) {
        fprintf(stderr, "%s:  missing base URI\n", argv[0]);
        return 1;
    }
    if (argc < 3) {
        fputs("missing common file extension or naming suffix\n", stderr);
        return 1;
    }

    if (argc < 4) {
        fputs("unspecified file number limit\n", stderr);
        return 1;
    }
    if (argc < 5) {
        file_final = strtoul(argv[3], NULL, 10);
        file_start = 0;
    } else {
        file_start = strtoul(argv[3], NULL, 10);
        file_final = strtoul(argv[4], NULL, 10);
    }

    if (file_final < file_start) {
        file_count = file_start; /* Swap final with start. */
        file_start = file_final;
        file_final = file_count;

        file_count = file_count - file_start + 1;
        file_digits = strlen(argv[3]); /* We would swap argv[3] with argv[4]. */
    } else {
        file_count = file_final - file_start + 1;
        file_digits = strlen(argv[(argc >= 5) ? 4 : 3]);
    }

    printf(
        "Downloading %lu files, numbered %lu through %lu.\n",
        file_count, file_start, file_final
    );
    puts("If this is correct, press ENTER to start.");
    getchar();

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

    for (i = 0; i < file_count; i++) {
        sprintf(
            full_command, "wget %s%.*lu%s %s",
            argv[1], file_digits, file_start + i, argv[2],
            "--auth-no-challenge"
        );
        system(full_command);
    }
    free(full_command);
    return 0;
}
