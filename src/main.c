#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct First {
    int32_t (*func)(int32_t);
    int32_t data;
    int8_t bebs;
};

struct Second {
    int32_t (*func)(int32_t);
    int32_t data;
    int32_t kek;
};

struct Third {
    int32_t (*func)(int32_t);
    int32_t data;
};

void first(void *abstract) {
    struct Third *foo = (struct Third *) abstract;
    int32_t data = foo->data;
    printf("[%p]Data is %d\n", abstract, data);
}

int32_t first_foo(int32_t i) {
    printf("First function. i is %d\n", i);
    return 1337;
}

int32_t second_foo(int32_t i) {
    printf("Second function. j is %d\n", i);
    return 1488;
}

void exec_func(void *abstract) {
    struct Third *foo = (struct Third *) abstract;
    int32_t res = foo->func(3336);
    printf("Result is: %d\n", res);
}

int32_t main(int32_t argc, char *argv[]) {
    struct First *obj1 = (struct First *) malloc(sizeof(struct First));
    obj1->func = &first_foo;
    obj1->bebs = 5;
    obj1->data = 1488;

    struct Second *obj2 = (struct Second *) malloc(sizeof(struct Second));
    obj2->func = &second_foo;
    obj2->kek = 1337;
    obj2->data = 228;

    printf("Obj1: %p\n", obj1);
    printf("Obj2: %p\n", obj2);

    first(obj1);
    first(obj2);

    exec_func(obj1);
    exec_func(obj2);

    free(obj1);
    free(obj2);

    return 0;
}