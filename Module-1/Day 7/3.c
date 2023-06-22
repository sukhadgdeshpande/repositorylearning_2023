#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void readLogFile() {
    FILE *file = fopen("fileName", "r");
    if (file == NULL) {
        printf("Unable to open the log file.\n");
        return;
    }

    char line[100];
    char *token;

    
    while (fgets(line, sizeof(line), file)) {
        
        token = strtok(line, ",");
        if (token == NULL)
            continue;

        
        logEntries[numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strcpy(logEntries[numEntries].sensorNo, token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        logEntries[numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        logEntries[numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        logEntries[numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strcpy(logEntries[numEntries].timestamp, token);

        numEntries++;
    }

    fclose(file);
}

void displayLogEntries() {
    printf("Log Entries:\n");
    printf("--------------------------------------------------\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}

int main() {
    readLogFile();
    displayLogEntries();

    return 0;
}