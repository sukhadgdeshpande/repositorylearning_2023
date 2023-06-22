#include <stdio.h>

typedef struct {
    double length;
    double width;
    double height;
} Box;

void calculateVolumeAndSurfaceArea(Box* box) {
    double volume, surfaceArea;
    
    volume = box->length * box->width * box->height;
    surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
    
    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
}

int main() {
    Box myBox;
    Box* boxPtr = &myBox;
    
    
    printf("Enter the length of the box: ");
    scanf("%lf", &(boxPtr->length));
    
    printf("Enter the width of the box: ");
    scanf("%lf", &(boxPtr->width));
    
    printf("Enter the height of the box: ");
    scanf("%lf", &(boxPtr->height));
    
    
    calculateVolumeAndSurfaceArea(boxPtr);
    
    return 0;
}