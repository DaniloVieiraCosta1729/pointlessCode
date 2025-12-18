#ifndef TOOLS_C
#define TOOLS_C
void transfWithPointer(int * boxA, int * boxB, void (*transf)(int *, int *));
void showBoxes(int * a, int * b);
int solution();
#endif