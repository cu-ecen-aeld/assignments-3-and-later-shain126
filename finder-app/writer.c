
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>

void create_file(const char *filepath, const char *content) {
    if (!filepath || !content) {
        fprintf(stderr, "Error: Please provide the writefile and writestr arguments.\n");
        syslog(LOG_ERR, "Invalid arguments. Usage: <program> <filepath> <content>");
        exit(1);

    }

	//  Create and write to the file
    FILE *file = fopen(filepath, "w");
    if (!file) {
        perror("Error creating file");
        syslog(LOG_ERR, "Error creating file: %s", filepath);
        exit(1);
    }
    
    if (fprintf(file, "%s", content) < 0) {
        perror("Error writing to file");
        syslog(LOG_ERR, "Error writing to file: %s", filepath);
        fclose(file);
        exit(1);
    }
    
    if (fclose(file) == EOF) {
        perror("Error closing file");
        syslog(LOG_ERR, "Error closing file: %s", filepath);
        exit(1);
    }

    syslog(LOG_DEBUG, "Writing %s to %s", content, filepath);
    syslog(LOG_INFO, "File created successfully: %s", filepath);
    printf("File created successfully: %s\n", filepath);
}

int main(int argc, char *argv[]) {
    openlog("file_creator", LOG_PID | LOG_CONS, LOG_USER);
    
    if (argc != 3) {
        fprintf(stderr, "Error: Please provide the writefile and writestr arguments.\n");
        syslog(LOG_ERR, "Invalid arguments. Usage: <program> <filepath> <content>");
	exit(1);

    }
    if (strlen(argv[2]) == 0) {
        fprintf(stderr, "Error: writestr argument cannot be empty.\n");
        syslog(LOG_ERR, "Invalid argument: writestr cannot be empty.");
        exit(1);  // Ensure correct exit code for validation
    }
    create_file(argv[1], argv[2]);
    
    closelog();
    return 0;
}
