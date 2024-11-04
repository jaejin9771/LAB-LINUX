// main.c
#include <stdio.h>
#include <dlfcn.h>

int main() {
    // 라이브러리 핸들
    void *handle;
    int (*add)(int, int);
    int (*subtract)(int, int);
    int (*multiply)(int, int);
    int (*divide)(int, int);

    // 라이브러리 열기
    handle = dlopen("./libcalculator.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Cannot open library: %s\n", dlerror());
        return 1;
    }

    // 함수 가져오기
    add = dlsym(handle, "add");
    subtract = dlsym(handle, "subtract");
    multiply = dlsym(handle, "multiply");
    divide = dlsym(handle, "divide");

    // 에러 확인
    if (!add || !subtract || !multiply || !divide) {
        fprintf(stderr, "Cannot load symbols: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // 사칙연산 수행
    int a = 10, b = 2;
    printf("Add: %d\n", add(a, b));
    printf("Subtract: %d\n", subtract(a, b));
    printf("Multiply: %d\n", multiply(a, b));
    printf("Divide: %d\n", divide(a, b));

    // 라이브러리 닫기
    dlclose(handle);
    return 0;
}
