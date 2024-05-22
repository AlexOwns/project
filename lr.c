#include "lr.h"
#define N 3
#define K 4

int lab1()
{
    float V;
    float v1;
    float v2;
    float t;
    printf("V = ");
    scanf("%f", &V);
    printf("v1 = ");
    scanf("%f", &v1);
    printf("v2 = ");
    scanf("%f", &v2);
    t = V/(v1-v2);
    printf("time = %f", t);
    return 0;
}
int dop1(){
    float V, v1, v2, t;
    printf("V = ");
    scanf("%f", &V);
    printf("v1 = ");
    scanf("%f", &v1);
    printf("v2 = ");
    scanf("%f", &v2);
    t = V/(v1-v2);
    printf("time = %f", t);
    return 0;
}
int lab2(){
    float s, a, b, e;
    int n;
    printf("n=");
    scanf("%d", &n);
    s = 0;
    a = 1;
    b = 1;
    e = a/b;
    while(n>0) {
        s += e;
        a = a*(a+2);
        b = b*(b+3);
        e = a/b;
        n --;
    }
    printf("s = %f", s);
    return 0;
}
int dop2(){
    float recursia(int n, float a, float b, float e) {
        if (n == 0) {
            return 0;
        }
        float s = e + recursia(n - 1, a * (a + 2), b * (b + 3), a * (a + 2) / (b * (b + 3)));
        return s;
    }

    float s, a, b, e;
    int n;
    printf("n=");
    scanf("%d", &n);
    s = 0;
    a = 1;
    b = 1;
    e = a / b;
    s = recursia(n, a, b, e);
    printf("s = %f\n", s);
    return 0;

}
int lab3(){
    char c;
    int in_word = 0;
    int contains_a = 0;
    int word_count = 0;

    printf("Введите текст: ");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            if (in_word) {
                if (contains_a) {
                    word_count++;
                }
                in_word = 0;
                contains_a = 0;
            }
        } else {
            in_word = 1;
            if (c == 'a' || c == 'A') {
                contains_a = 1;
            }
        }
    }

    if (in_word && contains_a) {
        word_count++;
    }

    printf("Количество слов, содержащих букву 'а': %d\n", word_count);

    return 0;
}
int dop3(){
    char c;
    int in_word = 0;
    int contains_a = 0;
    int contains_b = 0;
    int word_count = 0;

    printf("Введите текст: ");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == ',' || c == '.' || c == '\n') {
            if (in_word) {
                if (contains_a && !contains_b) {
                    word_count++;
                }
                in_word = 0;
                contains_a = 0;
                contains_b = 0;
            }
        } else {
            in_word = 1;
            if (c == 'a' || c == 'A') {
                contains_a = 1;
            }
            if (c == 'b' || c == 'B') {
                contains_b = 1;
            }
        }
    }
    if (in_word && contains_a && !contains_b) {
        word_count++;
    }

    printf("Количество слов, содержащих букву 'a', но не содержащих букву 'b': %d\n", word_count);

    return 0;
}
int lab4(){
    void remove_words(char *str) {
        int read_index = 0;
        int write_index = 0;
        char start_char, end_char;
        int word_start;

        while (str[read_index] != '\0') {
            while (str[read_index] && (str[read_index] == ' ' || str[read_index] == '\t' || str[read_index] == '\n' || str[read_index] == '\r')) {
                str[write_index++] = str[read_index++];
            }

            if (str[read_index] == '\0') break;
            word_start = read_index;
            while (str[read_index] && str[read_index] != ' ' && str[read_index] != '\t' && str[read_index] != '\n' && str[read_index] != '\r') {
                read_index++;
            }
            if (word_start < read_index) {
                start_char = str[word_start];
                end_char = str[read_index - 1];
                if (start_char >= 'A' && start_char <= 'Z') {
                    start_char += 'a' - 'A';
                }
                if (end_char >= 'A' && end_char <= 'Z') {
                    end_char += 'a' - 'A';
                }
                if (start_char != end_char) {
                    while (word_start < read_index) {
                        str[write_index++] = str[word_start++];
                    }
                }
            }
            while (str[read_index] && (str[read_index] == ' ' || str[read_index] == '\t' || str[read_index] == '\n' || str[read_index] == '\r')) {
                str[write_index++] = str[read_index++];
            }
        }
        str[write_index] = '\0';
    }
    char input[1000];
    int i = 0;
    char c;

    while ((c = getchar()) != EOF && c != '\n' && i < sizeof(input) - 1) {
        input[i++] = c;
    }
    input[i] = '\0';

    remove_words(input);

    printf("Результат: %s\n", input);

    return 0;
}
int dop4(){
    void process_words(char *str, char *longest_word) {
        int read_index = 0;
        int write_index = 0;
        char start_char, end_char;
        int word_start;

        int max_word_len = 0;
        int current_word_start = 0;
        int current_word_len = 0;

        while (str[read_index] != '\0') {
            while (str[read_index] && (str[read_index] == ' ' || str[read_index] == '\t' || str[read_index] == '\n' || str[read_index] == '\r')) {
                str[write_index++] = str[read_index++];
            }

            if (str[read_index] == '\0') break;
            word_start = read_index;
            while (str[read_index] && str[read_index] != ' ' && str[read_index] != '\t' && str[read_index] != '\n' && str[read_index] != '\r') {
                read_index++;
            }
            if (word_start < read_index) {
                start_char = str[word_start];
                end_char = str[read_index - 1];
                if (start_char >= 'A' && start_char <= 'Z') {
                    start_char += 'a' - 'A';
                }
                if (end_char >= 'A' && end_char <= 'Z') {
                    end_char += 'a' - 'A';
                }

                current_word_start = word_start;
                current_word_len = read_index - word_start;
                if (current_word_len > max_word_len) {
                    max_word_len = current_word_len;
                    for (int i = 0; i < max_word_len; i++) {
                        longest_word[i] = str[current_word_start + i];
                    }
                    longest_word[max_word_len] = '\0';
                }
                if (start_char != end_char) {
                    while (word_start < read_index) {
                        str[write_index++] = str[word_start++];
                    }
                }
            }
            while (str[read_index] && (str[read_index] == ' ' || str[read_index] == '\t' || str[read_index] == '\n' || str[read_index] == '\r')) {
                str[write_index++] = str[read_index++];
            }
        }
        str[write_index] = '\0';
    }
    char input[1000];
    char longest_word[1000] = "";
    int i = 0;
    char c;


    while ((c = getchar()) != EOF && c != '\n' && i < sizeof(input) - 1) {
        input[i++] = c;
    }
    input[i] = '\0';

    process_words(input, longest_word);

    printf("Результат: %s\n", input);
    if (longest_word[0] != '\0') {
        printf("Самое длинное слово: %s\n", longest_word);
    } else {
        printf("Самое длинное слово не найдено.\n");
    }

    return 0;
}
int lab5(){
    int g[10];
    int min = 0, max = 0;
    int i;
    printf("Введите 10 целых чисел: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &g[i]);
    }
    for (i = 1; i < 10; i++) {
        if (g[i] < g[min]) {
            min = i;
        }
        if (g[i] > g[max]) {
            max = i;
        }
    }
    int start = min < max ? min + 1 : max + 1;
    int end = min < max ? max : min;
    for (i = start; i < end; i++) {
        g[i] = 0;
    }
    printf("Массив после обнуления:");
    for (i = 0; i < 10; i++) {
        printf("%d ", g[i]);
    }
    return 0;
    printf("\n");
}
int dop5(){
    double avg(int arr[], int start, int end) {
        int sum = 0, count = 0;
        for (int i = start; i < end; i++) {
            sum += arr[i];
            count++;
        }
        return count > 0 ? (double)sum / count : 0;
    }


    int g[10];
    int min = 0, max = 0;
    int i;
    printf("Введите 10 целых чисел: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &g[i]);
    }
    for (i = 1; i < 10; i++) {
        if (g[i] < g[min]) {
            min = i;
        }
        if (g[i] > g[max]) {
            max = i;
        }
    }

    int start = min < max ? min + 1 : max + 1;
    int end = min < max ? max : min;

    double average = avg(g, start, end);
    printf("\nСреднее арифметическое чисел, которые должны обнулиться: %.2lf\n", average);

    for (i = start; i < end; i++) {
        g[i] = 0;
    }
    printf("Массив после обнуления:");
    for (i = 0; i < 10; i++) {
        printf("%d ", g[i]);
    }

    printf("\n");
    return 0;

}

int lab6(){
    int ar_prog(int arr[N][K]) {
        int i, j, diff = arr[0][1] - arr[0][0];

        for (i = 0; i < N; i++) {
            for (j = 2; j < K; j++) {
                if (arr[i][j] - arr[i][j - 1] != diff) {
                    return 0;
                }
            }
        }

        return 1;
    }
    int arr[N][K];
    int i, j;

    printf("Введите элементы массива %d на %d:\n", N, K);
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    if (ar_prog(arr)) {
        printf("Массив является арифметической прогрессией\n");
    } else {
        printf("Массив не является арифметической прогрессией\n");
    }
    return 0;
}
int dop6(){
    void selection_sort(int arr[N][K]) {
        for(int i=0; i<N*K-1; i++){
            int min_row=i/K;
            int min_c=i%K;
            for (int j = i+1; j < N*K; j++){
                int row=j/K;
                int c=j%K;
                if (arr[row][c]<arr[min_row][min_c]){
                    min_row=row;
                    min_c=c;
                }
            }
            if (i!=min_row*K+min_c){
                int temp = arr[i/K][i%K];
                arr[i/K][i%K] = arr[min_row][min_c];
                arr[min_row][min_c] = temp;
            }
        }
    }
    int ar_prog(int arr[N][K]) {
        int i, j, diff = arr[0][1] - arr[0][0];

        for (i = 0; i < N; i++) {
            for (j = 2; j < K; j++) {
                if (arr[i][j] - arr[i][j - 1] != diff) {
                    return 0;
                }
            }
        }

        return 1;
    }
    int arr[N][K];
    int i, j;

    printf("Введите элементы массива %d на %d:\n", N, K);
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    selection_sort(arr);
    printf("\nОтсортированный массив:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    if (ar_prog(arr)) {
        printf("Массив является арифметической прогрессией\n");
    } else {
        printf("Массив не является арифметической прогрессией\n");
    }
    return 0;
}
int lab7(){
    unsigned long cycle(unsigned long n, int k){
        unsigned long result;
        for(int i=0;i<k;i++){
            result=n<<i;
        }

        return result;
    }

    unsigned long n;
    int k;
    printf("Введите N: ");
    scanf("%ld", &n);
    printf("Введите K: ");
    scanf("%d", &k);
    unsigned long result=cycle(n, k);
    printf("Результат циклического сдвига: %ld\n", result);
    return 0;
}
